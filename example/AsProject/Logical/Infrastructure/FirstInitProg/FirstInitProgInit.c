/********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * Program: FirstInitProg
 * File: FirstInitProgInit.c
 * Author: ScismD
 * Created: January 07, 2014
 ********************************************************************
 * Implementation of program FirstInitProg
 ********************************************************************/

#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
#include <AsDefault.h>
#endif

#include <string.h>

void _INIT FirstInitProgInit(void)
{

	// Check for simulation
	// This is a DevLink using a Windows share which is not supported by ARsim
	// We use this instead of Diag function to support older CPU's
	simCheckDevLink.enable = 1;
	simCheckDevLink.pDevice = (UDINT)&("SimCheck");
	simCheckDevLink.pParam = (UDINT)&("/SIP=127.0.0.1 /PROTOCOL=cifs /SHARE=testfolder /USER=max /PASSWORD=passw");
	
	DevLink(&simCheckDevLink);
	
	if (simCheckDevLink.status == ERR_NOTIMPLEMENTED) {
		gSimulation = 1;
	}
	
	// Initialize User Loggers
	createLogInit("Errors", 1000000, arEVENTLOG_PERSISTENCE_VOLATILE);	
	createLogInit("Files", 1000000, arEVENTLOG_PERSISTENCE_VOLATILE);	
	createLogInit("Application", 1000000, arEVENTLOG_PERSISTENCE_VOLATILE);	

	// Initialize error collector
	ErrorCollectorFn_Init(&gErrorCollector);

	// Link file devices
	//-------------------------------------------------------
	
	// This is NOT done in the CPU configuration because when using CPU simulation
	// you cannot have separate file devices for simulation mode,
	// and you cannot unlink devices that were entered in the CPU configuration

	// Set up file device names
	strcpy(fileDevice[0], "CF_User");
	strcpy(fileDevice[1], "CNC_PrgDir");
	strcpy(fileDevice[2], "Recipes");
	strcpy(fileDevice[3], "permBackup");

	// Set up file device paths
	if (gSimulation) {
		strcpy(directory[0], "C:\\ARSimUser\\Sandbox");
		strcpy(directory[1], "C:\\ARSimUser\\Sandbox\\CNC");
		strcpy(directory[2], "C:\\ARSimUser\\Sandbox\\Recipes");
		strcpy(directory[3], "C:\\ARSimUser\\Sandbox\\PermData");		
	} else {
		// TODO: This won't work (nicely) with ARwin
		strcpy(directory[0], "F:\\");
		strcpy(directory[1], "F:\\CNC");
		strcpy(directory[2], "F:\\Recipes");
		strcpy(directory[3], "F:\\PermData");	
	}	
	
	// Link file devices
	for (i = 0; i < NUM_FILEDEVICES; i++) {
		
		strcpy(parameters[i], "/DEVICE=");
		strcat(parameters[i], directory[i]);
		
		fileDeviceDevLink[i].enable = 1;
		fileDeviceDevLink[i].pDevice = (UDINT)&(fileDevice[i]);
		fileDeviceDevLink[i].pParam = (UDINT)&(parameters[i]);
		
		DevLink(&fileDeviceDevLink[i]);
		
		if (fileDeviceDevLink[i].status != 0)
			errcolAddError((UDINT)"File Devices", (UDINT)"Error linking file device", fileDeviceDevLink[i].status, 0, &gErrorCollector);

	}
		
	// Initialize Persisters
	//-------------------------------------------------------
	
	// Working variables
	
	// Machine configuration
	varGetVariableList((UDINT)"Configuration", (UDINT)&(gPersister[PERM_CONFIGURATION].IN.WorkingVariableList));
				
	// Home data
	strcpy(gPersister[PERM_HOME_DATA].IN.WorkingVariableList[0],"gEndlessPosition");
	
	// Axis pars
	// TODO: I think we should move away from gMotorBasic inside persisters and towards local Configuration variables
	#ifdef NUM_MOTOR 	// Only execute this loop if NUM_MOTOR is defined by ServoControl
	for (i = 0; i < NUM_MOTOR; i++) {
		brsitoa(i, (UDINT)indexString);
		strcpy(axisString, "gMotorBasic");
		appendArrayIndex(i, (UDINT)axisString);
		strcat(axisString, ".IN.PAR");
		if (i <= PERSIST_MAI_VARLIST) {
			strcpy(gPersister[PERM_AXIS_PARS].IN.WorkingVariableList[i], axisString);
		} else {
			errcolAddError((UDINT)"Perm Data", (UDINT)"Too many axes for one persister.", 0, 0, &gErrorCollector);
			break;
		}
	}
	#endif

	// Permanent variables
	gPersister[PERM_CONFIGURATION].IN.pPersistentVariable = (UDINT)&gPermConfiguration;
	gPersister[PERM_CONFIGURATION].IN.sizeofPersistentVariable = sizeof(gPermConfiguration);

	gPersister[PERM_HOME_DATA].IN.pPersistentVariable = (UDINT)&gPermHomeData;
	gPersister[PERM_HOME_DATA].IN.sizeofPersistentVariable = sizeof(gPermHomeData);

	gPersister[PERM_AXIS_PARS].IN.pPersistentVariable = (UDINT)&gPermAxisPars;
	gPersister[PERM_AXIS_PARS].IN.sizeofPersistentVariable = sizeof(gPermAxisPars);

	gPersister[PERM_AXIS_CFG].IN.pPersistentVariable = (UDINT)&gPermAxisCfgs;
	gPersister[PERM_AXIS_CFG].IN.sizeofPersistentVariable = sizeof(gPermAxisCfgs);
	
	// DataValid and PersistFn_Init()
	for(i = 0; i < NUM_PERSISTERS; i++){
		gPersister[i].IN.pDataValid = (UDINT)&gDataValid[i];
		PersistFn_Init(&gPersister[i]);
		if(gPersister[i].OUT.STAT.Error){
			errcolAddError((UDINT)"Perm Data", (UDINT)gPersister[i].OUT.STAT.ErrorString, gPersister[i].OUT.STAT.ErrorID, 0, &gErrorCollector);
		}
	}	
	
	// Initialize persister CSV backups
	errcolAddSourceByName((UDINT)"Machine configuration backup", (UDINT)"gPermBackup[0]", &gErrorCollector);
	errcolAddSourceByName((UDINT)"Home data backup", (UDINT)"gPermBackup[1]", &gErrorCollector);
	errcolAddSourceByName((UDINT)"Axis pars backup", (UDINT)"gPermBackup[2]", &gErrorCollector);
	errcolAddSourceByName((UDINT)"Axis cfg backup", (UDINT)"gPermBackup[3]", &gErrorCollector);
	
	strcpy(gPermBackup[PERM_CONFIGURATION].IN.PAR.FileName, "configuration.csv");
	strcpy(gPermBackup[PERM_HOME_DATA].IN.PAR.FileName, "homeData.csv");
	strcpy(gPermBackup[PERM_AXIS_PARS].IN.PAR.FileName, "axisPars.csv");
	strcpy(gPermBackup[PERM_AXIS_CFG].IN.PAR.FileName, "axisCfg.csv");

	for( i = 0; i < NUM_PERSISTERS; i++){
		
		strcpy(gPermBackup[i].IN.PAR.FileDevice, "permBackup");
		memcpy(&gPermBackup[i].IN.PAR.VariableList, &gPersister[i].IN.WorkingVariableList, sizeof(gPermBackup[i].IN.PAR.VariableList) );
		
		strcpy(gPermBackup[i].IN.CFG.LogFileName, ".csvlogPermBackup");
		brsitoa(i, (UDINT)indexString);
		strcat(gPermBackup[i].IN.CFG.LogFileName, indexString);
		
		CSVFn_Init(&(gPermBackup[i]));
		
		if (!gDataValid[i]) {
			CSVOpenFile_Init(&gPermBackup[i]);
			if (!gPermBackup[i].OUT.STAT.Error) {
				gDataValid[i] = 1;
				errcolAddError((UDINT)"Data restored", (UDINT)&(gPermBackup[i].IN.PAR.FileName), 0, 0, &gErrorCollector);
			}
		}
		
	} // loop through permbackup

	// Load configuration.csv every startup
	//CSVOpenFile_Init(&gPermBackup[PERM_CONFIGURATION]);

} // _INIT
