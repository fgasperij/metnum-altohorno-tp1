#ifndef MATRIZ_H
#define MATRIZ_H

#include "defines.h"
#include <vector>
#include <list>

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
		Pos posiciones_x; //Pos[i] = Numero de fila de la matriz anterior que se encuentra en la posicion i.
		Pos posiciones_y; //Pos[i] = Numero de columna de la matriz anterior que se encuentra en la posicion i.
		T escalar;
		T sumando;
		bool transpuesta;
	public:
		
		class vectorMatriz{
			friend class Matriz;
			public:
			T& operator[](int j){
				return parent->matriz[i][j];
			}
			private:
			vectorMatriz(Matriz<T>* matriz, int fila){
				parent = matriz;
				i = fila;
			}
			Matriz<T>* parent;
			int i;
		};
		Matriz(){
			escalar = 1;
			sumando = 0;
			transpuesta = false;
		};
		// Crea una matriz con cant_filas y cant_columnas y la llena con ceros.
		Matriz(int tamanio, T val = 0){
           		 int cant_filas = tamanio; int cant_columnas = tamanio;
           		 vector< vector<T> > m = vector< vector<T> > (cant_filas);
           		 for(int i = 0; i < cant_filas; i++){
                		m[i] = vector<T> (cant_columnas, val);
            		}		
            		matriz = m;
			//matriz = crearMatrix(tamanio, tamanio);
			posiciones_x = crearPosiciones(tamanio);
		}
		Matriz(int cant_filas, int cant_columnas, T val = 0){
		    	vector< vector<T> > m = vector< vector<T> > (cant_filas);
		        for(int i = 0; i < cant_filas; i++){
		        m[i] = vector<T> (cant_columnas, val);
		    	}
		   	matriz = m;
			//matriz = crearMatrix(cant_filas, cant_columnas);
			posiciones_x = crearPosiciones(cant_filas);
		}
		// Intercambiar dos filas, es intercambiar dos numeritos en el vector posiciones.
		void intercambiar(int i, int j, int tipo = FILA){
			if(tipo == FILA){
				if(i != j){
					int temp = posiciones_x[i];
					this->posiciones_x[i] = posiciones_x[j];
					this->posiciones_x[j] = temp;
				}
			}
//			else{
//				if(i != j){
//					int temp = posiciones[i];
//					this->posiciones_y[i] = posiciones_y[j];
//					this->posiciones_y[j] = temp;
//				}
//			}
		}

		T& operator[](int i){
			//return matriz[posiciones[i]];
			return vectorMatriz(*this, posiciones_x[i]);
		}


		int cantFilas()const {return matriz.size();}
		int cantColumnas()const {return matriz[0].size();}
};

#endif
