#!/bin/bash

b=$(gpio read 5);

until [ $b -eq 0 ] 
do
	sleep 0.25	
	let b=$(gpio read 5)
done

until [ $b -eq 1 ] 
do
	sleep 0.25	
	let b=$(gpio read 5)
done

echo "Setting Value..."
