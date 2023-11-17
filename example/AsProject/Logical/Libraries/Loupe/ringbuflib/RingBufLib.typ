(*
 * File: RingBufLib.typ
 * Copyright (c) 2023 Loupe
 * https://loupe.team
 * 
 * This file is part of RingBufLib, licensed under the MIT License.
 *
 ********************************************************************
 * Data types of library RingBufST
 ********************************************************************)

TYPE
	RING_BUF_ERR : 
		(
		RING_BUF_ERR_INVALID_BUFFER,
		RING_BUF_ERR_INVALID_BUF_POINTER,
		RING_BUF_ERR_DATA_NOT_INIT,
		RING_BUF_ERR_MAX_VALUES_ZERO,
		RING_BUF_ERR_INDEX_OUTSIDE_RANGE,
		RING_BUF_ERR_NUM_ENTRIES_ZERO,
		RING_BUF_ERR_DEST_INVALID,
		RING_BUF_ERR_
		);
	Buffer_typ : 	STRUCT 
		Data : UDINT;
		DataSize : UDINT;
		TopIndex : INT;
		MaxValues : UINT;
		NumberValues : UINT;
	END_STRUCT;
END_TYPE
