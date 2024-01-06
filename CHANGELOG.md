2.0.2 - Add a new value type that just sets and reads the value of the component

2.0.1 - Fix issue where writing a value to the PLC would not update the HMI if the value was clamped on the PLC to the current value
	  - Fix momentary button behavior when the user leaves an element while holding the mouse down
      - Add read group functions to local HMI machine

2.0.0 - Transition webHMI name to Lux / Loupe UX

1.6.0 - Add read groups attribute to support more sophisticated machine variable reads with frequency limits and callbacks

1.5.0 - Add a max frequency to cyclic reads
	  - Force cyclic reads between writes
	  - Fix copy/paste pv
	  - Remove processing of elements without valid plc variables

1.4.0 - Add unit conversion feature for lux-num-value using
		https://convert.js.org/ library
		Add support for databinding to hmi-side data
	   	Add user levels

1.3.1 - Fix missing write callbacks for root variables
		Fix checkbox behavior to reset var when unchecked
		Add invisible input custom element

1.3.0 - Synchronize release version with OMJSON

1.2.3 - Ensure databinding still starts when included after dom is fully loaded

1.2.2 - Add support for lux-num-value updating inputs on drag

1.2.1 - Fix nav tabs that use href
		Clean up version history

1.2.0 - Add lux-ignore-bubbling and lux-confirm functionality  
      	Add support for led with same data-led-true and data-led-false classes 
     	Add support for nav tabs with data-target instead of href
      	Improve databind update efficiency 

1.1.1 - Fix backwards compatibility bug regarding using Machine.value() in other contexts

1.1.0 - Rework client-server comms
		Add LICENSE.txt
		Add configurable HMI refresh rate
		Add timeout to onDisconnect to avoid crashing of connect and disconnect
		Add try/catch for user callbacks
		Add document events when connection is established or lost

1.0.0 - First release

0.13.0 - Change lux-tab class name to lux-tab-pane
		Remove '.arg' from the end of all event names

0.12.0 - Add documentation
		Add default implementation for led-on and led-off class styling
		Fix bug with empty variable name in the middle of the list

0.11.0 - Update version to match OMJSON for upcoming release

0.2.1 -	Add additional support for less used tags
		Add option support for .lux-text-value (options are not visible)
		Add textarea support for .lux-text-value
