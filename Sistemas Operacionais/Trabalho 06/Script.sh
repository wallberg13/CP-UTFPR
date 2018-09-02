#!/bin/bash
echo "Processo de Compilacao do Consumidor"
gcc Consumidor.c -o consumidor -pthread

echo "Processo de Compilacao do Produtor"
gcc Produtor.c -o produtor -pthread

echo "Processo de Compilacao da Main"
gcc main.c -o main -pthread
