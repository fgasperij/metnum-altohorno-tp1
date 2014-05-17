#ifndef MISC_H
#define MISC_H

#include <vector>
#include <cmath>

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
                max_val = abs(A[h][i]);
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
                max_val = abs(A[h][i]);
                max_pos = h;
            }
        }
        return max_pos;
    }
}

int damePos(int i, int j, int angulos){
    if(j == 0){return  (angulos + (i-1)*angulos);}
    else if(j == angulos+1){return (1 + (i-1)*angulos);}
    return j + (i-1)*angulos;
}

template<class T>
T dameActual(T r, T delta_R, T delta_Th){
    return -2/(delta_R*delta_R) + 1/(r*delta_R) - 2/(r*r*delta_Th*delta_Th);
}

template<class T>
T dameAntRad(T r, T delta_R){
    return 1/(delta_R*delta_R) - 1/(r*delta_R);
}

template<class T>
T dameAntAng(T r, T delta_Th){
    return 1/(r*r*delta_Th*delta_Th);
}

template<class T>
T dameSigRad(T r, T delta_R){
    return 1/(delta_R*delta_R);
}

template<class T>
T dameSigAng(T r, T delta_Th){
    return dameAntAng(r,delta_Th);
}


template<class T>
void cargarFila(Matriz<T>& A, int i, int j, T rad, T delta_R, T delta_Th, int angulos, T rad_int){
    T r = (i-1)*delta_R +rad_int;
    int idAntRad = damePos(i-1, j, angulos)-1;
    int idAntAng = damePos(i, j-1, angulos)-1;
    int idSigRad = damePos(i+1, j, angulos)-1;
    int idSigAng = damePos(i, j+1, angulos)-1;
    int idActual = damePos(i, j, angulos)-1;
    A[idActual][idActual] = dameActual(r, delta_R, delta_Th);
    A[idActual][idAntRad] = dameAntRad(r, delta_R);
    A[idActual][idAntAng] = dameAntAng(r, delta_Th);
    A[idActual][idSigRad] = dameSigRad(r, delta_R);
    A[idActual][idSigAng] = dameSigAng(r, delta_Th);
}



//Esta funcion se encarga de plantear el sistema
template<class T>
void plantearSistema(Matriz<T>& A, vector<T>& b, Data& data, int cant = TODO){
    int tam_b = b.size();
    int tam_A = A.cantFilas();
    int tam_temp_ext = data.temp_ext.size();
    //Parte superior e inferior de A y b de la expresion Ax = b.
    if(cant == TODO || cant == VECTOR_b){
        for(int i = 0; i < data.n; i++){
            b[i] = data.temp_int[i];
            b[tam_b-i-1] = data.temp_ext[tam_temp_ext-i-1];
        }
    }
    // El resto, para cada radio y para cada angulo en ese radio
    if(cant == TODO || cant == MATRIZ_A){
        T rad = data.rad_ext - data.rad_int;
        T delta_R = rad/(data.m-1);
        T delta_Th = (2*pi)/data.n;
        T rad_int =  data.rad_int;

        for(int i = 0; i < data.n; i++){
            A[i][i] = 1;
            A[tam_A-i-1][tam_A-i-1] = 1;
        }

        for(int i = 2; i < data.m; i++){
            for(int j = 1; j < data.n+1; j++){
                cargarFila(A, i, j, rad, delta_R, delta_Th, data.n, rad_int);
            }
        }
    }
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

template<class T>
bool esCero(T& val){
   return ((-CERO < val) && (val < CERO));
}


template<class T>
void backSubst(Matriz<T>& A, vector<T>& b, vector<T>& res, int lu = NO_LU){
    int tamanio = A.cantFilas();
    vector<T> aux = vector<T> (tamanio);
    if(lu == LU){
        for(int i = 0; i < tamanio; i++){
            aux[i] = A[i][i];
            A[i][i] = 1;
        }
    }
    if(res.size() != (unsigned int) tamanio){cerr << "backSubst: Tamaño no coincidente" << endl; return;}
    for(int i = tamanio-1; i+1 > 0; i--){
        T acum = 0;
        for(int j = tamanio-1; j > i ; j--){
            acum += res[j]*A[i][j];
        }
        res[i] = (b[i] - acum)/A[i][i];
    }
    if(lu == LU){
        for(int i = 0; i < tamanio; i++){
            A[i][i] = aux[i];
        }
    }
}

template<class T>
void forwSubst(Matriz<T>& A, vector<T>& b, vector<T>& res, int lu = NO_LU){
    int tamanio = A.cantFilas();
    vector<T> aux = vector<T> (tamanio);
    if(lu == LU){
        for(int i = 0; i < tamanio; i++){
            aux[i] = A[i][i];
            A[i][i] = 1;
        }
    }
    if(res.size() != (unsigned int) tamanio){cerr << "forwSubst: Tamaño no coincidente" << endl; return;}
    for(int i = 0; i < tamanio; i++){
        T acum = 0;
        for(int j = 0; j < i ; j++){
            acum += res[j]*A[i][j];
        }
        res[i] = (b[i] - acum)/A[i][i];
    }
    if(lu == LU){
        for(int i = 0; i < tamanio; i++){
            A[i][i] = aux[i];
        }
    }
}



#endif
