/*
 * File: lux.js
 * Copyright (c) 2023 Loupe
 * https://loupe.team
 * 
 * This file is part of Loupe UX, licensed under the MIT License.
 * 
 */
// Use uppercase namespace
var LUX = {
	version: '2.0.1'
};

// export default LUX

// UMD (Universal Module Definition)
if (typeof define === 'function' && define.amd) {
	// AMD
	define('lux', LUX);
} else if (typeof module === 'object' && typeof module.exports === 'object') {
	// Node.js
	module.exports = LUX;
}

var jQueryImport;

// jQuery polyfills - Later
if (typeof jQuery === 'undefined') {

	try {
		
		// appease jenkins if possible
		// jest runs tests in a node environment without the wrapping app that "includes" jQuery
		jQueryImport = require('jquery');

	} catch {
		throw new Error('Polyfill not done! Get jQuery!');
	}

} else {
	jQueryImport = jQuery;
}

LUX.extend = jQueryImport.extend;
LUX.isEmptyObject = jQueryImport.isEmptyObject;
LUX.each = jQueryImport.each;
LUX.machines = [];
/**
 * The complete machine-options.
 * @typedef {Object} Machine_Options
 * @property {'ws'} protocol 'ws' - Protocol to be used
 * @property {?string} ipAddress location.hostname - Server Address
 * @property {?number} port 8000 - Server Port
 * @property {?number} timeout_ms 250 - Connection timeout in ms
 * @property {?number} maxRetryCount 5 - Max retry count before throwing disconnect
 * @property {?number} maxReconnectCount 5 - Max reconnect 
 * @property {?number} maxMessageFrequency 60 - Max message frequency in hz 
 */

// Machine constructor
//-----------------------------------------------------

/**
 * 
 * @param {Machine_Options} options 
 */
LUX.Machine = function (options) {
	'use strict';

	var thisMachine;

	//Add this machine to the global list of machines
	LUX.machines.push(this) 

	// Grab machine scope for lower functions
	thisMachine = this;

	/** @type {Machine_Options} */
	var settings;
	let hostname = typeof location !== "undefined" ? location.hostname : "localhost";
	// Set defaults and extend with options, without modifying defaults
	/** @type {Machine_Options} */
	var defaults = {
		protocol: 'ws',
		ipAddress: hostname,
		port: 8000,
		timeout_ms: 250,
		maxRetryCount: 5,
		maxReconnectCount: 5,
		maxMessageFrequency: 60
	};
	settings = LUX.extend({}, defaults, options);

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

	/**
	 * @param {any} context LUX.Machine
	 * @param {Machine_Options} settings 
	 */
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
		// Does each new LUX.Machine() get a new read/write?
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

		// write.lastRequestTime is the time of the last write request
		write.lastRequestTime = 0
		
		//Keep track of consecutive writes
		write.consecutiveWrites = 0;

		//Keep track of callbacks
		write.callbacks = [];
		write.activeCallbacks = [];

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
		read.consecutiveSingleReads = 0;


		//Active read list
		read.activeCyclicList = {};

		// read.cyclicList is the list of variables to be read from the PLC cyclically.
		// It is persistent per page load.
		read.cyclicList = [];
		read.cyclicListReadGroup = {};

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
		read.waiting = false
		// read.lastRequestTime is the time of the last read request
		read.lastRequestTime = 0;

		read.callbacks = [];
		read.activeCallbacks = [];

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

			//Snapshot the time of the write
			write.lastRequestTime = Date.now();


		}
		// writeVariableList()
		function getVariableListArray(variableList){
			if( Array.isArray( variableList) ){
				return variableList;
			}
			else{
				return Object.getOwnPropertyNames(variableList);
			}
		}
		function readVariableList(variableList) {

			// Get the list of variables as a string array
			var variableListArray = getVariableListArray(variableList);

			ws.onerror = function (event) {

				misc.readError();
				clearTimeout(read.timeout);

				if (read.retryCount < settings.maxRetryCount) {
					read.retryCount += 1;
					readVariableList(variableList);
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

			//Snapshot the time of the read
			read.lastRequestTime = Date.now();
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
				let list;
				if (!LUX.isEmptyObject(write.context) && write.consecutiveWrites < 1 ) {					
					write.consecutiveWrites++;
					write.writing = true;
					write.retryCount = 0;
					write.activeCallbacks = write.callbacks;
					write.callbacks = [];
					writeVariableList(write.context, write.variableList);
					write.context = {};
					write.variableList = {};
				} else if (!read.waiting && !LUX.isEmptyObject(read.singleList[0]) && read.consecutiveSingleReads < 1 ) {
					read.consecutiveSingleReads++;
					read.reading = true;
					read.retryCount = 0;
					read.activeCallbacks = read.callbacks;
					read.callbacks = [];
					readVariableList(read.singleList[0]);
					read.singleList[0] = {};
				} else if ( !read.waiting && (list = getNextReadList() ) ){
					read.consecutiveSingleReads = 0;
					write.consecutiveWrites = 0;
					read.reading = true;
					read.retryCount = 0;
					read.activeCallbacks = read.callbacks;
					read.callbacks = [];
					readVariableList(list);
				}
				//If there was a write or single read, then we need to process the queue again
				else if( !LUX.isEmptyObject(write.context) && write.consecutiveWrites > 0 ){
					write.consecutiveWrites = 0;
					processQueue();
				}
				else if( !LUX.isEmptyObject(read.singleList[0]) && read.consecutiveSingleReads > 0 && !read.waiting ){
					read.consecutiveSingleReads = 0;
					processQueue();
				}
				else{
					var timeSinceLastMessage = Date.now() - read.lastRequestTime;
					var timeToWait = (1/settings.maxMessageFrequency)*1000 - timeSinceLastMessage;
					if (timeToWait < 0) timeToWait = 0;
					read.waiting = true
					setTimeout(()=>{
						read.waiting =false;
						processQueue()
					}, timeToWait);
				}
			}
		}
		// processQueue()

		function getNextReadList(){
			let list = {}
			let now = Date.now()
			//Add the global list
			for (const key in read.cyclicListReadGroup) {
				if (Object.hasOwnProperty.call(read.cyclicListReadGroup, key)) {
					const element = read.cyclicListReadGroup[key];
					if( element.enable ){
						if( now - element.lastReadTime > element.minReadTime ){
							element.lastReadTime = now
							LUX.extend( list, element.data ) 
						}
					}			
				}
			}
			//If the list has no members, then return undefined
			if( Object.getOwnPropertyNames(list).length === 0 ){
				return undefined
			}
			else{
				//Look through the list and see if there are items who's parents are alread here
				//If so, then remove them from the list
				for (const key in list) {
					if(parentIsInList(key, list)){
						delete list[key]
					}
				}
				return getVariableListArray(list)
			}
		}

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
					LUX.each(entry, function (prop, value) {
						setDeepValue(parsed, prop, value);
						entry = parsed;
					});
				}
				// Extend the read context with the variable read back
				LUX.extend(true, read.context, entry);
			});

			// Trigger events
			// Want to do something different here
			var variableList = [];
			if (responseData.forEach !== undefined) {
				responseData.forEach(function (property) {
					Array.prototype.push.apply(variableList, Object.getOwnPropertyNames(property))
				});
			} else {
				// This is not currently used by reads
				Array.prototype.push.apply(variableList, Object.getOwnPropertyNames(responseData))
			}

			$(document).trigger('readsuccess', [variableList]);
			$(document).trigger('readcomplete', [variableList]);

			// Trigger variable specific events
			// Maybe replace these variable level read events with variable change events
			variableList.forEach(function (entry) {
				$(document).trigger(entry + "-readsuccess", [entry]);
				$(document).trigger(entry + "-readcomplete", new Array(entry));
			});

			//Trigger callbacks for the write
			read.activeCallbacks.forEach((callback)=>{
				try{
					callback()
				}catch(error){
					console.warn('Error in write callback')
					console.warn(error)
				}
			})
			read.activeCallbacks = [];

			// Done reading
			read.reading = false;
			clearTimeout(read.timeout);

		}
		// processReadResponse()

		function processWriteResponse(responseData) {

			// Call auxiliary functions
			misc.writeSuccess();
			misc.writeComplete();
			/*
			//TODO: This is not currently supported because OMJSON
			//	Does not return the corrected type
			//	Need to fix OMJSON before we can update the local 
			//	data with the written data
			//////////////////////////////////////////////////////
			// Put all of the response variables into the context		
			Object.entries(responseData).forEach(function([name,entry]) {
				let parsed;
				if (name.length === 0) return
				if (name[0].indexOf('.') >= 0 || name[0].indexOf('[') >= 0) {
					parsed = {};
					LUX.each(entry, function (prop, value) {
						setDeepValue(parsed, prop, value);
						entry = parsed;
					});
				}
				let obj = {}
				obj[name] = entry
				// Extend the read context with the variable read back
				LUX.extend(true, thisMachine, obj);
			});
			*/
						
			// Trigger events
			// want to do something different here
			var variableList = [];
			if (responseData.forEach !== undefined) {
				// This is not currently used for writes
				responseData.forEach(function (property) {
					Array.prototype.push.apply(variableList, Object.getOwnPropertyNames(property))
				});
			} else {
				Array.prototype.push.apply(variableList, Object.getOwnPropertyNames(responseData))
			}

			$(document).trigger('writesuccess', [variableList]);
			$(document).trigger('writecomplete', [variableList]);

			// Trigger variable specific events
			variableList.forEach(function (entry) {
				$(document).trigger(entry + "-writesuccess", new Array(entry));
				$(document).trigger(entry + "-writecomplete", new Array(entry));
			});

			//Trigger callbacks for the write
			write.activeCallbacks.forEach((callback)=>{
				try{
					callback()
				}catch(error){
					console.warn('Error in write callback')
					console.warn(error)
				}
			})
			
			write.activeCallbacks= [];

			// Done writing
			write.writing = false;
			clearTimeout(write.timeout);

		}
		// processWriteResponse()

		function openWebSocket() {

			ws = new WebSocket(settings.protocol + "://" + settings.ipAddress + ':' + settings.port);

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
								
				//Calculate the time it took to process the last message,
				//then use the max frequency to determine how long to wait
				//before processing the next message
				if( settings.maxMessageFrequency > 0 ){
					var timeSinceLastMessage = Date.now() - read.lastRequestTime;
					var timeToWait = (1/settings.maxMessageFrequency)*1000 - timeSinceLastMessage;
					if (timeToWait < 0) timeToWait = 0;
					read.waiting = true
					setTimeout(()=>{
						read.waiting =false;
						processQueue()
					}, timeToWait);
				}

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
			list[variableName] = {};
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
		//Get the read group object for a given name
		thisConnection.getReadGroup = function(ReadGroupName){
			let cyclicListReadGroup = read.cyclicListReadGroup[ReadGroupName]
			if( typeof cyclicListReadGroup == 'undefined'){
				read.cyclicListReadGroup[ReadGroupName] = {name: ReadGroupName, enable:true, lastReadTime:0, minReadTime:0, enableCallback: null , data: {}}
				cyclicListReadGroup = read.cyclicListReadGroup[ReadGroupName]
			}
			return cyclicListReadGroup
		}

		//Get the names of all the read groups
		thisConnection.getReadGroupList = function(){
			return Object.getOwnPropertyNames(read.cyclicListReadGroup);
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
			LUX.extend(true, write.context, tempObj);

			// Add a callback event if given
			if (callback) {
				write.callbacks.push(callback);
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
						
					});

					// Add the callback
					if (callback) {
						read.callbacks.push(callback);
					}
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
						read.callbacks.push(callback);
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
				if (callback) {
					read.callbacks.push(callback);
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
			let cyclicListReadGroup = thisConnection.getReadGroup('global')
			let cyclicList = cyclicListReadGroup.data;


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
				if (!parentIsInList(variableName, cyclicList)) {
					
					// Add variable to cyclic and complete lists
					addToList(variableName, cyclicList);
					read.completeList[0][variableName] = {};

					// Delete any children already contained in the list
					// TODO: This might break cyclic call backs?
					deleteChildrenFromList(variableName, cyclicList);
					
					// Add the callback
					// TODO: Callback is not added if the parent is in the list
					if (callback) {
						//TODO: how should we handle callbacks for cyclic reads?
						//	Single callbacks have been transitioned to using
						//	a callback array, which is prefer.
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

		//Set the ReadGroup enabled/disabled
		thisConnection.setReadGroupEnable = function( ReadGroupName, enable ){
			let cyclicListReadGroup = thisConnection.getReadGroup(ReadGroupName)
			cyclicListReadGroup.enable = enable
		}

		//Set the ReadGroup max frequency in Hz
		thisConnection.setReadGroupMaxFrequency = function(  ReadGroupName, hz  ){
			if( hz > 0){ 
				thisConnection.getReadGroup(ReadGroupName).minReadTime = (1/hz)*1000;
			}			
		}

		//Set the ReadGroup enable callback that allows the user to enable/disable the read group manually
		thisConnection.setReadGroupEnableCallback = function( ReadGroupName, callback ){
			let cyclicListReadGroup = thisConnection.getReadGroup(ReadGroupName)
			cyclicListReadGroup.enableCallback = callback;
		}		

		//Add a cyclic read for variables on a specific ReadGroupName.
		//This is used to prevent cyclic reads from being sent to the PLC
		//when the ReadGroupName is not active.
		thisConnection.addReadGroupVariableReadCyclic = function ( ReadGroupName, variableName, callback) {

			let cyclicListReadGroup = thisConnection.getReadGroup(ReadGroupName)
			let cyclicList = cyclicListReadGroup.data;
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
				if (!parentIsInList(variableName, cyclicList)) {
					
					// Add variable to cyclic and complete lists
					addToList(variableName, cyclicList);
					read.completeList[0][variableName] = {};

					// Delete any children already contained in the list
					// TODO: This might break cyclic call backs?
					deleteChildrenFromList(variableName, cyclicList);
					
					// Add the callback
					// TODO: Callback is not added if the parent is in the list
					if (callback) {
						//TODO: how should we handle callbacks for cyclic reads?
						//	Single callbacks have been transitioned to using
						//	a callback array, which is prefer.
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

		}
		
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

	// Add a variable to be read cyclically
	function initCyclicReadGroup( ReadGroupName, varName, successCallback) {
		thisMachine.connection.addReadGroupVariableReadCyclic(ReadGroupName, varName, successCallback);
	}

	// Write a variable to the PLC once
	function writeVariable(varName, value, successCallback) {
		thisMachine.connection.addVariableWrite(varName, value, successCallback);
	}

	//Set the ReadGroupName enabled/disabled
	function setReadGroupEnable( ReadGroupName, enable ){
		thisMachine.connection.setReadGroupEnable( ReadGroupName, enable)
	}

	//Get the list of read group names
	function getReadGroupList(){
		return thisMachine.connection.getReadGroupList()
	}

	//Get the read group object for a given name
	function getReadGroup( ReadGroupName ){
		return thisMachine.connection.getReadGroup( ReadGroupName )
	}	

	//Set the ReadGroup max frequency in Hz
	function setReadGroupMaxFrequency( ReadGroupName, hz ){
		thisMachine.connection.setReadGroupMaxFrequency(ReadGroupName, hz)
	}

	//Set the ReadGroup enable callback that allows the user to enable/disable the read group manually
	function setReadGroupEnableCallback( ReadGroupName, callback ){
		thisMachine.connection.setReadGroupEnableCallback(ReadGroupName, callback)
	}

	//Print the data for the read groups in the console
	function printReadGroups(){
		let readGroupsPrinter = []
		thisMachine.connection.getReadGroupList().forEach( (ReadGroupName)=>{
			readGroupsPrinter.push( thisMachine.connection.getReadGroup(ReadGroupName) )
		})
		console.log(readGroupsPrinter)
	}

	//This call will manage all the read groups
	//	- If the read group is not managed by the user, it will be enabled/disabled based on the would show flag
	//	- If the read group is managed by the user, it will be not be enabled/disabled here
	//  - If the read group is managed by the user, but there is an error in the callback, it will be enabled/disabled here
	function readGroupShouldManage( ReadGroupName, wouldShow ){
		let readGroup = thisMachine.connection.getReadGroup( ReadGroupName )
		 // Start by assuming the library will auto-manage the ReadGroup callback
		let shouldManage = true;
		try{
			//Check to see if there is a callback to enable/disable the readGroup
			// If this callback return should manage, check the global callback
			if(readGroup.enableCallback !== null ){
				shouldManage = readGroup.enableCallback( readGroup, wouldShow)
			}
			//If the global callback returns should manage, we should manage it
			if( enableReadGroupsCallback !== null && shouldManage ){
				shouldManage = enableReadGroupsCallback( readGroup, wouldShow)
			}
			readGroup.error	= null		
		}
		//If there is an error in the callback, post it and assume the library should manage
		catch(error){
			if( typeof readGroup.error == 'undefined' ){
				console.warn('Error in readGroup enable/disable callback:\n', error)
			}
			readGroup.error = error;
			shouldManage = true;
		}
		if( shouldManage ){
			readGroup.enable = wouldShow;
			readGroup.autoManage = true;	
		}
		else{
			readGroup.autoManage = false;	
		}
		return true
	}

	let enableReadGroupsCallback = null;
	//Set the callback that allows the user to enable/disable ALL read groups.
	//	- First priority is the callback in the read group
	//  - Second priority is the global callback
	//  - Third priority is the wouldShow flag
	function setReadEnableCallback(callBack){
		enableReadGroupsCallback = callBack;
	}

	// User level
	//---------------------------------------------

	var userLevelPV;
	var currentUserLevel = 0;

	function setUserLevel(level) {
		currentUserLevel = level;
	}

	function setUserLevelPV(levelPV) {
		if (levelPV !== undefined) { // Don't set PV to something that doesn't exist; that's what clearUserLevelPV is for
			userLevelPV = levelPV;
			initCyclicRead(levelPV);
		}
	}

	function clearUserLevelPV() {
		userLevelPV = undefined;
	}

	function getUserLevel() {
		if (userLevelPV === undefined) {
			// Not using PV; use internal value instead
			return currentUserLevel;
		}
		return thisMachine.value(userLevelPV);
	}

	/**
	 * @param {Machine_Options} options 
	 */
	function updateSettings(options) {
		LUX.extend(settings, options); // Overwrite current settings but do not create a new object
	}
	
	// Machine API definition
	//---------------------------------------------

	thisMachine.value = value;
	thisMachine.readVariable = readVariable;
	thisMachine.initCyclicRead = initCyclicRead;

	thisMachine.initCyclicReadGroup = initCyclicReadGroup;
	thisMachine.setReadGroupEnable = setReadGroupEnable;
	thisMachine.getReadGroup = getReadGroup;
	thisMachine.getReadGroupList = getReadGroupList;
	thisMachine.setReadGroupEnableCallback = setReadGroupEnableCallback;
	thisMachine.setReadGroupMaxFrequency = setReadGroupMaxFrequency;
	thisMachine.readGroupShouldManage = readGroupShouldManage;
	thisMachine.printReadGroups = printReadGroups;
	thisMachine.setReadEnableCallback = setReadEnableCallback;

	thisMachine.writeVariable = writeVariable;
	thisMachine.updateSettings = updateSettings

	thisMachine.setUserLevel = setUserLevel;
	thisMachine.setUserLevelPV = setUserLevelPV;
	thisMachine.clearUserLevelPV = clearUserLevelPV;
	thisMachine.getUserLevel = getUserLevel;


	// Establish a new connection
	//---------------------------------------------

	if (settings.protocol.toLowerCase() === 'http') {
		// DEPRECATED. WILL NOT FUNCTION.
		thisMachine.connection = new HttpConnection(thisMachine, settings);
	} else if (settings.protocol.toLowerCase() === 'none') {
		// no connection
	} else {
		thisMachine.connection = new WebSocketConnection(thisMachine, settings);
	}

};
// Machine()


// HMI (Local Machine)
//---------------------------------------------

// Compose HMI data update function from list of all custom callbacks
LUX.localDataCallbacks = [];

// Execute list of custom callbacks
// Used by data-binding cyclic update loop
LUX.updateLocalData = function () {

	this.localDataCallbacks.forEach( function (cb) {
		
		try {

			cb();

		} catch (err) {

			console.error("HMI custom data callback failed - " + err.message);

		}

	});

};

// HMI (Local Machine) constructor
LUX.HMI = function (...dataCallbacks) {

	// add custom callback[s] to list of all local machine callbacks
	LUX.localDataCallbacks.push(...dataCallbacks);

	var machineOptions = {
		protocol: 'none',
		port: 0,
		ipAddress: '',
		maxReconnectCount: 0 
	  };
	// use Machine constructor with this scope then override some functions (fancy)
	LUX.Machine.call(this, machineOptions);

	this.writeVariable = function (variableName, setValue, successCallback) {

		// Add the object to the write context, being careful to clone objects and not point to already existing objects
		var tempObj = {};
		this.value.call(tempObj, variableName, setValue);
		LUX.extend(true, this, tempObj);

		// don't register callback, just call it immediately because there's no comms or anything
		if (successCallback) {
			setTimeout(successCallback, 0);
		}

	}

	this.readVariable = this.initCyclicRead = function (variableName, successCallback) {

		if (variableName) {
			
			// add variable if it doesn't exist yet
			if ( this.value.call(this, variableName) === undefined) {
				this.writeVariable(variableName, '');
			}

		}

		// don't register callback, just call it immediately because there's no comms or anything
		if (successCallback) {
			setTimeout(successCallback, 0);
		}

	}

	this.initCyclicReadGroup = function ( ReadGroupName, variableName, successCallback) {
		this.initCyclicRead(variableName, successCallback);
	}

	this.getReadGroupList = function(){
		return [];
	}
	
 };
// HMI()


// Auxiliary functions
//---------------------------------------------

// JSON stringify a property within a structure or array
// TODO: Why are you out here?
LUX.jsonStringifyDeepProperty = function (obj, prop) {

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
			return LUX.jsonStringifyDeepProperty(obj[e], prop);
		} else {
			i = parseInt(e.substring(startArrayIndex + 1), 10);
			e = e.substring(0, startArrayIndex);
			type = Object.prototype.toString.call(obj[e]);
			if (type !== "[object Array]")
				return 'undefined';
			type = Object.prototype.toString.call(obj[e][i]);
			if (type !== "[object Object]")
				return 'undefined';
			return LUX.jsonStringifyDeepProperty(obj[e][i], prop);
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
