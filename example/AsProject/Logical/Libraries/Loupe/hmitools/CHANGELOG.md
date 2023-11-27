0.11.4 - Migrate from AsString to AsBrStr

0.11.3 - Refresh file list when changing directories

0.11.2 - Refresh DirectoryFub if filter changes. 

0.11.1 - Fix some bugs with DirectoryFub().
			Change DirectoryFub() refresh rate from 1s to 60s (perhaps temporarily).
			Add explicit Refresh to DirectoryFub() and HMIFileBrowse().

0.11.0 - 20151030 - Added support for dataobjects in HMIFileBrowse().

0.10.4 - 20151007 - Listbox fub find index is more strict. Only selects index if it matches exaclty.

0.10.3 - 20150914 - Fixed some issues in log viewer that cause IEC check library to complain.

0.10.2 - 20150805 - Option to show or hide hidden files.

0.10.1 - 20150701 - Fixed bug in HMI File Browse that causes the file selection to go nuts if a filter is applied.

0.10.0 - 20150601 - Added confirm bit to buttons. 

0.09.6 - 20140108 - Moved recipe manager logging to LogThat functions

0.09.5 - 20131115 - Modified recipe manager to do logging.
				  - Added a modified status to recipe manager.

0.09.4 - 20131111 - DirectoryFub: Will filter file extensions only of exact match. 
					HMI_File_Browse: Internal vars placed into "Internal" structure.

0.09.3 - 20131108 - Added RecipeMgr() fn. Allows for simple structure copies through VC, and will integrate with the CSVFileLib

0.09.2 - 20131106 - FUB rename: HMIDirectory to HMIFileBrowse

0.09.1 - 20131105 - Directoryfub changes:
				  - If internal fubs return busy, jump out of for loop.

0.09.0 - 20131104 - HMIDirectory changes:
				  - Allow the developer to not use inputs that are optional.
				  - Show the applied filter in the status
				  - " " in filter will clear filter.

0.08.9 - 20130909 - ListSelection resets selected value to -1 when enable is false.

0.08.8 - 20130812 - Updated HMIDirectory for file/directory browsing

0.08.7 - 20130729 - Updated RingBufLib dependency version.

0.08.7 - 20130802 - Added index datapoint to HMI_Button_typ

0.08.6 - 20130702 - Updated for new RingBufLib functions.

0.08.5 - 20130701 - Changed dependency from RingBufST to RingBufLib

0.08.4 - 20130628 - Get info will no longer flash error and status if it can't find the logger.
				  - Better handling of switching between loggers so that there aren't random entries from other loggers
				  - LogViewHMI will display error from LogView as first item in list
				  
0.08.3 - 20130522 - Removed HMI_STRING derived type, as it is incompatible with AS 3.0.81.

0.08.2 - 20130401 - Merged TrendLib 1.90.1 into HMITools.

0.08.1 - 20121227 - Merged with HMITools library.

0.07.0 - 20120416 - Added HMI_Scale_typ

0.06.0 - 20120330 - Added PageSize to HMI_Listbox_typ

0.05.0 - 20120330 - Changed STRLEN_IN from 80 to 260

0.04.0 - 20120104 - Release version of 0.03.3.

0.03.3 - 20111214 - Minor tweaks to data types. CHECK COMPATIBILITY.

0.03.2 - 20111111 - Added CalibrationStateDP to HMI_Basic_typ.

0.03.1 - 20111019 - Changed datatypes to be consistent with VC names.
			Removed UserLevel from HMI_Basic_typ.

0.03.0 - 20110801 - Release version of 0.02.2. Includes toggle tabs and external page changes.

0.02.2 - 20110729 - First try at external page changes with toggle tabs.

0.02.1 - 20110531 - First try at toggle tab CMDs.
			Tested, but external page changes are impossible at this point.

0.02.0 - 20110518 - Release version of 0.01.3.
			Still need to make tab CMDs toggles instead of sets. This is going to be tricky.

0.01.3 - 20110518 - Third crack at generic tab fns

0.01.2 - 20110518 - Second crack at generic tab fns
			Added HMI_Basic_typ

0.01.1 - 20110517 - First crack at generic tab fns
			Added HMI_FindCurrTab function to find current primary and secondary tab

0.01.0 - 20110509 - Release version of 0.00.4

0.00.4 - 20110503 - Changed library name from HMI_Types to HMI_Basic
			Added HMI_Show, HMI_Hide, HMI_Lock, and HMI_Unlock functions
			Changed all "Visible" elements to "StatusDP"
			Removed almost all "Lock" elements
			Added HMI_SetFocus, HMI_ResetFocus, and HMI_OpenTouchpad functions

0.00.3 - 20110325 - Added Completion field to HMI_Listbox_typ

0.00.2 - 20110318 - Changed name from HMITypLib to HMI_Types. 
			This denotes that the library contains ONLY datatypes, no functions.
			Added HMI_ to all datatypes (Button_typ -> HMI_Button_typ).
			Changed 'Datapoint' to 'DP' (ColorDatapoint -> ColorDP).

0.00.1 - 20110310 - First version