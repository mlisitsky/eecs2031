#!/bin/bash


for i in {1..16..1}
do
	./setbits.sh $i
	sleep 1
	echo $i
done
