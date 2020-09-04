//------------------------------------------------------------------------------
// Copyright 2020 Loupe
//------------------------------------------------------------------------------

// Use uppercase namespace
var WEBHMI = {
	version: '1.3.0'
};

// UMD (Universal Module Definition)
if (typeof define === 'function' && define.amd) {
	// AMD
	define('webhmi', WEBHMI);
} else if (typeof module === 'object' && typeof module.exports === 'object') {
	// Node.js
	module.exports = WEBHMI;
}

// jQuery polyfills - Later
if (typeof jQuery === 'undefined') {
	throw new Error('Polyfill not done! Get jQuery!');
} else {
	WEBHMI.extend = jQuery.extend;
	WEBHMI.isEmptyObject = jQuery.isEmptyObject;
	WEBHMI.each = jQuery.each;
}

// Machine constructor
//-----------------------------------------------------

WEBHMI.Machine = function (options) {

	'use strict';

	var thisMachine, defaults, settings;

	// Grab machine scope for lower functions
	thisMachine = this;

	// Set defaults and extend with options, without modifying defaults
	defaults = {
		protocol: 'ws',
		ipAddress: location.hostname,
		port: 8000,
		timeout_ms: 250,
		maxRetryCount: 5,
		maxReconnectCount: 5
	};
	settings = WEBHMI.extend({}, defaults, options);

	// Value functions
	//-----------------------------------------------------

	// Set a value deep within a structure
	// Return the object that was set
	function setDeepValue(obj, prop, value) {

		var e, startArrayIndex, type, i;

		// First time through, split prop
		if (typeof prop === "string") {
			prop = prop.split(".");
		}

		if (prop.length > 1) {

			// If not at bottom of prop, keep going
			e = prop.shift();

			// Check for array elements
			startArrayIndex = e.indexOf('[');

			if (startArrayIndex === -1) {
				// If element does not exist, create it
				type = Object.prototype.toString.call(obj[e]);
				if (type !== "[object Object]") {
					obj[e] = {};
				}
				return setDeepValue(obj[e], prop, value);
			} else {
				i = parseInt(e.substring(startArrayIndex + 1), 10);
				e = e.substring(0, startArrayIndex);
				// If array does not exist, create it
				type = Object.prototype.toString.call(obj[e]);
				if (type !== "[object Array]") {
					obj[e] = [];
				}
				// If element does not exist, create it
				type = Object.prototype.toString.call(obj[e][i]);
				if (type !== "[object Object]") {
					obj[e][i] = {};
				}
				return setDeepValue(obj[e][i], prop, value);
			}

		} else {

			e = prop[0];

			// Check for array elements
			startArrayIndex = e.indexOf('[');
			if (startArrayIndex === -1) {
				obj[e] = value;
				return obj[e];
			} else {
				i = parseInt(e.substring(startArrayIndex + 1), 10);
				e = e.substring(0, startArrayIndex);
				// If array does not exist, create it
				type = Object.prototype.toString.call(obj[e]);
				if (type !== "[object Array]") {
					obj[e] = [];
				}
				obj[e][i] = value;
				return obj[e][i];
			}
		}
	}
	// setDeepValue()

	// Get the value of a property deep within a structure or array
	// Return the value of the property
	function getDeepValue(obj, prop) {

		var e, startArrayIndex, type, i;

		// First time through, split prop
		if (typeof prop === "string") {
			prop = prop.split(".");
		}

		if (prop.length > 1) {

			// If not at bottom of prop, keep going
			e = prop.shift();

			// Check for array elements
			startArrayIndex = e.indexOf('[');
			if (startArrayIndex === -1) {
				type = Object.prototype.toString.call(obj[e]);
				if (type !== "[object Object]") {
					return undefined;
				}
				return getDeepValue(obj[e], prop);
			} else {
				i = parseInt(e.substring(startArrayIndex + 1), 10);
				e = e.substring(0, startArrayIndex);
				type = Object.prototype.toString.call(obj[e]);
				if (type !== "[object Array]") {
					return undefined;
				}
				type = Object.prototype.toString.call(obj[e][i]);
				if (type !== "[object Object]") {
					return undefined;
				}
				return getDeepValue(obj[e][i], prop);
			}

		} else {

			e = prop[0];

			// Check for array elements
			startArrayIndex = e.indexOf('[');
			if (startArrayIndex === -1) {
				return obj[e];
			} else {
				i = parseInt(e.substring(startArrayIndex + 1), 10);
				e = e.substring(0, startArrayIndex);
				type = Object.prototype.toString.call(obj[e]);
				if (type !== "[object Array]") {
					return undefined;
				}
				return obj[e][i];
			}
		}
	}
	// getDeepValue()

	// Get or set a value from an object using a string
	// Return the object that was set
	function value(name, setValue) {
		if (setValue !== undefined) {
			return setDeepValue(this, name, setValue);
		} else {
			return getDeepValue(this, name);
		}
	}
	// value()

	
	// Connection functions
	//-----------------------------------------------------

	function WebSocketConnection(context, settings) {

		// Private variables
		//-----------------------------------------------------

		// TODO: Get rid of misc...
		var thisConnection, ws, write, read, misc;

		thisConnection = this;
		thisConnection.reconnectCount = 0;


		// Writing variables
		//---------------------------------

		// write is the main structure for writing variables to the PLC
		// TODO: Since these are block local variables, what happens if you make more than one 
		// connection? I think this works fine
		// Does each new WEBHMI.Machine() get a new read/write?
		write = {};

		// write.context is an object that is built up to be written
		// write.context mirrors PLC variables
		// When you call API.writeVariable(), it adds the variable to write.context
		write.context = {};

		// write.variableList is a list of the variable names that were added via API.writeVariable()
		// this list of names is important to keep track of the events that need to be thrown
		write.variableList = {};

		// write.writing indicates that this pipe is currently writing to the PLC
		write.writing = false;

		// write.retryCount is the number of failed writes for the current write attempt
		// the connection will try to write settings.maxRetryCount times before failing and trying the next write
		write.retryCount = 0;

		// timer for resending on error
		write.timeout = 0;


		// Reading variables
		//-----------------------------------------

		// read is the main structure for reading variables from the PLC
		read = {};

		// read.context is a variable that mirrors the variables on the PLC
		read.context = context || {};

		// Variable lists are arrays of objects whose properties are the names of the variables
		// to be read.
		// Each object in the array should be small enough to result in tolerable read requests.
		
		// read.singleList is the list of variables to be read from the PLC one time.
		// It is discarded after the read is complete.
		read.singleList = [];
		read.singleList[0] = {};

		// read.cyclicList is the list of variables to be read from the PLC cyclically.
		// It is persistent per page load.
		read.cyclicList = [];
		read.cyclicList[0] = {};

		// read.completeList is a list of all of the variables that have ever been read
		// from the PLC.
		// It supports requesting a full update of all previously read variables. 
		// It is persistent per page load.
		// TODO: BUT WHY???
		read.completeList = [];
		read.completeList[0] = {};

		read.reading = false;
		read.retryCount = 0;
		read.timeout = 0;


		// Statistics
		//--------------------------------------------------

		misc = {};

		misc.statistics = {};
		misc.statistics.read = {};
		misc.statistics.read.startCount = 0;
		misc.statistics.read.completeCount = 0;
		misc.statistics.read.successCount = 0;
		misc.statistics.read.errorCount = 0;
		misc.statistics.read.totalNetTime = 0;

		misc.statistics.write = {};
		misc.statistics.write.startCount = 0;
		misc.statistics.write.completeCount = 0;
		misc.statistics.write.successCount = 0;
		misc.statistics.write.errorCount = 0;
		misc.statistics.write.totalNetTime = 0;

		misc.statistics.frameRate = 0;
		misc.statistics.frameRateFiltered = 0;

		misc.statistics.isConnected = false;
		misc.statistics.openCount = 0;
		misc.statistics.closeCount = 0;

		function updateFrameRate() {
			misc.statistics.frameNetTime = misc.statistics.startTime - misc.statistics.frameStartTime;
			misc.statistics.frameStartTime = misc.statistics.startTime;
			if (misc.statistics.frameNetTime > 0) {
				misc.statistics.frameRate = 1000 / misc.statistics.frameNetTime;
			}
			if (misc.statistics.frameRateFiltered == 0) {
				misc.statistics.frameRateFiltered = misc.statistics.frameRate;
			} else {
				misc.statistics.frameRateFiltered = (99 * misc.statistics.frameRateFiltered + misc.statistics.frameRate) / 100;
			}
		}
		// updateFrameRate()

		misc.readBefore = function () {
			misc.statistics.startTime = performance.now();
			updateFrameRate();
			misc.statistics.read.startCount += 1;
		};

		misc.readComplete = function () {
			misc.statistics.finishTime = performance.now();
			misc.statistics.netTime = misc.statistics.finishTime - misc.statistics.startTime;
			misc.statistics.read.totalNetTime += misc.statistics.netTime;
			misc.statistics.read.completeCount++;
			misc.statistics.read.averageNetTime = misc.statistics.read.totalNetTime / misc.statistics.read.completeCount;
			misc.statistics.read.frameRate = 1000 / misc.statistics.read.averageNetTime;
		};

		misc.readSuccess = function () {
			misc.statistics.read.successCount++;
		};

		misc.readError = function () {
			misc.statistics.read.errorCount++;
		};

		misc.writeBefore = function () {
			misc.statistics.startTime = performance.now();
			updateFrameRate();
			misc.statistics.write.startCount++;
		};

		misc.writeComplete = function () {
			misc.statistics.finishTime = performance.now();
			misc.statistics.netTime = misc.statistics.finishTime - misc.statistics.startTime;
			misc.statistics.write.totalNetTime += misc.statistics.netTime;
			misc.statistics.write.completeCount++;
			misc.statistics.write.averageNetTime = misc.statistics.write.totalNetTime / misc.statistics.write.completeCount;
			misc.statistics.write.frameRate = 1000 / misc.statistics.write.averageNetTime;
		};

		misc.writeSuccess = function () {
			misc.statistics.write.successCount++;
		};

		misc.writeError = function () {
			misc.statistics.write.errorCount++;
		};

		// Private functions
		//------------------------------------------------------------------

		// Write a variable list to the PLC
		function writeVariableList(context, variableListObject) {

			var variableListArray = Object.getOwnPropertyNames(variableListObject);

			ws.onerror = function (event) {
				// maybe the event can be used to resend the data outside of the writeVariableList function???
				misc.writeError();
				clearTimeout(write.timeout);

				// Retry if appropriate, otherwise generate error events
				if (write.retryCount < settings.maxRetryCount) {
					write.retryCount += 1;
					writeVariableList(context, variableListObject);
				} else {
					$(document).trigger('writeerror', [context]);
					$(document).trigger('writecomplete', [context]);
					// TODO: Should we get rid of these events, and the variableListArray? and the variableListObject?
					variableListArray.forEach(function (entry) {
						$(document).trigger(entry + "-writeerror", new Array(entry));
						$(document).trigger(entry + "-writecomplete", new Array(entry));
					});
					write.writing = false;
					processQueue();
				}

			};
			// ws.onerror()

			misc.writeBefore();

			ws.send(JSON.stringify({
				type: 'write',
				data: context
			}));

			write.timeout = setTimeout(ws.onerror, settings.timeout_ms);

		}
		// writeVariableList()

		function readVariableList(variableListObject) {

			// Get the list of variables as a string array
			var variableListArray = Object.getOwnPropertyNames(variableListObject);

			ws.onerror = function (event) {

				misc.readError();
				clearTimeout(read.timeout);

				if (read.retryCount < settings.maxRetryCount) {
					read.retryCount += 1;
					readVariableList(variableListObject);
				} else {
					$(document).trigger('readerror', [variableListArray]);
					$(document).trigger('readcomplete', [variableListArray]);

					// TODO: These events are used for variable read callbacks currently.
					// We would like to move to a different approach and to stop throwing
					// variable-specific events.
					variableListArray.forEach(function (entry) {
						$(document).trigger(entry + "-readerror", [entry]);
						$(document).trigger(entry + "-readcomplete", new Array(entry));
					});
					read.reading = false;
					processQueue();
				}
			};

			misc.readBefore();

			ws.send(JSON.stringify({
				type: 'read',
				data: variableListArray
			}));

			read.timeout = setTimeout(ws.onerror, settings.timeout_ms);

		}
		// readVariableList()

		// Process read and write queues
		// checks if we are reading or writing and connected
		// if not reading or writing:
		// do any writes first
		// then do any one shot reads
		// then do cyclic read
		// TODO: Add ability to handle multiple read list objects
		function processQueue() {
			if (!read.reading && !write.writing && ws.readyState === ws.OPEN) {
				if (!WEBHMI.isEmptyObject(write.context)) {
					write.writing = true;
					write.retryCount = 0;
					writeVariableList(write.context, write.variableList);
					write.context = {};
					write.variableList = {};
				} else if (!WEBHMI.isEmptyObject(read.singleList[0])) {
					read.reading = true;
					read.retryCount = 0;
					readVariableList(read.singleList[0]);
					read.singleList[0] = {};
				} else if (!WEBHMI.isEmptyObject(read.cyclicList[0])) {
					read.reading = true;
					read.retryCount = 0;
					readVariableList(read.cyclicList[0]);
				}
			}
		}
		// processQueue()

		function processReadResponse(responseData) {

			// Call auxiliary functions
			misc.readSuccess();
			misc.readComplete();

			// Put all of the response variables into the read context
			responseData.forEach(function (entry) {
				// Check for objects or arrays to extend objects at their highest level, instead of the highest level read ('gAxis' vs 'gAxis.OUT.STAT')
				// REVIEW THIS
				var name, parsed;

				// TODO: If you send down an empty var name, then you will get an empty object back
				// This does not handle that scenario, because name[0] is undefined.
				name = Object.getOwnPropertyNames(entry);
				if (name.length === 0) return
				if (name[0].indexOf('.') >= 0 || name[0].indexOf('[') >= 0) {
					parsed = {};
					WEBHMI.each(entry, function (prop, value) {
						setDeepValue(parsed, prop, value);
						entry = parsed;
					});
				}
				// Extend the read context with the variable read back
				WEBHMI.extend(true, read.context, entry);
			});

			// Trigger events
			// Want to do something different here
			var variableList = [];
			if (responseData.forEach !== undefined) {
				responseData.forEach(function (property) {
					variableList.push(Object.getOwnPropertyNames(property)[0]);
				});
			} else {
				variableList.push(Object.getOwnPropertyNames(responseData)[0]);
			}

			$(document).trigger('readsuccess', [variableList]);
			$(document).trigger('readcomplete', [variableList]);

			// Trigger variable specific events
			// Maybe replace these variable level read events with variable change events
			variableList.forEach(function (entry) {
				$(document).trigger(entry + "-readsuccess", [entry]);
				$(document).trigger(entry + "-readcomplete", new Array(entry));
			});

			// Done reading
			read.reading = false;
			clearTimeout(read.timeout);

		}
		// processReadResponse()

		function processWriteResponse(responseData) {

			// Call auxiliary functions
			misc.writeSuccess();
			misc.writeComplete();

			// Trigger events
			// want to do something different here
			var variableList = [];
			if (responseData.forEach !== undefined) {
				responseData.forEach(function (property) {
					variableList.push(Object.getOwnPropertyNames(property)[0]);
				});
			} else {
				variableList.push(Object.getOwnPropertyNames(responseData)[0]);
			}

			$(document).trigger('writesuccess', [variableList]);
			$(document).trigger('writecomplete', [variableList]);

			// Trigger variable specific events
			variableList.forEach(function (entry) {
				$(document).trigger(entry + "-writesuccess", new Array(entry));
				$(document).trigger(entry + "-writecomplete", new Array(entry));
			});
			
			// Done writing
			write.writing = false;
			clearTimeout(write.timeout);

		}
		// processWriteResponse()

		function openWebSocket() {

			ws = new WebSocket("ws://" + settings.ipAddress + ':' + settings.port);

			ws.onopen = function () {
				clearTimeout(read.timeout);
				clearTimeout(write.timeout);
				misc.statistics.openCount++;
				misc.statistics.isConnected = true;
				thisConnection.reconnectCount = 0;
				processQueue();

				$(document).trigger('connect');
			};

			ws.onmessage = function (e) {

				// DEMO ONLY!
				if (typeof hmiContext !== 'undefined') {
					hmiContext.response = e.data;
				}
				// END DEMO ONLY

				var msg;
				try{
					msg = JSON.parse(e.data);
				}
				catch(error){
					console.warn('Error parsing JSON response')
					msg = JSON.parse(escapeSpecialChars(e.data));
				}

				switch (msg.type) {
				case 'readresponse':
					processReadResponse(msg.data);
					break;
				case 'writeresponse':
					processWriteResponse(msg.data);
					break;
				}
				// switch(msg.type)

				// TODO: Experiment with timeout here
				// This can get rid of the missed requests, but it also wrecks the refresh rate
				// And it doesn't really get rid of missed requests :(
				//setTimeout(processQueue, 50);
				
				processQueue();

			};
			// ws.onmessage()

			// ws.onerror = function(event) {

			// 	if (write.writing){

			// 		//call function to do unimportant things
			// 		//misc.writeError();

			// 		clearTimeout(write.timeout);

			// 		// Retry if appropriate, otherwise generate error events
			// 		if (write.retryCount < settings.maxRetryCount) {
			// 			write.retryCount++;
			// 			writeVariableList(write.context, write.variableList); // This doesn't work because the write.context is not necessarily the same as it was when you sent the original message
			// 		} else {
			// 			$(document).trigger('writeerror', [list]);
			// 			$(document).trigger('writecomplete', [list]);
			// 			Object.getOwnPropertyNames(write.variableList).forEach(function (entry) {
			// 				$(document).trigger(entry + "-writeerror", new Array(entry));
			// 				$(document).trigger(entry + "-writecomplete", new Array(entry));
			// 			});
			// 			write.writing = false;
			// 			processQueue();
			// 		}

			// 	} else if(read.reading) {

			// 	}
			// };
			// ws.onerror()

			ws.onclose = function () {

				// Reset connection
				read.reading = false;
				write.writing = false;
				clearTimeout(read.timeout);
				clearTimeout(write.timeout);
				misc.statistics.closeCount++;
				misc.statistics.isConnected = false;

				setTimeout(thisConnection.onDisconnect, 50);

			};
			// ws.onclose()

		}
		// openWebSocket()

		function escapeSpecialChars(jsonString) {
			return jsonString.replace(/\n/g, "\\n")
				.replace(/\r/g, "\\r")
				.replace(/\t/g, "\\t")
				.replace(/\f/g, "\\f");
		}

		// Clean variable names before adding them to any lists
		function cleanVariableName(uncleanVariableName) {

			if (typeof uncleanVariableName === 'undefined') {
				return uncleanVariableName;
			}

			// Limit task names to 10 characters
			let splitString = uncleanVariableName.split(':');

			if (splitString.length === 2) {
				// Found a single ':'
				// Limit the task name to 10 characters
				return splitString[0].substring(0, 10) + ':' + splitString[1];
			}
			else {
				// Found no ':' or more than one ':'
				// Don't process the input
				return uncleanVariableName;
			}
		}

		// Check to see if a variable's parent is already contained in a list
		function parentIsInList(variableName, list) {

			// If the parent is in the list, then the variable should be skipped
			let inList = false;

			// Check for list array
			// TODO: Now that all lists are arrays, this could be cleaned up some
			if (Array.isArray(list)) {
				// Check all array entries
				list.forEach(function (listObject) {
					// If the parent is in any listObject, then skip it
					inList = inList || parentIsInList(variableName, listObject);
				});
			}
			else {
				// The list is not an array. It is an object with variable names for properties
				// (like cyclicList[0])
				for (var propName in list) {
					if (list.hasOwnProperty(propName)) {
						if (variableName.indexOf(propName) === 0) {
							if ((variableName.charAt(propName.length) === '.') || (variableName.charAt(propName.length) === '[')) {
								// variableName starts with property name and has a '.' or '[' right
								// after the property name, like myStruct and myStruct.element, or
								// myArray and myArray[5]
								inList = true;
							}
						}
					}
				}
			}

			return inList;
		}

		// Add a variable to a list in the appropriate list object
		function addToList(variableName, list) {

			// Trivial implementation works just fine for now
			list[0][variableName] = {};
			return;

			// TODO: Keep this around for later?
			// // If the variableName itself is too big to fit in a list, bonk
			// if (variableName.length >= 1350) {
			// 	// TODO: Throw error here
			// 	return;
			// }

			// // Add to last list object, check size, if necessary, add new list object
			// let lastListObject = list[list.length - 1];
			// lastListObject[variableName] = {};

			// // Check size of list
			// let lastListStringArray = Object.getOwnPropertyNames(lastListObject);
			// let dataString = JSON.stringify(lastListStringArray);

			// // If resulting list object is too big, make a new one and add the variable to it
			// if (dataString.length > 1400) {
			// 	delete lastListObject[variableName];
			// 	list[list.length] = {};
			// 	list[list.length - 1][variableName] = {};
			// }

		}

		// Delete a variable's obsolete children from a list
		function deleteChildrenFromList(variableName, list) {

			// If you add a parent, then the children should be deleted from the list
			// for efficiency
			if (Array.isArray(list)) {
				// Check all array entries
				list.forEach(function (listObject) {
					deleteChildrenFromList(variableName, listObject);
				});
			}
			else {
				for (var propName in list) {
					if (list.hasOwnProperty(propName)) {
						if (propName.indexOf(variableName) === 0 && propName !== variableName) {
							// propName starts with variable, but is not actually the variable
							if ((propName.charAt(variableName.length) === '.') || (propName.charAt(variableName.length) ==='[')) {
								// And the propName has a '.' or '[' next, like myStruct.element 
								// and myStruct, or myArray[5] and myArray
								delete(list[propName]);
							}
						}
					}
				}
			}
		}

		// Public functions
		//----------------------------------------------------------------

		// Add variable to write queue
		thisConnection.addVariableWrite = function (variableName, setValue, callback) {

			// Add variable name to the list of variables explicitly written by the user
			// This is used to generate write events
			write.variableList[variableName] = {};

			// If there is no input setValue, then use the current value from the read context
			if (typeof setValue === 'undefined') {
				setValue = getDeepValue(read.context, variableName);
			}

			// Add the object to the write context, being careful to clone objects and not point to already existing objects
			var tempObj = {};
			setDeepValue(tempObj, variableName, setValue);
			WEBHMI.extend(true, write.context, tempObj);

			// Add a callback event if given
			if (callback) {
				$(document).one(variableName + '-writecomplete', callback);
			}

			// Process the read/write queues
			processQueue();

		};
		// this.addVariableWrite()

		// Add variable to read once
		thisConnection.addVariableRead = function (variableName, callback) {

			// If there is a variable name, add that name to the list of variables to read
			if (variableName) {

				// This function handles arrays differently than addVariableReadCyclic().
				// I did not want to call processQueue() multiple times for a single array
				// of variables.
				if (Array.isArray(variableName)) {
					variableName.forEach(function (e) {

						// Clean variable name
						// TODO: This can cause bad behavior if a variable with a long
						// task name is bound via data binding
						//e = cleanVariableName(e);

						// Add the name to the single and complete lists
						read.singleList[0][e] = {};
						read.completeList[0][e] = {};
						
						// Add the callback
						if (callback) {
							$(document).one(e + '-readcomplete', callback);
						}

					});
				}
				else {

					// Clean variable name
					// TODO: This can cause bad behavior if a variable with a long
					// task name is bound via data binding
					//variableName = cleanVariableName(variableName);
					
					// Add the name to the single and complete lists
					read.singleList[0][variableName] = {};
					read.completeList[0][variableName] = {};
					
					// Add the callback
					if (callback) {
						$(document).one(variableName + '-readcomplete', callback);
					}
				}

			} 
			else {

				// If the variableName is '' or undefined, then read the complete variable list.
				// Do this by adding every element to the singleList in the same method as 
				// individual variables.
				// Do not just replace the singleList because there could be new variables there.
				Object.getOwnPropertyNames(read.completeList[0]).forEach(function (e) {
					read.singleList[0][e] = {};
				});

				// Add the callback
				// TODO: This might have weird timing issues
				if (callback) {
					$(document).one('readcomplete', callback);
				}
			
			}
			
			processQueue();

		};
		// this.addVariableRead();

		// Add variable to read cyclically
		thisConnection.addVariableReadCyclic = function (variableName, callback) {

			// Check for empty or undefined variableName
			if (typeof variableName === 'undefined' || variableName === '') {
				return;
			}

			// If the variable name is an array, add all variables
			if (Array.isArray(variableName)) {
				variableName.forEach(function (e) {
					// Recurse
					thisConnection.addVariableReadCyclic(e, callback);
				});
			}
			else {

				// Clean variable name
				// TODO: This can cause bad behavior if a variable with a long
				// task name is bound via data binding
				//variableName = cleanVariableName(variableName);

				// If the variable's parent is in the list, don't do anything
				if (!parentIsInList(variableName, read.cyclicList)) {
					
					// Add variable to cyclic and complete lists
					addToList(variableName, read.cyclicList);
					read.completeList[0][variableName] = {};

					// Delete any children already contained in the list
					// TODO: This might break cyclic call backs?
					deleteChildrenFromList(variableName, read.cyclicList);
					
					// Add the callback
					// TODO: Callback is not added if the parent is in the list
					if (callback) {
						$(document).on(variableName + '-readcomplete', callback);
					}
				}
			}

			// TODO: This gets called a lot if you add an array of variables
			// It does sometimes lead to an initial read of the first array element,
			// followed by reads of the entire array.
			// I doubt it will cause problems
			processQueue();

			// TODO: Would be nice to combine a lot of this functionality with addVariableRead.
			// something like addVariableToList(listToAddTo, varName, callback)

		};
		// addVariableReadCyclic()

		thisConnection.reconnect = openWebSocket;

		thisConnection.onDisconnect = function () {
			if (thisConnection.reconnectCount <= settings.maxReconnectCount) {
				// Try to reconnect
				thisConnection.reconnectCount++;
				thisConnection.reconnect();
			} else {

				$(document).trigger('disconnect');

				// Prompt user for reconnection
				var shouldReconnect = confirm('Machine connection lost! Please check machine controller and physical connections.\nPress OK to attempt to reconnect.\nPress Cancel to end machine communication (a page reload will be required to reestablish communication)');
				if (shouldReconnect) {
					thisConnection.reconnect();
				}
				
			}
		};
		// onDisconnect()

		thisConnection.statistics = misc.statistics;

		// Open the WebSocket connection
		//----------------------------------------------------------------

		openWebSocket();

	}
	// WebSocketConnection()


	// Variable functions
	//---------------------------------------------

	// Read a variable from the PLC once
	function readVariable(varName, successCallback) {
		thisMachine.connection.addVariableRead(varName, successCallback);
	}

	// Add a variable to be read cyclically
	function initCyclicRead(varName, successCallback) {
		thisMachine.connection.addVariableReadCyclic(varName, successCallback);
	}

	// Write a variable to the PLC once
	function writeVariable(varName, value, successCallback) {
		thisMachine.connection.addVariableWrite(varName, value, successCallback);
	}

	
	// Machine API definition
	//---------------------------------------------

	thisMachine.value = value;
	thisMachine.readVariable = readVariable;
	thisMachine.initCyclicRead = initCyclicRead;
	thisMachine.writeVariable = writeVariable;


	// Establish a new connection
	//---------------------------------------------

	if (settings.protocol.toLowerCase() === 'http') {
		// DEPRECATED. WILL NOT FUNCTION.
		thisMachine.connection = new HttpConnection(thisMachine, settings);
	} else {
		thisMachine.connection = new WebSocketConnection(thisMachine, settings);
	}

};
// Machine()


// Auxiliary functions
//---------------------------------------------

// JSON stringify a property within a structure or array
// TODO: Why are you out here?
WEBHMI.jsonStringifyDeepProperty = function (obj, prop) {

	var e, startArrayIndex, type, i;

	// First time through, split prop
	if (typeof prop === "string")
		prop = prop.split(".");

	if (prop.length > 1) {

		// If not at bottom of prop, keep going
		e = prop.shift();

		// Check for array elements
		startArrayIndex = e.indexOf('[');
		if (startArrayIndex === -1) {
			type = Object.prototype.toString.call(obj[e]);
			if (type !== "[object Object]")
				return 'undefined';
			return WEBHMI.jsonStringifyDeepProperty(obj[e], prop);
		} else {
			i = parseInt(e.substring(startArrayIndex + 1), 10);
			e = e.substring(0, startArrayIndex);
			type = Object.prototype.toString.call(obj[e]);
			if (type !== "[object Array]")
				return 'undefined';
			type = Object.prototype.toString.call(obj[e][i]);
			if (type !== "[object Object]")
				return 'undefined';
			return WEBHMI.jsonStringifyDeepProperty(obj[e][i], prop);
		}

	} else {

		e = prop[0];

		startArrayIndex = e.indexOf('[');
		if (startArrayIndex === -1) {
			return JSON.stringify(obj[e]);
		} else {
			i = parseInt(e.substring(startArrayIndex + 1), 10);
			e = e.substring(0, startArrayIndex);
			type = Object.prototype.toString.call(obj[e]);
			if (type !== "[object Array]")
				return 'undefined';
			return JSON.stringify(obj[e][i]);
		}

	}

};
// jsonStringifyDeepProperty()
