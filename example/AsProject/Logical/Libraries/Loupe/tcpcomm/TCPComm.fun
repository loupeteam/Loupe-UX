(*
 * File: TCPComm.fun
 * Copyright (c) 2023 Loupe
 * https://loupe.team
 * 
 * This file is part of TCPComm, licensed under the MIT License.
 *
 *)

FUNCTION TCPManageConnection : UINT (*Cyclic function for managing TCP communications*) (*$GROUP=User*)
	VAR_IN_OUT
		t : TCPConnectionMgr_typ;
	END_VAR
END_FUNCTION

FUNCTION TCPStreamReceive : UINT (*Cyclic function to receive packets of data*) (*$GROUP=User*)
	VAR_IN_OUT
		t : TCPStream_typ;
	END_VAR
END_FUNCTION

FUNCTION TCPStreamSend : UINT (*Cyclic function to send packets of data*) (*$GROUP=User*)
	VAR_IN_OUT
		t : TCPStream_typ;
	END_VAR
END_FUNCTION
