#ifndef MATRIZ_H
#define MATRIZ_H

#include "defines.h"
#include <vector>

template<class T>
vector< vector<T> > crearMatrix(int cant_filas, int cant_columnas){
		vector< vector<T> > m = vector< vector<T> > (cant_filas);
		for(int i = 0; i < cant_filas; i++){
			m[i] = vector<T> (cant_columnas);
			for(int j =0; j < cant_columnas; j++){
				m[i][j] = 0;
			}
		}
		return m;
}


Pos crearPosiciones(int cant_filas){
	Pos p = Pos (cant_filas);
	for(int i = 0; i < cant_filas; i++){
		p[i] = i;
	}
	return p;
}

// El siguiente tipo matriz es una matriz comun y corriente, con la unica diferencia que guardo
// rastro de los intercambios de fila con ayuda de un vector de manera de poder intercambiar filas
// de manera rapida. La interfaz es la misma que un vector de vector, pero se agrega la funcion
// intercambiar la cual permuta dos filas.
template<class T>
class Matriz{
	private:
		vector< vector<T> > matriz; //Matriz "fisica" donde se guardan los datos.
		Pos posiciones; //Pos[i] = Numero de fila de la matriz anterior que se encuentra en la posicion i.
	public:
		Matriz();
		// Crea una matriz con cant_filas y cant_columnas y la llena con ceros.
		Matriz(int tamanio){
            int cant_filas = tamanio; int cant_columnas = tamanio;
            vector< vector<T> > m = vector< vector<T> > (cant_filas);
            for(int i = 0; i < cant_filas; i++){
                m[i] = vector<T> (cant_columnas, 0);
            }
            matriz = m;
			//matriz = crearMatrix(tamanio, tamanio);
			posiciones = crearPosiciones(tamanio);
		}
		Matriz(int cant_filas, int cant_columnas){
            vector< vector<T> > m = vector< vector<T> > (cant_filas);
            for(int i = 0; i < cant_filas; i++){
                m[i] = vector<T> (cant_columnas, 0);
            }
            matriz = m;
			//matriz = crearMatrix(cant_filas, cant_columnas);
			posiciones = crearPosiciones(cant_filas);
		}
		// Intercambiar dos filas, es intercambiar dos numeritos en el vector posiciones.
		void intercambiar(int i, int j){
			if(i != j){
				int temp = posiciones[i];
				this->posiciones[i] = posiciones[j];
				this->posiciones[j] = temp;
			}
		}
		vector<T>& operator[](int i){
			return matriz[posiciones[i]];
		}


		int cantFilas(){return matriz.size();}
		int cantColumnas(){return matriz[0].size();}
};

#endif
