#!/bin/bash

p=0

while :
do
	./waitForButtonPress.sh

	((p++))
	./setbits.sh $p

	if [ $p -eq 16 ] ;
	then
		gpio write 6 1
		sleep 2
		gpio write 6 0
		break
	fi
done
