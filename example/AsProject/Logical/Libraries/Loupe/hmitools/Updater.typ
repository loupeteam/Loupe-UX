(********************************************************************
 * COPYRIGHT -- HP
 ********************************************************************
 * Program: Recipe
 * File: Recipe.typ
 * Author: jmorasch
 * Created: May 29, 2013
 ********************************************************************
 * Local data types of program Recipe
 ********************************************************************)

TYPE
	RecipeUpdater_Internal_typ : 	STRUCT 
		State : RecipeUpdater_STATE;
		DirRead : DirRead;
		CurrentFile : fiDIR_READ_DATA;
	END_STRUCT;
	RecipeUpdater_STATE : 
		(
		RecipeUpdater_ST_IDLE,
		RecipeUpdater_ST_ReadDirectory,
		RecipeUpdater_ST_ReadFile,
		RecipeUpdater_ST_WAIT,
		RecipeUpdater_ST_UpdateFile,
		RecipeUpdater_ST_Done,
		RecipeUpdater_ST_
		);
END_TYPE
