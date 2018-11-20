#!/bin/bash

for i in 1 2 3 4 5
do
	for j in 1 2 3 4
	do
		gpio write $j 1
	done
	sleep 1
	for j in 1 2 3 4
	do
		gpio write $j 0
	done
	sleep 1
done
