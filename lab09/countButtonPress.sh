#!/bin/bash

p=0
b=$(gpio read 5)

while :
do

	until [ $b -eq 0 ]
	do
		let b=$(gpio read 5)
	done

	until [ $b -eq 1 ]
	do
		let b=$(gpio read 5)
	
	done
		((p++))
		echo $p
		./setbits.sh $p

	if [ $p -eq 16 ] ;
	then
		gpio write 6 1
		sleep 1
	fi
done
