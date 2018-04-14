#!/bin/bash
gcc *.c -o main -lm
for x in Instancias/burma14/*.dat
do
  ./main $x burma14.txt
done
