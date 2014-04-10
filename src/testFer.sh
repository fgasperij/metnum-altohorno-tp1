#!/bin/bash

#Modo de uso= ./tests.sh arg1
#arg1 = Cantidad de instancias de tests.

nombre_test=''

argc=$#

#Determino cantidad de tests.
if [ $argc -ne 0 ]
then
	nombre_test=$1
fi

#Compilo
g++ -O2 -o base/tp base/main.cpp

#Borro resultados anteriores
rm -f "testsInforme/$nombre_test/*.out"

#Corro los tests con Gauss

files=./testsInforme/$nombre_test/*.in
i=1
for f in $files
do
	echo "Running $f"
	./base/tp "$f" "testsInforme/$nombre_test/test$i.out" 0
	echo "OK"
	i=$((i + 1))
done