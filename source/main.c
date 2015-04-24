#include "TM4C123.h"                    // Device header
#include "timer.h"

unsigned int speed;
unsigned int idle_eventCounter;
int main(){
	SystemCoreClockUpdate();
	speed=SystemCoreClock;
	timerInit();
	timerSet(1814,0);//interrupt every (0+1)*2000 counts 
	timerIRQConfig(1);
	ledsInit();
	GPIOF->DATA|=(0x1<<1)|(0x1<<2)|(0x1<<3);
	timerEnable(1);
	while(1){
		if(timer_eventCounter>=(44100/2)){
			timer_eventCounter=0;
			GPIOF->DATA^=(0x1<<1)|(0x1<<2)|(0x1<<3);
		}
		idle_eventCounter++;
	}
}
