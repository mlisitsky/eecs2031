#!/bin/bash

for i in 1 2 3 4 6
do
gpio mode $i out
gpio write $i 0
done
gpio mode 5 in
gpio mode 5 up

