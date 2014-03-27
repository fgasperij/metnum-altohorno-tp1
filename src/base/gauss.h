#ifndef GAUSS_H
#define GAUSS_H

#include "misc.h"
#include "Matriz.h"
#include "defines.h"

//Triangulacion de la parte inferior.
template<class T>
int gaussInf(Matriz<T>& A, vector<T>& b){
	// Voy iterando la matriz fila por fila.
	int cant_filas = A.cantFilas();
	int cant_columnas = A.cantColumnas();
	for(int i=0; i < cant_filas; i++){
		// Uso de pivoteo parcial para reducir el error, agarro la fila con elemento maximo en la columna actual.
		// Se deben intercambiar las filas
		int max_pos = maxPos(A, i, INF);
		A.intercambiar(max_pos, i);
		swap(b[max_pos], b[i]);
		if(A[i][i] == 0){return -1;}  // Error, la matriz no se puede triangular
		//  Aplico gauss fila por fila a partir de la fila siguiente a la fila pivot.
		for(int j = i+1; j < cant_filas; j++){
			T Aji = A[j][i];
			// Si ya hay un cero, no hago nada.
			if(Aji != 0){
                for(int k = i; k < cant_columnas; k++){
                    // Aplico gauss en toda la fila. Con k = i se cancelan los valores.
                    A[j][k] = A[j][k]*A[i][i] - A[i][k]*Aji;

                }
                // Actualizo b.
                b[j] = b[j]*A[i][i] - b[j]*Aji;
                // Mando un cero porque no confio en los double y ni se si van a ser double.
                A[j][i] = 0;
			}
		}
	}
	return 0;
}

//Triangulacion de la parte superior.
template<class T>
int gaussSup(Matriz<T>& A, vector<T>& b){
	// Voy iterando la matriz fila por fila.
	int cant_filas = A.cantFilas();
	int cant_columnas = A.cantColumnas();
	for(int i=cant_filas-1; i+1 > 0; i--){
		// Uso de pivoteo parcial para reducir el error, agarro la fila con elemento maximo en la columna actual.
		// Se deben intercambiar las filas
		int max_pos = maxPos(A, i, SUP);
		A.intercambiar(max_pos, i);
		swap(b[max_pos], b[i]);
		if(A[i][i] == 0){return -1;}  // Error, la matriz no se puede triangular
		//  Aplico gauss fila por fila a partir de la fila siguiente a la fila pivot.
		for(int j = i-1; j+1 > 0; j--){
            T Aji = A[j][i];
            // Si ya hay un cero, no hago nada.
            if(Aji != 0){
                for(int k = i; k > cant_columnas; k--){
                    // Aplico gauss en toda la fila. Con k = i se cancelan los valores.
                    A[j][k] = A[j][k]*A[i][i] - A[i][k]*Aji;
                }
                // Actualizo b.
                b[j] = b[j]*A[i][i] - b[j]*Aji;
                // Mando un cero porque no confio en los double y ni se si van a ser double.
                A[j][i] = 0;
            }
		}
	}
	return 0;
}


//Triangulo la parte de abajo y despues la de arriba. Queda una matriz diagonal.
template<class T>
int eliminacionGauss(Matriz<T>& A, vector<T>& b){
    if(gaussInf(A, b) == -1){return -1;}
    if(gaussSup(A, b) == -1){return -1;}
    return 0;
}

#endif
