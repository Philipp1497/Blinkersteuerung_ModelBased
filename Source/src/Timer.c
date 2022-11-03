#include "Timer.h"
#include "Blinkersteuerung.h"

extern int zuendung_aktiv;
extern int flag;
extern int richtungs_blinken_flag;
extern int links_blink_zustand;
extern int rechts_blink_zustand;

int counter = 1;
int blink_counter = 0;

interrupt void cpu_timer0_isr(void)
{
    CpuTimer0.InterruptCount++;

    warntaster();
    rechtsblinken();
    linksblinken();
    zuendungstaster();

    if(flag == 1)
    {
        richtungs_blinken_flag = 0;
        blink_counter = 0;
        rtDW.is_c1_Blinkersteuerung = 1U;
    }

    if(((links_blink_zustand == 3) || (rechts_blink_zustand == 3)) && blink_counter >= 60)
    {
        blink_counter = 59; // falls noch aktives Signal, weiter blinken
    }

    if(blink_counter >= 60)
    {
        richtungs_blinken_flag = 0;
        blink_counter = 0;
        rtDW.is_c1_Blinkersteuerung = 1U;
    }

    storeSignal();
    if(counter > 10)
    {
        Blinkersteuerung_step();
        counter = 1;
    }
    writeToPorts();
    if(richtungs_blinken_flag != 0)
    {
        blink_counter++;
    }
    counter++;


    // Acknowledge this interrupt to receive more interrupts from group 1
    PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
}

void storeSignal()
{
    rtU.eingang  = flag;
    rtU.zuendung = zuendung_aktiv;
    switch(richtungs_blinken_flag)
    {
        case 0:
            rtU.links = 0;
            rtU.rechts = 0;
            break;
        case 1:
            rtU.links = 0;
            rtU.rechts = 1;
            break;
        case 2:
            rtU.links = 1;
            rtU.rechts = 0;
            break;
    }

}
