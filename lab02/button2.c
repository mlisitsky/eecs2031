#include <wiringPi.h>
#include <stdio.h>

#define LedPin	0
#define ButtonPin 1

int main (int argc, char *argv []) {
	wiringPiSetup () ;
	pinMode(LedPin, OUTPUT) ; 
	pinMode (ButtonPin, INPUT) ;
	pullUpDnControl(ButtonPin, PUD_UP) ;

	for (;;)
	{
		/* int x = digitalRead(1) ; */
		digitalWrite (LedPin, HIGH) ; 
		if (digitalRead(ButtonPin) == 0) {
			/* printf ("ON \n") ;	*/
			/* digitalWrite(0, HIGH) ; */
			/* digitalWrite (0, HIGH) ; delay (1000) ; */
			digitalWrite (LedPin, LOW) ; delay (75) ;
		}
		/* digitalWrite(0, LOW) ; delay (75) ; */
	}
	
       	return 0;
}
