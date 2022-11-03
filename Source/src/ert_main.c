/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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


/**

    Gpio Belegung:

    Warnblinktaster:    Gpio23 = Versorgung ,   Gpio26 = Signal

    Rechtsblinktaster:  Gpio7  = Versorgung ,   Gpio22 = Signal

    Linksblinktaster:   Gpio3  = Versorgung ,   Gpio17 = Signal

    Versorgung LEDS:    Gpio20 , Gpio19

**/

#include <stddef.h>
#include <stdio.h>            /* This example main program uses printf/fflush */
#include "Blinkersteuerung.h"          /* Model header file */
#include "Init.h"

/*
 * Associating rt_OneStep with a real-time clock or interrupt service routine
 * is what makes the generated code "real-time".  The function rt_OneStep is
 * always associated with the base rate of the model.  Subrates are managed
 * by the base rate from inside the generated code.  Enabling/disabling
 * interrupts and floating point context switches are target specific.  This
 * example code indicates where these should take place relative to executing
 * the generated code step function.  Overrun behavior should be tailored to
 * your application needs.  This example simply sets an error status in the
 * real-time model and returns from rt_OneStep.
 */
void rt_OneStep(void);
void rt_OneStep(void)
{
  static boolean_T OverrunFlag = false;

  /* Disable interrupts here */

  /* Check for overrun */
  if (OverrunFlag) {
    rtmSetErrorStatus(rtM, "Overrun");
    return;
  }

  OverrunFlag = true;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
  /* Set model inputs here */

  /* Step the model */
  Blinkersteuerung_step();

  /* Get model outputs here */

  /* Indicate task complete */
  OverrunFlag = false;

  /* Disable interrupts here */
  /* Restore FPU context here (if necessary) */
  /* Enable interrupts here */
}

/*
 * The example main function illustrates what is required by your
 * application code to initialize, execute, and terminate the generated code.
 * Attaching rt_OneStep to a real-time clock is target specific. This example
 * illustrates how you do this relative to initializing the model.
 */
 
 
 
 #ifndef CEEDLING
int AppMain(void)
{
   /* Initialize model */
  Blinkersteuerung_initialize();

  /* Attach rt_OneStep to a timer or interrupt service routine with
   * period 0.2 seconds (base rate of the model) here.
   * The call syntax for rt_OneStep is
   *
   *  rt_OneStep();
   */
  rt_OneStep();
  while (rtmGetErrorStatus(rtM) == (NULL)) {
    /*  Perform application tasks here */
  }

  return 0;
}

int main(void)
{
   return AppMain();
}
#else
int AppMain(void)
{
/* Initialize model */
  Blinkersteuerung_initialize();

  /* Attach rt_OneStep to a timer or interrupt service routine with
   * period 0.2 seconds (base rate of the model) here.
   * The call syntax for rt_OneStep is
   *
   *  rt_OneStep();
   */
  rt_OneStep();

  return 0;
}
#endif


/*
 * File trailer for generated code.
 *
 * [EOF]
 */
