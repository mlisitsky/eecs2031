#!/bin/bash


for i in 1 2 3 4
do
	gpio write $i $((($1 >> ($i-1)) & 1))
done
