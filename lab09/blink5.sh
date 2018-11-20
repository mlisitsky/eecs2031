#!/bin/bash

for i in 1 2 3 4 5
do
gpio write 1 1
gpio write 2 1
gpio write 3 1
gpio write 4 1
sleep 1
gpio write 1 0
gpio write 2 0
gpio write 3 0
gpio write 4 0
sleep 1
done
