![Automation Resources Group](http://automationresourcesgroup.com/images/arglogo254x54.png)

#CSVFileLib Library
The CSVFileLib library provides a simple, intuitive interface for writing and reading variable values to and from comma separated value (CSV) files.

Files offer power fail safe data storage. They have the advantage over permanent memory that they are also protected against battery failure. Formatting files into a plain text CSV format allows them to be easily edited externally and then imported to the machine. The ability to open and save CSV files can be very useful for machine configuration and recipe storage, in particular. 

Issues often arise during machine commissioning that are not apparent during development. Also, customer specific requirements can surface at any time during a machine’s lifecycle. Flexible machine configuration can provide solutions to these kinds of problems without requiring a machine software update or an engineer site visit.

The CSVFileLib library allows you to store machine configuration information in a plain text file that can be used to set the values of variables on the machine. And, since the file contains the names of the variables to be written, adding a new configuration item is as simple as adding a line of text to the file; nothing else needs to be modified, and no software updates are required.

The library is also robust to errors that might occur while handling  CSV files. If a line in the file cannot be processed for any reason (for example, a mistyped variable name), that error is logged, and the next line is processed. The log information is available in a text file that can be useful in correcting the error. 

It is also possible to save current variable values back to a CSV file, allowing you to implement machine configuration or recipe editing interfaces on the machine itself. 

The library interface and file format were carefully designed to be as straight-forward and powerful as possible, allowing this functionality to be easily integrated into any project.

#Usage
The CSVFileLib functionality can be integrated into any project using a data structure and two function calls. HMI functionality requires another data structure and function call, as well as corresponding Visual Components elements. For an example of how to use this in a project, please see the ARG Automation Studio Starter Project at [https://github.com/autresgrp/StarterProject](https://github.com/autresgrp/StarterProject).

##Initialization
To access files via Automation Runtime, a file device must be configured in the system configuration. To use the CSVFileLib functionality, a variable must be declared of type **CSVFileMgr_typ**. This variable must then be initialized in the INIT routine of your program. Initialization consists of optionally setting configuration settings and calling the **CSVFn_Init()** function.

	CSVFn_Init( CSVFileMgr );

##Cyclic Operation
The **CSVFn_Cyclic()** function must be called in the CYCLIC routine of your program once every scan, unconditionally. This function should not be called on the same CSVFileMgr variable more than once per scan.

	CSVFn_Cyclic( CSVFileMgr );

The CSVFileMgr structure can then be used as an interface for higher level programs.

	IF( LoadConfiguration )THEN
		LoadConfiguration:=				0;
		CSVFileMgr.IN.PAR.FileDevice:=	'CF_User';
		CSVFileMgr.IN.PAR.FileName:=	'config.csv';
		CSVFileMgr.IN.CMD.OpenFile:=	1;
	END_IF
	
	IF( UpdateConfiguration )THEN
		UpdateConfiguration:=			0;
		CSVFileMgr.IN.PAR.FileDevice:=	'CF_User';
		CSVFileMgr.IN.PAR.FileName:=	'config.csv';
		CSVFileMgr.IN.CMD.UpdateFile:=	1;
	END_IF
	
	IF( OpenRecipe )THEN
		OpenRecipe:=					0;
		CSVFileMgr.IN.PAR.FileDevice:=	'CF_User';
		CSVFileMgr.IN.PAR.FileName:=	'Recipe.csv';
		CSVFileMgr.IN.CMD.OpenFile:=	1;
	END_IF
	
	IF( SaveRecipe )THEN
		SaveRecipe:=						0;
		CSVFileMgr.IN.PAR.FileDevice:=		'CF_User';
		CSVFileMgr.IN.PAR.FileName:=		'NewRecipe.csv';
		CSVFileMgr.IN.PAR.VariableList[0]:=	'myGlobalRecipe';
		CSVFileMgr.IN.CMD.SaveVariableListToFile:=	1;
	END_IF
	
	IF( DeleteRecipe )THEN
		DeleteRecipe:=					0;
		CSVFileMgr.IN.PAR.FileDevice:=	'CF_User';
		CSVFileMgr.IN.PAR.FileName:=	'OldRecipe.csv';
		CSVFileMgr.IN.CMD.DeleteFile:=	1;
	END_IF
	
	IF( CSVFileMgr.OUT.STAT.Done )THEN
		CSVFileMgr.IN.CMD.OpenFile:=	0;
		CSVFileMgr.IN.CMD.UpdateFile:=	0;
		CSVFileMgr.IN.CMD.SaveVariableListToFile:=	0;
		CSVFileMgr.IN.CMD.DeleteFile:=	0;
	END_IF

##File Format
The file format used by the CSVFileLib library is

	//Variable Name, Value, Optional Description
	myGlobalVar, 1.0, This is a global variable
	myTask:myLocalVar, 2.0, This is a local variable
	myGlobalString, "", This is how to store an empty string value

Commas are not allowed in the variable name or value fields, as they will be misinterpreted as separators. Commas are allowed in the optional item description field, however. Any line beginning with '//' will be considered a comment, and the library is flexible with respect to white space padding in the fields (meaning tabs and spaces can be used to align columns if desired). Leading and trailing quotation marks will be ignored, with the exception that they are necessary if you wish to store an empty string value. The file can be generated and modified using any plain text editor or spreadsheet program which supports CSV files.

##HMI Integration
If file handling must be done by a machine operator, the HMI interface can be used. The **CSVFileMgr_HMI** structure is designed to make HMI development as simple as possible. The structure elements are organized by HMI object (button, dialog box, etc.), and the basic element names are consistent with Visual Components property names. The **CSVFn_HMI_Cyclic()** function handles setting and resetting the CSVFileMgr inputs appropriately. It also takes care of locking the HMI buttons if the CSVFileMgr is busy. This architecture makes it very easy to access files both from programs (on machine startup, for example) and from the HMI.

For an example of a fully implemented HMI interface, please see the ARG Automation Studio Starter Project at [https://github.com/autresgrp/StarterProject](https://github.com/autresgrp/StarterProject).

#Reference

##Log File
Certain log information is recorded during every file operation and stored in a plain text file with the name specified in **IN.CFG.LogFileName**. If no name is given, then the default file name is **.csvlog**. This log information can be very useful for locating any errors with the CSV file. If multiple **CSVFileMgr** variables access the same file device, then different log file names should be specified for each. This ensures that different **CSVFileMgr** variables do not try to access the same file at the same time.

##CSVFileMgr Data Structure
The main data structure of the CSVFileLib library is the CSVFileMgr structure (CSVFileMgr_typ data type). This provides the interface to higher level programs and also stores all necessary internal information. It is divided into inputs (CSVFileMgr.IN), outputs (CSVFileMgr.OUT), and internals (CSVFileMgr.Internal).

###Inputs
The CSVFileMgr inputs are divided into commands (IN.CMD), parameters (IN.PAR), and configuration settings (IN.CFG). Commands are used to initiate operations, and parameters and configuration settings determine how the commands will be processed. The difference between parameters and configuration settings is that configuration settings are generally set only once, while parameters might be set any time a command is issued.

####Commands
* **OpenFile** - Read variable values from a file.
* **UpdateFile** - Update an existing file with current variable values. The variables to be written to the file are taken from the file itself.
* **SaveVariableListToFile** - Write variable values to a file. The variables to be written to the file are taken from **IN.PAR.VariableList**.
* **DeleteFile** - Delete a file.
* **AcknowledgeError** - Acknowledge any errors that occur during file operations.

####Parameters
* **FileDevice** - The file device where the file is located.
* **FileName** - The name of the file, including any file extension.
* **VariableList** - The list of variable names to write to the file for **SaveVariableListToFile** operations. It is possible to write basic variables, arrays, and structures to the file. The list will only be processed until the first empty variable name is found, so the **VariableList** must not be sparse.
* **Prefix** - This will be added to the beginning of any variable names read from a file, and removed from the beginning of any variable names saved to a file. This makes it possible to save the contents of one variable to a file and load them to a different variable later. **Prefix** should always be the name of a structure. When using a **Prefix** for **SaveVariableListToFile** operations, all of the items in **VariableList** should begin with **Prefix**.

####Configuration Settings
* **MaxFileSize** - The maximum file size that can be handled, in bytes. The default value is 100000 bytes.
* **MaxLineLength** - The maximum length of one line in the file, including newline characters. The default value is 500 characters.
* **MaxLinesPerScan** - The maximum number of lines that will be processed in one scan. The default value is 500 lines.
* **VerboseLog** - If **VerboseLog** is set to 0, then only errors and final status information will be written to the log file. If **VerboseLog** is set to 1, then additional status information will be written to the log file, including what is parsed from the file and additional variable information. The default value is 0.
* **LogFileName** - The file name to use for the log file. If no name is given, then the default log file name is **.csvlog**.
* **DisableLogging** - Disable logging of file actions in the AR logging system when set to 1. The default value is 0.
* **LoggerName** - Name of the logger to use. For details, see the help for the LogThat, BRSE_ARL, and AsArLog libraries. The default value is 'Files.'

###Outputs
The CSVFileMgr outputs contain status information (OUT.STAT).

* **Busy** - Operation is currently being processed.
* **Done** - Operation completed successfully. **Done** is reset when the input command is reset.
* **Error** - Error occurred during operation. **Error** is reset with the **AcknowledgeError** command.
* **ErrorID** - Current error ID number.
* **ErrorString** - Current error text information.
* **ErrorLevel** - Current error level.
* **ErrorState** - State in which the error occurred.
* **State** - Current state of the operation.

##CSVFileMgr_HMI Data Structure
The CSVFileMgr_HMI data structure is organized based on HMI objects. It is divided into main page elements (CSVFileMgr_HMI.Main), file dialog box elements (CSVFileMgr_HMI.DialogBox), delete confirmation, progress, and error status elements (CSVFileMgr_HMI.DeleteConfirm, CSVFileMgr_HMI.Progress, CSVFileMgr_HMI.ErrorStatus), text snippets (CSVFileMgr_HMI.TextSnippets), and internals (CSVFileMgr_HMI.Internal). 

This data structure relies on basic data types defined in the **HMI_Basic** library. Please see the **HMI_Basic** documentation for a description of these fundamental types.

###Main Page Elements
These elements are mapped to items on the main file handling page of the HMI.

* **OpenFile** - Data points for the Open button.
* **UpdateFile** - Data points for the Update button.
* **SaveVariableListToFile** - Data points for the Save button.
* **DeleteFile** - Data points for the Delete button.

###Dialog Box Layer Elements
These elements are mapped to items on a layer containing the file action (Open, Update, Save, Delete) dialog box.

* **StatusDP** - Status data point used for controlling layer visibility.
* **FileNameList** - List of files on the file device to connect to the file name listbox.
* **FileNameListbox** - Data points for the file name listbox.
* **FileNameTextInput** - Data points for the file name input box.
* **Action** - Data points for the Action button used to confirm Open, Update, Save, and Delete operations.
* **Cancel** - Data points for the Cancel button.
* **Refresh** - Data points for the Refresh button used to refresh the file list.
* **PageUp** - Data points for the Page Up button.
* **PageDown** - Data points for the Page Down button.

###Delete Confirmation Layer Elements
These elements are mapped to a layer confirming file deletion.

* **StatusDP** - Status data point used for controlling layer visibility.
* **Yes** - Data points for the Yes button (confirming file deletion).
* **No** - Data points for the No button (cancelling file deletion).

###Progress Layer Elements
These elements are mapped to a layer showing progress while opening, saving, or deleting a file.

* **StatusDP** - Status data point used for controlling layer visibility.
* **Progress** - Counter showing progress. Counts up indefinitely until the operation is done.

###Error Status Layer Elements
These elements are mapped to a layer showing error status.

* **StatusDP** - Status data point used for controlling layer visibility.
* **AcknowledgeError** - Data points for Acknowledge Error button.

###Text Snippets
These elements are mapped to text snippets used by some of the objects above.

* **FileName** - File name used for delete confirmation layer.
* **Action** - Name of action to be used on dialog box layer (Open, Save, Delete).
* **ProgressLabel** - Label for progress layer (Opening…, Saving…, Deleting…)
* **ErrorID** - Error ID number for error status layer.
* **ErrorString** - Error text for error status layer.

##Error ID Numbers
* 50000 - CSV_ERR_INVALIDINPUT - Invalid function input.
* 50002 - CSV_ERR_MEMALLOC - Error allocating memory. Check IN.CFG.MaxFileSize and MaxLineLength.
* 50003 - CSV_ERR_NOTINITIALIZED - CSVFileMgr is not initialized. Call CSVFn_Init() in the initialization routine of your task.
* 50004 - CSV_ERR_LINEFAILURE - Error occurred while parsing file. Check log for details.
* 50005 - CSV_ERR_BUFFERFULL - Maximum file size reached. Check IN.CFG.MaxFileSize.