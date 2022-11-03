/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Blinkersteuerung.c
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

#include "Blinkersteuerung.h"
#include "Taster.h"
#include "rtwtypes.h"
#include "DSP280x_Device.h"     // DSP280x Headerfile Include File
#include "DSP280x_Examples.h"   // DSP280x Examples Include File

#define IN_OFF1                        (1U)
#define IN_ON1                         (2U)
#define IN_ON_BEIDE                    (2U)
#define IN_ON_LINKS                    (3U)
#define IN_ON_RECHTS                   (4U)

/* Defines Chart */
#define IN_LAMPEN_OFF                  (1U)
#define IN_LAMPEN_ON                   (2U)
#define IN_LAMPE_LINKS_ON              (3U)
#define IN_LAMPE_RECHTS_ON             (4U)
#define IN_NO_ACTIVE_CHILD             (0U)
#define IN_OFF                         (1U)
#define IN_ON                          (2U)
#define IN_WARNBLINK                   (3U)

void writeToPorts(void);
interrupt void cpu_timer0_isr(void);

extern int richtungs_blinken_flag;

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Model step function */
void Blinkersteuerung_step(void)
{


  /* Chart: '<Root>/Chart2' */
  if (rtDW.is_active_c2_Blinkersteuerung == 0U) {
      rtDW.is_active_c2_Blinkersteuerung = 1U;
      rtDW.durationCounter_1_h = 0L;
      rtDW.is_c2_Blinkersteuerung = IN_OFF;

      /* Outport: '<Root>/ausgang' */
      rtY.ausgang = 0.0;
    } else if (rtDW.is_c2_Blinkersteuerung == 1U) {
      if (!(rtU.eingang > 0.0)) {
        rtDW.durationCounter_1_h = 0L;
      }

      if (rtDW.durationCounter_1_h > 0L) {
        rtDW.durationCounter_1 = 0L;
        rtDW.is_c2_Blinkersteuerung = IN_ON;

        /* Outport: '<Root>/ausgang' */
        rtY.ausgang = 1.0;
      } else {
        /* Outport: '<Root>/ausgang' */
        rtY.ausgang = 0.0;
      }
    } else {
      /* case IN_ON: */
      if (!(rtU.eingang <= 0.0)) {
        rtDW.durationCounter_1 = 0L;
      }

      if (rtDW.durationCounter_1 > 0L) {
        rtDW.durationCounter_1_h = 0L;
        rtDW.is_c2_Blinkersteuerung = IN_OFF;

        /* Outport: '<Root>/ausgang' */
        rtY.ausgang = 0.0;
      } else {
        /* Outport: '<Root>/ausgang' */
        rtY.ausgang = 1.0;
      }
    }

    if (rtU.eingang <= 0.0) {
      rtDW.durationCounter_1++;
    } else {
      rtDW.durationCounter_1 = 0L;
    }

    if (rtU.eingang > 0.0) {
      rtDW.durationCounter_1_h++;
    } else {
      rtDW.durationCounter_1_h = 0L;
    }

  /* End of Chart: '<Root>/Chart2' */

  //****************************************
  /* Chart: '<Root>/Chart' incorporates:
     *  Inport: '<Root>/links'
     *  Inport: '<Root>/rechts'
     *  Inport: '<Root>/warnblink'
     *  Inport: '<Root>/zuendung'
     */
    if (rtDW.is_active_c3_Blinkersteuerung == 0U)
    {
      rtDW.is_active_c3_Blinkersteuerung = 1U;
      rtDW.is_c3_Blinkersteuerung = IN_OFF;

      /* Outport: '<Root>/zuendung_out' */
      rtY.zuendung_out = 0.0;

      /* Outport: '<Root>/links_out' */
      rtY.links_out = 0.0;

      /* Outport: '<Root>/rechts_out' */
      rtY.rechts_out = 0.0;
    }
    else
    {
      switch (rtDW.is_c3_Blinkersteuerung)
      {
       case IN_OFF:
        if (rtU.zuendung == 1.0)
        {
          rtDW.is_c3_Blinkersteuerung = IN_ON;

          /* Outport: '<Root>/zuendung_out' */
          rtY.zuendung_out = 1.0;
          rtDW.is_ON = IN_LAMPEN_OFF;

          /* Outport: '<Root>/links_out' */
          rtY.links_out = 0.0;

          /* Outport: '<Root>/rechts_out' */
          rtY.rechts_out = 0.0;
        }
        else if ((rtU.eingang == 1.0) && (rtU.zuendung == 0.0))
        {
          rtDW.is_c3_Blinkersteuerung = IN_WARNBLINK;

          /* Outport: '<Root>/links_out' */
          rtY.links_out = 1.0;

          /* Outport: '<Root>/rechts_out' */
          rtY.rechts_out = 1.0;
        }
        else
        {
          /* Outport: '<Root>/zuendung_out' */
          rtY.zuendung_out = 0.0;

          /* Outport: '<Root>/links_out' */
          rtY.links_out = 0.0;

          /* Outport: '<Root>/rechts_out' */
          rtY.rechts_out = 0.0;
        }
       break;

       case IN_ON:
        if (rtU.zuendung == 0.0) {
          rtDW.is_ON = IN_NO_ACTIVE_CHILD;
          rtDW.is_c3_Blinkersteuerung = IN_OFF;

          /* Outport: '<Root>/zuendung_out' */
          rtY.zuendung_out = 0.0;

          /* Outport: '<Root>/links_out' */
          rtY.links_out = 0.0;

          /* Outport: '<Root>/rechts_out' */
          rtY.rechts_out = 0.0;
        } else if ((rtU.eingang == 1.0) && (rtU.links == 0.0) && (rtU.rechts ==
                    0.0)) {
          rtDW.is_ON = IN_NO_ACTIVE_CHILD;
          rtDW.is_c3_Blinkersteuerung = IN_WARNBLINK;

          /* Outport: '<Root>/links_out' */
          rtY.links_out = 1.0;

          /* Outport: '<Root>/rechts_out' */
          rtY.rechts_out = 1.0;
        } else {
          /* Outport: '<Root>/zuendung_out' */
          rtY.zuendung_out = 1.0;
          switch (rtDW.is_ON) {
           case IN_LAMPEN_OFF:
            if ((rtU.links == 1.0) && (rtU.rechts == 0.0)) {
              rtDW.is_ON = IN_LAMPE_LINKS_ON;

              /* Outport: '<Root>/links_out' */
              rtY.links_out = 1.0;

              /* Outport: '<Root>/rechts_out' */
              rtY.rechts_out = 0.0;
            } else if ((rtU.links == 0.0) && (rtU.rechts == 1.0)) {
              rtDW.is_ON = IN_LAMPE_RECHTS_ON;

              /* Outport: '<Root>/rechts_out' */
              rtY.rechts_out = 1.0;

              /* Outport: '<Root>/links_out' */
              rtY.links_out = 0.0;
            } else if ((rtU.links == 1.0) && (rtU.rechts == 1.0)) {
              rtDW.is_ON = IN_LAMPEN_ON;

              /* Outport: '<Root>/rechts_out' */
              rtY.rechts_out = 1.0;

              /* Outport: '<Root>/links_out' */
              rtY.links_out = 1.0;
            } else {
              /* Outport: '<Root>/links_out' */
              rtY.links_out = 0.0;

              /* Outport: '<Root>/rechts_out' */
              rtY.rechts_out = 0.0;
            }
            break;
           case IN_LAMPEN_ON:
                    if (rtU.rechts == 0.0) {
                      rtDW.is_ON = IN_LAMPE_LINKS_ON;

                      /* Outport: '<Root>/links_out' */
                      rtY.links_out = 1.0;

                      /* Outport: '<Root>/rechts_out' */
                      rtY.rechts_out = 0.0;
                    } else if (rtU.links == 0.0) {
                      rtDW.is_ON = IN_LAMPE_RECHTS_ON;

                      /* Outport: '<Root>/rechts_out' */
                      rtY.rechts_out = 1.0;

                      /* Outport: '<Root>/links_out' */
                      rtY.links_out = 0.0;
                    } else {
                      /* Outport: '<Root>/rechts_out' */
                      rtY.rechts_out = 1.0;

                      /* Outport: '<Root>/links_out' */
                      rtY.links_out = 1.0;
                    }
                    break;

                   case IN_LAMPE_LINKS_ON:
                    if (rtU.links == 0.0) {
                      rtDW.is_ON = IN_LAMPEN_OFF;

                      /* Outport: '<Root>/links_out' */
                      rtY.links_out = 0.0;

                      /* Outport: '<Root>/rechts_out' */
                      rtY.rechts_out = 0.0;
                    } else if (rtU.rechts == 1.0) {
                      rtDW.is_ON = IN_LAMPEN_ON;

                      /* Outport: '<Root>/rechts_out' */
                      rtY.rechts_out = 1.0;

                      /* Outport: '<Root>/links_out' */
                      rtY.links_out = 1.0;
                    } else {
                        if(rtDW.temporalCounter_i1 == 1 || rtDW.temporalCounter_i1 == 3)
                        {
                            /* Outport: '<Root>/rechts_out' */
                          rtY.rechts_out = 0.0;

                          /* Outport: '<Root>/links_out' */
                          rtY.links_out = 1.0;
                        }
                        else
                        {
                            /* Outport: '<Root>/rechts_out' */
                          rtY.rechts_out = 0.0;

                          /* Outport: '<Root>/links_out' */
                          rtY.links_out = 0.0;
                        }
                    }
                    break;

                   default:
                    /* case IN_LAMPE_RECHTS_ON: */
                    if (rtU.rechts == 0.0) {
                      rtDW.is_ON = IN_LAMPEN_OFF;

                      /* Outport: '<Root>/links_out' */
                      rtY.links_out = 0.0;

                      /* Outport: '<Root>/rechts_out' */
                      rtY.rechts_out = 0.0;
                    } else if (rtU.links == 1.0) {
                      rtDW.is_ON = IN_LAMPEN_ON;

                      /* Outport: '<Root>/rechts_out' */
                      rtY.rechts_out = 1.0;

                      /* Outport: '<Root>/links_out' */
                      rtY.links_out = 1.0;
                    } else {
                        if(rtDW.temporalCounter_i1 == 1 || rtDW.temporalCounter_i1 == 3)
                        {
                            /* Outport: '<Root>/rechts_out' */
                          rtY.rechts_out = 1.0;

                          /* Outport: '<Root>/links_out' */
                          rtY.links_out = 0.0;
                        }
                        else
                        {
                            /* Outport: '<Root>/rechts_out' */
                          rtY.rechts_out = 0.0;

                          /* Outport: '<Root>/links_out' */
                          rtY.links_out = 0.0;
                        }

                    }
                    break;
                  }
                }
                break;


       default:
        /* case IN_WARNBLINK: */
       if(rtU.eingang == 1)
       {
         if(rtDW.durationCounter_1_h % 2 == 0)
         {
             /* Outport: '<Root>/links_out' */
              rtY.links_out = 0.0;

              /* Outport: '<Root>/rechts_out' */
              rtY.rechts_out = 0.0;
         }
         else
         {
             /* Outport: '<Root>/links_out' */
             rtY.links_out = 1.0;

             /* Outport: '<Root>/rechts_out' */
             rtY.rechts_out = 1.0;
         }
       }
       else
       {
           if ((rtU.links == 1.0) && (rtU.zuendung == 1.0)) {
                rtDW.is_c3_Blinkersteuerung = IN_ON;

                /* Outport: '<Root>/zuendung_out' */
                rtY.zuendung_out = 1.0;
                rtDW.is_ON = IN_LAMPE_LINKS_ON;

                /* Outport: '<Root>/links_out' */
                rtY.links_out = 1.0;

                /* Outport: '<Root>/rechts_out' */
                rtY.rechts_out = 0.0;
              } else if ((rtU.rechts == 1.0) && (rtU.zuendung == 1.0)) {
                rtDW.is_c3_Blinkersteuerung = IN_ON;

                /* Outport: '<Root>/zuendung_out' */
                rtY.zuendung_out = 1.0;
                rtDW.is_ON = IN_LAMPE_RECHTS_ON;

                /* Outport: '<Root>/rechts_out' */
                rtY.rechts_out = 1.0;

                /* Outport: '<Root>/links_out' */
                rtY.links_out = 0.0;
              } else if ((rtU.eingang == 0.0) && (rtU.zuendung == 0.0)) {
                rtDW.is_c3_Blinkersteuerung = IN_OFF;

                /* Outport: '<Root>/zuendung_out' */
                rtY.zuendung_out = 0.0;

                /* Outport: '<Root>/links_out' */
                rtY.links_out = 0.0;

                /* Outport: '<Root>/rechts_out' */
                rtY.rechts_out = 0.0;
              } else if ((rtU.eingang == 0.0) && (rtU.zuendung == 1.0)) {
                rtDW.is_c3_Blinkersteuerung = IN_ON;

                /* Outport: '<Root>/zuendung_out' */
                rtY.zuendung_out = 1.0;
                rtDW.is_ON = IN_LAMPEN_OFF;

                /* Outport: '<Root>/links_out' */
                rtY.links_out = 0.0;

                /* Outport: '<Root>/rechts_out' */
                rtY.rechts_out = 0.0;
              }
              else
              {
                  /* Outport: '<Root>/links_out' */
                   rtY.links_out = 0.0;

                   /* Outport: '<Root>/rechts_out' */
                   rtY.rechts_out = 0.0;
              }
       }
       break;
      }
    }

    /* End of Chart: '<Root>/Chart' */

  //***************************************




  /* Chart: '<Root>/Chart1' */
  if (rtDW.temporalCounter_i1 < 3U) {
    rtDW.temporalCounter_i1 = (uint16_T)((int16_T)rtDW.temporalCounter_i1 + 1);
  }

  if (rtDW.is_active_c1_Blinkersteuerung == 0U) {
    rtDW.is_active_c1_Blinkersteuerung = 1U;
    rtDW.is_c1_Blinkersteuerung = IN_OFF;
    rtDW.count = 0L;
  } else {
    switch (rtDW.is_c1_Blinkersteuerung) {
     case IN_OFF:
      if ((rtU.links == 1) && (rtU.rechts == 0)) {
        if (rtDW.count > 2147483644L) {
          rtDW.count = MAX_int32_T;
        } else {
          rtDW.count += 3L;
        }

        rtDW.is_c1_Blinkersteuerung = IN_ON_LINKS;
        rtDW.is_ON = IN_LAMPE_LINKS_ON;
        //rtDW.is_ON_LINKS = IN_ON;
        rtDW.temporalCounter_i1 = 0U;
      } else if ((rtU.rechts == 1) && (rtU.links == 0)) {
        if (rtDW.count > 2147483644L) {
          rtDW.count = MAX_int32_T;
        } else {
          rtDW.count += 3L;
        }

        rtDW.is_c1_Blinkersteuerung = IN_ON_RECHTS;
        rtDW.is_ON = IN_LAMPE_RECHTS_ON;
        //rtDW.is_ON_RECHTS = IN_ON;
        rtDW.temporalCounter_i1 = 0U;
      } else if ((rtU.links == 1) && (rtU.rechts == 1)) {
        rtDW.is_c1_Blinkersteuerung = IN_ON_BEIDE;
        rtDW.is_ON = IN_LAMPEN_ON;
        //rtDW.is_ON_BEIDE = IN_ON1;
        rtDW.temporalCounter_i1 = 0U;
      } else {
        rtDW.count = 0L;
      }
      break;

     case IN_ON_BEIDE:
      if ((rtU.links == 0) || (rtU.rechts == 0)) {
          rtDW.is_ON = IN_LAMPEN_OFF;
        //rtDW.is_ON_BEIDE = IN_NO_ACTIVE_CHILD;
        rtDW.is_c1_Blinkersteuerung = IN_OFF;
        rtDW.count = 0L;
      } else if (rtDW.is_ON == IN_LAMPEN_ON) {
        if (rtDW.temporalCounter_i1 >= 3U) {
            rtDW.is_ON = IN_LAMPEN_ON;
          //rtDW.is_ON_BEIDE = IN_ON1;
          rtDW.temporalCounter_i1 = 0U;
        }

        /* case IN_ON1: */
      } else if (rtDW.temporalCounter_i1 >= 3U) {
          rtDW.is_ON = IN_LAMPEN_OFF;
          //rtDW.is_ON_BEIDE = IN_OFF1;
        rtDW.temporalCounter_i1 = 0U;
      }
      break;

     case IN_ON_LINKS:
      if ((rtDW.count == 0L) || (rtU.rechts == 1)) {
          rtDW.is_ON = IN_LAMPEN_OFF;
          //rtDW.is_ON_LINKS = IN_NO_ACTIVE_CHILD;
        rtDW.is_c1_Blinkersteuerung = IN_OFF;
        rtDW.count = 0L;
      } else if (rtDW.is_ON == IN_LAMPE_LINKS_ON) {
        if (rtDW.temporalCounter_i1 >= 3U) {
            rtDW.is_ON = IN_LAMPEN_OFF;
          //rtDW.is_ON_LINKS = IN_ON;
          rtDW.temporalCounter_i1 = 1U;
        }

        /* case IN_ON: */
      } else if (rtDW.temporalCounter_i1 >= 3U) {
        if (rtDW.count < -2147483647L) {
          rtDW.count = MIN_int32_T;
        } else {
          rtDW.count--;
        }
        rtDW.is_ON = IN_LAMPEN_OFF;
        //rtDW.is_ON_LINKS = IN_OFF;
        rtDW.temporalCounter_i1 = 1U;
      }
      break;

     default:
      /* case IN_ON_RECHTS: */
      if ((rtU.links == 1) || (rtDW.count == 0L)) {
          rtDW.is_ON = IN_LAMPEN_OFF;
          //rtDW.is_ON_RECHTS = IN_NO_ACTIVE_CHILD;
        rtDW.is_c1_Blinkersteuerung = IN_OFF;
        rtDW.count = 0L;
      } else if (rtDW.is_ON == IN_LAMPE_RECHTS_ON) {
        if (rtDW.temporalCounter_i1 >= 3U) {
            rtDW.is_ON = IN_LAMPEN_OFF;
            //rtDW.is_ON_RECHTS = IN_ON;
          rtDW.temporalCounter_i1 = 1U;
        }

        /* case IN_ON: */
      } else if (rtDW.temporalCounter_i1 >= 3U) {
        if (rtDW.count < -2147483647L) {
          rtDW.count = MIN_int32_T;
        } else {
          rtDW.count--;
        }
        rtDW.is_ON = IN_LAMPEN_OFF;
        //rtDW.is_ON_RECHTS = IN_OFF;
        rtDW.temporalCounter_i1 = 1U;

      }
      break;
    }
  }

  /* End of Chart: '<Root>/Chart1' */
}

void Gpio_select(void)
{
    EALLOW;
    GpioCtrlRegs.GPAMUX1.all = 0x00000000;  // All GPIO
    GpioCtrlRegs.GPAMUX2.all = 0x00000000;  // All GPIO
    GpioCtrlRegs.GPAMUX1.all = 0x00000000;  // All GPIO
    GpioDataRegs.GPASET.bit.GPIO3;   //output letch is set
    GpioDataRegs.GPASET.bit.GPIO7;   //output letch is set
    GpioDataRegs.GPASET.bit.GPIO23;   //output letch is set
    GpioCtrlRegs.GPADIR.all = 0x00980888;   //  GPIO3,GPIO7,GPIO11, GPIO19, GPIO20 and GPIO23 are outputs

    GpioDataRegs.GPASET.all |= BIT11;

    GpioCtrlRegs.GPACTRL.all = 0x0000ff00;  //input qualification 510xTsysclkout for GPIO8-15
    GpioCtrlRegs.GPAQSEL1.bit.GPIO9 = 2;    //6 samples
//    GpioIntRegs.GPIOXINT1SEL.bit.GPIOSEL |= 0x1A; //Enable GPIO26 as Interrupt Source
//    XIntruptRegs.XINT1CR.bit.ENABLE |= 0x01;
//    XIntruptRegs.XINT1CR.bit.POLARITY |= 0x00;

    EDIS;

}


void writeToPorts()
{
    /*rtU.eingang  = !GpioDataRegs.GPADAT.bit.GPIO26;
    rtU.links    = !GpioDataRegs.GPADAT.bit.GPIO17;
    rtU.rechts   = !GpioDataRegs.GPADAT.bit.GPIO22;
    rtU.zuendung = !GpioDataRegs.GPADAT.bit.GPIO9;*/

    GpioDataRegs.GPADAT.bit.GPIO11 = !rtY.zuendung_out;
    GpioDataRegs.GPADAT.bit.GPIO19 = rtY.links_out;
    GpioDataRegs.GPADAT.bit.GPIO20 = rtY.rechts_out;


    //GpioDataRegs.GPADAT.bit.GPIO19 = rtY.ausgang;
    //GpioDataRegs.GPADAT.bit.GPIO20 = rtY.ausgang;
}
/*
 * File trailer for generated code.
 *
 * [EOF]
 */
