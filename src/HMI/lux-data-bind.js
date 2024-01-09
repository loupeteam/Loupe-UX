/*
 * File: lux-data-bind.js
 * Copyright (c) 2023 Loupe
 * https://loupe.team
 * 
 * This file is part of Loupe UX, licensed under the MIT License.
 * 
 */

// Check for lux global object
if (typeof LUX === 'undefined') {
	throw new Error('LUX data binding requires LUX core');
}

LUX.dataBindVersion = '2.0.2';

// Check for being a 'number'
function isNumeric(obj) {
	return !Number.isNaN(parseFloat(obj)) && isFinite(obj)
}

LUX.isNumeric = isNumeric

// Make sure the convert library is included
let convertFeatEnable = false;
if ((typeof convert === 'undefined') || (typeof convert.convert !== 'function')) {
	console.warn('Convert library not defined in index.html and will be disabled')
	console.warn('Inclusion Example: <script src="lux/convert.prod.js"></script>')
} else {
	LUX.convert = convert.convert
	convertFeatEnable = true;
}

// BOOLify something
function isTrue(value) {

	switch (typeof value) {

		case 'boolean':
			return value

		case 'number':
			return value !== 0

		case 'string':
			// If you are a number string, like '2', treat yourself like a number
			if (isNumeric(value)) {
				return value !== '0'
			} else {
				switch (value.toLowerCase()) {
					case 'true':
					case 'on':
					case 'yes':
						return true
					default:
						return false
				}
			}

		default:
			return false
	}

}

LUX.isTrue = isTrue

// Check for custom equality
// Types supported: Undefined, Boolean, Number, String
function isEqual(in1, in2) {

	// If you don't have either input, default to false
	if (in1 === undefined || in2 === undefined) {
		return false
	}

	// Check for type independent equality
	if (in1 == in2) {
		return true
	}

	// If both inputs are numbers, return false
	// If they are both the same number, in1 == in2, and 
	// true will be returned above
	if (isNumeric(in1) && isNumeric(in2)) {
		return in1 == in2 // Guaranteed to be false at this point
	}

	if (typeof in1 == 'string' && typeof in2 == 'string') {
		return in1 == in2 // Guaranteed to be false at this point
	}

	// If you get to this point, check for isTrue()
	// This allows comparing 'boolean like' strings and numbers
	return isTrue(in1) === isTrue(in2)

}

// Set a value deep within an arbitrary object
LUX.setDeepObjectValue = function (obj, prop, value) {
	//Note: This function was pulled out of Lux 
	//	so that it can be used in other places
	//	It is modified from the original to
	//	check if an object is more generic than just
	//	Object.prototype.toString.call(obj) === '[object Object]'
	//	It's possible that this could be pulled back into lux
	//	But that feels more risky than just leaving it here
	//	Since this is a new use case..
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
			if (typeof obj[e] === "undefined") {
				obj[e] = {};
			}
			return LUX.setDeepObjectValue(obj[e], prop, value);
		} else {
			i = parseInt(e.substring(startArrayIndex + 1), 10);
			e = e.substring(0, startArrayIndex);
			// If array does not exist, create it
			if (typeof obj[e] === "undefined") {
				obj[e] = [];
			}
			// If element does not exist, create it
			if ( typeof obj[e] === "undefined") {
				obj[e][i] = {};
			}
			return LUX.setDeepObjectValue(obj[e][i], prop, value);
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
			if (typeof obj[e] === "undefined") {
				obj[e] = [];
			}
			obj[e][i] = value;
			return obj[e][i];
		}
	}
}

// Get attribute values
//----------------------

LUX.getVarName = function ($element) {
	return $element.attr('data-var-name');
};

LUX.getHideVarName = function ($element) {
	var value = $element.attr('data-var-name-hide');
	if (value === undefined) {
		value = LUX.getVarName($element);
		$element.attr('data-var-name-hide', value);
	}
	return value;
};

LUX.getLockVarName = function ($element) {
	var value = $element.attr('data-var-name-lock');
	if (value === undefined) {
		value = LUX.getVarName($element);
		$element.attr('data-var-name-lock', value);
	}
	return value;
};

LUX.getMachineName = function ($element) {
	var value = $element.attr('data-machine-name');
	if (value === undefined) {
		value = 'machine';
		$element.attr('data-machine-name', value);
	}
	return value;
};

LUX.getMachine = function ($element) {
	// Abstract this in case there is not a window. or something else unheard of.
	return window[LUX.getMachineName($element)];
}

LUX.getLedTrue = function ($element) {
	var value = $element.attr('data-led-true');
	if (value === undefined) {
		value = 'led-on';
		$element.attr('data-led-true', value);
	}
	return value;
}

LUX.getLedFalse = function ($element) {
	var value = $element.attr('data-led-false');
	if (value === undefined) {
		value = 'led-off';
		$element.attr('data-led-false', value);
	}
	return value;
};

LUX.getSetValue = function ($element) {
	var value = $element.attr('data-set-value');
	if (value === undefined) {
		value = true;
		$element.attr('data-set-value', value);
	}
	return value;
};

LUX.getHideTrue = function ($element) {
	var value = $element.attr('data-hide-true');
	if (value === undefined) {
		value = 'hidden';
		$element.attr('data-hide-true', value);
	}
	return value;
};

LUX.getLockTrue = function ($element) {
	var value = $element.attr('data-lock-true');
	if (value === undefined) {
		value = 'disabled';
		$element.attr('data-lock-true', value);
	}
	return value;
};

LUX.getResetValue = function ($element) {
	var value = $element.attr('data-reset-value');
	if (value === undefined) {
		value = false;
		$element.attr('data-reset-value', value);
	}
	return value;
};

LUX.getHideSetValue = function ($element) {
	var value = $element.attr('data-hide-set');
	if (value === undefined) {
		value = true;
		$element.attr('data-hide-set', value);
	}
	return value;
};

LUX.getLockSetValue = function ($element) {
	var value = $element.attr('data-lock-set');
	if (value === undefined) {
		value = true;
		$element.attr('data-lock-set', value);
	}
	return value;
};

LUX.getUserLevelShow = function ($element) {
	return $element.attr('min-user-level-show');
};

LUX.getUserLevelUnlock = function ($element) {
	return $element.attr('min-user-level-unlock');
};

LUX.getRange = function ($element) {
	var value = $element.attr('data-range');
	if (value === undefined) {
		value = '[-1, 0, 1, 2]';
		$element.attr('data-range', value);
	}
	return JSON.parse(value);
};

LUX.getValue = function ($element) {

	//var localMachine = window[LUX.getMachineName($element)];
	var localMachine = LUX.getMachine($element); // NOTE: Try this here before migrating everything else...

	var varName = LUX.getVarName($element);
	if (varName === undefined) {
		return "No variable";
	}
	if ($element.attr('data-var-name-added') != varName) {
		$element.attr('data-var-name-added', varName)
		localMachine.initCyclicReadGroup(LUX.getDataReadGroup($element), varName);
	}

	var varValue = localMachine.value(varName);

	return varValue;

}

LUX.getHideValue = function ($element) {

	//var localMachine = window[LUX.getMachineName($element)];
	var localMachine = LUX.getMachine($element); // NOTE: Try this here before migrating everything else...

	var varName = LUX.getHideVarName($element);
	if (varName === undefined) {
		return "No variable";
	}

	if ($element.attr('data-var-name-added-hide') != varName) {
		$element.attr('data-var-name-added-hide', varName)
		localMachine.initCyclicReadGroup(LUX.getDataReadGroup($element), varName);
	}

	var varValue = localMachine.value(varName);
	return varValue;

}

LUX.getLockValue = function ($element) {

	//var localMachine = window[LUX.getMachineName($element)];
	var localMachine = LUX.getMachine($element); // NOTE: Try this here before migrating everything else...

	var varName = LUX.getLockVarName($element);
	if (varName === undefined) {
		return "No variable";
	}
	if ($element.attr('data-var-name-lock-added') != varName) {
		$element.attr('data-var-name-lock-added', varName)
		localMachine.initCyclicReadGroup(LUX.getDataReadGroup($element), varName);
	}

	var varValue = localMachine.value(varName);

	return varValue;

}

LUX.getDataReadGroup = function ($element) {
	var ReadGroupName = $element[0].closest('[data-read-group]');
	if (ReadGroupName != null) {
		return ReadGroupName.getAttribute('data-read-group');
	}
	else {
		return 'global'
	}
}

LUX.getUserLevel = function ($element) {

	//var localMachine = window[LUX.getMachineName($element)];
	var localMachine = LUX.getMachine($element); // NOTE: Try this here before migrating everything else...

	return localMachine.getUserLevel(); // Handles everything we need it to

}
// NOTE: What is the point of this function? I guess it will init things that are not already in the list, but that is a funny name if that is the point.
LUX.getCyclicReads = function () {
	$("[data-var-name]").each(function (index, element) {
		LUX.getValue($(this));
	});
}

LUX.writeValueFromElement = function ($this, value) {
	var localMachine = window[LUX.getMachineName($this)];
	let VariableName = LUX.getVarName($this);
	//BUG Note: This is a temporary work around for a debounce/cache issue
	//	Currently, every time we update an element, we cache the value
	//	so that we don't update the element again if the value is the same.
	//	When we write a variable, we don't update the cache because we don't
	//	know what the value will be after the write. This means that if we
	//	write a variable, if it gets changed on the machine to the original
	//	value, it will not update the element. This is a problem because
	//	if the user typed in a value, it will always show what they typed
	//	even if the machine changed it back. This is not the desired behavior.
	localMachine.writeVariable(VariableName, value, ()=>{
		//BUG Note: Long term we want to do this:
		//	This will work because we will parse the write response
		//	when we get it back and update the cache with the new value.
		//
		//  Currently OMJSON does not support this 
		//	because the response has a bug where
		//  it does not return the value with the corrected
		//	type in all cases. For example, if you write
		//  a boolean as "true", it will return a string "true"
		//	instead of transorming it to a boolean.
		//  This means inputs that expect a boolean will
		//	show NaN instead of true or false.
		//	This means we can't clear the cache here
		//	because we will immediately re-render the element
		//	with the wrong value, and cache the wrong value.
		
		// $this.removeAttr('data-machine-value');
	});
	//As a work around we will do this
	//  This will cause the value to be read again
	//  from the machine and after that we can clear the cache
	//	so it will re-render if it needs to.
	localMachine.readVariable(VariableName, ()=>{
		$this.removeAttr('data-machine-value');
	});
}

// Update ReadGroup elements
//----------------------

// find all LED elems
LUX.queryLEDs = function () {
	LUX.elems.led = Array.prototype.slice.call(document.querySelectorAll('.lux-led'));
}

LUX.updateLEDs = function () {

	// iterate over array of visible lux led elements
	LUX.visibleElems.led.forEach(function (element) {

		const $this = $(element);
		const varValue = LUX.getValue($this);
		if (typeof varValue !== "undefined" && !isEqual($this.attr('data-machine-value-led'), varValue)) {
			$this.attr('data-machine-value-led', varValue)
			const setValue = LUX.getSetValue($this);
			const resetValue = LUX.getResetValue($this);

			// if (typeof varValue === 'boolean') {
			// 	setValue = LUX.isTrue(setValue);
			// 	resetValue = LUX.isTrue(resetValue);
			// }

			if (isEqual(varValue, setValue)) {
				$this.removeClass(LUX.getLedFalse($this)).addClass(LUX.getLedTrue($this));
			} else if (isEqual(varValue, resetValue)) {
				$this.removeClass(LUX.getLedTrue($this)).addClass(LUX.getLedFalse($this));
			} else {
				$this.removeClass(LUX.getLedFalse($this)).removeClass(LUX.getLedTrue($this));
			}
		}
	})
}

// find hide/show elems
LUX.queryHide = function () {
	LUX.elems.hide = Array.prototype.slice.call(document.querySelectorAll('.lux-hide, .lux-show, [min-user-level-show]'));
}

LUX.updateHide = function () {

	LUX.elems.hide.forEach(function (element) {

		const $this = $(element);

		const hasHideUserLevel = ($this.attr('min-user-level-show') !== undefined);
		const hasHide = $this.hasClass('lux-hide');
		const hasShow = $this.hasClass('lux-show');

		const varValue = LUX.getHideValue($this);
		const userLevel = LUX.getUserLevel($this);

		if (((hasHide || hasShow) && !isEqual($this.attr('data-machine-value-hide'), varValue)) || (hasHideUserLevel && !isEqual($this.attr('data-machine-value-user-level-show'), userLevel))) {

			if (hasHide || hasShow) $this.attr('data-machine-value-hide', varValue);
			if (hasHideUserLevel) $this.attr('data-machine-value-user-level-show', userLevel);

			const setValue = LUX.getHideSetValue($this); // elements that only have user level will get data-hide-set here; this is fine
			const userLevelShow = LUX.getUserLevelShow($this);

			if ((hasHide && isEqual(varValue, setValue)) || (hasShow && !isEqual(varValue, setValue)) || (hasHideUserLevel && (userLevel < userLevelShow))) {
				$this.addClass(LUX.getHideTrue($this));
			} else {
				$this.removeClass(LUX.getHideTrue($this));
			}

		}

	})

}

LUX.queryDataMaps = function () {
	LUX.elems.datamap = Array.prototype.slice.call(document.querySelectorAll('[data-map]'));

}

LUX.updateDataMaps = function () {
	
	function updateParameterValue($element, localMachine, key, dataVarName) {
		let keyname = key.replace('.','-')
		if ($element.attr('data-var-name-added-' + keyname) != dataVarName) {
			$element.attr('data-var-name-added-' + keyname, dataVarName)
			localMachine.initCyclicReadGroup(LUX.getDataReadGroup($element), dataVarName);
		}
		let value = localMachine.value(dataVarName);
		if ($element.attr('data-machine-value-' + keyname) != value) {
			$element.attr('data-machine-value-' + keyname, value)
			$element.each((index, val) => {
				LUX.setDeepObjectValue(val, key, value);			
			});
		}
	}
	
	function updateParameter($element, elMachine, key, value) {
		if (typeof value === 'string') {
			updateParameterValue($element, elMachine, key, value);
			return
		}
	
		if (typeof value === 'object' && value['data-var-name']) {
			let {
				['data-var-name']:dataVarName,
				machine
			} = value;		
			let localMachine = window[machine] 
			if(localMachine == undefined){
				localMachine = elMachine;
			} 
			updateParameterValue($element, localMachine, key, dataVarName);
			return
		}
	}
	
	LUX.visibleElems.datamap.forEach((el) => {
		let mapping = el.dataMapObject;
		if (!mapping) {
			mapping = el.getAttribute('data-map');
			mapping = mapping.replace(/'/g, '"');
			mapping = JSON.parse(mapping);
			el.dataMapObject = mapping;
		}
		let $element = $(el);
		var localMachine = LUX.getMachine($element); // NOTE: Try this here before migrating everything else...
		for (let key in mapping) {
			updateParameter($element, localMachine, key, mapping[key]);
		}
	});
}
// find lock/unlock elems
LUX.queryLock = function () {
	LUX.elems.lock = Array.prototype.slice.call(document.querySelectorAll('.lux-lock, .lux-unlock, [min-user-level-unlock]'));
}

LUX.updateLock = function () {

	LUX.elems.lock.forEach(function (element) {

		const $this = $(element);

		const hasLockUserLevel = ($this.attr('min-user-level-unlock') !== undefined);
		const hasLock = $this.hasClass('lux-lock');
		const hasUnlock = $this.hasClass('lux-unlock');

		const varValue = LUX.getLockValue($this);
		const userLevel = LUX.getUserLevel($this);

		if (((hasLock || hasUnlock) && !isEqual($this.attr('data-machine-value-lock'), varValue)) || (hasLockUserLevel && !isEqual($this.attr('data-machine-value-user-level-unlock'), userLevel))) {

			if (hasLock || hasUnlock) $this.attr('data-machine-value-lock', varValue);
			if (hasLockUserLevel) $this.attr('data-machine-value-user-level-unlock', userLevel);

			const setValue = LUX.getLockSetValue($this); // elements that only have user level will get data-lock-set here; this is fine
			const userLevelUnlock = LUX.getUserLevelUnlock($this);

			if ((hasLock && isEqual(varValue, setValue)) || (hasUnlock && !isEqual(varValue, setValue)) || (hasLockUserLevel && (userLevel < userLevelUnlock))) {
				$this.addClass(LUX.getLockTrue($this));
				$this.prop('disabled', true);
			} else {
				$this.removeClass(LUX.getLockTrue($this));
				$this.prop('disabled', false);
			}

		}

	})

}

// find all toggle btn elems
LUX.queryToggleButtons = function () {
	LUX.elems.toggleButton = Array.prototype.slice.call(document.querySelectorAll('.lux-btn-toggle'));
}

LUX.updateToggleButtons = function () {

	LUX.visibleElems.toggleButton.forEach(function (element) {

		var $this = $(element);

		var varValue = LUX.getValue($this);
		if (typeof varValue !== 'undefined' && !isEqual($this.attr('data-machine-value-toggle'), varValue)) {
			$this.attr('data-machine-value-toggle', varValue)
			if (isEqual(varValue, LUX.getSetValue($this))) {
				$this.addClass('toggle-active');
			} else if (isEqual(varValue, LUX.getResetValue($this))) {
				$this.removeClass('toggle-active');
			} else {
				$this.removeClass('toggle-active');
			}
		}
	});

};

// find all checkbox elems
LUX.queryCheckboxes = function () {
	LUX.elems.checkbox = Array.prototype.slice.call(document.querySelectorAll('.lux-checkbox'));
}

LUX.updateCheckboxes = function () {

	// if (lux.numActiveWrites !== 0)
	// return;

	LUX.visibleElems.checkbox.forEach(function (element) {

		var $this = $(element);

		var isChecked = $this.prop('checked');

		var varValue = LUX.getValue($this);
		if (typeof varValue !== 'undefined' && !isEqual($this.attr('data-machine-value-checkbox'), varValue)) {
			$this.attr('data-machine-value-checkbox', varValue)
			if (isEqual(varValue, LUX.getSetValue($this)) && !isChecked) {
				$this.prop('checked', true);
			} else if (isEqual(varValue, LUX.getResetValue($this)) && isChecked) {
				$this.prop('checked', false);
			}
		}
	});

};

// find tab elems
LUX.queryTabs = function () {
	LUX.elems.tab = Array.prototype.slice.call(document.querySelectorAll('.lux-tab-pane'));
}

LUX.updateTabs = function () {

	// if (lux.numActiveWrites !== 0)
	// return;

	LUX.elems.tab.forEach(function (element) {

		var $this = $(element);

		var varValue = LUX.getValue($this);
		if (typeof varValue !== 'undefined' && !isEqual($this.attr('data-machine-value-tab'), varValue)) {
			$this.attr('data-machine-value-tab', varValue)
			if ((varValue == LUX.getSetValue($this))) {
				var tabs = $('.nav-tabs');
				var tab = tabs.find('a[data-target="#' + $this[0].id + '"]');
				if (tab.length == 0)
					tab = tabs.find('a[href="#' + $this[0].id + '"]');
				tab.first().tab('show') // this requires bootstrap
			}
		}
	});

};

// find all component elems
LUX.queryComponents = function () {
	LUX.elems.component = Array.prototype.slice.call(document.querySelectorAll('.lux-value'));
}

LUX.updateComponents = function () {
	LUX.visibleElems.component.forEach(function (element) {

		var $this = $(element);

		var varValue = LUX.getValue($this);
		if (typeof varValue !== 'undefined' && !isEqual($this.attr('data-machine-value'), varValue)) {
			$this.attr('data-machine-value', varValue)
			$this.val(varValue);
		}
	});
};

// find all range elems
LUX.queryRange = function () {
	LUX.elems.range = Array.prototype.slice.call(document.querySelectorAll('.lux-range'));
}

LUX.updateRange = function () {

	LUX.visibleElems.range.forEach(function (element) {

		var $this = $(element);

		var varValue = LUX.getValue($this);
		if (typeof varValue !== 'undefined' && !isEqual($this.attr('data-machine-value-range'), varValue)) {
			$this.attr('data-machine-value-range', varValue)
			var Range = LUX.getRange($this);

			var rangeNumber = -1;

			if (Range.some(function (element) {
				if (varValue < element) {
					return true;
				}
				rangeNumber++;
				return false;
			}) == false) {
			}
			$this.attr("data-range-number", rangeNumber);
		}
	});
};

// find all input elems
LUX.queryInputs = function () {
	LUX.elems.num = Array.prototype.slice.call(document.querySelectorAll('.lux-num-value'));
	LUX.elems.text = Array.prototype.slice.call(document.querySelectorAll('.lux-text-value:not(option)'));
	LUX.elems.textOption = Array.prototype.slice.call(document.querySelectorAll('option.lux-text-value'));
	LUX.elems.dropdown = Array.prototype.slice.call(document.querySelectorAll('.lux-dropdown'));
}

LUX.updateInputs = function () {

	LUX.visibleElems.num.forEach(function (element) {

		var $this = $(element);

		if (!$this.is(":focus") && !$this.hasClass("editing")) {

			var varValue = LUX.getValue($this);
			if (typeof varValue !== "undefined" && !isEqual($this.attr('data-machine-value-num'), varValue)) {
				$this.attr('data-machine-value-num', varValue)
				if (varValue === false) {
					$this.html('false');
					$this.val('false');
				}
				else if (varValue === true) {
					$this.html('true');
					$this.val('true');
				}
				else {

					var unitFactor = $this.attr('data-unit-factor');
					if (Object.prototype.toString.call(unitFactor) === '[object Undefined]') {
						unitFactor = 1;
					}

					var unitOffset = $this.attr('data-unit-offset');
					if (Object.prototype.toString.call(unitOffset) === '[object Undefined]') {
						unitOffset = 0;
					}

					varValue = varValue * unitFactor + unitOffset;

					var sourceUnits = $this.attr('data-source-units');
					var displayUnits = $this.attr('data-display-units');

					// make sure both source and target units are defined
					if ((Object.prototype.toString.call(sourceUnits) !== '[object Undefined]') &&
						(Object.prototype.toString.call(displayUnits) !== '[object Undefined]') &&
						convertFeatEnable) {

						// split the units into string arrays
						let sourceUnitsSplit = sourceUnits.split('/');
						let displayUnitsSplit = displayUnits.split('/');

						// no divisor in either element so convert as normal
						if ((sourceUnitsSplit.length == 1) && (displayUnitsSplit.length == 1)) {
							varValue = LUX.convert(varValue, sourceUnitsSplit[0]).to(displayUnitsSplit[0]);
						}
						// divisor in both elements so do dimentional analysis
						else if ((sourceUnitsSplit.length == 2) && (displayUnitsSplit.length == 2)) {
							varValue = LUX.convert(varValue, sourceUnitsSplit[0]).to(displayUnitsSplit[0]) /
								LUX.convert(1, sourceUnitsSplit[1]).to(displayUnitsSplit[1]);
						}
						// divisor in one element but not the other so warning
						else if (+$this.attr('data-complex-unit-warning') != 1) {
							console.warn(`Issue converting the complex units ${sourceUnits} to ${displayUnits}. The data-var-name for element is <${$this.attr('data-var-name')}>. For complex units, a "/" is required in both data-source-units and data-display-units.`);
							$this.attr('data-complex-unit-warning', 1);
						}
					}

					var fixed = $this.attr('data-fixed');
					if (Object.prototype.toString.call(fixed) !== '[object Undefined]') {
						varValue = varValue.toFixed(fixed);
					}

					var precision = $this.attr('data-precision');
					if (Object.prototype.toString.call(precision) !== '[object Undefined]') {
						varValue = varValue.toPrecision(precision);
					}

					var exponent = $this.attr('data-exponent');
					if (Object.prototype.toString.call(exponent) !== '[object Undefined]') {
						varValue = varValue.toExponential(exponent);
					}
					var digits = $this.attr('data-pad');
					if (Object.prototype.toString.call(digits) !== '[object Undefined]') {
						varValue = (digits + varValue).slice(-digits.length)
					}
					var unitText = $this.attr('data-unit-text');
					if (Object.prototype.toString.call(unitText) === '[object Undefined]') {
						unitText = '';
						// fallback to target units if none specified
						if ((Object.prototype.toString.call(displayUnits) !== '[object Undefined]') &&
							(convertFeatEnable)) {
							unitText = displayUnits;
						}
					}
					if (varValue >= 0) {
						varValue = ' ' + varValue;
					}

					$this.html(varValue + ' ' + unitText);
					$this.val(parseFloat(varValue));

				}
			}
			// not false
		}
		// not in focus
	});

	LUX.visibleElems.text.forEach(function (element) {

		var $this = $(element);

		if (!$this.is(":focus")) {

			var varValue = LUX.getValue($this);
			var string = varValue
			if (typeof varValue === 'object') {
				string = JSON.stringify(varValue, null, 4)
			}
			if (typeof varValue !== "undefined" && !isEqual($this.attr('data-machine-value-text'), string)) {
				$this.attr('data-machine-value-text', varValue)
				if (varValue === false) {
					$this.html('false');
					$this.val('false');
				} else {
					$this.html(string);
					$this.val(string);
				}
			}
		}
	});

	LUX.elems.textOption.forEach(function (element) {

		var $this = $(element);

		if (!$this.is(":focus")) {

			var varValue = LUX.getValue($this);

			if (typeof varValue !== 'undefined' && !isEqual($this.attr('data-machine-value-text-option'), varValue)) {
				$this.attr('data-machine-value-text-option', varValue)
				if (varValue === false) {
					$this.html('false');
					$this.val('false');
				} else {
					$this.html(varValue);
					$this.val(varValue);
				}
			}
		}
	});

	LUX.visibleElems.dropdown.forEach(function (element) {

		var $this = $(element);

		if (!$this.is(":focus")) {

			var varValue = LUX.getValue($this);
			if (typeof varValue !== 'undefined' && !isEqual($this.attr('data-machine-value-dropdown'), varValue)) {
				$this.attr('data-machine-value-dropdown', varValue)
				element.options.selectedIndex = varValue;
			}
		}
	});

};

LUX.addVarWriteEvents = function () {

	$(document).on(
		{
			mousedown: function (event) {
				var $this = $(this);
				LUX.writeValueFromElement($this, LUX.getSetValue($this));
				$this.one('mouseleave', function () {
					LUX.writeValueFromElement($this, LUX.getResetValue($this));
					$this.blur();
				});
			},

			mouseup: function (event) {
				var $this = $(this);
				LUX.writeValueFromElement($this, LUX.getResetValue($this));
				$this.blur();
				$this.off('mouseleave');
			},

			touchstart: function (event) {
				event.preventDefault();
				var $this = $(this);
				LUX.writeValueFromElement($this, LUX.getSetValue($this));
				//This is not required because touchend is triggered when the touch leaves the element
				//$this.one('touchleave', function(){$this.trigger('touchend');});
			},

			touchend: function (event) {
				event.preventDefault();
				var $this = $(this);
				LUX.writeValueFromElement($this, LUX.getResetValue($this));
				$this.blur();
				//This is not required because touchend is triggered when the touch leaves the element
				//$this.off('touchleave');
			}
		},
		'.lux-btn-momentary');
	// momentary button

	$(document).on(
		{
			click: function (event) {
				var $this = $(this);
				var localMachine = window[LUX.getMachineName($this)];

				if ($this.hasClass("lux-ignore-bubbling") && (this !== event.target)) {
					return;
				}
				if ($this.hasClass("lux-confirm")) {
					LuxConfirmModal('Do you want to "' + $this.context.innerHTML + '"?', function () {
						LUX.writeValueFromElement($this, LUX.getSetValue($this));
					})
				}
				else {
					LUX.writeValueFromElement($this, LUX.getSetValue($this));
				}
			}
		},
		'.lux-btn-set');
	// set button

	function LuxConfirmModal(btnMsg, callbackFunc) {
		var YesClick = function () {
			if (typeof (callbackFunc) == "function") {
				callbackFunc();
			}
			$('#LuxConfirmModal').modal('hide');
			$('#LuxConfirmModal .btn-yes-popup, #LuxConfirmModal .btn-no-popup').unbind('click')
		}
		var NoClick = function () {
			$('#LuxConfirmModal').modal('hide');
			$('#LuxConfirmModal .btn-yes-popup, #LuxConfirmModal .btn-no-popup').unbind('click')
		}

		if (!$('#LuxConfirmModal')[0]) {
			// add confirmation pop-up to html if it hasn't been added yet
			var myModal = `<div class="modal fade" id="LuxConfirmModal" role="dialog">
				<div class="modal-dialog">
					<div class="modal-content">
					<div class="modal-header">
						<h5 class="modal-title">Confirm dialog</h5>
						<button type="button" class="close" data-dismiss="modal" aria-label="Close">
						<span aria-hidden="true">&times;</span>
						</button>
					</div>
						<div class="modal-body">
							<p class="modal-msg">temp</p>
						</div>
						<div class="modal-footer">
							<button type="button" class="btn btn-default btn1 btn-yes-popup">Confirm</button>
							<button type="button" class="btn btn-default btn2 btn-no-popup">Cancel</button>
						</div>
					</div>
				</div>
			</div>`;

			$('body').append(myModal);
		}
		$('#LuxConfirmModal .btn-yes-popup').click(YesClick);
		$('#LuxConfirmModal .btn-no-popup').click(NoClick);
		$('.modal-msg').text(btnMsg);
		$('#LuxConfirmModal').modal('show');
	}

	$(document).on(
		{
			click: function (event) {

				var $this = $(this);
				var localMachine = window[LUX.getMachineName($this)];

				if ($this.hasClass("lux-ignore-bubbling") && (this !== event.target)) {
					return;
				}

				if ($this.hasClass("lux-confirm")) {
					LuxConfirmModal('Do you want to "' + $this.context.innerHTML + '"?', function () {
						var varValue = LUX.getValue($this);

						if (isEqual(varValue, LUX.getSetValue($this))) {
							LUX.writeValueFromElement($this, LUX.getResetValue($this));
						} else if (isEqual(varValue, LUX.getResetValue($this))) {
							LUX.writeValueFromElement($this, LUX.getSetValue($this));
						} else {
							LUX.writeValueFromElement($this, LUX.getSetValue($this));
						}
						$this.blur();
					})
				}
				else {
					var varValue = LUX.getValue($this);

					if (isEqual(varValue, LUX.getSetValue($this))) {
						LUX.writeValueFromElement($this, LUX.getResetValue($this));
					} else if (isEqual(varValue, LUX.getResetValue($this))) {
						LUX.writeValueFromElement($this, LUX.getSetValue($this));
					} else {
						LUX.writeValueFromElement($this, LUX.getSetValue($this));
					}
					$this.blur();
				}
			}
		},
		'.lux-btn-toggle');
	// toggle button

	$(document).on(
		{
			click: function (event) {

				// 'checked' is changed between clicking and executing this event handler.
				// So, checkboxes do not behave like toggles.

				var $this = $(this);

				if ($this.prop('checked')) {
					LUX.writeValueFromElement($this, LUX.getSetValue($this));
				} else {
					LUX.writeValueFromElement($this, LUX.getResetValue($this));
				}
			}
		},
		'input:checkbox.lux-checkbox');
	// checkbox

	$(document).on(
		{
			change: function (event) {

				var $this = $(this);

				var varValue = parseFloat($this.val());

				var unitFactor = $this.attr('data-unit-factor');
				if (Object.prototype.toString.call(unitFactor) === '[object Undefined]') {
					unitFactor = 1;
				}

				var unitOffset = $this.attr('data-unit-offset');
				if (Object.prototype.toString.call(unitOffset) === '[object Undefined]') {
					unitOffset = 0;
				}

				varValue = (varValue - unitOffset) / unitFactor;

				var sourceUnits = $this.attr('data-source-units');
				var displayUnits = $this.attr('data-display-units');

				// make sure both source and target units are defined
				if ((Object.prototype.toString.call(sourceUnits) !== '[object Undefined]') &&
					(Object.prototype.toString.call(displayUnits) !== '[object Undefined]') &&
					convertFeatEnable) {

					// split the units into string array
					let sourceUnitsSplit = sourceUnits.split('/');
					let displayUnitsSplit = displayUnits.split('/');

					// no divisor in either element so convert as normal
					if ((sourceUnitsSplit.length == 1) && (displayUnitsSplit.length == 1)) {
						varValue = LUX.convert(varValue, displayUnitsSplit[0]).to(sourceUnitsSplit[0]);
					}
					// divisor in both elements so do dimentional analysis
					else if ((sourceUnitsSplit.length == 2) && (displayUnitsSplit.length == 2)) {
						varValue = LUX.convert(varValue, displayUnitsSplit[0]).to(sourceUnitsSplit[0]) /
							LUX.convert(1, displayUnitsSplit[1]).to(sourceUnitsSplit[1]);
					}
					// divisor in one element but not the other so warning
					else if (+$this.attr('data-complex-unit-warning') != 1) {
						console.warn(`Issue converting the complex units ${sourceUnits} to ${displayUnits}. The data-var-name for element is <${$this.attr('data-var-name')}>. For complex units, a "/" is required in both data-source-units and data-display-units.`);
						$this.attr('data-complex-unit-warning', 1);
					}
				}

				LUX.writeValueFromElement($this, varValue);				
				$this.blur();

			}

		},
		'input.lux-num-value, invisible-input.lux-num-value, .lux-num-value');
	// num-value input

	$(document).on(
		{
			change: function (event) {
				var $this = $(this);
				var varValue = $this.val();
				LUX.writeValueFromElement($this, varValue);				
				$this.blur();
			}
		},
		'.lux-value');
	// num-value input

	$(document).on(
		{
			input: function (event) {

				var $this = $(this);

				if ($this.attr('data-prevent-drag')) return

				var varValue = parseFloat($this.val());

				var unitFactor = $this.attr('data-unit-factor');
				if (Object.prototype.toString.call(unitFactor) === '[object Undefined]') {
					unitFactor = 1;
				}

				var unitOffset = $this.attr('data-unit-offset');
				if (Object.prototype.toString.call(unitOffset) === '[object Undefined]') {
					unitOffset = 0;
				}

				varValue = (varValue - unitOffset) / unitFactor;

				var sourceUnits = $this.attr('data-source-units');
				var displayUnits = $this.attr('data-display-units');

				// make sure both source and target units are defined
				if ((Object.prototype.toString.call(sourceUnits) !== '[object Undefined]') &&
					(Object.prototype.toString.call(displayUnits) !== '[object Undefined]') &&
					convertFeatEnable) {

					// split the units into string array
					let sourceUnitsSplit = sourceUnits.split('/');
					let displayUnitsSplit = displayUnits.split('/');

					// no divisor in either element so convert as normal
					if ((sourceUnitsSplit.length == 1) && (displayUnitsSplit.length == 1)) {
						varValue = LUX.convert(varValue, displayUnitsSplit[0]).to(sourceUnitsSplit[0]);
					}
					// divisor in both elements so do dimentional analysis
					else if ((sourceUnitsSplit.length == 2) && (displayUnitsSplit.length == 2)) {
						varValue = LUX.convert(varValue, displayUnitsSplit[0]).to(sourceUnitsSplit[0]) /
							LUX.convert(1, displayUnitsSplit[1]).to(sourceUnitsSplit[1]);
					}
					// divisor in one element but not the other so warning
					else if (+$this.attr('data-complex-unit-warning') != 1) {
						console.warn(`Issue converting the complex units ${sourceUnits} to ${displayUnits}. The data-var-name for element is <${$this.attr('data-var-name')}>. For complex units, a "/" is required in both data-source-units and data-display-units.`);
						$this.attr('data-complex-unit-warning', 1);
					}
				}

				LUX.writeValueFromElement($this, varValue);
				$this.blur();

			}

		},
		'input.lux-num-value.ondrag, invisible-input.lux-num-value.ondrag');
	// num-value continuous change

	$(document).on(
		{
			change: function (event) {
				var $this = $(this);
				LUX.writeValueFromElement($this, $this.val());
			}
		},
		'input.lux-text-value, invisible-input.lux-text-value, textarea.lux-text-value');
	// text-value input or textarea

	$(document).on(
		{
			change: function (event) {
				var $this = $(this);
				LUX.writeValueFromElement($this, $this[0].options.selectedIndex);
			}
		},
		'.lux-dropdown');
	// dropdown

};
LUX.updateReadGroupComms = function () {
	LUX.machines.forEach(machine => {
		machine.getReadGroupList().forEach(ReadGroupName => {
			if (ReadGroupName != 'global') {
				machine.readGroupShouldManage(ReadGroupName, document.querySelector(`[data-read-group=${ReadGroupName}]`) != null)
			}
		})
	});
}

LUX.observers = [];

/**
 * Lux databinding types
 * @typedef {Object} DataBinding_types
 * @property {Element[]} num
 * @property {Element[]} text
 * @property {Element[]} textOption
 * @property {Element[]} dropdown
 * @property {Element[]} checkbox
 * @property {Element[]} toggleButton
 * @property {Element[]} led
 * @property {Element[]} range
 * @property {Element[]} tab
 * @property {Element[]} component
 * @property {Element[]} datamap
 * @property {Element[]} hide
 * @property {Element[]} lock
 */

/** Current lux elements in DOM
 * @type {DataBinding_types}
 */
LUX.elems = {
	num: [],
	text: [],
	textOption: [],
	dropdown: [],
	checkbox: [],
	toggleButton: [],
	led: [],
	range: [],
	tab: [],
	component: [],
	datamap: [],
	hide: [],
	lock: []
};

/** Currently visible lux elements in DOM
 * @type {DataBinding_types}
 */
LUX.visibleElems = {
	num: [],
	text: [],
	textOption: [],
	dropdown: [],
	checkbox: [],
	toggleButton: [],
	led: [],
	range: [],
	tab: [],
	component: [],
	datamap: [],
	hide: [],
	lock: []
};

// FORCES LAYOUT REFLOW
LUX.checkVisibility = function () {
	// TODO: Don't rebuild array from scratch each call
	Object.keys(LUX.elems).forEach(function (key) {
		if (LUX.visibleElems.hasOwnProperty(key)) {
			LUX.visibleElems[key] = LUX.elems[key].filter(elem => (elem.offsetWidth || elem.offsetHeight || elem.getClientRects().length || (elem.getAttribute('force-hmi-update') == 'true')));
		}
	});
};

LUX.queryDom = function () {
	// TODO: insted of querying document for each class, first query document for class*=lux and then sort based on the different types
	LUX.queryInputs();
	LUX.queryToggleButtons();
	LUX.queryLEDs();
	LUX.queryRange();
	LUX.queryTabs();
	LUX.queryComponents();
	LUX.queryDataMaps();
	LUX.queryHide();
	LUX.queryLock();
};

LUX.updateHMI = function () {
	LUX.updateLocalData(); // run custom callbacks first so that local data is up-to-date for our element updates
	LUX.checkVisibility(); // FORCES LAYOUT REFLOW
	LUX.trigger("update-hmi");
	LUX.updateInputs();
	LUX.updateToggleButtons();
	LUX.updateLEDs();
	LUX.updateRange();
	LUX.updateTabs();
	LUX.updateComponents();
	LUX.updateDataMaps();
	LUX.updateHide();
	LUX.updateLock();
	LUX.updateReadGroupComms();
}

LUX.updateBindings = function () {
	LUX.getCyclicReads();
}

// Include files into an HTML document
LUX.includeFiles = function (successCallback) {

	var numberFiles = 0;
	$("[data-include]").each(function (index, element) {
		numberFiles++;
		var $this = $(this);
		var fileName = $this.attr("data-include");
		console.log("loading " + fileName);
		$this.load(fileName, function () {
			numberFiles--;
			if (numberFiles == 0) {
				if (successCallback) {
					successCallback();
				}
			}
		});
	});
	if (numberFiles == 0) {
		successCallback();
	}
};

// Load a template
LUX.loadTemplate = function (fileName, data, id, callback) {

	$.get(fileName, function (response) {
		//console.log("loading " + fileName);
		$.tmpl(response, data).appendTo(id);
		if (callback) {
			callback();
		}
	});

};

LUX.callbacks = [];
LUX.on = function (callback) {
	LUX.callbacks.push(callback);
}
LUX.trigger = function (eventName) {
	var args = Array.prototype.slice.call(arguments);
	args.shift();
	LUX.callbacks.forEach(function (userCallbacks) {
		Object.keys(userCallbacks).forEach(function (callBack) {
			if (callBack == eventName) {
				try {
					userCallbacks[callBack].apply(this, args);
				} catch (e) {
					console.error("lux-data-bind:" + eventName + ": ", e);
				}
			}
		})
	})
}

LUX.addVarWriteEvents();

// start observer with IIFE call
(function () {
	// DOM observer to trigger queries
	// TODO: handle adding or removing lux class from existing node
	var observer = new MutationObserver(function (mutations) {

		// Was a new lux element added to the DOM?
		// Use Arrray.some() instead of Array.forEach() for easy loop break when we find a lux element added or remove from DOM
		var requestQuery = Array.prototype.slice.call(mutations).some(function (mutation) {
			// check added nodes for lux changes
			var changed = Array.prototype.slice.call(mutation.addedNodes).some(function (node) {
				if (node.nodeType == node.ELEMENT_NODE) {
					// check elem, check descendents
					if (node.matches("[class*='lux']")) {
						// elem has a class starting with 'lux'
						return true;
					} else if (node.querySelector("[class*='lux']")) {
						// elem has a descendant element with a class starting with 'lux'
						return true;
					}
				}
				// node is not an element or doesn't contain lux class
				return false;
			});

			// check removed nodes for lux changes
			changed |= Array.prototype.slice.call(mutation.removedNodes).some(function (node) {
				if (node.nodeType == node.ELEMENT_NODE) {
					// check elem, check descendents
					if (node.matches("[class*='lux']")) {
						// elem has a class starting with 'lux'
						return true;
					} else if (node.querySelector("[class*='lux']")) {
						// elem has a descendant element with a class starting with 'lux'
						return true;
					}
				}
				// node is not an element or doesn't contain lux class
				return false;
			});

			return changed;
		})

		// If so, re-query
		if (requestQuery) {
			// TODO: Call this outside the callback (setTimeout with no time arg to add to queue, queue each query individually to give room for interrupts?)
			LUX.queryDom();
		}

	})

	const observerOptions = {
		attributes: false,
		childList: true,
		characterData: false,
		subtree: true
	};

	// start DOM observer
	observer.observe(document, observerOptions);

	LUX.observers.push(observer);

	// run initial query in case DOM is already loaded
	LUX.queryDom();

})();

// Start updating the HMI after the first successful read
$(document).one({
	'readsuccess': function () {
		// TODO: Move this to a parameter in lux.js, probably, when you make a new machine
		var refresh = LUX.hmiRefresh ? LUX.hmiRefresh : 100;
		setInterval(LUX.updateHMI, refresh);
	}
});

//This element can be used to catch value changed events on elements that wouldn't normally have an "Input"
class invisibleInput extends HTMLElement {
	constructor() {
		super()
		this.setAttribute('force-hmi-update', true)
	}
	set value(v) {
		this._value = v
		this.setAttribute('value', v)
		this._render()
	}
	get value() {
		if(this._value === undefined){
			return 0;
		}
		else{
			return this._value
		}
	}
	_render() {
		let evt = new Event("render", {
			"bubbles": true,
			"cancelable": true
		});
		this.dispatchEvent(evt);
		this.render()
	}
	render() {

	}
}

customElements.define('invisible-input', invisibleInput);