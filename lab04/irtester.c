#include <stdio.h>
#include <wiringPi.h>
#include "ifttt.h"

int main(int argc, char *argv[])
{
  int i;
  wiringPiSetup () ;
  pinMode(0, INPUT);
  pinMode (1, OUTPUT);
  pinMode (2, OUTPUT);
  while(1) {
    printf("Waiting for reset\n");
    while(digitalRead(0) == 1) {
	    digitalWrite (1, HIGH);
	    delay (300);
	    digitalWrite (1, LOW);
	    delay (300);
    }
    printf("Waiting for event\n");
    while(digitalRead(0) == 0) {
	   ifttt("http://red.eecs.yorku.ca:8080/trigger/event/with/key/mlisits", "my1", "my 2", "my 33333"); 
	    digitalWrite (2, HIGH);
	    delay (300);
	    digitalWrite (2, LOW);
	    delay (300);
    }
    printf("Alarm\n");
  }
  /*NOTREACHED*/
  return 0 ;
}
