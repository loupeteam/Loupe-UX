(*
* File: HMITools.typ
* Copyright (c) 2023 Loupe
* https://loupe.team
* 
* This file is part of HMITools, licensed under the MIT License.
* 
*)

TYPE
	HMI_ERR_enum : 
		(
		HMI_ERR_OK := 0,
		HMI_ERR_INVALIDINPUT := 50000,
		HMI_ERR_BUSY := 65535
		);
END_TYPE
