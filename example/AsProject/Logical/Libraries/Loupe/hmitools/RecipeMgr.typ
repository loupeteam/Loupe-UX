(********************************************************************
 * COPYRIGHT -- Automation Resources Group
 ********************************************************************
 * Library: HMITools
 * File: RecipeMgr.typ
 * Author: David Blackburn
 * Created: March 22, 2012
 ********************************************************************
 * Data types of library HMITools
 ********************************************************************)

TYPE
	RecMgr_HMI_typ : 	STRUCT 
		RetrieveFromSystem : HMI_Button_typ; (*Retrieve current system recipe (copy from pSystemRecipe to pHMIRecipe)*)
		ApplyToSystem : HMI_Button_typ; (*Apply current recipe to system (copy from pHMIRecipe to pSystemRecipe)*)
		Modified : HMI_Bitmap_typ;
	END_STRUCT;
	RecMgr_IN_typ : 	STRUCT 
		pHMIRecipe : UDINT; (*HMI Recipe location. Given as an address.*)
		pSystemRecipe : UDINT; (*System Recipe location. Given as an address.*)
		RecipeLength : UDINT; (*Size of the recipe in bytes*)
		LoggerName : STRING[LOG_STRLEN_LOGGERNAME];
	END_STRUCT;
	RecipeMgr_typ : 	STRUCT 
		IN : RecMgr_IN_typ;
		HMI : RecMgr_HMI_typ;
	END_STRUCT;
END_TYPE
