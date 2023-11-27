(*
* File: DataBuffer.typ
* Copyright (c) 2023 Loupe
* https://loupe.team
* 
* This file is part of DataBuffer, licensed under the MIT License.
* 
*)

TYPE
	DATBUF_ERR_enum : 
		(
		DATBUF_ERR_INVALIDINPUT := 50000,
		DATBUF_ERR_MEMALLOC,
		DATBUF_ERR_NOTINITIALIZED,
		DATBUF_ERR_BUFFERFULL
		);
	datbufBuffer_typ : 	STRUCT 
		pData : UDINT;
		currentLength : UDINT;
		maxLength : UDINT;
	END_STRUCT;
END_TYPE
