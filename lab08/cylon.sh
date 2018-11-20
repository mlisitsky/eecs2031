#!/bin/bash

while :
do	
	for j in 1 2 3 4 3 2
	do
		gpio write $j 1
		sleep 0.25
		gpio write $j 0
	done
done
