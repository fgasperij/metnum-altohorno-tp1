#ifndef UTILS_H
#define UTILS_H

#include <vector>

#include "defines.h"

// Funciones miscelaneas.

//Busca la posicion de maximo valor a partir de la posicion i.
// Se debe especificar el sentido, SUP es hacia arriba, INF es hacia abajo.
template<class T>
int maxPos(vector< vector<T> >& A, int i, int tipo){
    if(tipo ==  INF){
        T max_val = abs(A[i][i]);
        int max_pos = i;
        for(int h = i+1; h < A.size(); h++){
            if (A[h][i] > max_val){
                max_val = abs(A[i][h]);
                max_pos = h;
            }
        }
        return max_pos;
    }
    else{
        T max_val = abs(A[i][i]);
        int max_pos = i;
        for(int h = i-1; h+1 > 0; h--){
            if (A[h][i] > max_val){
                max_val = abs(A[i][h]);
                max_pos = h;
            }
        }
        return max_pos;
    }
}

//Funcion auxiliar para ver si algo es 0.
template<class T>
bool esCero(T& val){
    return (abs(val) < CERO);
}

//A es la matriz, b es el b, y res es donde se guardan los resultados, el tamanio de res debe coincidir con b y A.
template<class T>
void backSubst(vector< vector<T> >& A, vector<T>& b, vector<T>& res){
    unsigned int tamanio = A.size();
    if(res.size() != tamanio){cerr << "backSubst: Tamaño no coincidente"; return;}
    res[tamanio-1] = b[tamanio-1]/A[tamanio-1][tamanio-1];
    for(int i = tamanio-1; i+1 > 0; i--){
        T acum = 0;
        for(int j = tamanio-1; j > i ; j--){
            acum += res[j]*A[i][j];
        }
        res[i] = (b[i] - acum)/A[i][i];
    }
}

template<class T>
void forwSubst(vector< vector<T> >& A, vector<T>& b, vector<T>& res){
    unsigned int tamanio = A.size();
    if(res.size() != tamanio){cerr << "forwSubst: Tamaño no coincidente"; return;}
    res[0] = b[0]/A[0][0];
    for(int i = 0; i < tamanio; i++){
        T acum = 0;
        for(int j = 0; j+1 < i ; j++){
            acum += res[j]*A[i][j];
        }
        res[i] = (b[i] - acum)/A[i][i];
    }
}



#endif
