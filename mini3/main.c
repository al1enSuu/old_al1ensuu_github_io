
#include "lpc_types.h"

#include "main.h"
#include "ad.h"
#include "led.h"
#include "serialIO.h"
#include "sysTick.h"
#include "i2cIO.h"

void stage1()
{
	while(1)
	{
		int data = 0;
		data = readChannel(1);
		if (data)
		{
		serialPrintWithInt("\n\rVoltage: %\n\r", data);
		break;}
	}
}

void stage2()
{
	while(1)
	DAC_outputSineWave(3.3, 1);
}

void stage3()
{
	int data = 0;
	while(1)
	{
		data = 0;
		data = readChannel(1);

		if (data)
		{	
			//serialPrintWithInt("\n\rVoltage: %\n\r", data);
			DAC_output((int)(0x3ff*(data*1.0)/0xfff));
		}
		//delayMS(1000);
	}
}

int main()
{   
	serial_init();
	AI_init();
	DAC_init();
	TIMER_init();
    //stage1();
    stage2();
    //stage3();
    
    return 0;
}
