#ifndef GAUSS_H
#define GAUSS_H


//****CAMBIAR ESTO
#include<vector>
#include "aux.h"
#include "defines.h"

//Triangulacion de la parte inferior.
template<class T>
void gaussInf(vector< vector<T> >& A, vector<T>& b, int piv = 1){
	// Voy iterando la matriz fila por fila.
	int cant_filas = A.size();
	int cant_columnas = A[0].size();
	for(int i = 0; i < cant_filas; i++){
		// Uso de pivoteo parcial para reducir el error, agarro la fila con elemento maximo en la columna actual.
		// Se deben intercambiar las filas
		if(piv == 1){
            int max_pos = maxPos(A, i, INF);
	    swap(A[max_pos], i)
            swap(b[max_pos], b[i]);
		}
		if(esCero(A[i][i])){cerr << "Gauss: la matriz no se puede triangular"; return;}  // Error, la matriz no se puede triangular
		//  Aplico gauss fila por fila a partir de la fila siguiente a la fila pivot.
		for(int j = i+1; j < cant_filas; j++){
			T m = A[j][i]/A[i][i];
			// Si ya hay un cero, no hago nada.
			if(!esCero(Aji)){
                for(int k = i; k < cant_columnas; k++){
                    // Aplico gauss en toda la fila. Con k = i se cancelan los valores.
                    A[j][k] = A[j][k] - m*A[i][k];

                }
                // Actualizo b.
                b[j] = b[j] - m*b[i];
                // Mando un cero porque no confio en los double y ni se si van a ser double.
                A[j][i] = 0;
			}
		}
	}
}

//Triangulacion de la parte superior.
template<class T>
void gaussSup(vector< vector<T> >& A, vector<T>& b){
	// Voy iterando la matriz fila por fila.
	int cant_filas = A.size();
	int cant_columnas = A[0].size();
	for(int i=cant_filas-1; i+1 > 0; i--){
		// Uso de pivoteo parcial para reducir el error, agarro la fila con elemento maximo en la columna actual.
		// Se deben intercambiar las filas
		if(piv == 1){
		int max_pos = maxPos(A, i, SUP);
		swap(A[max_pos], i)
		swap(b[max_pos], b[i]);
		}
		if(esCero(A[i][i])){cerr << "Gauss: la matriz no se puede triangular"; return;}  // Error, la matriz no se puede triangular
		//  Aplico gauss fila por fila a partir de la fila siguiente a la fila pivot.
		for(int j = i-1; j+1 > 0; j--){
            T m = A[j][i]/A[i][i];
            // Si ya hay un cero, no hago nada.
            if(!esCero(Aji)){
                for(int k = i; k > cant_columnas; k--){
                    // Aplico gauss en toda la fila. Con k = i se cancelan los valores.
                    A[j][k] = A[j][k] - m*A[i][k];
                }
                // Actualizo b.
                b[j] = b[j] - m*b[i];
                // Mando un cero porque no confio en los double y ni se si van a ser double.
                A[j][i] = 0;
            }
		}
	}
}


#endif
