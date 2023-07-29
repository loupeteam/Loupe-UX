/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef CONVERT_H_
#define CONVERT_H_
#ifdef __cplusplus
extern "C" 
{
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
/* Constants */




/* Datatypes and datatypes of function blocks */


/* Prototyping of functions and function blocks */
_BUR_PUBLIC signed short H_TO_NINT(signed short IN);
_BUR_PUBLIC unsigned short H_TO_NUINT(unsigned short IN);
_BUR_PUBLIC signed long H_TO_NDINT(signed long IN);
_BUR_PUBLIC unsigned long H_TO_NUDINT(unsigned long IN);
_BUR_PUBLIC float H_TO_NREAL(float IN);
_BUR_PUBLIC double H_TO_NLREAL(double IN);
_BUR_PUBLIC plctime H_TO_NTIME(plctime IN);
_BUR_PUBLIC DATE_AND_TIME H_TO_NDT(DATE_AND_TIME IN);
_BUR_PUBLIC signed short N_TO_HINT(signed short IN);
_BUR_PUBLIC unsigned short N_TO_HUINT(unsigned short IN);
_BUR_PUBLIC signed long N_TO_HDINT(signed long IN);
_BUR_PUBLIC unsigned long N_TO_HUDINT(unsigned long IN);
_BUR_PUBLIC float N_TO_HREAL(float IN);
_BUR_PUBLIC double N_TO_HLREAL(double IN);
_BUR_PUBLIC plctime N_TO_HTIME(plctime IN);
_BUR_PUBLIC DATE_AND_TIME N_TO_HDT(DATE_AND_TIME IN);
_BUR_PUBLIC signed short swapINT(signed short IN);
_BUR_PUBLIC unsigned short swapUINT(unsigned short IN);
_BUR_PUBLIC signed long swapDINT(signed long IN);
_BUR_PUBLIC unsigned long swapUDINT(unsigned long IN);
_BUR_PUBLIC plcdt swapDT(plcdt IN);
_BUR_PUBLIC plctime swapTIME(plctime IN);
_BUR_PUBLIC float swapREAL(float IN);
_BUR_PUBLIC double swapLREAL(double IN);


#ifdef __cplusplus
};
#endif
#endif /* CONVERT_H_ */

