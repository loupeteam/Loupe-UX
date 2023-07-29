/* Automation Studio generated header file */
/* Do not edit ! */
/* bodyguard 0.03.0 */

#ifndef _BODYGUARD_
#define _BODYGUARD_
#ifdef __cplusplus
extern "C" 
{
#endif
#ifndef _bodyguard_VERSION
#define _bodyguard_VERSION 0.03.0
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
#ifdef _SG3
		#include "AsGuard.h"
		#include "AsIODiag.h"
		#include "runtime.h"
#endif
#ifdef _SG4
		#include "AsGuard.h"
		#include "AsIODiag.h"
		#include "runtime.h"
#endif
#ifdef _SGC
		#include "AsGuard.h"
		#include "AsIODiag.h"
		#include "runtime.h"
#endif


/* Datatypes and datatypes of function blocks */
typedef struct tgProtect_int_FUB_typ
{	struct guardRegisterLicense registerLicense;
	struct guardCheckLicense checkLicense;
} tgProtect_int_FUB_typ;

typedef struct tgProtect_internal_typ
{	struct tgProtect_int_FUB_typ FUB;
} tgProtect_internal_typ;

typedef struct tgProtect
{
	/* VAR_INPUT (analog) */
	unsigned long productCode;
	plcstring orderNumber[256];
	plcstring description[256];
	plcdword reaction;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long availableLicenses;
	unsigned long neededLicenses;
	unsigned long licenseIdent;
	/* VAR (analog) */
	struct tgProtect_internal_typ internal;
	/* VAR_INPUT (digital) */
	plcbit allowSimulation;
	/* VAR_OUTPUT (digital) */
	plcbit licenseRegistered;
	plcbit licenseOk;
} tgProtect_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void tgProtect(struct tgProtect* inst);


#ifdef __cplusplus
};
#endif
#endif /* _BODYGUARD_ */

