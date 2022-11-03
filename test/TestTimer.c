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
#include "Blinkersteuerung.h"

#define LED_BEIDE       0x00180000


void setUp(void)
{
}

void tearDown(void)
{
}


int flag;			//Warnblinkflag:  0 = Warnblinken aus, 1 = Warnblinken an

void testTimerIsr_when_ZuendungAndWarnblinkenAreNotActive()
{	
	flag = 0;				
	
	zuendungstaster();
    warntaster();
    rechtsblinken();
    linksblinken();
	cpu_timer0_isr();
	
}
