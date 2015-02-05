#include "TM4C123.h"                    // Device header

unsigned speed;

int main(){
	SystemCoreClockUpdate();
	speed=SystemCoreClock;
	while(1);
}
