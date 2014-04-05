!/bin/bash

#Modo de uso= ./tests.sh arg1
#arg1 = Cantidad de instancias de tests.

cantTests=0

argc=$#

#Determino cantidad de tests.
if [ $argc -ne 0 ]
then
	cantTests=$1
fi

#Compilo
g++ -std=c++0x -o base/tp base/main.cpp

#Borro resultados anteriores
rm -f tests/*.out

#Corro los tests con Gauss
for ((i=1; i < $cantTests+1; i++))
do
	./base/tp tests/test$i.in tests/testGauss$i.out 0
done

#Corro los tests con Gauss
for((i=1; i < $cantTests+1; i++))
do
	./base/tp tests/test$i.in tests/testLU$i.out 1
done
