(*
 * File: StringExt.typ
 * Copyright (c) 2023 Loupe
 * https://loupe.team
 * 
 * This file is part of StringExt, licensed under the MIT License.
 *
 *)

TYPE
	STREXT_ERR_enum : 
		(
		STREXT_ERR_INVALID_INPUT := -1
		);
	StrExtArgs_typ : 	STRUCT  (*Arguments for formatter*)
		r : ARRAY[0..4]OF REAL; (*Reals*)
		s : ARRAY[0..4]OF UDINT; (*Pointers to String*)
		b : ARRAY[0..4]OF BOOL; (*Booleans*)
		i : ARRAY[0..4]OF DINT; (*Signed Integers*)
	END_STRUCT;
END_TYPE
