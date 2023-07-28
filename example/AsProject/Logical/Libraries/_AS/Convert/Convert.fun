                                                                       
{REDUND_OK} FUNCTION swapDT : DATE_AND_TIME        (*swaps the byte order of a DATE_AND_TIME value*)
	VAR_INPUT
		IN	:DATE_AND_TIME;            (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION swapTIME : TIME               (*swaps the byte order of a TIME value*)
	VAR_INPUT
		IN	:TIME;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION swapREAL : REAL               (*swaps the byte order of a REAL value*)
	VAR_INPUT
		IN	:REAL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION swapLREAL : LREAL             (*swaps the byte order of a LREAL value*)
	VAR_INPUT
		IN	:LREAL;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION swapUDINT : UDINT             (*swaps the byte order of an UDINT value*)
	VAR_INPUT
		IN	:UDINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION swapDINT : DINT               (*swaps the byte order of a DINT value*)
	VAR_INPUT
		IN	:DINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION swapUINT : UINT               (*swaps the byte order of an UINT value*)
	VAR_INPUT
		IN	:UINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION swapINT : INT                 (*swaps the byte order of a INT value*)
	VAR_INPUT
		IN	:INT;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION N_TO_HDT : DATE_AND_TIME      (*converts a DATE_AND_TIME value from network (big endian) to host byte order*)
	VAR_INPUT
		IN	:DATE_AND_TIME;            (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION N_TO_HTIME : TIME             (*converts a TIME value from network (big endian) to host byte order*)
	VAR_INPUT
		IN	:TIME;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION N_TO_HREAL : REAL             (*converts a REAL value from network (big endian) to host byte order*)
	VAR_INPUT
		IN	:REAL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION N_TO_HLREAL : LREAL           (*converts a LREAL value from network (big endian) to host byte order*)
	VAR_INPUT
		IN	:LREAL;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION N_TO_HUDINT : UDINT           (*converts a UDINT value from network (big endian) to host byte order*)
	VAR_INPUT
		IN	:UDINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION N_TO_HDINT : DINT             (*converts a DINT value from network (big endian) to host byte order*)
	VAR_INPUT
		IN	:DINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION N_TO_HUINT : UINT             (*converts a UINT value from network (big endian) to host byte order*)
	VAR_INPUT
		IN	:UINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION N_TO_HINT : INT               (*converts an INT value from network (big endian) to host byte order*)
	VAR_INPUT
		IN	:INT;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION H_TO_NDT : DATE_AND_TIME      (*converts a DATE_AND_TIME value from host to network byte order (big endian)*)
	VAR_INPUT
		IN	:DATE_AND_TIME;            (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION H_TO_NTIME : TIME             (*converts a TIME value from host to network byte order (big endian)*)
	VAR_INPUT
		IN	:TIME;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION H_TO_NREAL : REAL             (*converts a REAL value from host to network byte order (big endian)*)
	VAR_INPUT
		IN	:REAL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION H_TO_NLREAL : LREAL           (*converts a LREAL value from host to network byte order (big endian)*)
	VAR_INPUT
		IN	:LREAL;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION H_TO_NUDINT : UDINT           (*converts a UDINT value from host to network byte order (big endian)*)
	VAR_INPUT
		IN	:UDINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION H_TO_NDINT : DINT             (*converts a DINT value from host to network byte order (big endian)*)
	VAR_INPUT
		IN	:DINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION H_TO_NUINT : UINT             (*converts a UINT value from host to network byte order (big endian)*)
	VAR_INPUT
		IN	:UINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION H_TO_NINT : INT               (*converts an INT value from host to network byte order (big endian)*)
	VAR_INPUT
		IN	:INT;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION DT_TO_UDINT : UDINT           (*converts a DATE_AND_TIME (32 bit date in seconds) value to a UDINT value (32 bits unsigned)*)
	VAR_INPUT
		IN	:DATE_AND_TIME;            (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION DT_TO_DINT : DINT             (*converts a DATE_AND_TIME (32 bit date in seconds) value to a DINT value (32 bits signed)*)
	VAR_INPUT
		IN	:DATE_AND_TIME;            (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK} FUNCTION DT_TO_BOOL : BOOL             (*converts a DATE_AND_TIME value (32 bit date in seconds) to a BOOL value (1 bit)*)
	VAR_INPUT
		IN	:DATE_AND_TIME;            (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION TIME_TO_DINT : DINT           (*converts a TIME value (32 bit time in milliseconds) to a DINT value (32 bits signed)*)
	VAR_INPUT
		IN	:TIME;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION TIME_TO_UDINT : UDINT         (*converts a TIME value (32 bit time in milliseconds) to a UDINT value (32 bits unsigned)*)
	VAR_INPUT
		IN	:TIME;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION TIME_TO_BOOL : BOOL           (*converts a TIME value (32 bit time in milliseconds) to a BOOL value (1 bit)*)
	VAR_INPUT
		IN	:TIME;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION BOOL_TO_SINT : SINT           (*converts a BOOL value (1 bit) to a SINT value (8 bits signed)*)
	VAR_INPUT
		IN	:BOOL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION SINT_TO_INT : INT             (*converts a SINT value (8 bits signed) to an INT value (16 bits signed)*)
	VAR_INPUT
		IN	:SINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION SINT_TO_LREAL : LREAL         (*converts a SINT value (8 bits signed) to a LREAL value (64 bit floating point number)*)
	VAR_INPUT
		IN	:SINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION SINT_TO_REAL : REAL           (*converts a SINT value (8 bits signed) to a REAL value (32 bit floating point number)*)
	VAR_INPUT
		IN	:SINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION SINT_TO_UDINT : UDINT         (*converts a SINT value (8 bits signed) to a UDINT value (32 bits unsigned)*)
	VAR_INPUT
		IN	:SINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION SINT_TO_UINT : UINT           (*converts a SINT value (8 bits signed) to a UINT value (16 bits unsigned)*)
	VAR_INPUT
		IN	:SINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION SINT_TO_USINT : USINT         (*converts a SINT value (8 bits signed) to a USINT value (8 bits unsigned)*)
	VAR_INPUT
		IN	:SINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION SINT_TO_DINT : DINT           (*converts a SINT value (8 bits signed) to a DINT value (32 bits signed)*)
	VAR_INPUT
		IN	:SINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION SINT_TO_BOOL : BOOL           (*converts a SINT value (8 bits signed) to a BOOL value (1 bit)*)
	VAR_INPUT
		IN	:SINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION BOOL_TO_DT : DATE_AND_TIME    (*converts a BOOL value (1 bit) to a DATE_AND_TIME value (32 bit date in seconds)*)
	VAR_INPUT
		IN	:BOOL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION BOOL_TO_TIME : TIME           (*converts a BOOL value (1 bit) to a TIME value (32 bit time in milliseconds)*)
	VAR_INPUT
		IN	:BOOL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION BOOL_TO_REAL : REAL           (*converts a BOOL value (1 bit) to a REAL value (32 bit floating point number)*)
	VAR_INPUT
		IN	:BOOL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION BOOL_TO_UDINT : UDINT         (*converts a BOOL value (1 bit) to a UDINT value (32 bits unsigned)*)
	VAR_INPUT
		IN	:BOOL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION BOOL_TO_UINT : UINT           (*converts a BOOL value (1 bit) to a UINT value (16 bits unsigned)*)
	VAR_INPUT
		IN	:BOOL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION BOOL_TO_USINT : USINT         (*converts a BOOL value (1 bit) to a USINT value (8 bits unsigned)*)
	VAR_INPUT
		IN	:BOOL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION BOOL_TO_DINT : DINT           (*converts a BOOL value (1 bit) to a DINT value (32 bits signed)*)
	VAR_INPUT
		IN	:BOOL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION BOOL_TO_INT : INT             (*converts a BOOL value (1 bit) to an INT value (16 bits signed)*)
	VAR_INPUT
		IN	:BOOL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION INT_TO_LREAL : LREAL          (*converts an INT value (16 bits signed) to a LREAL value (64 bit floating point number)*)
	VAR_INPUT
		IN	:INT;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION INT_TO_REAL : REAL            (*converts an INT value (16 bits signed) to a REAL value (32 bit floating point number)*)
	VAR_INPUT
		IN	:INT;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION INT_TO_UDINT : UDINT          (*converts an INT value (16 bits signed) to a UDINT value (32 bits unsigned)*)
	VAR_INPUT
		IN	:INT;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION INT_TO_UINT : UINT            (*converts an INT value (16 bits signed) to a UINT value (16 bits unsigned)*)
	VAR_INPUT
		IN	:INT;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION INT_TO_USINT : USINT          (*converts an INT value (16 bits signed) to a USINT value (8 bits unsigned)*)
	VAR_INPUT
		IN	:INT;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION INT_TO_DINT : DINT            (*converts an INT value (16 bits signed) to a DINT value (32 bits signed)*)
	VAR_INPUT
		IN	:INT;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION INT_TO_SINT : SINT            (*converts an INT value (16 bits signed) to a SINT value (8 bits signed)*)
	VAR_INPUT
		IN	:INT;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION INT_TO_BOOL : BOOL            (*converts an INT value (16 bits signed) to a BOOL value (1 bit)*)
	VAR_INPUT
		IN	:INT;                      (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION DINT_TO_DT : DATE_AND_TIME    (*converts a DINT value (32 bits signed) to a DATE_AND_TIME value (32 bit date in seconds)*)
	VAR_INPUT
		IN	:DINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION DINT_TO_TIME : TIME           (*converts a DINT value (32 bits signed) to a TIME value (32 bit time in milliseconds)*)
	VAR_INPUT
		IN	:DINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION DINT_TO_LREAL : LREAL         (*converts a DINT value (32 bits signed) to a LREAL value (64 bit floating point number)*)
	VAR_INPUT
		IN	:DINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION DINT_TO_REAL : REAL           (*converts a DINT value (32 bits signed) to a REAL value (32 bit floating point number)*)
	VAR_INPUT
		IN	:DINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION DINT_TO_UDINT : UDINT         (*converts a DINT value (32 bits signed) to a UDINT value (32 bits unsigned)*)
	VAR_INPUT
		IN	:DINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION DINT_TO_UINT : UINT           (*converts a DINT value (32 bits signed) to a UINT value (16 bits unsigned)*)
	VAR_INPUT
		IN	:DINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION DINT_TO_USINT : USINT         (*converts a DINT value (32 bits signed) to a USINT value (8 bits unsigned)*)
	VAR_INPUT
		IN	:DINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION DINT_TO_INT : INT             (*converts a DINT value (32 bits signed) to an INT value (16 bits signed)*)
	VAR_INPUT
		IN	:DINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION DINT_TO_SINT : SINT           (*converts a DINT value (32 bits signed) to a SINT value (8 bits signed)*)
	VAR_INPUT
		IN	:DINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION DINT_TO_BOOL : BOOL           (*converts a DINT value (32 bits signed) to a BOOL value (1 bit)*)
	VAR_INPUT
		IN	:DINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION USINT_TO_BOOL : BOOL          (*converts a USINT value (8 bits unsigned) to a BOOL value (1 bit)*)
	VAR_INPUT
		IN	:USINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION USINT_TO_LREAL : LREAL        (*converts a USINT value (8 bits unsigned) to a LREAL value (64 bit floating point number)*)
	VAR_INPUT
		IN	:USINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION USINT_TO_REAL : REAL          (*converts a USINT value (8 bits unsigned) to a REAL value (32 bit floating point number)*)
	VAR_INPUT
		IN	:USINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION USINT_TO_UDINT : UDINT        (*converts a USINT value (8 bits unsigned) to a UDINT value (32 bits unsigned)*)
	VAR_INPUT
		IN	:USINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION USINT_TO_UINT : UINT          (*converts a USINT value (8 bits unsigned) to a UINT value (16 bits unsigned)*)
	VAR_INPUT
		IN	:USINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION USINT_TO_DINT : DINT          (*converts a USINT value (8 bits unsigned) to a DINT value (32 bits signed)*)
	VAR_INPUT
		IN	:USINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION USINT_TO_INT : INT            (*converts a USINT value (8 bits unsigned) to an INT value (16 bits signed)*)
	VAR_INPUT
		IN	:USINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION USINT_TO_SINT : SINT          (*converts a USINT value (8 bits unsigned) to a SINT value (8 bits signed)*)
	VAR_INPUT
		IN	:USINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION UDINT_TO_DT : DATE_AND_TIME   (*converts a UDINT value (32 bits unsigned) to a DATE_AND_TIME value (32 bit date in seconds)*)
	VAR_INPUT
		IN	:UDINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION UDINT_TO_TIME : TIME          (*converts a UDINT value (32 bits unsigned) to a TIME value (32 bit time in milliseconds)*)
	VAR_INPUT
		IN	:UDINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION UDINT_TO_LREAL : LREAL        (*converts a UDINT value (32 bits unsigned) to a LREAL value (64 bit floating point number)*)
	VAR_INPUT
		IN	:UDINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION UDINT_TO_REAL : REAL          (*converts a UDINT value (32 bits unsigned) to a REAL value (32 bit floating point number)*)
	VAR_INPUT
		IN	:UDINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION UDINT_TO_UINT : UINT          (*converts a UDINT value (32 bits unsigned) to a UINT value (16 bits unsigned)*)
	VAR_INPUT
		IN	:UDINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION UDINT_TO_USINT : USINT        (*converts a UDINT value (32 bits unsigned) to a USINT value (8 bits unsigned)*)
	VAR_INPUT
		IN	:UDINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION UDINT_TO_DINT : DINT          (*converts a UDINT value (32 bits unsigned) to a DINT value (32 bits signed)*)
	VAR_INPUT
		IN	:UDINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION UDINT_TO_INT : INT            (*converts a UDINT value (32 bits unsigned) to an INT value (16 bits signed)*)
	VAR_INPUT
		IN	:UDINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION UDINT_TO_SINT : SINT          (*converts a UDINT value (32 bits unsigned) to a SINT value (8 bits signed)*)
	VAR_INPUT
		IN	:UDINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION UDINT_TO_BOOL : BOOL          (*converts a UDINT value (32 bits unsigned) to a BOOL value (1 bit)*)
	VAR_INPUT
		IN	:UDINT;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION UINT_TO_BOOL : BOOL           (*converts a UINT value (16 bits unsigned) to a BOOL value (1 bit)*)
	VAR_INPUT
		IN	:UINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION UINT_TO_LREAL : LREAL         (*converts a UINT value (16 bits unsigned) to a LREAL value (64 bit floating point number)*)
	VAR_INPUT
		IN	:UINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION UINT_TO_REAL : REAL           (*converts a UINT value (16 bits unsigned) to a REAL value (32 bit floating point number)*)
	VAR_INPUT
		IN	:UINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION UINT_TO_UDINT : UDINT         (*converts a UINT value (16 bits unsigned) to a UDINT value (32 bits unsigned)*)
	VAR_INPUT
		IN	:UINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION UINT_TO_USINT : USINT         (*converts a UINT value (16 bits unsigned) to a USINT value (8 bits unsigned)*)
	VAR_INPUT
		IN	:UINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION UINT_TO_DINT : DINT           (*converts a UINT value (16 bits unsigned) to a DINT value (32 bits signed)*)
	VAR_INPUT
		IN	:UINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION UINT_TO_INT : INT             (*converts a UINT value (16 bits unsigned) to an INT value (16 bits signed)*)
	VAR_INPUT
		IN	:UINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION UINT_TO_SINT : SINT           (*converts a UINT value (16 bits unsigned) to a SINT value (8 bits signed)*)
	VAR_INPUT
		IN	:UINT;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION REAL_TO_LREAL : LREAL         (*converts a REAL value (32 bit floating point number) to a LREAL value (64 bit floating point number)*)
	VAR_INPUT
		IN	:REAL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION REAL_TO_UDINT : UDINT         (*converts a REAL value (32 bit floating point number) to a UDINT value (32 bits unsigned)*)
	VAR_INPUT
		IN	:REAL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION REAL_TO_UINT : UINT           (*converts a REAL value (32 bit floating point number) to a UINT value (16 bits unsigned)*)
	VAR_INPUT
		IN	:REAL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION REAL_TO_USINT : USINT         (*converts a REAL value (32 bit floating point number) to a USINT value (8 bits unsigned)*)
	VAR_INPUT
		IN	:REAL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION REAL_TO_DINT : DINT           (*converts a REAL value (32 bit floating point number) to a DINT value (32 bits signed)*)
	VAR_INPUT
		IN	:REAL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION REAL_TO_INT : INT             (*converts a REAL value (32 bit floating point number) to an INT value (16 bits signed)*)
	VAR_INPUT
		IN	:REAL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION REAL_TO_SINT : SINT           (*converts a REAL value (32 bit floating point number) to a SINT value (8 bits signed)*)
	VAR_INPUT
		IN	:REAL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION REAL_TO_BOOL : BOOL           (*converts a REAL value (32 bit floating point number) to a BOOL value (1 bit)*)
	VAR_INPUT
		IN	:REAL;                     (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION LREAL_TO_REAL : REAL          (*converts a LREAL value (64 bit floating point number) to a REAL value (32 bit floating point number)*)
	VAR_INPUT
		IN	:LREAL;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION LREAL_TO_UDINT : UDINT        (*converts a LREAL value (64 bit floating point number) to a UDINT value (32 bits unsigned)*)
	VAR_INPUT
		IN	:LREAL;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION LREAL_TO_UINT : UINT          (*converts a LREAL value (64 bit floating point number) to a UINT value (16 bits unsigned)*)
	VAR_INPUT
		IN	:LREAL;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION LREAL_TO_USINT : USINT        (*converts a LREAL value (64 bit floating point number) to a USINT value (8 bits unsigned)*)
	VAR_INPUT
		IN	:LREAL;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION LREAL_TO_DINT : DINT          (*converts a LREAL value (64 bit floating point number) to a DINT value (32 bits signed)*)
	VAR_INPUT
		IN	:LREAL;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION LREAL_TO_INT : INT            (*converts a LREAL value (64 bit floating point number) to an INT value (16 bits signed)*)
	VAR_INPUT
		IN	:LREAL;                    (*input value*)
	END_VAR
END_FUNCTION
{REDUND_OK}  FUNCTION LREAL_TO_SINT : SINT          (*converts a LREAL value (64 bit floating point number) to a SINT value (8 bits signed)*)
	VAR_INPUT
		IN	:LREAL;                    (*input value*)
	END_VAR
END_FUNCTION
