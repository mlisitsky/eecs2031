#include <wiringPi.h> 
#include <stdio.h> 
int main (int argc, char *argv[]) 
{ 
  wiringPiSetup () ; 
  pinMode (5, INPUT) ; 
  pullUpDnControl(5, PUD_UP) ; 
  for (;;) 
  { 
    int x = digitalRead(5); 
    printf("Got a %d\n",x); 
  } 
  return 0 ; 
} 
