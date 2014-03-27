#ifndef UTILS_H
#define UTILS_H

#include <vector>

#include "Matriz.h"
#include "defines.h"

// Funciones miscelaneas.

//Busca la posicion de maximo valor a partir de la posicion i.
// Se debe especificar el sentido, SUP es hacia arriba, INF es hacia abajo.
template<class T>
int maxPos(Matriz<T>& A, int i, int tipo){
    if(tipo ==  INF){
        T max_val = abs(A[i][i]);
        int max_pos = i;
        for(int h = i+1; h < A.cantFilas(); h++){
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


///******TODO***/////FUNCION SIN TERMINAR
//Esta funcion se encarga de plantear el sistema
template<class T>
void plantearSistema(Matriz<T>& A, vector<T>& b, Data& data){
    T r = data.rad_ext - data.rad_int;
    T delta_R = r/(data.m-1);
    T delta_Th = (2*pi)/data.n;
    //delta_R+=delta_Th;
    int tam_b = b.size();
    int tam_A = A.cantFilas();
    //Parte superior e inferior de A y b de la expresion Ax = b.
    for(int i = 0; i < data.n; i++){
        b[i] = data.temp_int[i];
        A[i][i] = 1;
        A[tam_A-i-1][tam_A-i-1] = 1;
        b[tam_b-i-1] = data.temp_ext[i];
    }
    //tjk
    T t_a = -2/delta_R*delta_R - 2/r*r*delta_Th*delta_Th + 1/r*delta_R;
    t_a++;
}

// Funcion trivial, resuelve el problema una vez que la matriz es diagonal.
// Basta con divir b[i] por el coeficiente A[i][i] para obtener el valor de la incognita.
template<class T>
void resolverSistema(Matriz<T>& A, vector<T>& b){
    int tamanio = A.cantFilas();
    for(int i = 0; i < tamanio; i++){
        if(A[i][i] != 0 && A[i][i] != 1){b[i] = b[i] / A[i][i]; A[i][i] = 1;}
    }

}



#endif
