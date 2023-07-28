0.00.7 -	Increase maximum size of variable list from 50 to 100
0.00.6 -	Changed PV_xgetadr status handling to properly handle deleted variables
0.00.4 -	Changed memory alignment check
0.00.3 - 	BACKWARDS COMPATIBILITY ISSUES!
			Changed DataValid to pDataValid. DataValid needs to be tracked 
			in an external power safe variable. Giving the Persistence object
			the address of DataValid allows the object to reset DataValid if it
			detects corrupted memory.
			Bug fixes. 
			Performance improvements.
0.00.2 - 	Added check for data moving.
0.00.1 - 	PersistFn_Init() to load values from persistent memory.
			PersistFn_Cyclic() to store values to persistent memory.