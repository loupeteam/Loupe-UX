![Automation Resources Group](http://automationresourcesgroup.com/dist/img/logos/_headerLogo/ARG-Logo-Black-RGB.png)

# FIOWrap Library
The FIOWrap library provides a simple, intuitive interface for opening and saving files and managing files and directories..

Files offer power fail safe data storage. They have the advantage over permanent memory that they are also protected against battery failure. The FIOWrap library provides a clean interface for the most common file operations. Any state machines necessary to perform these operations are built into the library and do not need to be implemented by the application developer.

# Usage
The FIOWrap functionality can be integrated into any project using a data structure and a function call. For an example of how to use this in a project, please see the ARG Automation Studio Starter Project at [https://github.com/autresgrp/StarterProject](https://github.com/autresgrp/StarterProject).

## FIOWrapper

### Initialization
To access files via Automation Runtime, a file device must be configured in the system configuration. To use the FIOWrap functionality, a variable must be declared of type **FIOWrap_typ**.

### Cyclic Operation
To handle files cyclically, the **FIOWrapFn_Cyclic()** must be called in the CYCLIC routine of your program, once every scan, unconditionally. This function should not be called on the same FIOWrapper variable more than once per scan.

	FIOWrapFn_Cyclic( FIOWrapper );

The FIOWrapper can then be used as an interface for higher level programs.

	IF( OpenRecipeFile )THEN
	
		OpenRecipeFile:=	0;

		FIOWrapper.IN.PAR.FileDevice:=	'CF_User';
		FIOWrapper.IN.PAR.FileName:=	'rec1.rec';
		FIOWrapper.IN.PAR.pData:=		ADR(Recipe);
		FIOWrapper.IN.PAR.len:=			SIZEOF(Recipe);

		FIOWrapper.IN.CMD.Open:=		1;

	END_IF

	IF( SaveRecipeFile )THEN

		SaveRecipeFile:=	0;

		FIOWrapper.IN.PAR.FileDevice:=	'CF_User';
		FIOWrapper.IN.PAR.FileName:=	'rec1.rec';
		FIOWrapper.IN.PAR.pData:=		ADR(Recipe);
		FIOWrapper.IN.PAR.len:=			SIZEOF(Recipe);

		FIOWrapper.IN.CMD.SaveAs:=		1;

	END_IF

	IF( FIOWrapper.OUT.STAT.Done )THEN
		FIOWrapper.IN.CMD.Open:=		0;
		FIOWrapper.IN.CMD.SaveAs:=	0;
	END_IF

No formatting is performed when opening or saving files. That is, data is not converted to or from ASCII text by this library. For opening or saving formatted text files, please check the CSVWrap or CFGFileLib libraries.

## FIOManage

### Initialization
To use the FIOManage functionality, a variable must be declared of type **FIOManage**.

### Cyclic Operation
To manage files/directories cyclically, the **FIOManageFn_Cyclic()** must be called in the CYCLIC routine of your program, once every scan, unconditionally. This function should not be called on the same FIOManage variable more than once per scan.

	FIOManageFn_Cyclic( FIOManage );

The FIOManage can then be used to manage the number of files/directories.

		IF( Scan )THEN

			FIOManage.IN.PAR.FileDevice := 'Recipes';
			FIOManage.IN.PAR.ItemName := 'test';
			FIOManage.IN.PAR.MaxNumItems := 5;
			FIOManage.IN.PAR.Mode := MANAGE_FILE_MODE;

			FIOManage.IN.CMD.Scan:= 1;

		ELSIF( FIOManage.OUT.STAT.Done OR FIOManage.OUT.STAT.Error )

			FIOManage.IN.CMD.Scan:= 0;

		END_IF

## Reference

### FIOWrapper Data Structure
The main data structure of the FIOWrap library is the FIOWrapper structure (FIOWrap_typ datatype). This provides the interface to higher level programs and also stores all necessary internal information. It is divided into inputs (FIOWrapper.IN), outputs (FIOWrapper.OUT), and internals (FIOWrapper.Internal).

#### Inputs
The FIOWrapper inputs are divided into commands (IN.CMD) and parameters (IN.PAR). Commands are used to initiate operations, and parameters determine how the commands will be processed.

##### Commands
* **Open** - Read data from a file.
* **SaveAs** - Save data to a file.
* **AppendToFile** - Append data to the end of a file.
* **Delete** - Delete a file.
* **AcknowledgeError** - Acknowledge any errors that occur.

##### Parameters
* **FileDevice** - The file device where the file is located.
* **FileName** - The name of the file, including any file extension.
* **Suffix** - An optional string to append to the older file when creating a new file of the same name. If Suffix is not populated, a time stamp will be appended by default.
* **pData** - Starting address of the data buffer. For Open operations, data will be copied from the file to pData. For SaveAs and AppendToFile operations, data will be copied from pData to the file.
* **len** - Length of the data to be copied, in bytes.
* **offset** - Starting offset within the file, in bytes. For Open and SaveAs operations, data will be copied from or to the file starting at **offset**. For AppendToFile operations, the offset to the end of the file is obtained automatically and the **offset** input is ignored.
* **MaxFileSize** - The maximum file size allowed during AppendToFile operations. If this file size would be exceeded by appending the data, the data is not written to the file, and an error is issued. This input is ignored during Open and SaveAs operations.
* **MultiFile** - When true, allows additional files to be created when append to a file would exceed the MaxFileSize.

#### Outputs
The FIOWrapper outputs contain status information (OUT.STAT).

* **Busy** - Operation is currently being processed.
* **Done** - Operation completed successfully. **Done** is reset when the input command is reset.
* **Error** - Error occurred during operation. **Error** is reset with the **AcknowledgeError** command.
* **ErrorID** - Current error ID number.
* **ErrorString** - Current error text information.
* **ErrorLevel** - Current error level.
* **ReadyForCMD** - The FIOWrapper is ready to accept a new command. It is equivalent to `NOT(Busy OR Done OR Error)`.
* **NewFile** - A file was created during the last operation
* **FileLen** - Length of the file currently being operated on in bytes.


### FIOManage Data Structure
The FIOManage structure provides the interface to for managing both directories and files.

#### Inputs
The FIOManage inputs are divided into commands (IN.CMD) and parameters (IN.PAR). Commands are used to initiate operations, and parameters determine how the commands will be processed.

##### Commands
* **Scan** - Look through the working directory for files/directories that match the ItemName and keep only the newest, up to MaxNumItems, of either files or directories. A max of 10 files can be deleted per scan.
* **DeleteAll** - Delete all the files in your current Filedevice and Directory.
* **AcknowledgeError** - Acknowledge any errors that occur.

##### Parameters
* **FileDevice** - The file device where the file is located.
* **Directory** - The subdirectory to manage, can be left blank unless the file device is the root folder.
* **ItemName** - The name of the file (optional extension) or directory to be managed. The name acts as a filter, any file/directory that begins with ItemName will be managed. To filter all files/directories set ItemName := '*'. ItemName := '' is not valid.
* **MaxNumItems** - The max number of files kept that match the ItemName filter. 
* **Mode** - Allows choosing whether to manage files, directories, or both. Supported modes are: fiFILE(0), fiDIRECTORY(1), and fiBOTH(2). FIOManage manages files by default.

#### Outputs
The FIOWrapper outputs contain status information (OUT.STAT).

* **Busy** - Operation is currently being processed.
* **Done** - Operation completed successfully. **Done** is reset when the input command is reset.
* **Error** - Error occurred during operation. **Error** is reset with the **AcknowledgeError** command.
* **ErrorID** - Current error ID number.
* **ErrorString** - Current error text information.
* **ErrorLevel** - Current error level.
* **ReadyForCMD** - The FIOManage is ready to accept a new command. It is equivalent to `NOT(Busy OR Done OR Error)`.

## Error ID Numbers
* 20700 - fiERR\_INVALID\_PATH - Invalid path.
* 20701 - fiERR\_DATA\_SIZE - Data length is too small (DirRead).
* 20702 - fiERR\_NO\_MORE\_ENTRIES - No more file handles available.
* 20703 - fiERR\_NOT_SUPPORTED - System error.
* 20704 - fiERR\_INVALID_TYP - Invalid type.
* 20705 - fiERR\_EXIST - File already exists.
* 20706 - fiERR\_ACCESS - Access not possible with the desired mode.
* 20707 - fiERR\_MODE - Illegal mode.
* 20708 - fiERR\_FILE\_NOT\_FOUND - File not found. Check IN.PAR.FileName.
* 20709 - fiERR\_FILE_DEVICE - File device not found. Check IN.PAR.FileDevice.
* 20710 - fiERR\_SPACE - Not enough memory to write file.
* 20711 - fiERR\_SEEK - Invalid file offset.
* 20712 - fiERR\_FILE - File not allowed.
* 20713 - fiERR\_LESS\_VIRTUAL\_MEMORY - Not enough memory to write file.
* 20714 - fiERR\_COM\_FILE\_OPEN - System error.
* 20715 - fiERR\_COM\_FILE\_CLOSE - System error.
* 20716 - fiERR\_COM\_FILE\_READ - System error.
* 20717 - fiERR\_COM\_FILE\_WRITE - System error.
* 20718 - fiERR\_COM\_FILE\_IOCTL - System error.
* 20719 - fiERR\_DATA - Invalid parameter. Check IN.PAR.pData.
* 20720 - fiERR\_ASYNC_MANAGER - System error.
* 20721 - fiERR\_FILE\_NOT\_OPENED - File not opened.
* 20722 - fiERR\_INVALID_DIRECTORY - Invalid directory. Check IN.PAR.FileDevice and IN.PAR.FileName.
* 20723 - fiERR\_DIR\_NOT\_EXIST - Directory does not exist. Check IN.PAR.FileDevice and IN.PAR.FileName.
* 20724 - fiERR\_DIR\_NOT\_EMPTY - Directory is not empty.
* 20725 - fiERR\_DIR\_ALREADY\_EXIST - Directory already exists.
* 20726 - fiERR\_DETMEMINFO - System error.
* 20727 - fiERR\_NOT\_ENOUGH\_FREEMEM - Not enough memory to write file.
* 20728 - fiERR\_DIR\_INVALID\_HANDLE - System error.
* 20729 - fiERR\_PARAMETER - System error.
* 20730 - fiERR\_DEVICE\_ALREADY\_EXIST - Device already exists.
* 20731 - fiERR\_DEVICE\_INVALID\_HANDLE - Invalid device handle.
* 20732 - fiERR\_NETIO\_IP\_UNEQUAL - IP address error. Check hostname.
* 20796 - fiERR\_INIT - System error.
* 20797 - fiERR\_DEVICE\_DRIVER - System error.
* 20798 - fiERR\_DEVICE\_MANAGER - File device error. Check IN.PAR.FileDevice.
* 20799 - fiERR\_SYSTEM - System error.

* 50000 - FIOWRAP\_ERR\_INVALIDOP - Internal error.
* 50001 - FIOWRAP\_ERR\_INVALIDFILTER - Input required for IN.PAR.ItemName. Set IN.PAR.ItemName := '*' to mamange all files/directories.
* 50002 - FIOWRAP\_ERR\_INVALIDDIR - Cannot manage in root directory. Check IN.PAR.FileDevice and IN.PAR.FileDirectory.
* 50003 - FIOWRAP\_ERR\_MAXFILESIZE - Error while appending: maximum file size would be exceeded.

Error ID numbers 20700 - 20799 are passed on directly from the FileIO library. For additional information on these errors, please see the Automation Studio Online Help.