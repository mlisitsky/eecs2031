#!/bin/bash

for (( ; ; ))
do
gpio write $((RANDOM % 5)) 0
gpio write $((RANDOM % 5)) 1
sleep 0.25
done
