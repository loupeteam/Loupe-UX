/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _ASBRMATH_
#define _ASBRMATH_
#ifdef __cplusplus
extern "C" 
{
#endif

#include <bur/plctypes.h>

#ifndef _IEC_CONST
#define _IEC_CONST _WEAK const
#endif

/* Constants */
#ifdef _REPLACE_CONST
 #define brm2_SQRTPI 1.12838
 #define brmSQRT1_2 0.707107
 #define brmSQRTPI 1.77245
 #define brmLOG2_E 0.693147
 #define brmLOG10E 0.434294
 #define brmIVLN10 0.434294
 #define brmINVLN2 1.4427
 #define brmTWOPI 6.28319
 #define brmSQRT3 1.73205
 #define brmSQRT2 1.41421
 #define brmLOG2E 1.4427
 #define brmLN2LO 1.90821e-010
 #define brmLN2HI 0.693147
 #define brm3PI_4 2.35619
 #define brmPI_4 0.785398
 #define brmPI_2 1.5708
 #define brmLN10 2.30259
 #define brm2_PI 0.63662
 #define brm1_PI 0.31831
 #define brmLN2 0.693147
 #define brmPI 3.14159
 #define brmE 2.71828
#else
 _IEC_CONST float brm2_SQRTPI = 1.12838;
 _IEC_CONST float brmSQRT1_2 = 0.707107;
 _IEC_CONST float brmSQRTPI = 1.77245;
 _IEC_CONST float brmLOG2_E = 0.693147;
 _IEC_CONST float brmLOG10E = 0.434294;
 _IEC_CONST float brmIVLN10 = 0.434294;
 _IEC_CONST float brmINVLN2 = 1.4427;
 _IEC_CONST float brmTWOPI = 6.28319;
 _IEC_CONST float brmSQRT3 = 1.73205;
 _IEC_CONST float brmSQRT2 = 1.41421;
 _IEC_CONST float brmLOG2E = 1.4427;
 _IEC_CONST float brmLN2LO = 1.90821e-010;
 _IEC_CONST float brmLN2HI = 0.693147;
 _IEC_CONST float brm3PI_4 = 2.35619;
 _IEC_CONST float brmPI_4 = 0.785398;
 _IEC_CONST float brmPI_2 = 1.5708;
 _IEC_CONST float brmLN10 = 2.30259;
 _IEC_CONST float brm2_PI = 0.63662;
 _IEC_CONST float brm1_PI = 0.31831;
 _IEC_CONST float brmLN2 = 0.693147;
 _IEC_CONST float brmPI = 3.14159;
 _IEC_CONST float brmE = 2.71828;
#endif







/* Prototyping of functions and function blocks */
float brmatan2(float y, float x);
float brmceil(float x);
float brmcosh(float x);
float brmfloor(float x);
float brmfmod(float x, float y);
float brmfrexp(float x, unsigned long pExp);
float brmldexp(float x, signed long exp_val);
float brmmodf(float x, unsigned long plp);
float brmpow(float x, float y);
float brmsinh(float x);
float brmtanh(float x);


#ifdef __cplusplus
};
#endif
#endif /* _ASBRMATH_ */

