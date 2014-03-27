#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <vector>
#include "Matriz.h"
#include "defines.h"

//Funciones para ver vectores y matrices por pantalla.

template<class T>
void mostrarVector(const vector<T>& vec){
	unsigned int tam = vec.size();
	if(tam !=0 ){
		for(unsigned int i=0; i < tam-1; ++i){
			cout << vec[i] << " ";
		}
        cout << vec[tam-1];
	}
}

template<class T>
void mostrarMatriz(const Matriz<T>& A){
    int cant_filas = A.cantFilas();
    int cant_columnas = A.cantColumnas();
    for(int i = 0 ; i < cant_filas; i++){
        mostrarVector(A[i]);
        cout << endl;
    }
}

#endif
