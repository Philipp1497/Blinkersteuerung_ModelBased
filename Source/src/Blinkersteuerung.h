/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Blinkersteuerung.h
 *
 * Code generated for Simulink model 'Blinkersteuerung'.
 *
 * Model version                  : 8.0
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Sat Aug  6 13:53:31 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Blinkersteuerung_h_
#define RTW_HEADER_Blinkersteuerung_h_
#ifndef Blinkersteuerung_COMMON_INCLUDES_
#define Blinkersteuerung_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Blinkersteuerung_COMMON_INCLUDES_ */

/* Model Code Variants */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T zuendung;                     /* '<Root>/zuendung' */
  real_T links;                        /* '<Root>/links' */
  real_T rechts;                       /* '<Root>/rechts' */
  real_T eingang;                      /* '<Root>/warnblink' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T zuendung_out;                 /* '<Root>/zuendung_out' */
  real_T links_out;                    /* '<Root>/links_out' */
  real_T rechts_out;                   /* '<Root>/rechts_out' */
  real_T ausgang;                      /* '<Root>/warnblink' */
} ExtY;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  int32_T durationCounter_1;           /* '<Root>/Chart2' */
  int32_T durationCounter_1_h;         /* '<Root>/Chart2' */
  int32_T count;                       /* '<Root>/Chart1' */
  uint16_T is_active_c2_Blinkersteuerung;/* '<Root>/Chart2' */
  uint16_T is_c2_Blinkersteuerung;     /* '<Root>/Chart2' */
  uint16_T is_active_c1_Blinkersteuerung;/* '<Root>/Chart1' */
  uint16_T is_c1_Blinkersteuerung;     /* '<Root>/Chart1' */
  uint16_T is_ON_LINKS;                /* '<Root>/Chart1' */
  uint16_T is_ON_BEIDE;                /* '<Root>/Chart1' */
  uint16_T is_ON_RECHTS;               /* '<Root>/Chart1' */
  uint16_T temporalCounter_i1;         /* '<Root>/Chart1' */
  uint16_T is_active_c3_Blinkersteuerung;/* '<Root>/Chart' */
  uint16_T is_c3_Blinkersteuerung;     /* '<Root>/Chart' */
  uint16_T is_ON;                      /* '<Root>/Chart' */
} DW;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void Blinkersteuerung_initialize(void);
extern void Blinkersteuerung_step(void);
extern void writeToPorts(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Blinkersteuerung'
 * '<S1>'   : 'Blinkersteuerung/Chart'
 * '<S2>'   : 'Blinkersteuerung/Chart1'
 * '<S3>'   : 'Blinkersteuerung/Chart2'
 */
#endif                                 /* RTW_HEADER_Blinkersteuerung_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
