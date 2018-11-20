#!/bin/bash

p=0

while :
do
	n=`gpio read 5`
	if [ $n == 0 ] ;
	then
		((p++))
		echo $p
		./setbits.sh $p
		sleep 0.5
	fi
	if [ $p == 16 ] ;
	then
		gpio write 6 1
		sleep 1
	fi
done
