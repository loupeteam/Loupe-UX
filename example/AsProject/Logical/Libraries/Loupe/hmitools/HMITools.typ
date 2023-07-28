(********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * Library: HMITools
 * File: HMITools.typ
 * Author: Josh
 * Created: November 07, 2012
 ********************************************************************
 * Data types of library HMITools
 ********************************************************************)

TYPE
	HMI_ERR_enum : 
		(
		HMI_ERR_OK := 0,
		HMI_ERR_INVALIDINPUT := 50000,
		HMI_ERR_BUSY := 65535
		);
END_TYPE
