* Stepper Motor */

#include <reg51.h>

sbit half_full_cycle = P2^1;	// Half cycle = 0, Full cycle= 1
sbit PULSE = P2^7;				// Clock pulse
sbit S7 = P3^1;   				// Switch S7 on trainer
sbit S6 = P3^0;					// Switch S6 on trainer

void main(void)
{
	while (1)
	{
		// Half cycle = 1, Full cycle= 0
		if(S7==1)  // When Switch S7 is pressed
		{
			half_full_cycle = 1;  	// Half Cycle
			// Generate a clock pulse
			PULSE=1;
			delay(10);
			PULSE=0;
			delay(10);
		}

		if(S6==1)
		{
			half_full_cycle = 0;  	// Full Cycle
			// Generate a clock pulse
			PULSE=1;
			delay(10);
			PULSE=0;
			delay(10);
		}
	}
}

void delay (int time)     // this function is used for delay
{
	int e,f;
	for(e=1;e<=time;e++)    // generate a delay of 500*times*1us
		for(f=1;f<=500;f++);
}
