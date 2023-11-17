(*
* File: Updater.typ
* Copyright (c) 2023 Loupe
* https://loupe.team
* 
* This file is part of HMITools, licensed under the MIT License.
* 
*)

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
