# webHMI

Documentation can be found at https://loupeteam.github.io/Sandbox/libraries/webhmi.html.

## Revision
- 1.6.1 - Add read group functions to local HMI machine
- 1.6.0 - Add read groups
- 1.5.1 - Add waiting to avoid pileup
- 1.5.0 - Add a max frequency to cyclic reads
	  	- Force cyclic reads between writes
	  	- Fix copy/paste pv
	  	- Remove processing of elements without valid plc variables
- 1.4.0 - Add unit conversion feature for webhmi-num-value using
		https://convert.js.org/ library
		Add support for databinding to hmi-side data
	   	Add user levels
- 1.3.1 - Fix missing write callbacks for root variables
		Fix checkbox behavior to reset var when unchecked
		Add invisible input custom element
- 1.3.0 - Synchronize release version with OMJSON
- 1.2.3 - Ensure databinding still starts when included after dom is fully loaded
- 1.2.2 - Add support for webhmi-num-value updating inputs on drag
- 1.2.1 - Fix nav tabs that use href
		Clean up version history
- 1.2.0 - Add webhmi-ignore-bubbling and webhmi-confirm functionality  
      	Add support for led with same data-led-true and data-led-false classes 
     	Add support for nav tabs with data-target instead of href
      	Improve databind update efficiency 
- 1.1.1 - Fix backwards compatibility bug regarding using Machine.value() in other contexts
- 1.1.0 - Rework client-server comms
		Add LICENSE.txt
		Add configurable HMI refresh rate
		Add timeout to onDisconnect to avoid crashing of connect and disconnect
		Add try/catch for user callbacks
		Add document events when connection is established or lost
- 1.0.0 - First release
- 0.13.0 - Change webhmi-tab class name to webhmi-tab-pane
		Remove '.arg' from the end of all event names
- 0.12.0 - Add documentation
		Add default implementation for led-on and led-off class styling
		Fix bug with empty variable name in the middle of the list
- 0.11.0 - Update version to match OMJSON for upcoming release
- 0.2.1 -	Add additional support for less used tags
		Add option support for .webhmi-text-value (options are not visible)
		Add textarea support for .webhmi-text-value