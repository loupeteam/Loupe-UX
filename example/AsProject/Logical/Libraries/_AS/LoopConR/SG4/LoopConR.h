/* Automation Studio generated header file */
/* Do not edit ! */
/* LoopConR 4.10.2 */

#ifndef _LOOPCONR_
#define _LOOPCONR_
#ifdef __cplusplus
extern "C" 
{
#endif
#ifndef _LoopConR_VERSION
#define _LoopConR_VERSION 4.10.2
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
#ifdef _SG4
		#include "sys_lib.h"
		#include "brsystem.h"
#endif
#ifdef _SG3
		#include "sys_lib.h"
		#include "brsystem.h"
#endif
#ifdef _SGC
		#include "sys_lib.h"
		#include "brsystem.h"
#endif

/* Constants */
#ifdef _REPLACE_CONST
 #define LCRPID_TUNE_REQU_PER_5 500000U
 #define LCRSLIMPID_REQU_PER_5 500000U
 #define LCRSLIMPID_REQU_PER_4 400000U
 #define LCRPID_TUNE_REQU_PER_4 400000U
 #define LCRPID_TUNE_REQU_PER_3 300000U
 #define LCRSLIMPID_REQU_PER_3 300000U
 #define LCRTEMP_STEP_ERROR 65535U
 #define LCR_ERR_DISABLED 65534U
 #define LCR_ERR_PT2O_TF_NEG_ZERO 33154U
 #define LCR_ERR_PT2O_D_NEG 33153U
 #define LCR_ERR_LCRTEMPTune_DT_IGNORED 33152U
 #define LCR_ERR_LCRTEMPPID_INVALID_MODE 33151U
 #define LCR_ERR_LCRTEMPTune_INVALID_MODE 33150U
 #define LCR_WARN_PT2O_TF_TS 33102U
 #define LCR_WARN_LCRTEMPTune_ASYNC 33101U
 #define LCR_WARN_LCRTEMPTune_DT_HIGH 33100U
 #define LCR_ERR_SCHEDULE_N 31574U
 #define LCR_ERR_SCHEDULE_P 31573U
 #define LCR_ERR_LCRTEMPPID_NO_TALT 31572U
 #define LCR_ERR_LCRTEMPPID_TKNICK 31571U
 #define LCR_ERR_LCRTEMPTune_TASKTIME_0 31570U
 #define LCR_ERR_LCRTEMPPID_ILLEGALMODE 31569U
 #define LCR_ERR_LCRTEMPPID_WR_PTR 31568U
 #define LCR_ERR_LCRTEMPPID_WR_PARA 31567U
 #define LCR_ERR_LCRTEMPTune_WR_TSET 31567U
 #define LCR_ERR_LCRTEMPTune_WR_PTR 31566U
 #define LCR_ERR_LCRPIDTune_MAXMIN 31564U
 #define LCR_ERR_POINTER 31563U
 #define LCR_ERR_LCRDBLPID_DX_DT 31562U
 #define LCR_ERR_LCRDBLPID_WX_LOW 31561U
 #define LCR_ERR_LCRPIDTune_CONTROL_VAR 31560U
 #define LCR_ERR_LCRPIDTune_INVALID_REQU 31559U
 #define LCR_ERR_LCRPID_PAR_FBKMODE 31558U
 #define LCR_ERR_LCRPID_PAR_DYMAX 31557U
 #define LCR_ERR_LCRPID_PAR_DMODE 31556U
 #define LCR_ERR_LCRPID_PARADAT 31554U
 #define LCR_ERR_LCRPID_MODE 31553U
 #define LCR_ERR_LCRPID_IDENT 31552U
 #define LCR_ERR_LCRMovAvgFlt_BASE 31551U
 #define LCR_ERR_LCRIntegrate_TN 31550U
 #define LCRPID_TUNE_REQU_OSC_3 30000U
 #define LCRSLIMPID_REQU_OSC_3 30000U
 #define LCRPID_TUNE_REQU_OSC_2 20000U
 #define LCRSLIMPID_REQU_OSC_2 20000U
 #define LCR_ERR_LCRTT_TT_NEG 12048U
 #define LCR_ERR_LCRPT12_T2_NEG 12047U
 #define LCR_ERR_LCRPT12_T1_NEG 12046U
 #define LCR_ERR_LCRCurveByPoints_TABLE 12045U
 #define LCR_ERR_LCRPID_PAR_DEADBAND 12044U
 #define LCR_ERR_LCRPID_PAR_WX_MAXMIN 12043U
 #define LCR_ERR_LCRPID_PAR_DEADBAND_MODE 12042U
 #define LCR_ERR_LCRPIDTune_W_CHANGED 12041U
 #define LCR_ERR_LCRPIDTune_TIMEOUT 12040U
 #define LCR_ERR_LCRPIDTune_PARAMETER 12039U
 #define LCR_ERR_LCRPIDTune_ABORT 12038U
 #define LCR_ERR_MAXMIN 12037U
 #define LCR_ERR_LCRContinServo_TIMPULSE 12036U
 #define LCR_ERR_LCRContinServo_TCHANGE 12035U
 #define LCR_ERR_LCRRamp_DYUP_DYDOWN 12034U
 #define LCR_ERR_LCRPWM_TPERIOD 12033U
 #define LCR_ERR_LCRPWM_TPULSE 12033U
 #define LCR_ERR_LCRPWM_TMINPULSE 12032U
 #define LCR_ERR_LCRPT1_T 12031U
 #define LCR_ERR_LCRPID_PAR_TV 12030U
 #define LCR_ERR_LCRPID_PAR_TN 12029U
 #define LCR_ERR_LCRPID_PAR_TF 12028U
 #define LCR_ERR_LCRPID_PAR_KW 12027U
 #define LCR_ERR_LCRPID_PAR_KP 12026U
 #define LCR_ERROR 12025U
 #define LCR_ERR_LCRPID_PAR_KFBK 12025U
 #define LCR_WARN_LCRTEMPPID_WR_PARA 12024U
 #define LCR_WARN_LCRTEMPTune_WR_BASE 12023U
 #define LCR_WARN_LCRTEMPTune_WR_PARA 12022U
 #define LCR_WARN_LCRTEMPTune_HEAT_TP 12021U
 #define LCR_WARN_LCRDBLPID_TUNE_CHANGE 12019U
 #define LCR_WARN_LCRTT_MEM 12018U
 #define LCR_WARN_LCRTT_TT_INT 12017U
 #define LCR_WARN_LCRTT_TT_TS 12016U
 #define LCR_WARN_LCRTT_TT_ZERO 12015U
 #define LCR_WARN_LCRPT12_T2_INT 12014U
 #define LCR_WARN_LCRPT12_T2_TS 12013U
 #define LCR_WARN_LCRPT12_T2_ZERO 12012U
 #define LCR_WARN_LCRPT12_T1_INT 12011U
 #define LCR_WARN_LCRPT12_T1_TS 12010U
 #define LCR_WARN_LCRPID_YMAN_LIMIT 12009U
 #define LCR_WARN_LCRPID_A_LIMIT 12008U
 #define LCR_WARN_Tx_DT 12007U
 #define LCR_WARN_LCRPT12_T1_ZERO 12005U
 #define LCR_WARN_LCRPIDTune_CYCLETIME 12004U
 #define LCR_WARN_LCRPID_YFBK_LIMIT 12003U
 #define LCR_WARN_LCRPID_I_MINLIMIT 12002U
 #define LCR_WARN_LCRPID_I_MAXLIMIT 12001U
 #define LCRSLIMPID_REQU_OSC_1 10000U
 #define LCRPID_TUNE_REQU_OSC_1 10000U
 #define LCRSLIMPID_REQU_CHR_REF_OS 5000U
 #define LCRPID_TUNE_REQU_CHR_REF_OS 5000U
 #define LCRSLIMPID_REQU_CHR_REF_AP 4000U
 #define LCRPID_TUNE_REQU_CHR_REF_AP 4000U
 #define LCRPID_TUNE_REQU_ZN_DIST 3000U
 #define LCRSLIMPID_REQU_ZN_DIST 3000U
 #define LCRPID_TUNE_REQU_CHR_DIST_OS 2000U
 #define LCRSLIMPID_REQU_CHR_DIST_OS 2000U
 #define LCRPID_TUNE_REQU_CHR_DIST_AP 1000U
 #define LCRSLIMPID_REQU_CHR_DIST_AP 1000U
 #define LCRSLIMPID_REQU_P 300U
 #define LCRPID_TUNE_REQU_P 300U
 #define LCRSLIMPID_REQU_PI 200U
 #define LCRPID_TUNE_REQU_PI 200U
 #define LCRTEMP_STEP_DONE 130U
 #define LCRTEMP_STEP_PID_DONE 125U
 #define LCRTEMP_STEP_PID_DONE_COOLONLY 122U
 #define LCRTEMP_STEP_COOL 120U
 #define LCRPID_TUNE_ADDINFO_OSC_PERIOD 111U
 #define LCRTEMP_STEP_START_COOL 110U
 #define LCRTEMP_STEP_WAIT_COOLONLY 105U
 #define LCRPID_MODE_FREEZE_JOLTFREE 105U
 #define LCRPID_MODE_CLOSE_JOLTFREE 104U
 #define LCRPID_MODE_OPEN_JOLTFREE 103U
 #define LCRPID_MODE_MAN_JOLTFREE 102U
 #define LCRTEMP_STEP_WAIT_COOL 100U
 #define LCRPID_TUNE_REQU_PID 100U
 #define LCRSLIMPID_REQU_PID 100U
 #define LCRTEMP_STEP_PID_COOL 90U
 #define LCRTEMP_STEP_PID 80U
 #define LCRTEMP_STEP_FREE 70U
 #define LCRTEMP_STEP_START_FREE 60U
 #define LCRTEMP_STEP_WAIT_FREE 50U
 #define LCRPID_TUNE_STATE_FINISHED 50U
 #define LCRPID_TUNE_STATE_RESET_CNTL 49U
 #define LCRPID_TUNE_STATE_CALC_PARA 45U
 #define LCRTEMP_STEP_PID_FREE 40U
 #define LCRTEMP_STEP_HEAT 30U
 #define LCRPID_TUNE_STATE_STEP_WAITEQ2 22U
 #define LCRPID_TUNE_STATE_STEP_MAXGRAD 21U
 #define LCRSLIMPID_REQU_DIR_NEG 20U
 #define LCRTEMP_STEP_START_HEAT 20U
 #define LCRPID_TUNE_STATE_STEP_WAITEQ1 20U
 #define LCRPID_TUNE_REQU_DIR_NEG 20U
 #define LCRPID_TUNE_STATE_OSC_CNTLPAR 19U
 #define LCRPID_TUNE_STATE_OSC_PERFORM_2 13U
 #define LCRPID_TUNE_STATE_OSC_PERFORM_1 12U
 #define LCRPID_TUNE_STATE_OSC_SEQ_CNTL 11U
 #define LCRTEMP_STEP_WAIT_HEAT 10U
 #define LCRSLIMPID_REQU_DIR_POS 10U
 #define LCRPID_TUNE_STATE_OSCILLATE 10U
 #define LCRPID_TUNE_REQU_DIR_POS 10U
 #define LCRDBLPID_MODE_TUNE_Y2 9U
 #define LCRDBLPID_MODE_TUNE_Y1 8U
 #define LCRDBLPID_MODE_TUNE_6 7U
 #define LCRDBLPID_MODE_TUNE_4 6U
 #define LCRPID_FBK_MODE_SET_YI 5U
 #define LCRPID_MODE_FREEZE 5U
 #define LCRTEMP_STEP_WAIT 5U
 #define LCRSLIMPID_REQU_WRITE_PARAS 4U
 #define LCRPID_MODE_CLOSE 4U
 #define LCRPID_FBK_MODE_LIMIT_YI 4U
 #define LCRDBLPID_TSTATE_ERROR 4U
 #define LCRPID_FBK_MODE_EXT_SELECTOR 3U
 #define LCRSLIMPID_REQU_READ_PARAS 3U
 #define LCRDBLPID_TSTATE_FINISHED 3U
 #define LCRPID_MODE_OPEN 3U
 #define LCRPID_TUNE_REQU_STEPRESPONSE 2U
 #define LCRPID_FBK_MODE_EXTERN 2U
 #define LCRPID_MODE_MAN 2U
 #define LCRSLIMPID_REQU_STEPRESPONSE 2U
 #define LCRPID_D_MODE_E 2U
 #define LCRDBLPID_TSTATE_Y2 2U
 #define LCRTEMPPID_MODE_MAN 2U
 #define LCRPID_DEADBAND_MODE_STANDARD_I 2U
 #define LCRSLIMPID_REQU_OSCILLATE 1U
 #define LCRTEMP_COOL 1U
 #define LCRTEMP_PT2 1U
 #define LCRTEMP_HYST_MODE_JOLTFREE 1U
 #define LCRTEMPPID_MODE_AUTO 1U
 #define LCRPID_TUNE_REQU_OSCILLATE 1U
 #define LCRDBLPID_TSTATE_Y1 1U
 #define LCRPID_FBK_MODE_INTERN 1U
 #define LCRPID_DEADBAND_MODE_STANDARD 1U
 #define LCRPID_D_MODE_X 1U
 #define LCRPID_MODE_AUTO 1U
 #define LCRTEMPTune_MODE_EXP 1U
 #define LCRPID_TUNE_REQU_OFF 0U
 #define LCRDBLPID_TSTATE_OFF 0U
 #define LCRTEMPTune_MODE_DEF 0U
 #define LCRTEMP_PT1 0U
 #define LCRSLIMPID_REQU_OFF 0U
 #define LCRPID_TUNE_STATE_READY 0U
 #define LCRPID_MODE_OFF 0U
 #define LCRTEMP_HEAT 0U
 #define LCRPID_DEADBAND_MODE_ZERO 0U
#else
 #ifndef _GLOBAL_CONST
   #define _GLOBAL_CONST _WEAK const
 #endif
 _GLOBAL_CONST unsigned long LCRPID_TUNE_REQU_PER_5;
 _GLOBAL_CONST unsigned long LCRSLIMPID_REQU_PER_5;
 _GLOBAL_CONST unsigned long LCRSLIMPID_REQU_PER_4;
 _GLOBAL_CONST unsigned long LCRPID_TUNE_REQU_PER_4;
 _GLOBAL_CONST unsigned long LCRPID_TUNE_REQU_PER_3;
 _GLOBAL_CONST unsigned long LCRSLIMPID_REQU_PER_3;
 _GLOBAL_CONST unsigned short LCRTEMP_STEP_ERROR;
 _GLOBAL_CONST unsigned short LCR_ERR_DISABLED;
 _GLOBAL_CONST unsigned short LCR_ERR_PT2O_TF_NEG_ZERO;
 _GLOBAL_CONST unsigned short LCR_ERR_PT2O_D_NEG;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRTEMPTune_DT_IGNORED;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRTEMPPID_INVALID_MODE;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRTEMPTune_INVALID_MODE;
 _GLOBAL_CONST unsigned short LCR_WARN_PT2O_TF_TS;
 _GLOBAL_CONST unsigned short LCR_WARN_LCRTEMPTune_ASYNC;
 _GLOBAL_CONST unsigned short LCR_WARN_LCRTEMPTune_DT_HIGH;
 _GLOBAL_CONST unsigned short LCR_ERR_SCHEDULE_N;
 _GLOBAL_CONST unsigned short LCR_ERR_SCHEDULE_P;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRTEMPPID_NO_TALT;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRTEMPPID_TKNICK;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRTEMPTune_TASKTIME_0;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRTEMPPID_ILLEGALMODE;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRTEMPPID_WR_PTR;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRTEMPPID_WR_PARA;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRTEMPTune_WR_TSET;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRTEMPTune_WR_PTR;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRPIDTune_MAXMIN;
 _GLOBAL_CONST unsigned short LCR_ERR_POINTER;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRDBLPID_DX_DT;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRDBLPID_WX_LOW;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRPIDTune_CONTROL_VAR;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRPIDTune_INVALID_REQU;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRPID_PAR_FBKMODE;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRPID_PAR_DYMAX;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRPID_PAR_DMODE;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRPID_PARADAT;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRPID_MODE;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRPID_IDENT;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRMovAvgFlt_BASE;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRIntegrate_TN;
 _GLOBAL_CONST unsigned long LCRPID_TUNE_REQU_OSC_3;
 _GLOBAL_CONST unsigned long LCRSLIMPID_REQU_OSC_3;
 _GLOBAL_CONST unsigned long LCRPID_TUNE_REQU_OSC_2;
 _GLOBAL_CONST unsigned long LCRSLIMPID_REQU_OSC_2;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRTT_TT_NEG;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRPT12_T2_NEG;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRPT12_T1_NEG;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRCurveByPoints_TABLE;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRPID_PAR_DEADBAND;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRPID_PAR_WX_MAXMIN;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRPID_PAR_DEADBAND_MODE;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRPIDTune_W_CHANGED;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRPIDTune_TIMEOUT;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRPIDTune_PARAMETER;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRPIDTune_ABORT;
 _GLOBAL_CONST unsigned short LCR_ERR_MAXMIN;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRContinServo_TIMPULSE;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRContinServo_TCHANGE;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRRamp_DYUP_DYDOWN;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRPWM_TPERIOD;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRPWM_TPULSE;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRPWM_TMINPULSE;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRPT1_T;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRPID_PAR_TV;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRPID_PAR_TN;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRPID_PAR_TF;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRPID_PAR_KW;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRPID_PAR_KP;
 _GLOBAL_CONST unsigned short LCR_ERROR;
 _GLOBAL_CONST unsigned short LCR_ERR_LCRPID_PAR_KFBK;
 _GLOBAL_CONST unsigned short LCR_WARN_LCRTEMPPID_WR_PARA;
 _GLOBAL_CONST unsigned short LCR_WARN_LCRTEMPTune_WR_BASE;
 _GLOBAL_CONST unsigned short LCR_WARN_LCRTEMPTune_WR_PARA;
 _GLOBAL_CONST unsigned short LCR_WARN_LCRTEMPTune_HEAT_TP;
 _GLOBAL_CONST unsigned short LCR_WARN_LCRDBLPID_TUNE_CHANGE;
 _GLOBAL_CONST unsigned short LCR_WARN_LCRTT_MEM;
 _GLOBAL_CONST unsigned short LCR_WARN_LCRTT_TT_INT;
 _GLOBAL_CONST unsigned short LCR_WARN_LCRTT_TT_TS;
 _GLOBAL_CONST unsigned short LCR_WARN_LCRTT_TT_ZERO;
 _GLOBAL_CONST unsigned short LCR_WARN_LCRPT12_T2_INT;
 _GLOBAL_CONST unsigned short LCR_WARN_LCRPT12_T2_TS;
 _GLOBAL_CONST unsigned short LCR_WARN_LCRPT12_T2_ZERO;
 _GLOBAL_CONST unsigned short LCR_WARN_LCRPT12_T1_INT;
 _GLOBAL_CONST unsigned short LCR_WARN_LCRPT12_T1_TS;
 _GLOBAL_CONST unsigned short LCR_WARN_LCRPID_YMAN_LIMIT;
 _GLOBAL_CONST unsigned short LCR_WARN_LCRPID_A_LIMIT;
 _GLOBAL_CONST unsigned short LCR_WARN_Tx_DT;
 _GLOBAL_CONST unsigned short LCR_WARN_LCRPT12_T1_ZERO;
 _GLOBAL_CONST unsigned short LCR_WARN_LCRPIDTune_CYCLETIME;
 _GLOBAL_CONST unsigned short LCR_WARN_LCRPID_YFBK_LIMIT;
 _GLOBAL_CONST unsigned short LCR_WARN_LCRPID_I_MINLIMIT;
 _GLOBAL_CONST unsigned short LCR_WARN_LCRPID_I_MAXLIMIT;
 _GLOBAL_CONST unsigned long LCRSLIMPID_REQU_OSC_1;
 _GLOBAL_CONST unsigned long LCRPID_TUNE_REQU_OSC_1;
 _GLOBAL_CONST unsigned long LCRSLIMPID_REQU_CHR_REF_OS;
 _GLOBAL_CONST unsigned long LCRPID_TUNE_REQU_CHR_REF_OS;
 _GLOBAL_CONST unsigned long LCRSLIMPID_REQU_CHR_REF_AP;
 _GLOBAL_CONST unsigned long LCRPID_TUNE_REQU_CHR_REF_AP;
 _GLOBAL_CONST unsigned long LCRPID_TUNE_REQU_ZN_DIST;
 _GLOBAL_CONST unsigned long LCRSLIMPID_REQU_ZN_DIST;
 _GLOBAL_CONST unsigned long LCRPID_TUNE_REQU_CHR_DIST_OS;
 _GLOBAL_CONST unsigned long LCRSLIMPID_REQU_CHR_DIST_OS;
 _GLOBAL_CONST unsigned long LCRPID_TUNE_REQU_CHR_DIST_AP;
 _GLOBAL_CONST unsigned long LCRSLIMPID_REQU_CHR_DIST_AP;
 _GLOBAL_CONST unsigned long LCRSLIMPID_REQU_P;
 _GLOBAL_CONST unsigned long LCRPID_TUNE_REQU_P;
 _GLOBAL_CONST unsigned long LCRSLIMPID_REQU_PI;
 _GLOBAL_CONST unsigned long LCRPID_TUNE_REQU_PI;
 _GLOBAL_CONST unsigned short LCRTEMP_STEP_DONE;
 _GLOBAL_CONST unsigned short LCRTEMP_STEP_PID_DONE;
 _GLOBAL_CONST unsigned short LCRTEMP_STEP_PID_DONE_COOLONLY;
 _GLOBAL_CONST unsigned short LCRTEMP_STEP_COOL;
 _GLOBAL_CONST unsigned short LCRPID_TUNE_ADDINFO_OSC_PERIOD;
 _GLOBAL_CONST unsigned short LCRTEMP_STEP_START_COOL;
 _GLOBAL_CONST unsigned short LCRTEMP_STEP_WAIT_COOLONLY;
 _GLOBAL_CONST unsigned char LCRPID_MODE_FREEZE_JOLTFREE;
 _GLOBAL_CONST unsigned char LCRPID_MODE_CLOSE_JOLTFREE;
 _GLOBAL_CONST unsigned char LCRPID_MODE_OPEN_JOLTFREE;
 _GLOBAL_CONST unsigned char LCRPID_MODE_MAN_JOLTFREE;
 _GLOBAL_CONST unsigned short LCRTEMP_STEP_WAIT_COOL;
 _GLOBAL_CONST unsigned long LCRPID_TUNE_REQU_PID;
 _GLOBAL_CONST unsigned long LCRSLIMPID_REQU_PID;
 _GLOBAL_CONST unsigned short LCRTEMP_STEP_PID_COOL;
 _GLOBAL_CONST unsigned short LCRTEMP_STEP_PID;
 _GLOBAL_CONST unsigned short LCRTEMP_STEP_FREE;
 _GLOBAL_CONST unsigned short LCRTEMP_STEP_START_FREE;
 _GLOBAL_CONST unsigned short LCRTEMP_STEP_WAIT_FREE;
 _GLOBAL_CONST unsigned short LCRPID_TUNE_STATE_FINISHED;
 _GLOBAL_CONST unsigned short LCRPID_TUNE_STATE_RESET_CNTL;
 _GLOBAL_CONST unsigned short LCRPID_TUNE_STATE_CALC_PARA;
 _GLOBAL_CONST unsigned short LCRTEMP_STEP_PID_FREE;
 _GLOBAL_CONST unsigned short LCRTEMP_STEP_HEAT;
 _GLOBAL_CONST unsigned short LCRPID_TUNE_STATE_STEP_WAITEQ2;
 _GLOBAL_CONST unsigned short LCRPID_TUNE_STATE_STEP_MAXGRAD;
 _GLOBAL_CONST unsigned long LCRSLIMPID_REQU_DIR_NEG;
 _GLOBAL_CONST unsigned short LCRTEMP_STEP_START_HEAT;
 _GLOBAL_CONST unsigned short LCRPID_TUNE_STATE_STEP_WAITEQ1;
 _GLOBAL_CONST unsigned long LCRPID_TUNE_REQU_DIR_NEG;
 _GLOBAL_CONST unsigned short LCRPID_TUNE_STATE_OSC_CNTLPAR;
 _GLOBAL_CONST unsigned short LCRPID_TUNE_STATE_OSC_PERFORM_2;
 _GLOBAL_CONST unsigned short LCRPID_TUNE_STATE_OSC_PERFORM_1;
 _GLOBAL_CONST unsigned short LCRPID_TUNE_STATE_OSC_SEQ_CNTL;
 _GLOBAL_CONST unsigned short LCRTEMP_STEP_WAIT_HEAT;
 _GLOBAL_CONST unsigned long LCRSLIMPID_REQU_DIR_POS;
 _GLOBAL_CONST unsigned short LCRPID_TUNE_STATE_OSCILLATE;
 _GLOBAL_CONST unsigned long LCRPID_TUNE_REQU_DIR_POS;
 _GLOBAL_CONST unsigned char LCRDBLPID_MODE_TUNE_Y2;
 _GLOBAL_CONST unsigned char LCRDBLPID_MODE_TUNE_Y1;
 _GLOBAL_CONST unsigned char LCRDBLPID_MODE_TUNE_6;
 _GLOBAL_CONST unsigned char LCRDBLPID_MODE_TUNE_4;
 _GLOBAL_CONST unsigned char LCRPID_FBK_MODE_SET_YI;
 _GLOBAL_CONST unsigned char LCRPID_MODE_FREEZE;
 _GLOBAL_CONST unsigned short LCRTEMP_STEP_WAIT;
 _GLOBAL_CONST unsigned long LCRSLIMPID_REQU_WRITE_PARAS;
 _GLOBAL_CONST unsigned char LCRPID_MODE_CLOSE;
 _GLOBAL_CONST unsigned char LCRPID_FBK_MODE_LIMIT_YI;
 _GLOBAL_CONST unsigned char LCRDBLPID_TSTATE_ERROR;
 _GLOBAL_CONST unsigned char LCRPID_FBK_MODE_EXT_SELECTOR;
 _GLOBAL_CONST unsigned long LCRSLIMPID_REQU_READ_PARAS;
 _GLOBAL_CONST unsigned char LCRDBLPID_TSTATE_FINISHED;
 _GLOBAL_CONST unsigned char LCRPID_MODE_OPEN;
 _GLOBAL_CONST unsigned long LCRPID_TUNE_REQU_STEPRESPONSE;
 _GLOBAL_CONST unsigned char LCRPID_FBK_MODE_EXTERN;
 _GLOBAL_CONST unsigned char LCRPID_MODE_MAN;
 _GLOBAL_CONST unsigned long LCRSLIMPID_REQU_STEPRESPONSE;
 _GLOBAL_CONST unsigned char LCRPID_D_MODE_E;
 _GLOBAL_CONST unsigned char LCRDBLPID_TSTATE_Y2;
 _GLOBAL_CONST unsigned long LCRTEMPPID_MODE_MAN;
 _GLOBAL_CONST unsigned char LCRPID_DEADBAND_MODE_STANDARD_I;
 _GLOBAL_CONST unsigned long LCRSLIMPID_REQU_OSCILLATE;
 _GLOBAL_CONST unsigned char LCRTEMP_COOL;
 _GLOBAL_CONST unsigned char LCRTEMP_PT2;
 _GLOBAL_CONST unsigned char LCRTEMP_HYST_MODE_JOLTFREE;
 _GLOBAL_CONST unsigned long LCRTEMPPID_MODE_AUTO;
 _GLOBAL_CONST unsigned long LCRPID_TUNE_REQU_OSCILLATE;
 _GLOBAL_CONST unsigned char LCRDBLPID_TSTATE_Y1;
 _GLOBAL_CONST unsigned char LCRPID_FBK_MODE_INTERN;
 _GLOBAL_CONST unsigned char LCRPID_DEADBAND_MODE_STANDARD;
 _GLOBAL_CONST unsigned char LCRPID_D_MODE_X;
 _GLOBAL_CONST unsigned char LCRPID_MODE_AUTO;
 _GLOBAL_CONST unsigned long LCRTEMPTune_MODE_EXP;
 _GLOBAL_CONST unsigned long LCRPID_TUNE_REQU_OFF;
 _GLOBAL_CONST unsigned char LCRDBLPID_TSTATE_OFF;
 _GLOBAL_CONST unsigned long LCRTEMPTune_MODE_DEF;
 _GLOBAL_CONST unsigned char LCRTEMP_PT1;
 _GLOBAL_CONST unsigned long LCRSLIMPID_REQU_OFF;
 _GLOBAL_CONST unsigned short LCRPID_TUNE_STATE_READY;
 _GLOBAL_CONST unsigned char LCRPID_MODE_OFF;
 _GLOBAL_CONST unsigned char LCRTEMP_HEAT;
 _GLOBAL_CONST unsigned char LCRPID_DEADBAND_MODE_ZERO;
#endif




/* Datatypes and datatypes of function blocks */
typedef struct lcrCurveByPoints_TabEntry_type
{	float x;
	float y;
} lcrCurveByPoints_TabEntry_type;

typedef struct lcrdblpid_par_typ
{	float Y_max;
	float Y_min;
	signed short K_fact;
	float Kp;
	float Tn;
	float Tv;
} lcrdblpid_par_typ;

typedef struct lcrpid_tune_osc_options_typ
{	float osc_minAmplitude;
	float Q_min;
} lcrpid_tune_osc_options_typ;

typedef struct lcrpid_tune_step_options_typ
{	float eqDeltaX;
	float eqDeltaWX;
	float eqDeltat;
	float evalDeltaX;
	unsigned short evalNfilter;
	unsigned short exitNotMaxdXCount;
	float exitdXRatio;
} lcrpid_tune_step_options_typ;

typedef struct lcrdblpid_tune_typ
{	signed short P1_manualAdjust;
	signed short I1_manualAdjust;
	signed short D1_manualAdjust;
	signed short P2_manualAdjust;
	signed short I2_manualAdjust;
	signed short D2_manualAdjust;
	float X_min;
	float X_max;
	float X0;
	float de_min;
	float Y0;
	float Y1step;
	float Y2step;
	unsigned long tuneY1_opt;
	unsigned long tuneY2_opt;
	unsigned char tune_first;
	float hyst;
	float measDelta;
	struct lcrpid_tune_osc_options_typ osc_opt;
	struct lcrpid_tune_step_options_typ step_opt;
} lcrdblpid_tune_typ;

typedef struct lcrpid_internal_typ
{	unsigned short size;
	plcbit valid;
	float WX_max;
	float WX_min;
	plcbit invert;
	float deadband;
	unsigned char deadband_mode;
	float dY_max;
	float Kp;
	float Kp_Tn;
	float Tv_Tf;
	float Tf_reciproc;
	float Kw;
	float Kfbk_Kp;
	float Kfbk_Kp_max;
	unsigned char fbk_mode;
	unsigned char d_mode;
	unsigned char force_mode;
	float Y_force;
	float W;
	float X;
	unsigned char pid_init;
	signed long Yp1;
	signed long Yp2;
	signed long dYi1;
	signed long dYi2;
	signed long Yi1;
	signed long Yi2;
	float dt_Tf;
	signed long a11;
	signed long a12;
	signed long a21;
	signed long a22;
	signed long Yd1;
	signed long Yd2;
	signed long Ytotal1;
	signed long Ytotal2;
	signed long Ylim1;
	signed long Ylim2;
	signed long Y1;
	signed long Y2;
	float deltaY_fbk;
	float e_fbk;
} lcrpid_internal_typ;

typedef struct lcrpid_procPar_typ
{	unsigned short size;
	plcbit valid;
	plcbit stepResp_valid;
	float stepResp_v;
	float stepResp_t_u;
	float stepResp_t_g;
	plcbit osc_valid;
	float osc_amplitudeRatio;
	float osc_tPeriod;
	plcbit force_params;
	float Kp;
	float Kp_tune;
	float Tn;
	float Tn_tune;
	float Tv;
	float Tv_tune;
} lcrpid_procPar_typ;

typedef struct lcrpid_old_typ
{	struct lcrpid_procPar_typ processPar;
	signed short P_manualAdjust;
	signed short I_manualAdjust;
	signed short D_manualAdjust;
	float Y_min;
	float Y_max;
	float dY_max;
	float Tf_Tv;
	float Kw;
	float Kfbk;
	float deadband;
	float W;
	unsigned long request;
	unsigned char fbk_mode;
	unsigned char d_mode;
	plcbit invert;
	plcbit enable;
} lcrpid_old_typ;

typedef struct lcrpid_osc_val_typ
{	float X;
	float t;
} lcrpid_osc_val_typ;

typedef struct lcrpid_osc_per_typ
{	struct lcrpid_osc_val_typ max;
	struct lcrpid_osc_val_typ min;
} lcrpid_osc_per_typ;

typedef struct lcrpid_tune_addpar_typ
{	float t_max_tune;
	float WX_min;
	float WX_max;
	float dY_max;
	float Tf_Tv;
	float Kw;
	float Kfbk;
	unsigned char fbk_mode;
	unsigned char d_mode;
	float deadband;
	unsigned char deadband_mode;
	plcbit invert;
} lcrpid_tune_addpar_typ;

typedef struct lcrpid_tune_osc_typ
{	struct lcrpid_tune_osc_options_typ options;
	unsigned short oscPhase;
	signed char dir;
	plcbit enHi;
	plcbit enLo;
	float Y_hi;
	float Y_lo;
	unsigned short i_maxPeriod;
	unsigned short i_period;
	float X_ampl;
	float X_avg;
	float X_min_avg;
	float X_max_avg;
	float Y_avg;
	float deltaY;
	float t_Ylohi[5];
	float t_Yhilo[5];
	float Q_act;
	float a_wx;
	float amplitudeRatio;
	float Ku;
	float tPeriod;
	struct lcrpid_osc_per_typ period[5];
} lcrpid_tune_osc_typ;

typedef struct lcrpid_tune_step_typ
{	struct lcrpid_tune_step_options_typ options;
	float Y0;
	float Y1;
	float t_jump;
	float W;
	float X0;
	float Xmax;
	float Xmin;
	float Xfiltered;
	plcbit deltaXok;
	plcbit deltaWXok;
	float eqTime;
	signed char dir;
	float deltaX;
	float X1;
	float t1;
	plcbit t1set;
	float dX_dt;
	float dX_dt_max;
	float XmaxGrad;
	float maxX1;
	float maxX2;
	float maxt1;
	float maxt2;
	float tmaxGrad;
	float gainFactor;
	float deadTime;
	float riseTime;
	unsigned short notMaxCount;
	float gradientRatio;
} lcrpid_tune_step_typ;

typedef struct lcrpt2o_Internal_typ
{	signed long Ts;
	unsigned long Ts_dbl_1;
	unsigned long Ts_dbl_2;
	float V_old;
	float D_old;
	float Tf_old;
	unsigned char Set_y_old;
	unsigned char Set_y_2;
	unsigned long x1_dbl_1;
	unsigned long x1_dbl_2;
	unsigned long x2_dbl_1;
	unsigned long x2_dbl_2;
	unsigned long Sqrt_D_1_dbl_1;
	unsigned long Sqrt_D_1_dbl_2;
	unsigned long Ts_Tf_dbl_1;
	unsigned long Ts_Tf_dbl_2;
	unsigned long Exp_D_Ts_Tf_dbl_1;
	unsigned long Exp_D_Ts_Tf_dbl_2;
	unsigned long a0_dbl_1;
	unsigned long a0_dbl_2;
	unsigned long a1_dbl_1;
	unsigned long a1_dbl_2;
	unsigned long b0_dbl_1;
	unsigned long b0_dbl_2;
	unsigned long b1_dbl_1;
	unsigned long b1_dbl_2;
	unsigned long Bootkey;
} lcrpt2o_Internal_typ;

typedef struct LCRPWM
{
	/* VAR_INPUT (analog) */
	float x;
	float max_value;
	float min_value;
	float t_min_pulse;
	float t_period;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	float t_on;
	float t_off;
	/* VAR (analog) */
	signed long cnt_terron_1;
	signed long cnt_terron_2;
	signed long cnt_terroff_1;
	signed long cnt_terroff_2;
	signed long cnt_t_pulse_1;
	signed long cnt_t_pulse_2;
	unsigned long store1;
	unsigned long store2;
	unsigned long timeCnt;
	struct SysInfo sysinfo_inst;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR_OUTPUT (digital) */
	plcbit pulse;
	/* VAR (digital) */
	plcbit corr;
} LCRPWM_typ;

typedef struct lcrschedule_add_typ
{	float periodTime;
	float onTime;
	float t_on_intern;
	float bcOnTime;
	unsigned short sortIndex;
	struct LCRPWM fbkPWM;
	plcbit flagDelay;
} lcrschedule_add_typ;

typedef struct lcrschedule_par_typ
{	float P;
	float X;
	plcbit pulse;
	float Pout;
	plcbit lim;
	struct lcrschedule_add_typ Internal;
} lcrschedule_par_typ;

typedef struct lcrslimpid_par_typ
{	float Y_max;
	float Y_min;
	float Kp;
	float Tn;
	float Tv;
	float Kfbk;
} lcrslimpid_par_typ;

typedef struct lcrtemp_add_typ
{	float mem01;
	float mem02;
	float mem10;
	float mem20;
	float exp_mem;
	float cnt01;
	float cnt02;
	float cnt10;
	float cnt20;
	float cnt03;
	float cnt30;
	float cnt00;
	float t_ignore_dT_heat;
	float t_ignore_dT_free;
	float t_ignore_dT_cool;
	float yMin;
	float yMax;
	unsigned long reserved3;
	unsigned long reserved4;
	plcbit reserved5;
	plcbit reserved6;
} lcrtemp_add_typ;

typedef struct lcrtemp_pid_internal_typ
{	plcbit enable_cooling;
	plcbit disable_heating;
	float hyst;
	float delay;
	float Kw;
	float Kfbk;
	float Kp_h;
	float Tn_h;
	float Tv_h;
	float Kp_c;
	float Tn_c;
	float Tv_c;
	float dynGeneral;
	float dynHeat;
	float dynCool;
	float mem01;
	float mem02;
	float mem10;
	float mem20;
	float exp_mem;
	float yMin;
	float yMax;
} lcrtemp_pid_internal_typ;

typedef struct lcrtemp_pid_opt_typ
{	float Kp_h;
	float Tn_h;
	float Tv_h;
	float Tf_h;
	float Kp_c;
	float Tn_c;
	float Tv_c;
	float Tf_c;
	float dynGeneral;
	float dynHeat;
	float dynCool;
} lcrtemp_pid_opt_typ;

typedef struct lcrtemp_pid_set_typ
{	float hyst;
	unsigned char hyst_mode;
	float delay;
	float Kw;
	float Kfbk;
} lcrtemp_pid_set_typ;

typedef struct lcrtemp_tune_set_typ
{	unsigned long mode;
	float Temp_amb;
	float dRatio_heat;
	float cnt_tp_heat;
	float delta_T_heat;
	float dT_min_heat;
	float dRatio_free;
	float cnt_tp_free;
	float delta_T_free;
	float dT_min_free;
	float dRatio_cool;
	float cnt_tp_cool;
	float delta_T_cool;
	float dT_min_cool;
	float delta_T_sync_heat;
	float delta_dT_sync_heat;
	float cnt_wait_heat;
	float delta_T_sync_free;
	float delta_dT_sync_free;
	float cnt_wait_free;
	float delta_T_sync_cool;
	float delta_dT_sync_cool;
	float cnt_wait_cool;
	float filter_base_T;
	float delta_T_sync_stop;
	float Y_heat_tune;
} lcrtemp_tune_set_typ;

typedef struct lcrtemp_set_typ
{	plcbit enable_cooling;
	plcbit disable_heating;
	struct lcrtemp_pid_opt_typ PIDpara;
	struct lcrtemp_tune_set_typ TuneSet;
	struct lcrtemp_pid_set_typ PIDSet;
	struct lcrtemp_add_typ Internal;
} lcrtemp_set_typ;

typedef struct lcrtemp_tune_internal_typ
{	plcbit cool_tuning;
	plcbit disable_heating;
	unsigned long mode;
	float Temp_amb;
	float dRatio_heat;
	float cnt_tp_heat;
	float delta_T_heat;
	float dT_min_heat;
	float dRatio_free;
	float cnt_tp_free;
	float delta_T_free;
	float dT_min_free;
	float dRatio_cool;
	float cnt_tp_cool;
	float delta_T_cool;
	float dT_min_cool;
	float delta_T_sync_heat;
	float delta_dT_sync_heat;
	float cnt_wait_heat;
	float delta_T_sync_free;
	float delta_dT_sync_free;
	float cnt_wait_free;
	float delta_T_sync_cool;
	float delta_dT_sync_cool;
	float cnt_wait_cool;
	float filter_base_T;
	float t_ignore_dT_heat;
	float t_ignore_dT_free;
	float t_ignore_dT_cool;
	float delta_T_sync_stop;
} lcrtemp_tune_internal_typ;

typedef struct LCRScal
{
	/* VAR_INPUT (analog) */
	float x;
	float x1;
	float y1;
	float x2;
	float y2;
	/* VAR_OUTPUT (analog) */
	float y;
} LCRScal_typ;

typedef struct LCRPID
{
	/* VAR_INPUT (analog) */
	unsigned long ident;
	float W;
	float X;
	float Y_max;
	float Y_min;
	float A;
	float Y_man;
	float Y_fbk;
	unsigned char mode;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	float e;
	float Y;
	float Yp;
	float Yi;
	float Yd;
	/* VAR (analog) */
	float Yi_set;
	float Yi_min;
	float Yi_max;
	float Yi_minInternal;
	float Yi_maxInternal;
	float Tv_Tf_old;
	float e_old;
	unsigned short deadband_state;
	struct SysInfo sysinfo_inst;
	struct LCRScal scal_inst;
	unsigned long store1;
	unsigned long store2;
	unsigned long timeCnt;
	unsigned short musecs_old;
	/* VAR_INPUT (digital) */
	plcbit enable;
	plcbit hold_I;
	/* VAR (digital) */
	plcbit Set_Yi;
	plcbit force_Yi;
	plcbit joltFreeDoneLowerLim;
	plcbit joltFreeDoneUpperLim;
	plcbit enable_old;
} LCRPID_typ;

typedef struct LCRCurveByPoints
{
	/* VAR_INPUT (analog) */
	float x;
	unsigned short NoOfPoints;
	struct lcrCurveByPoints_TabEntry_type* ptr_table;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	float y;
	/* VAR (analog) */
	signed short i_tab;
	unsigned short iterations;
	struct LCRScal scal1;
} LCRCurveByPoints_typ;

typedef struct LCRPIDpara
{
	/* VAR_INPUT (analog) */
	float WX_max;
	float WX_min;
	float deadband;
	unsigned char deadband_mode;
	float dY_max;
	float Kp;
	float Tn;
	float Tv;
	float Tf;
	float Kw;
	float Kfbk;
	unsigned char fbk_mode;
	unsigned char d_mode;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long ident;
	/* VAR (analog) */
	struct lcrpid_internal_typ internal_data;
	/* VAR_INPUT (digital) */
	plcbit enable;
	plcbit enter;
	plcbit invert;
} LCRPIDpara_typ;

typedef struct LCRContinServo
{
	/* VAR_INPUT (analog) */
	float x;
	float max_value;
	float min_value;
	float t_impulse;
	float t_change_up;
	float t_change_down;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	float hysteresis_up;
	float hysteresis_down;
	/* VAR (analog) */
	unsigned short counter_state;
	unsigned long bootkey_old;
	unsigned long systicks_old;
	unsigned short musecs_old;
	signed long t_cnt_1;
	signed long t_cnt_2;
	signed long y_dbl_1;
	signed long y_dbl_2;
	struct SysInfo sysInfo_inst;
	/* VAR_INPUT (digital) */
	plcbit enable;
	plcbit ref;
	/* VAR_OUTPUT (digital) */
	plcbit up;
	plcbit down;
	plcbit refOk;
	/* VAR (digital) */
	plcbit enable_old;
	plcbit ref_old;
} LCRContinServo_typ;

typedef struct LCRPT1
{
	/* VAR_INPUT (analog) */
	float x;
	float t;
	float y_set;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	float y;
	/* VAR (analog) */
	unsigned short counter_state;
	unsigned long bootkey_old;
	unsigned long systicks_old;
	unsigned short musecs_old;
	signed long y_dbl_1;
	signed long y_dbl_2;
	struct SysInfo sysinfo_inst;
	/* VAR_INPUT (digital) */
	plcbit enable;
	plcbit set;
} LCRPT1_typ;

typedef struct LCRRamp
{
	/* VAR_INPUT (analog) */
	float x;
	float dy_up;
	float dy_down;
	float y_max;
	float y_min;
	float y_set;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	float y;
	/* VAR (analog) */
	signed long y_dbl_1;
	signed long y_dbl_2;
	unsigned long timestore1;
	unsigned long timestore2;
	unsigned long getDtForceOff;
	struct SysInfo sysinfo_inst;
	/* VAR_INPUT (digital) */
	plcbit enable;
	plcbit set;
	/* VAR_OUTPUT (digital) */
	plcbit x_reached;
	plcbit max_limit;
	plcbit min_limit;
} LCRRamp_typ;

typedef struct LCRIntegrate
{
	/* VAR_INPUT (analog) */
	float x;
	float tn;
	float y_max;
	float y_min;
	float y_set;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	float y;
	/* VAR (analog) */
	unsigned short counter_state;
	unsigned long bootkey_old;
	unsigned long systicks_old;
	unsigned short musecs_old;
	signed long y_dbl_1;
	signed long y_dbl_2;
	struct SysInfo sysinfo_inst;
	/* VAR_INPUT (digital) */
	plcbit enable;
	plcbit set;
	/* VAR_OUTPUT (digital) */
	plcbit max_limit;
	plcbit min_limit;
} LCRIntegrate_typ;

typedef struct LCRLimit
{
	/* VAR_INPUT (analog) */
	float in;
	signed long max_value;
	signed long min_value;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	signed long out;
	/* VAR_OUTPUT (digital) */
	plcbit max_limit;
	plcbit min_limit;
} LCRLimit_typ;

typedef struct LCRLimScal
{
	/* VAR_INPUT (analog) */
	float x;
	float x1;
	float y1;
	float x2;
	float y2;
	/* VAR_OUTPUT (analog) */
	float y;
} LCRLimScal_typ;

typedef struct LCRMovAvgFlt
{
	/* VAR_INPUT (analog) */
	float x;
	unsigned short base;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	float y;
	/* VAR (analog) */
	signed long sum_old_dbl_1;
	signed long sum_old_dbl_2;
	unsigned long p_xold;
	unsigned short i_xold;
	unsigned short base_old;
	unsigned long bootkey_old;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR (digital) */
	plcbit enable_old;
} LCRMovAvgFlt_typ;

typedef struct LCRTimeBasedOnOff
{
	/* VAR_INPUT (analog) */
	float x;
	float max_value;
	float min_value;
	float timpulse;
	float tchange_up;
	float tchange_down;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	float hysteresis_up;
	float hysteresis_down;
	/* VAR (analog) */
	unsigned short counter_state;
	unsigned long bootkey_old;
	unsigned long systicks_old;
	unsigned short musecs_old;
	signed long t_cnt_1;
	signed long t_cnt_2;
	signed long y_dbl_1;
	signed long y_dbl_2;
	struct SysInfo sysInfo_inst;
	/* VAR_INPUT (digital) */
	plcbit enable;
	plcbit ref;
	/* VAR_OUTPUT (digital) */
	plcbit up;
	plcbit down;
	plcbit refOk;
	/* VAR (digital) */
	plcbit enable_old;
	plcbit ref_old;
} LCRTimeBasedOnOff_typ;

typedef struct LCRDifferentiate
{
	/* VAR_INPUT (analog) */
	float x;
	float tv;
	float tf;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	float y;
	/* VAR (analog) */
	unsigned long store1;
	unsigned long store2;
	unsigned long timeCnt;
	unsigned short counter_state;
	unsigned long bootkey_old;
	unsigned long systicks_old;
	unsigned short musecs_old;
	struct SysInfo sysinfo_inst;
	signed long a11;
	signed long a12;
	signed long a21;
	signed long a22;
	/* VAR_INPUT (digital) */
	plcbit enable;
} LCRDifferentiate_typ;

typedef struct LCRPIDTune
{
	/* VAR_INPUT (analog) */
	float Y_min;
	float Y_max;
	float Y0;
	float Y1;
	float X0;
	float X_min;
	float X_max;
	signed short P_manualAdjust;
	signed short I_manualAdjust;
	signed short D_manualAdjust;
	unsigned long request;
	struct lcrpid_tune_addpar_typ* pAddPar;
	struct lcrpid_tune_osc_options_typ* pOptions_osc;
	struct lcrpid_tune_step_options_typ* pOptions_step;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned short addInfo;
	unsigned long ident;
	unsigned short state;
	/* VAR (analog) */
	float t_autotune;
	unsigned short status_tmp;
	unsigned short counter_state;
	unsigned long bootkey_old;
	unsigned long systicks_old;
	unsigned short musecs_old;
	float e;
	float e_minAmp;
	float e_old_up;
	float e_old_down;
	float e_old;
	struct SysInfo sysinfo_inst;
	struct LCRMovAvgFlt MovAvgFlt_inst;
	struct lcrpid_old_typ old;
	struct lcrpid_procPar_typ processPar;
	struct lcrpid_internal_typ internal_data;
	struct lcrpid_tune_addpar_typ addPar;
	struct lcrpid_tune_osc_typ oscillation;
	struct lcrpid_tune_step_typ stepresponse;
	/* VAR_INPUT (digital) */
	plcbit enable;
	plcbit okToStep;
	/* VAR_OUTPUT (digital) */
	plcbit rdyToStep;
	/* VAR (digital) */
	plcbit curveDown;
	plcbit curveUp;
} LCRPIDTune_typ;

typedef struct LCRSlimPID
{
	/* VAR_INPUT (analog) */
	float W;
	float X;
	unsigned long request;
	struct lcrslimpid_par_typ* pPar;
	/* VAR_OUTPUT (analog) */
	float e;
	float Y;
	unsigned short status;
	unsigned short addInfo;
	/* VAR (analog) */
	struct LCRMovAvgFlt MovAvgFlt_inst;
	struct LCRPIDTune PIDTune_inst;
	struct LCRPID PID_inst;
	unsigned long requ_old;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR (digital) */
	plcbit enable_old;
} LCRSlimPID_typ;

typedef struct LCRPFM
{
	/* VAR_INPUT (analog) */
	float x;
	float max_value;
	float min_value;
	float t_pulse;
	float t_pause;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	float area;
	float area_c;
	float range;
	float last;
	float tpls;
	unsigned short counter_state;
	unsigned long bootkey_old;
	unsigned long systicks_old;
	unsigned short musecs_old;
	struct SysInfo sysinfo_inst;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR_OUTPUT (digital) */
	plcbit pulse;
	/* VAR (digital) */
	plcbit enable_old;
} LCRPFM_typ;

typedef struct LCRTt
{
	/* VAR_INPUT (analog) */
	signed long Tt;
	float x;
	float y_set;
	/* VAR_OUTPUT (analog) */
	float y;
	unsigned short status;
	/* VAR (analog) */
	signed long Ts;
	signed long Tt_Max;
	float* pRingBuf;
	float* pBuf_OutIn;
	unsigned char set_old;
	unsigned char Set_y;
	unsigned long Bootkey;
	/* VAR_INPUT (digital) */
	plcbit enable;
	plcbit set;
	/* VAR (digital) */
	plcbit enable_old;
} LCRTt_typ;

typedef struct LCRPT2
{
	/* VAR_INPUT (analog) */
	float V;
	float T1;
	float T2;
	float x;
	float y_set;
	unsigned char set;
	/* VAR_OUTPUT (analog) */
	float y;
	unsigned short status;
	/* VAR (analog) */
	unsigned long x1_dbl_1;
	unsigned long x1_dbl_2;
	unsigned long x2_dbl_1;
	unsigned long x2_dbl_2;
	signed long Ts;
	unsigned long Ts_dbl_1;
	unsigned long Ts_dbl_2;
	unsigned char set_old;
	unsigned char Set_y;
	unsigned long Bootkey;
	/* VAR_INPUT (digital) */
	plcbit enable;
} LCRPT2_typ;

typedef struct LCRSimModExt
{
	/* VAR_INPUT (analog) */
	signed long Tt_h;
	signed long Tt_c;
	float k_h;
	float k_c;
	float PT2_T1;
	float PT2_T2;
	float Temp_amb;
	float Temp_c;
	float Alpha_h;
	float Alpha_c;
	/* VAR_OUTPUT (analog) */
	float y;
	unsigned short status;
	/* VAR (analog) */
	struct LCRTt Tt_heat;
	struct LCRTt Tt_cool;
	float k_h_intern;
	float k_c_intern;
	struct LCRPT2 PT2;
	float y_c;
	float y_end;
	float y_h;
	unsigned long Bootkey;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR (digital) */
	plcbit enable_old;
} LCRSimModExt_typ;

typedef struct LCRPT1e
{
	/* VAR_INPUT (analog) */
	float V;
	float T1;
	float x;
	float y_set;
	unsigned char set;
	/* VAR_OUTPUT (analog) */
	float y;
	unsigned short status;
	/* VAR (analog) */
	unsigned long x1_dbl_1;
	unsigned long x1_dbl_2;
	signed long Ts;
	unsigned long Ts_dbl_1;
	unsigned long Ts_dbl_2;
	unsigned char set_old;
	unsigned char Set_y;
	unsigned long Bootkey;
	/* VAR_INPUT (digital) */
	plcbit enable;
} LCRPT1e_typ;

typedef struct LCRDblActPID
{
	/* VAR_INPUT (analog) */
	float W;
	float X;
	float Y_man;
	unsigned char mode;
	struct lcrdblpid_par_typ* pPar1;
	struct lcrdblpid_par_typ* pPar2;
	struct lcrpid_tune_addpar_typ* pAddPar;
	struct lcrdblpid_tune_typ* pOpt;
	/* VAR_OUTPUT (analog) */
	float e;
	float Y1;
	float Y2;
	unsigned short status;
	unsigned char tuneState;
	/* VAR (analog) */
	struct LCRPID pid;
	struct LCRPIDTune tune;
	struct SysInfo sysinfo_inst;
	float gradient;
	float Y_avg;
	unsigned long tcnt_1;
	unsigned long tcnt_2;
	float Tmeas;
	float y_lim_old;
	float p_fact;
	unsigned long bootkey_old;
	unsigned long systicks_old;
	unsigned short musecs_old;
	unsigned char use_par;
	unsigned char meas;
	unsigned char mode_old;
	unsigned char tune_step;
	unsigned char tune_grad;
	unsigned char tune_2nd;
	unsigned char invert;
	unsigned char counter_state;
	unsigned char mode_int;
	/* VAR_INPUT (digital) */
	plcbit enable;
	plcbit hold_I;
	plcbit okToStep;
	/* VAR_OUTPUT (digital) */
	plcbit rdyToStep;
	/* VAR (digital) */
	plcbit enable_old;
} LCRDblActPID_typ;

typedef struct LCRMinMax
{
	/* VAR_INPUT (analog) */
	float in;
	/* VAR_OUTPUT (analog) */
	float out_min;
	float out_max;
	/* VAR_INPUT (digital) */
	plcbit reset;
} LCRMinMax_typ;

typedef struct LCRTempPID
{
	/* VAR_INPUT (analog) */
	float Temp_set;
	float Temp;
	float Y_man;
	unsigned long mode;
	struct lcrtemp_set_typ* pSettings;
	/* VAR_OUTPUT (analog) */
	float y_heat;
	float y_cool;
	unsigned short status;
	/* VAR (analog) */
	struct LCRPID pid;
	struct LCRPIDpara pid_para;
	float Temp_set_delay;
	float Temp_set_int;
	float TempSetOld;
	float delayCnt;
	signed char stateOld;
	signed char state;
	float a;
	struct SysInfo sysinfo_inst;
	unsigned char para_check_done;
	struct lcrtemp_pid_internal_typ internal_para;
	float dbl_dt;
	float tAlt;
	float altTime;
	float tKnick;
	float fAlt;
	float a_alt;
	float a_e;
	float a_internal;
	float Temp_set_int_old1;
	float Temp_set_int_old2;
	float Temp_set_int_old3;
	unsigned long mode_old;
	unsigned long timestore1;
	unsigned long timestore2;
	float yManInternal;
	unsigned long timeCnt;
	/* VAR_INPUT (digital) */
	plcbit enable;
	plcbit update;
	/* VAR (digital) */
	plcbit delayFlag;
	plcbit enable_old;
	plcbit altActive;
	plcbit err_flag;
} LCRTempPID_typ;

typedef struct LCRPT2o
{
	/* VAR_INPUT (analog) */
	float V;
	float D;
	float Tf;
	float u;
	unsigned char Set_y;
	float y_set;
	/* VAR_OUTPUT (analog) */
	float y;
	unsigned short status;
	/* VAR (analog) */
	struct lcrpt2o_Internal_typ Internal;
	/* VAR_INPUT (digital) */
	plcbit enable;
} LCRPT2o_typ;

typedef struct LCRTempTune
{
	/* VAR_INPUT (analog) */
	float Temp_set;
	float Temp;
	struct lcrtemp_set_typ* pSettings;
	/* VAR_OUTPUT (analog) */
	float y_heat;
	float y_cool;
	unsigned short status;
	/* VAR (analog) */
	struct LCRPID pid;
	struct LCRPIDpara pid_para;
	struct LCRDifferentiate DT2;
	struct LCRPT2o pt2;
	float Temp_flt;
	unsigned short step;
	float t;
	float Temp_start;
	float mem00;
	float cnt02;
	float cnt33;
	float cnt20;
	float pem01;
	float pem33;
	float pem10;
	float pem02;
	float pem44;
	float pem20;
	float tol01;
	float tol10;
	float tol02;
	float tol20;
	float tol22;
	float Temp_old;
	float delta_Temp;
	unsigned long tcnt_1;
	unsigned long tcnt_2;
	unsigned long tcnt_dT_1;
	unsigned long tcnt_dT_2;
	struct SysInfo sysinfo_inst;
	float Temp_set_internal;
	float timecounter;
	struct lcrtemp_tune_internal_typ internal_para;
	float dbl_dt;
	unsigned long call_counter;
	unsigned long store1;
	unsigned long store2;
	unsigned long timeCnt;
	float timer2;
	unsigned short waitCounter;
	float Y_heat_tune_intern;
	/* VAR_INPUT (digital) */
	plcbit enable;
	plcbit start;
	plcbit okToHeat;
	plcbit okToFree;
	plcbit okToFreeEnd;
	plcbit okToCool;
	plcbit okToCoolEnd;
	/* VAR_OUTPUT (digital) */
	plcbit rdyToHeat;
	plcbit rdyToFree;
	plcbit rdyToFreeEnd;
	plcbit rdyToCool;
	plcbit rdyToCoolEnd;
	plcbit done;
	plcbit busy;
	/* VAR (digital) */
	plcbit enable_old;
} LCRTempTune_typ;

typedef struct LCRSchedulePWM
{
	/* VAR_INPUT (analog) */
	float Pmax;
	unsigned short n;
	unsigned long pPar;
	float min_value;
	float max_value;
	float t_min_pulse;
	float t_period;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	struct SysInfo sysinfo_inst;
	unsigned long store1;
	unsigned long store2;
	unsigned long timeCnt;
	unsigned short numberUnits;
	unsigned short limFact;
	float Pact;
	float Pman;
	float intern0[6];
	struct lcrschedule_par_typ* in;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR (digital) */
	plcbit enable_old;
	plcbit cmd_delay;
	plcbit err_flag;
	plcbit limAll;
} LCRSchedulePWM_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void LCRPID(struct LCRPID* inst);
_BUR_PUBLIC void LCRScal(struct LCRScal* inst);
_BUR_PUBLIC void LCRCurveByPoints(struct LCRCurveByPoints* inst);
_BUR_PUBLIC void LCRPIDpara(struct LCRPIDpara* inst);
_BUR_PUBLIC void LCRContinServo(struct LCRContinServo* inst);
_BUR_PUBLIC void LCRPT1(struct LCRPT1* inst);
_BUR_PUBLIC void LCRRamp(struct LCRRamp* inst);
_BUR_PUBLIC void LCRIntegrate(struct LCRIntegrate* inst);
_BUR_PUBLIC void LCRLimit(struct LCRLimit* inst);
_BUR_PUBLIC void LCRLimScal(struct LCRLimScal* inst);
_BUR_PUBLIC void LCRPWM(struct LCRPWM* inst);
_BUR_PUBLIC void LCRMovAvgFlt(struct LCRMovAvgFlt* inst);
_BUR_PUBLIC void LCRTimeBasedOnOff(struct LCRTimeBasedOnOff* inst);
_BUR_PUBLIC void LCRDifferentiate(struct LCRDifferentiate* inst);
_BUR_PUBLIC void LCRSlimPID(struct LCRSlimPID* inst);
_BUR_PUBLIC void LCRPIDTune(struct LCRPIDTune* inst);
_BUR_PUBLIC void LCRPFM(struct LCRPFM* inst);
_BUR_PUBLIC void LCRSimModExt(struct LCRSimModExt* inst);
_BUR_PUBLIC void LCRTt(struct LCRTt* inst);
_BUR_PUBLIC void LCRPT2(struct LCRPT2* inst);
_BUR_PUBLIC void LCRPT1e(struct LCRPT1e* inst);
_BUR_PUBLIC void LCRDblActPID(struct LCRDblActPID* inst);
_BUR_PUBLIC void LCRMinMax(struct LCRMinMax* inst);
_BUR_PUBLIC void LCRTempPID(struct LCRTempPID* inst);
_BUR_PUBLIC void LCRTempTune(struct LCRTempTune* inst);
_BUR_PUBLIC void LCRPT2o(struct LCRPT2o* inst);
_BUR_PUBLIC void LCRSchedulePWM(struct LCRSchedulePWM* inst);


#ifdef __cplusplus
};
#endif
#endif /* _LOOPCONR_ */

