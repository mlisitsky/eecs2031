#!/bin/bash

for i in 1 2 3 4
do
gpio mode i out;
gpio write i 0;
done
