//------------------------------------------------------------------------------
// Copyright 2020 Loupe
//------------------------------------------------------------------------------

// Check for webHMI global object
if (typeof WEBHMI === 'undefined') {
	throw new Error('WEBHMI data binding requires WEBHMI core');
}

WEBHMI.dataBindVersion = '1.4.0';

// Check for being a 'number'
function isNumeric (obj) {
	return !Number.isNaN(parseFloat(obj)) && isFinite(obj)
}

WEBHMI.isNumeric = isNumeric

// Make sure the convert library is included
let convertFeatEnable = false;
if ((typeof convert === 'undefined') || (typeof convert.convert !== 'function')){
	console.warn('Convert library not defined in index.html and will be disabled')
	console.warn('Inclusion Example: <script src="webHMI/convert.prod.js"></script>')
}else{
	WEBHMI.convert = convert.convert
	convertFeatEnable = true;
}

// BOOLify something
function isTrue (value) {

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

WEBHMI.isTrue = isTrue

// Check for custom equality
// Types supported: Undefined, Boolean, Number, String
function isEqual (in1, in2) {

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

// Get attribute values
//----------------------

WEBHMI.getVarName = function ($element) {
	return $element.attr('data-var-name');
};

WEBHMI.getHideVarName = function ($element) {
	var value = $element.attr('data-var-name-hide');
	if (value === undefined) {
		value = WEBHMI.getVarName($element);
		$element.attr('data-var-name-hide', value);
	}
	return value;
};

WEBHMI.getLockVarName = function ($element) {
	var value = $element.attr('data-var-name-lock');
	if (value === undefined) {
		value = WEBHMI.getVarName($element);
		$element.attr('data-var-name-lock', value);
	}
	return value;
};

WEBHMI.getMachineName = function ($element) {
	var value = $element.attr('data-machine-name');
	if (value === undefined) {
		value = 'machine';
		$element.attr('data-machine-name', value);
	}
	return value;
};

WEBHMI.getMachine = function ($element) {
	// Abstract this in case there is not a window. or something else unheard of.
	return window[WEBHMI.getMachineName($element)];
}

WEBHMI.getLedTrue = function ($element) {
	var value = $element.attr('data-led-true');
	if (value === undefined) {
		value = 'led-on';
		$element.attr('data-led-true', value);
	}
	return value;
}

WEBHMI.getLedFalse = function ($element) {
	var value = $element.attr('data-led-false');
	if (value === undefined) {
		value = 'led-off';
		$element.attr('data-led-false', value);
	}
	return value;
};

WEBHMI.getSetValue = function ($element) {
	var value = $element.attr('data-set-value');
	if (value === undefined) {
		value = true;
		$element.attr('data-set-value', value);
	}
	return value;
};

WEBHMI.getHideTrue = function ($element) {
	var value = $element.attr('data-hide-true');
	if (value === undefined) {
		value = 'hidden';
		$element.attr('data-hide-true', value);
	}
	return value;
};

WEBHMI.getLockTrue = function ($element) {
	var value = $element.attr('data-lock-true');
	if (value === undefined) {
		value = 'disabled';
		$element.attr('data-lock-true', value);
	}
	return value;
};

WEBHMI.getResetValue = function ($element) {
	var value = $element.attr('data-reset-value');
	if (value === undefined) {
		value = false;
		$element.attr('data-reset-value', value);
	}
	return value;
};

WEBHMI.getHideSetValue = function ($element) {
	var value = $element.attr('data-hide-set');
	if (value === undefined) {
		value = true;
		$element.attr('data-hide-set', value);
	}
	return value;
};

WEBHMI.getLockSetValue = function ($element) {
	var value = $element.attr('data-lock-set');
	if (value === undefined) {
		value = true;
		$element.attr('data-lock-set', value);
	}
	return value;
};

WEBHMI.getUserLevelShow = function ($element) {
	return $element.attr('min-user-level-show');
};

WEBHMI.getUserLevelUnlock = function ($element) {
	return $element.attr('min-user-level-unlock');
};

WEBHMI.getRange = function ($element) {
	var value = $element.attr('data-range');
	if (value === undefined) {
		value = '[-1, 0, 1, 2]';
		$element.attr('data-range', value);
	}
	return JSON.parse(value);
};

WEBHMI.getValue = function ($element) {
	
	//var localMachine = window[WEBHMI.getMachineName($element)];
	var localMachine = WEBHMI.getMachine($element); // NOTE: Try this here before migrating everything else...
	
	var varName = WEBHMI.getVarName($element);
	if (varName === undefined) {
		return "No variable";
	}
	
	var varValue = localMachine.value(varName);
	if (varValue === undefined) {
		localMachine.initCyclicRead(varName); // this might cause bad behavior if the variable does not exist on the PLC.
	}

	return varValue;

}

WEBHMI.getHideValue = function ($element) {
	
	//var localMachine = window[WEBHMI.getMachineName($element)];
	var localMachine = WEBHMI.getMachine($element); // NOTE: Try this here before migrating everything else...
	
	var varName = WEBHMI.getHideVarName($element);
	if (varName === undefined) {
		return "No variable";
	}
	
	var varValue = localMachine.value(varName);
	if (varValue === undefined) {
		localMachine.initCyclicRead(varName); // this might cause bad behavior if the variable does not exist on the PLC.
	}

	return varValue;

}

WEBHMI.getLockValue = function ($element) {
	
	//var localMachine = window[WEBHMI.getMachineName($element)];
	var localMachine = WEBHMI.getMachine($element); // NOTE: Try this here before migrating everything else...
	
	var varName = WEBHMI.getLockVarName($element);
	if (varName === undefined) {
		return "No variable";
	}
	
	var varValue = localMachine.value(varName);
	if (varValue === undefined) {
		localMachine.initCyclicRead(varName); // this might cause bad behavior if the variable does not exist on the PLC.
	}

	return varValue;

}

WEBHMI.getUserLevel = function ($element) {

	//var localMachine = window[WEBHMI.getMachineName($element)];
	var localMachine = WEBHMI.getMachine($element); // NOTE: Try this here before migrating everything else...
	
	return localMachine.getUserLevel(); // Handles everything we need it to

}
// NOTE: What is the point of this function? I guess it will init things that are not already in the list, but that is a funny name if that is the point.
WEBHMI.getCyclicReads = function () {
	$("[data-var-name]").each(function (index, element) { 
		WEBHMI.getValue($(this));
	});
}

// Update page elements
//----------------------

// find all LED elems
WEBHMI.queryLEDs = function () {
	WEBHMI.elems.led = Array.prototype.slice.call(document.querySelectorAll('.webhmi-led'));
}

WEBHMI.updateLEDs = function () {

	// iterate over array of visible webhmi led elements
	WEBHMI.visibleElems.led.forEach(function (element) {

		const $this = $(element);
		const varValue = WEBHMI.getValue($this);
		if (!isEqual($this.attr('data-machine-value-led'), varValue)) {
			$this.attr('data-machine-value-led', varValue)
			const setValue = WEBHMI.getSetValue($this);
			const resetValue = WEBHMI.getResetValue($this);

			// if (typeof varValue === 'boolean') {
			// 	setValue = WEBHMI.isTrue(setValue);
			// 	resetValue = WEBHMI.isTrue(resetValue);
			// }

			if (isEqual(varValue, setValue)) {
				$this.removeClass(WEBHMI.getLedFalse($this)).addClass(WEBHMI.getLedTrue($this));
			} else if (isEqual(varValue, resetValue)) {
				$this.removeClass(WEBHMI.getLedTrue($this)).addClass(WEBHMI.getLedFalse($this));
			} else {
				$this.removeClass(WEBHMI.getLedFalse($this)).removeClass(WEBHMI.getLedTrue($this));
			}
		}
	})
}

// find hide/show elems
WEBHMI.queryHide = function () {
	WEBHMI.elems.hide = Array.prototype.slice.call(document.querySelectorAll('.webhmi-hide, .webhmi-show, [min-user-level-show]'));
}

WEBHMI.updateHide = function () {

	WEBHMI.elems.hide.forEach(function (element) {

		const $this = $(element);
		
		const hasHideUserLevel = ($this.attr('min-user-level-show') !== undefined);
		const hasHide = $this.hasClass('webhmi-hide');
		const hasShow = $this.hasClass('webhmi-show');

		const varValue = WEBHMI.getHideValue($this);
		const userLevel = WEBHMI.getUserLevel($this);

		if (((hasHide || hasShow) && !isEqual($this.attr('data-machine-value-hide'), varValue)) || (hasHideUserLevel && !isEqual($this.attr('data-machine-value-user-level-show'), userLevel))) {
		
			if(hasHide || hasShow) $this.attr('data-machine-value-hide', varValue);
			if(hasHideUserLevel) $this.attr('data-machine-value-user-level-show', userLevel);

			const setValue = WEBHMI.getHideSetValue($this); // elements that only have user level will get data-hide-set here; this is fine
			const userLevelShow = WEBHMI.getUserLevelShow($this);

			if ((hasHide && isEqual(varValue, setValue)) || (hasShow && !isEqual(varValue, setValue)) || (hasHideUserLevel && (userLevel < userLevelShow))) {
				$this.addClass(WEBHMI.getHideTrue($this));
			} else {
				$this.removeClass(WEBHMI.getHideTrue($this));
			}

		}

	})

}

// find lock/unlock elems
WEBHMI.queryLock = function () {
	WEBHMI.elems.lock = Array.prototype.slice.call(document.querySelectorAll('.webhmi-lock, .webhmi-unlock, [min-user-level-unlock]'));
}

WEBHMI.updateLock = function () {

	WEBHMI.elems.lock.forEach(function (element) {

		const $this = $(element);

		const hasLockUserLevel = ($this.attr('min-user-level-unlock') !== undefined);
		const hasLock = $this.hasClass('webhmi-lock');
		const hasUnlock = $this.hasClass('webhmi-unlock');

		const varValue = WEBHMI.getLockValue($this);
		const userLevel = WEBHMI.getUserLevel($this);

		if (((hasLock || hasUnlock) && !isEqual($this.attr('data-machine-value-lock'), varValue)) || (hasLockUserLevel && !isEqual($this.attr('data-machine-value-user-level-unlock'), userLevel))) {
		
			if(hasLock || hasUnlock) $this.attr('data-machine-value-lock', varValue);
			if(hasLockUserLevel) $this.attr('data-machine-value-user-level-unlock', userLevel);

			const setValue = WEBHMI.getLockSetValue($this); // elements that only have user level will get data-lock-set here; this is fine
			const userLevelUnlock = WEBHMI.getUserLevelUnlock($this);

			if ((hasLock && isEqual(varValue, setValue)) || (hasUnlock && !isEqual(varValue, setValue)) || (hasLockUserLevel && (userLevel < userLevelUnlock))) {
				$this.addClass(WEBHMI.getLockTrue($this));
				$this.prop('disabled', true);
			} else {
				$this.removeClass(WEBHMI.getLockTrue($this));
				$this.prop('disabled', false);
			}

		}

	})
	
}

// find all toggle btn elems
WEBHMI.queryToggleButtons = function () {
	WEBHMI.elems.toggleButton = Array.prototype.slice.call(document.querySelectorAll('.webhmi-btn-toggle'));
}

WEBHMI.updateToggleButtons = function () {

	WEBHMI.visibleElems.toggleButton.forEach(function (element) {

		var $this = $(element);

		var varValue = WEBHMI.getValue($this);
		if (!isEqual($this.attr('data-machine-value-toggle'), varValue)) {
			$this.attr('data-machine-value-toggle', varValue)
			if (isEqual(varValue, WEBHMI.getSetValue($this))) {
				$this.addClass('toggle-active');
			} else if (isEqual(varValue, WEBHMI.getResetValue($this))) {
				$this.removeClass('toggle-active');
			} else {
				$this.removeClass('toggle-active');
			}
		}
	});

};

// find all checkbox elems
WEBHMI.queryCheckboxes = function () {
	WEBHMI.elems.checkbox = Array.prototype.slice.call(document.querySelectorAll('.webhmi-checkbox'));
}

WEBHMI.updateCheckboxes = function () {

	// if (webHMI.numActiveWrites !== 0)
	// return;

	WEBHMI.visibleElems.checkbox.forEach(function (element) {

		var $this = $(element);

		var isChecked = $this.prop('checked');

		var varValue = WEBHMI.getValue($this);
		if (!isEqual($this.attr('data-machine-value-checkbox'), varValue)) {
			$this.attr('data-machine-value-checkbox', varValue)
			if (isEqual(varValue, WEBHMI.getSetValue($this)) && !isChecked) {
				$this.prop('checked', true);
			} else if (isEqual(varValue, WEBHMI.getResetValue($this)) && isChecked) {
				$this.prop('checked', false);
			}
		}
	});

};

// find tab elems
WEBHMI.queryTabs = function () {
	WEBHMI.elems.tab = Array.prototype.slice.call(document.querySelectorAll('.webhmi-tab-pane'));
}

WEBHMI.updateTabs = function () {

	// if (webHMI.numActiveWrites !== 0)
	// return;

	WEBHMI.elems.tab.forEach(function (element) {

		var $this = $(element);

		var varValue = WEBHMI.getValue($this);
		if (!isEqual($this.attr('data-machine-value-tab'), varValue)) {
			$this.attr('data-machine-value-tab', varValue)
			if ((varValue == WEBHMI.getSetValue($this))) {
				var tabs = $('.nav-tabs');
				var tab = tabs.find('a[data-target="#' + $this[0].id + '"]');
				if (tab.length == 0)
					tab = tabs.find('a[href="#' + $this[0].id + '"]');
				tab.first().tab('show') // this requires bootstrap
			}
		}
	});

};

// find all range elems
WEBHMI.queryRange = function () {
	WEBHMI.elems.range = Array.prototype.slice.call(document.querySelectorAll('.webhmi-range'));
}

WEBHMI.updateRange = function () {

	WEBHMI.visibleElems.range.forEach(function (element) {

		var $this = $(element);

		var varValue = WEBHMI.getValue($this);
		if (!isEqual($this.attr('data-machine-value-range'), varValue)) {
			$this.attr('data-machine-value-range', varValue)
			var Range = WEBHMI.getRange($this);

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
WEBHMI.queryInputs = function () {
	WEBHMI.elems.num = Array.prototype.slice.call(document.querySelectorAll('.webhmi-num-value'));
	WEBHMI.elems.text = Array.prototype.slice.call(document.querySelectorAll('.webhmi-text-value:not(option)'));
	WEBHMI.elems.textOption = Array.prototype.slice.call(document.querySelectorAll('option.webhmi-text-value'));
	WEBHMI.elems.dropdown = Array.prototype.slice.call(document.querySelectorAll('.webhmi-dropdown'));
}

WEBHMI.updateInputs = function () {

	WEBHMI.visibleElems.num.forEach(function (element) {
		
		var $this = $(element);

		if (!$this.is(":focus") && !$this.hasClass("editing")) {

			var varValue = WEBHMI.getValue($this);
			if (!isEqual($this.attr('data-machine-value-num'), varValue)) {
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
						convertFeatEnable){
						
						// split the units into string arrays
						let sourceUnitsSplit = sourceUnits.split('/');
						let displayUnitsSplit = displayUnits.split('/');
					
						// no divisor in either element so convert as normal
						if ((sourceUnitsSplit.length == 1) && (displayUnitsSplit.length == 1)){
							varValue = WEBHMI.convert(varValue, sourceUnitsSplit[0]).to(displayUnitsSplit[0]);
						}
						// divisor in both elements so do dimentional analysis
						else if ((sourceUnitsSplit.length == 2) && (displayUnitsSplit.length == 2)){
							varValue = WEBHMI.convert(varValue, sourceUnitsSplit[0]).to(displayUnitsSplit[0]) /
						 				WEBHMI.convert(1, sourceUnitsSplit[1]).to(displayUnitsSplit[1]);
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
							(convertFeatEnable)){
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

	WEBHMI.visibleElems.text.forEach(function (element) {

		var $this = $(element);

		if (!$this.is(":focus")) {

			var varValue = WEBHMI.getValue($this);
			var string = varValue
			if( typeof varValue === 'object' ){
				string = JSON.stringify(varValue, null, 4)
			}
			if (!isEqual($this.attr('data-machine-value-text'), string )) {
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

	WEBHMI.elems.textOption.forEach(function (element) {

		var $this = $(element);

		if (!$this.is(":focus")) {

			var varValue = WEBHMI.getValue($this);

			if (!isEqual($this.attr('data-machine-value-text-option'), varValue)) {
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

	WEBHMI.visibleElems.dropdown.forEach(function (element){
		
		var $this = $(element);

		if (!$this.is(":focus")) {

			var varValue = WEBHMI.getValue($this);
			if (!isEqual($this.attr('data-machine-value-dropdown'), varValue)) {
				$this.attr('data-machine-value-dropdown', varValue)
				element.options.selectedIndex = varValue;
			}
		}
	});
	
};

WEBHMI.addVarWriteEvents = function () {

	$(document).on(
		{
			mousedown: function (event) {
				var $this = $(this);
				var localMachine = window[WEBHMI.getMachineName($this)];
				localMachine.writeVariable(WEBHMI.getVarName($this), WEBHMI.getSetValue($this));
				$this.one('mouseleave', function () {
					$this.trigger('mouseup');
				});
			},

			mouseup: function (event) {
				var $this = $(this);
				var localMachine = window[WEBHMI.getMachineName($this)];
				localMachine.writeVariable(WEBHMI.getVarName($this), WEBHMI.getResetValue($this));
				$this.blur();
				$this.off('mouseleave');
			},

			touchstart: function (event) {
				event.preventDefault();
				var $this = $(this);
				var localMachine = window[WEBHMI.getMachineName($this)];
				localMachine.writeVariable(WEBHMI.getVarName($this), WEBHMI.getSetValue($this));
				//$this.one('touchleave', function(){$this.trigger('touchend');});
			},

			touchend: function (event) {
				event.preventDefault();
				var $this = $(this);
				var localMachine = window[WEBHMI.getMachineName($this)];
				localMachine.writeVariable(WEBHMI.getVarName($this), WEBHMI.getResetValue($this));
				$this.blur();
				//$this.off('touchleave');
			}
		}, 
		'.webhmi-btn-momentary');
	// momentary button

	$(document).on(
		{
			click: function (event) {
				var $this = $(this);
				var localMachine = window[WEBHMI.getMachineName($this)];

				if ($this.hasClass("webhmi-ignore-bubbling") && (this !== event.target)) {
					return;
				}
				if ($this.hasClass("webhmi-confirm")) {
					WebhmiConfirmModal('Do you want to "' + $this.context.innerHTML + '"?', function () {
						localMachine.writeVariable(WEBHMI.getVarName($this), WEBHMI.getSetValue($this));
					})
				}
				else {
					localMachine.writeVariable(WEBHMI.getVarName($this), WEBHMI.getSetValue($this));
				}
			}
		},
		'.webhmi-btn-set');
	// set button

	function WebhmiConfirmModal(btnMsg, callbackFunc) {
		var YesClick = function () {
			if (typeof (callbackFunc) == "function") {
				callbackFunc();
			}
			$('#WebhmiConfirmModal').modal('hide');
			$('#WebhmiConfirmModal .btn-yes-popup, #WebhmiConfirmModal .btn-no-popup').unbind('click')
		}
		var NoClick = function () {
			$('#WebhmiConfirmModal').modal('hide');
			$('#WebhmiConfirmModal .btn-yes-popup, #WebhmiConfirmModal .btn-no-popup').unbind('click')
		}

		if(!$('#WebhmiConfirmModal')[0]){
			// add confirmation pop-up to html if it hasn't been added yet
			var myModal = `<div class="modal fade" id="WebhmiConfirmModal" role="dialog">
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
		$('#WebhmiConfirmModal .btn-yes-popup').click(YesClick);
		$('#WebhmiConfirmModal .btn-no-popup').click(NoClick);
		$('.modal-msg').text(btnMsg);
		$('#WebhmiConfirmModal').modal('show');
	}

	$(document).on(
		{
			click: function (event) {

				var $this = $(this);
				var localMachine = window[WEBHMI.getMachineName($this)];

				if ($this.hasClass("webhmi-ignore-bubbling") && (this !== event.target)) {
					return;
				}

				if ($this.hasClass("webhmi-confirm")) {
					WebhmiConfirmModal('Do you want to "' + $this.context.innerHTML + '"?', function () {
						var varValue = WEBHMI.getValue($this);

						if (isEqual(varValue, WEBHMI.getSetValue($this))) {
							localMachine.writeVariable(WEBHMI.getVarName($this), WEBHMI.getResetValue($this));
						} else if (isEqual(varValue, WEBHMI.getResetValue($this))) {
							localMachine.writeVariable(WEBHMI.getVarName($this), WEBHMI.getSetValue($this));
						} else {
							localMachine.writeVariable(WEBHMI.getVarName($this), WEBHMI.getSetValue($this));
						}

						$this.blur();
					})
				}
				else {
					var varValue = WEBHMI.getValue($this);

					if (isEqual(varValue, WEBHMI.getSetValue($this))) {
						localMachine.writeVariable(WEBHMI.getVarName($this), WEBHMI.getResetValue($this));
					} else if (isEqual(varValue, WEBHMI.getResetValue($this))) {
						localMachine.writeVariable(WEBHMI.getVarName($this), WEBHMI.getSetValue($this));
					} else {
						localMachine.writeVariable(WEBHMI.getVarName($this), WEBHMI.getSetValue($this));
					}

					$this.blur();
				}
			}
		},
		'.webhmi-btn-toggle');
	// toggle button

	$(document).on(
		{
			click: function (event) {

				// 'checked' is changed between clicking and executing this event handler.
				// So, checkboxes do not behave like toggles.

				var $this = $(this);
				var localMachine = window[WEBHMI.getMachineName($this)];

				if ($this.prop('checked')) {
					localMachine.writeVariable(WEBHMI.getVarName($this), WEBHMI.getSetValue($this));
				} else {
					localMachine.writeVariable(WEBHMI.getVarName($this), WEBHMI.getResetValue($this));
				}
			}
		},
		'input:checkbox.webhmi-checkbox');
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
					convertFeatEnable){
				
					// split the units into string array
					let sourceUnitsSplit = sourceUnits.split('/');
					let displayUnitsSplit = displayUnits.split('/');

					// no divisor in either element so convert as normal
					if ((sourceUnitsSplit.length == 1) && (displayUnitsSplit.length == 1)){
						varValue = WEBHMI.convert(varValue, displayUnitsSplit[0]).to(sourceUnitsSplit[0]);
					}
					// divisor in both elements so do dimentional analysis
					else if ((sourceUnitsSplit.length == 2) && (displayUnitsSplit.length == 2)){
						varValue = WEBHMI.convert(varValue, displayUnitsSplit[0]).to(sourceUnitsSplit[0]) /
									WEBHMI.convert(1, displayUnitsSplit[1]).to(sourceUnitsSplit[1]);
					}
					// divisor in one element but not the other so warning
					else if (+$this.attr('data-complex-unit-warning') != 1) {
						console.warn(`Issue converting the complex units ${sourceUnits} to ${displayUnits}. The data-var-name for element is <${$this.attr('data-var-name')}>. For complex units, a "/" is required in both data-source-units and data-display-units.`);
						$this.attr('data-complex-unit-warning', 1);
					}
				}

				var localMachine = window[WEBHMI.getMachineName($this)];
				localMachine.writeVariable(WEBHMI.getVarName($this), varValue);
				$this.blur();

			}

		},
		'input.webhmi-num-value, invisible-input.webhmi-num-value');
	// num-value input

	$(document).on(
		{
			input: function (event) {

				var $this = $(this);

				if($this.attr('data-prevent-drag')) return

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
					convertFeatEnable){
				
					// split the units into string array
					let sourceUnitsSplit = sourceUnits.split('/');
					let displayUnitsSplit = displayUnits.split('/');

					// no divisor in either element so convert as normal
					if ((sourceUnitsSplit.length == 1) && (displayUnitsSplit.length == 1)){
						varValue = WEBHMI.convert(varValue, displayUnitsSplit[0]).to(sourceUnitsSplit[0]);
					}
					// divisor in both elements so do dimentional analysis
					else if ((sourceUnitsSplit.length == 2) && (displayUnitsSplit.length == 2)){
						varValue = WEBHMI.convert(varValue, displayUnitsSplit[0]).to(sourceUnitsSplit[0]) /
									WEBHMI.convert(1, displayUnitsSplit[1]).to(sourceUnitsSplit[1]);
					}
					// divisor in one element but not the other so warning
					else if (+$this.attr('data-complex-unit-warning') != 1) {
						console.warn(`Issue converting the complex units ${sourceUnits} to ${displayUnits}. The data-var-name for element is <${$this.attr('data-var-name')}>. For complex units, a "/" is required in both data-source-units and data-display-units.`);
						$this.attr('data-complex-unit-warning', 1);
					}
				}

				var localMachine = window[WEBHMI.getMachineName($this)];
				localMachine.writeVariable(WEBHMI.getVarName($this), varValue);
				$this.blur();

			}

		},
		'input.webhmi-num-value.ondrag, invisible-input.webhmi-num-value.ondrag');
	// num-value continuous change

	$(document).on(
		{
			change: function (event) {
				var $this = $(this);
				var localMachine = window[WEBHMI.getMachineName($this)];
				localMachine.writeVariable(WEBHMI.getVarName($this), $this.val());
				localMachine.readVariable(WEBHMI.getVarName($this));
			}
		},
		'input.webhmi-text-value, invisible-input.webhmi-text-value, textarea.webhmi-text-value');
	// text-value input or textarea

	$(document).on(
		{
			change: function (event) {
				var $this = $(this);
				var localMachine = window[WEBHMI.getMachineName($this)];
				localMachine.writeVariable(WEBHMI.getVarName($this), $this[0].options.selectedIndex);
				localMachine.readVariable(WEBHMI.getVarName($this));
			}
		},
		'.webhmi-dropdown');
	// dropdown

};

WEBHMI.observers = [];

/**
 * Webhmi databinding types
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
 * @property {Element[]} hide
 * @property {Element[]} lock
 */

/** Current webhmi elements in DOM
 * @type {DataBinding_types}
 */
WEBHMI.elems = {
	num: [], 
	text: [],
	textOption: [],
	dropdown: [],
	checkbox: [],
	toggleButton: [],
	led: [],
	range: [],
	tab: [],
	hide: [],
	lock: []
};

/** Currently visible webhmi elements in DOM
 * @type {DataBinding_types}
 */
WEBHMI.visibleElems = {
	num: [], 
	text: [],
	textOption: [],
	dropdown: [],
	checkbox: [],
	toggleButton: [],
	led: [],
	range: [],
	tab: [],
	hide: [],
	lock: [] 
};

// FORCES LAYOUT REFLOW
WEBHMI.checkVisibility = function () {
	// TODO: Don't rebuild array from scratch each call
	Object.keys(WEBHMI.elems).forEach(function (key) {
		if (WEBHMI.visibleElems.hasOwnProperty(key)) {
			WEBHMI.visibleElems[key] = WEBHMI.elems[key].filter(elem => (elem.offsetWidth || elem.offsetHeight || elem.getClientRects().length || (elem.getAttribute('force-hmi-update') == 'true') ));
		}
	});
};

WEBHMI.queryDom = function () {
	// TODO: insted of querying document for each class, first query document for class*=webhmi and then sort based on the different types
	WEBHMI.queryInputs();
	WEBHMI.queryToggleButtons();
	WEBHMI.queryLEDs();
	WEBHMI.queryRange();
	WEBHMI.queryTabs();
	WEBHMI.queryHide();
	WEBHMI.queryLock();
};

WEBHMI.updateHMI = function () {
	WEBHMI.updateLocalData(); // run custom callbacks first so that local data is up-to-date for our element updates
	WEBHMI.checkVisibility(); // FORCES LAYOUT REFLOW
	WEBHMI.trigger("update-hmi");
	WEBHMI.updateInputs();
	WEBHMI.updateToggleButtons();
	WEBHMI.updateLEDs();
	WEBHMI.updateRange();
	WEBHMI.updateTabs();
	WEBHMI.updateHide();
	WEBHMI.updateLock();
}

WEBHMI.updateBindings = function () {
	WEBHMI.getCyclicReads();
}

// Include files into an HTML document
WEBHMI.includeFiles = function (successCallback) {

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
	if(numberFiles==0){
		successCallback();
	}
};

// Load a template
WEBHMI.loadTemplate = function (fileName, data, id, callback) {

	$.get(fileName, function (response) {
		//console.log("loading " + fileName);
		$.tmpl(response, data).appendTo(id);
		if (callback) {
			callback();
		}
	});

};

WEBHMI.callbacks = [];
WEBHMI.on = function (callback) {
	WEBHMI.callbacks.push(callback);
}
WEBHMI.trigger = function (eventName) {
	var args = Array.prototype.slice.call(arguments);
	args.shift();
	WEBHMI.callbacks.forEach(function (userCallbacks) {
		Object.keys(userCallbacks).forEach(function (callBack) {
			if (callBack == eventName) {
				try {
					userCallbacks[callBack].apply(this, args);	
				} catch (e) {
					console.error("webhmi-data-bind:"+eventName+": ",e);
				}
			}
		})
	})
}

WEBHMI.addVarWriteEvents();

// start observer with IIFE call
(function () {
	// DOM observer to trigger queries
	// TODO: handle adding or removing webhmi class from existing node
	var observer = new MutationObserver(function (mutations) {

		// Was a new webhmi element added to the DOM?
		// Use Arrray.some() instead of Array.forEach() for easy loop break when we find a webhmi element added or remove from DOM
		var requestQuery = Array.prototype.slice.call(mutations).some(function (mutation) {
			// check added nodes for webhmi changes
			var changed = Array.prototype.slice.call(mutation.addedNodes).some(function (node) {
				if (node.nodeType == node.ELEMENT_NODE) {
					// check elem, check descendents
					if (node.matches("[class*='webhmi']")) {
						// elem has a class starting with 'webhmi'
						return true;
					} else if (node.querySelector("[class*='webhmi']")) {
						// elem has a descendant element with a class starting with 'webhmi'
						return true;
					}
				}
				// node is not an element or doesn't contain webhmi class
				return false;
			});

			// check removed nodes for webhmi changes
			changed |= Array.prototype.slice.call(mutation.removedNodes).some(function (node) {
				if (node.nodeType == node.ELEMENT_NODE) {
					// check elem, check descendents
					if (node.matches("[class*='webhmi']")) {
						// elem has a class starting with 'webhmi'
						return true;
					} else if (node.querySelector("[class*='webhmi']")) {
						// elem has a descendant element with a class starting with 'webhmi'
						return true;
					}
				}
				// node is not an element or doesn't contain webhmi class
				return false;
			});

			return changed;
		})

		// If so, re-query
		if (requestQuery) {
			// TODO: Call this outside the callback (setTimeout with no time arg to add to queue, queue each query individually to give room for interrupts?)
			WEBHMI.queryDom();
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

	WEBHMI.observers.push(observer);

	// run initial query in case DOM is already loaded
	WEBHMI.queryDom();

})();

// Start updating the HMI after the first successful read
$(document).one({
	'readsuccess': function () {
		// TODO: Move this to a parameter in webhmi.js, probably, when you make a new machine
		var refresh = WEBHMI.hmiRefresh ? WEBHMI.hmiRefresh : 100;
		setInterval(WEBHMI.updateHMI, refresh);	
	}
});

//This element can be used to catch value changed events on elements that wouldn't normally have an "Input"
class invisibleInput extends HTMLElement {
    constructor() {
        super()
		this.setAttribute('force-hmi-update',true)
    }
    set value( v ){
        this._value = v
        this.setAttribute('value', v)
        let evt = new Event("change", {
            "bubbles": true,
            "cancelable": true
        });
        this.dispatchEvent(evt);
    }
    get value( ){
        return this._value || 0
    }
}
      
customElements.define('invisible-input', invisibleInput);