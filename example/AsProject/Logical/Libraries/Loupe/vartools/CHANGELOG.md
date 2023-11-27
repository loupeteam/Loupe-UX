0.11.3 - Increase maximum size of variable list from 50 to 100
0.11.2 - populate variable values will populate ._ with just the parent name 
0.11.1 - Fix bug in populate variable values with arrays of strings
0.11.0 - Add new function to populate all the string members of a structure to the variable name
0.10.1 - Add support for external build
0.10.0 - Add support for BYTE, WORD, and DWORD
0.9.2 - Reduce repeated varGetInfo calls on unfound vars
      - Add varRefresh Fn to force refresh of variable info
0.9.1 - Update StringExt from 0.13 to 0.14
0.9.0 - Add support for WSTRING
0.8.2 - Add varGetValueLreal to get a PV value as an lreal
0.8.1 - Explicitly add null character at end of value strings
0.8 - Move from AsString functions to AsBrStr functions.
		Alphabetize the list coming from varGetVariableList().
		Add LREAL support for get and set.
		Add VAR_TYPE_UNDEFINED if error getting address.
		Add Array of variable member values to varVariableWatch for display purposes.
0.7 - Add varVariableWatch as an end-user facing function block to monitor values.
   		Modify variableBrowser to use varVariableWatch.
   		Add varGetValueReal to get a PV value as a real instead of a string.
0.6 - Add variableBrowser().
		varGetLocalVariableList now checks for duplicates.
0.5 - Add varGetLocalVariableList().
0.3 - Change handling of invalid BOOL values.
0.2 - Minor change to varGetInfo() implementation. No change to API.
0.1 - Includes varGetInfo(), varGetValue(), and varSetValue().
