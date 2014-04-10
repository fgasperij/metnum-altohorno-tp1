#!/bin/bash

#Modo de uso= ./tests.sh nombre_test iso_o_temps 
#arg1 = Cantidad de instancias de tests.

nombre_test=''

argc=$#

#Determino cantidad de tests.
if [ $argc -eq 2 ]
then
	nombre_test=$1
	iso_o_temps=$2
else
	echo "Modo de uso: ./tests.sh nombre_test iso_o_temps
  nombre_test:
   isotermaVsGranularidad
   isotermaVsBordes
   tiempoVsGranularidad
  iso_o_temps:
   0 = Devolver vector Isotermas
   1 = Devolver vector Temps"
	exit 1
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
	./base/tp "$f" "testsInforme/$nombre_test/test$i.out" 1 $iso_o_temps
	echo "OK"
	i=$((i + 1))
done
