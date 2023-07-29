(********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * Library: RingBufST
 * File: RingBufST.fun
 * Author: Josh
 * Created: December 07, 2012
 ********************************************************************
 * Functions and function blocks of library RingBufST
 ********************************************************************)

FUNCTION BufferCopyItems : UINT (*Copies the number of items specified into the buffer given*)
	VAR_INPUT
		Buffer : UDINT; (*Pointer to the buffer*)
		Offset : UINT; (*Item offset from the top of the buffer*)
		NumEntries : UINT; (*Number of entries to read*)
		Destination : UDINT; (*Pointer to where to put the data*)
		Status : UDINT; (*OPTIONAL: Pointer to status UINT*)
	END_VAR
	VAR
		Index : INT;
		CopyLen : INT; (*Internal value for number of entries to copy for each operation*)
		iNumEntries : UINT; (*Internal limited number of entries to copy*)
		iDestination : UDINT; (*Internal pointer to where to put the data for second copy*)
		ibuf : REFERENCE TO Buffer_typ;
	END_VAR
END_FUNCTION

FUNCTION BufferGetItemAdr : UDINT (*Gets a pointer the item at the specified index*)
	VAR_INPUT
		Buffer : UDINT; (*Pointer to the buffer*)
		Offset : UINT; (*Item offset from the top of the buffer*)
		Status : UDINT; (*OPTIONAL: Pointer to status UINT*)
	END_VAR
	VAR
		Index : INT;
		ibuf : REFERENCE TO Buffer_typ;
	END_VAR
END_FUNCTION

FUNCTION BufferAddToBottom : UINT (*Adds an item to the buttom of the buffer*)
	VAR_INPUT
		Buffer : UDINT; (*Pointer to the buffer*)
		Data : UDINT; (*Address of data to copy*)
	END_VAR
	VAR
		ibuf : REFERENCE TO Buffer_typ;
	END_VAR
END_FUNCTION

FUNCTION BufferAddToTop : UINT (*Adds an item to the top of the buffer*)
	VAR_INPUT
		Buffer : UDINT; (*Pointer to the buffer*)
		Data : UDINT; (*Address of data to copy*)
	END_VAR
	VAR
		ibuf : REFERENCE TO Buffer_typ;
	END_VAR
END_FUNCTION

FUNCTION BufferRemoveBottom : UINT (*Removes the item at the bottom of the buffer*)
	VAR_INPUT
		Buffer : UDINT; (*Pointer to the buffer*)
	END_VAR
	VAR
		ibuf : REFERENCE TO Buffer_typ;
	END_VAR
END_FUNCTION

FUNCTION BufferRemoveTop : UINT (*Removes the item at the top of the buffer*)
	VAR_INPUT
		Buffer : UDINT; (*Pointer to the buffer*)
	END_VAR
	VAR
		ibuf : REFERENCE TO Buffer_typ;
	END_VAR
END_FUNCTION

FUNCTION BufferRemoveOffset : UINT
	VAR_INPUT
		Buffer : UDINT; (*Pointer to the buffer*)
		Offset : UINT; (*Item offset from the top of the buffer*)
		Status : UDINT; (*OPTIONAL: Pointer to status UINT*)
	END_VAR
	VAR
		Index : INT;
		CopyLen : INT; (*Internal value for number of entries to copy for each operation*)
		iNumEntries : UINT; (*Internal limited number of entries to copy*)
		iDestination : UDINT; (*Internal pointer to where to put the data for second copy*)
		ibuf : REFERENCE TO Buffer_typ;
	END_VAR
END_FUNCTION

FUNCTION BufferBottom : UINT (*Returns the index of the bottom of the buffer*)
	VAR_INPUT
		Buffer : UDINT; (*Pointer to the buffer*)
	END_VAR
	VAR
		ibuf : REFERENCE TO Buffer_typ;
	END_VAR
END_FUNCTION

FUNCTION BufferInit : UINT (*Allocates buffer memory*)
	VAR_INPUT
		Buffer : UDINT; (*Pointer to the buffer*)
		MaxValues : UINT; (*Max number of entries*)
		DataSize : UDINT; (*Size of each entry*)
	END_VAR
	VAR
		ibuf : REFERENCE TO Buffer_typ;
	END_VAR
END_FUNCTION

FUNCTION BufferDestroy : UINT (*Deallocates buffer memory*)
	VAR_INPUT
		Buffer : UDINT; (*Pointer to the buffer*)
	END_VAR
	VAR
		ibuf : REFERENCE TO Buffer_typ;
	END_VAR
END_FUNCTION

FUNCTION BufferClear : UINT (*Clears the contents of the buffer*)
	VAR_INPUT
		Buffer : UDINT; (*Pointer to the buffer*)
	END_VAR
	VAR
		ibuf : REFERENCE TO Buffer_typ;
	END_VAR
END_FUNCTION

FUNCTION BufferFull : BOOL (*Returns 1 if the buffer is full, 0 if buffer is not full*)
	VAR_INPUT
		Buffer : UDINT; (*Pointer to the buffer*)
	END_VAR
	VAR
		ibuf : REFERENCE TO Buffer_typ;
	END_VAR
END_FUNCTION

FUNCTION BufferValid : BOOL (*Returns 1 if the buffer is valid, 0 if the buffer is not valid*)
	VAR_INPUT
		Buffer : UDINT; (*Pointer to the buffer*)
	END_VAR
	VAR
		ibuf : REFERENCE TO Buffer_typ;
	END_VAR
END_FUNCTION

FUNCTION BufferStatus : UINT (*Returns 0 if everything is ok, else returns error number why buffer is invalid*)
	VAR_INPUT
		Buffer : UDINT; (*Pointer to the buffer*)
	END_VAR
	VAR
		ibuf : REFERENCE TO Buffer_typ;
	END_VAR
END_FUNCTION

FUNCTION GetTopIndex : UINT (*Internal function: Returns offset of the top of the buffer.*)
	VAR_INPUT
		Buffer : UDINT; (*Pointer to the buffer*)
	END_VAR
	VAR
		ibuf : REFERENCE TO Buffer_typ;
	END_VAR
END_FUNCTION

FUNCTION GetBottomIndex : UINT (*Internal function: Returns offset of the bottom of the buffer*)
	VAR_INPUT
		Buffer : UDINT; (*Pointer to the buffer*)
	END_VAR
	VAR
		ibuf : REFERENCE TO Buffer_typ;
	END_VAR
END_FUNCTION

FUNCTION GetNextBottomIndex : UDINT (*Internal function: Returns offset to the next valid item at them bottom*)
	VAR_INPUT
		Buffer : UDINT; (*Pointer to the buffer*)
	END_VAR
	VAR
		ibuf : REFERENCE TO Buffer_typ;
	END_VAR
END_FUNCTION

FUNCTION SetStatusPointer : BOOL
	VAR_INPUT
		pStatus : UDINT;
		Status : UINT;
	END_VAR
	VAR
		iStatus : REFERENCE TO UINT;
	END_VAR
END_FUNCTION

FUNCTION GetNextTopIndex : UDINT (*Internal function: Returns offset to the next valid item at them bottom*)
	VAR_INPUT
		Buffer : UDINT; (*Pointer to the buffer*)
	END_VAR
	VAR
		ibuf : REFERENCE TO Buffer_typ;
	END_VAR
END_FUNCTION
