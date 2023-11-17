1.2.2 - Increase maximum size of variable list from 50 to 100

1.2.1 - Fix internal variable usage

1.2.0 - Add configurable number of Significant Figures for LREALs

1.1.0 - Add LREAL support
	Add '-lc' build option requirement

1.0.4 - Update to support new logThat 

1.0.3 - Update dependencies 

1.0.2 - Update dependencies 

1.0.1 - Support both new and old revInfo var names for header info

1.0.0 - Add support for quoted string values
		Change output format to use single quotes for strings instead of double 
		quotes
		Increase number of characters stored in variable values

0.16.0 - Add feature to use a global Variable to look up type but write to a 
		user supplied memory area

0.15.1 - Migrate from AsString to AsBrStr

0.15.0 - 20160322 - Update HMI to be a bit more user friendly

0.14.9 - 20150925 - Fix bug with temp file in folders

0.14.8 - 20150805 - Make temp file hidden

0.14.7 - 20150701 - Fix a version dependancy 

0.14.6 - 20150122 - Change logging to use new LogThat library
					While saving, CSVFn_HMI_Cyclic.c now appends the selected 
					file extension "FileExtSelection" from HMIFileBrowse FUB 
					if no extension is found in the FileSelection
					Change default max file size to 65536 to fix a complex 
					problem
					Add revision information to file header

0.13.0 - 20130730 - Add csvOpenFile_Init() fn

0.12.0 - 20130627 - Add logging functionality

0.11.0 - 20130114 - Update dependencies on HMITools library

0.10.0 - 20121022 - Add support for enums

0.9.0 - 20120803 - Update documentation to reflect changes to inputs
					Change the temporary filename to include the input filename 
					to fix the same problems as for the log file in 0.08.2
					Have a CFG input for the log file name - this fixes some 
					problems if	multiple CSV objects are trying to write to the 
					log file around the same time
					Prohibit empty file name input

0.8.0 - 20120420 - Add prefixes

0.7.0 - 20120410 - Make csvProcessData() reentrant (asynchronous)

0.6.0 - 20120405 - Change implementation to get better performance
					Add support for TIME and DATE_AND_TIME variables as integers

0.5.0 - 20120322 - Start HMI functionality
					Add DeleteFile CMD and functionality
					First full release candidate

0.4.0 - 20120320 - Change MaxIterations to MaxLines and retested
					Update documentation
					Add functionality to save variables
					Add new data types
					Change name to 'CSVFileLib'
					Change command names
					Change nomenclature from cfg/cfm to csv throughout library

0.3.0 - 20120113 - NEW FILE FORMAT
					INCOMPATIBLE WITH ALL OLDER VERSIONS OF CFGFileLib!!!

0.1.0 - 20110613 - First version
