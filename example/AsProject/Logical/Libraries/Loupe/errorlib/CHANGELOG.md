0.23.3 - Update dependency versions

0.23.2 - Update dependency versions

0.23.1 - Migrate from AsString to AsBrStr

0.23.0 - Changed acknowledgement behavior on invalid errors to ignore it instead of setting a nuisance error.

0.22.1 - Added if unacknowledged error is still active

0.22.0 - Move to new logging from LogThat library.
		BACKWARDS COMPATIBILITY ISSUES!

0.21.0 - Updated doc.
		Changed order of fn inputs.
		Added 'Internal' to the name of internal functions.
		Consolidated AddError() and AddErrorExt() functions.
		BACKWARDS COMPATIBILITY ISSUES!

0.20.0 - Changed acknowledge behavior. Acknowledge commands will be sent out for every error, not 
			just after all errors have been acknowledged for a given source.

0.19.0 - Changed behavior when pError == 0 to set error, add error to list, and log.

0.18.0 - Changed display string format.

0.17.0 - Removed Documentation folder to support 3.0.81.

0.16.0 - Added logging to errcolAcknowledge().
			Changed internal functions wrt ErrorID.
			Added errcolAddErrorExt() user function to add an error with extended information.

0.15.0 - Added OUT.ErrorCount.
			Changed internal error source storage architecture wrt SourceName.
			Added SourceTask to error source and error info.
			Changed implementation of errcolAddSourceByName().
			Added IN.CFG.ErrorCollectorSourceName.

0.14.0 - Removed ErrorLevel handling.
			Added logging to errcolAddError() function.
			Allowed multiple error collectors to write to the same logger.
			Tweaked display string format.

0.13.0 - Added errcolAddError() user function

0.12.0 - Added configurability for error item element names.

0.11.0 - Updated dependencies for HMITools library.

0.10.0 - Added search function

0.9.0 - Updated documentation

0.8.0 - Added documentation
		Changed to use GenerateTimestamp function from StringExt library
		Changed CFG inputs from 'Logbook' to 'Logger'
		Changed from 'EnableLogging' to 'DisableLogging'
		Added default CFG values

0.7.0 - Tested version of 0.06.1
		Next release candidate

0.6.1 - Changed error behavior of errcolAddSourceByName
		Fixed bug with init error in AddSource fns

0.6.0 - Tested version of 0.05.1
		First release candidate

0.5.1 - Tweaked Fn_HMI_Cyclic() for performance
		Added errcolRefreshHMIDisplay() and changed refresh behavior

0.5.0 - Tested version of 0.04.1

0.4.1 - Added timestamp to ErrorInfo and HMI display string

0.4.0 - Tested version of 0.03.1

0.3.1 - Changed acknowledge behavior from "possible" to "required" as per the lingo of VC

0.3.0 - Tested version of 0.02.1

0.2.1 - Cat'ed VarName onto end of syslib errors

0.2.0 - Tested version of 0.01.1

0.1.1 - Added Listbox.MaxDP handling

0.1.0 - First tested version. Still needs some HMI tweaking (Min and Max Index DPs on listbox)

0.0.2 - Second prototype (agreed upon behavior)

0.0.1 - First prototype
