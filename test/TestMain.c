#include "unity.h"
#include "UnityHelper.h"
#include "DSP280x_PieCtrl.c"
#include "DSP280x_CpuTimers.c"

#include "DSP280x_GlobalVariableDefs.c"
#include "DSP280x_Device.h"     // DSP280x Headerfile Include File
#include "DSP280x_Examples.h"   // DSP280x Examples Include File
//#include "Init.h"
#include "Taster.h"
#include "Timer.h"
#include "ert_main.c"
#include "Blinkersteuerung.h"
#include "MockInit.h"


static boolean_T OverrunFlag;

void setUp(void)
{
}

void tearDown(void)
{
}

void test_rt_OneStep(void)
{

  rt_OneStep();
}

void test_Main(void)
{
  Blinkersteuerung_initialize_Expect();
  
  AppMain();
}
