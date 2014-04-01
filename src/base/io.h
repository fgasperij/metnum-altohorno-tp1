#ifndef IO_H
#define IO_H

#include "defines.h"
#include "fstream"
#include <limits>

//Funciones de entrada salida pare leer y escribir datos en archivos.

void setearPrecision(ofstream& of, int prec){
   of.setf(ios::fixed, ios::floatfield );
   of.precision(prec);
}

//Lee los datos basios del archivo. La primer linea.
void leerDatosBasicos(const char* file, Data& data){
    ifstream file_s; file_s.open(file);
    file_s >> data.rad_int >> data.rad_ext >> data.n >> data.m >> data.isoterma >> data.c;
    data.temp_ext = vector<double> (data.n);
    data.temp_int = vector<double> (data.n);
    file_s.close();
}

//Lee los 2n elementos de la linea inst.
void leerDatosAvanzados(const char*  file, Data& data, int inst){
    ifstream file_s; file_s.open(file);
    for(int i=0; i < inst; ++i){
        file_s.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    for(int i = 0; i < data.n; i++){
        file_s >> data.temp_int[i];
    }
    for(int i = 0; i < data.n; i++){
        file_s >> data.temp_ext[i];
    }

    file_s.close();
}

// Escribe los resultados en archivo de salida.
template<class T>
void escribirVector(const char*  file, vector<T>& b){
    ofstream file_s; file_s.open(file, fstream::app);
    setearPrecision(file_s, PRECISION);
    int tamanio = b.size();
    for(int i = 0; i < tamanio; i++){
        file_s << b[i];
        if(i == tamanio-1){file_s << endl;}
        else{file_s << " ";}
    }
    file_s.close();
}

template<class T>
void escribirMatriz(const char*  file, Matriz<T>& A){
    for(int i = 0; i < A.cantFilas(); i++){
        escribirVector(file, A[i]);
    }
}

template<class T>
void leerVector(const char*  file, vector<T>& b){
    ifstream file_s; file_s.open(file);
    int tamanio = b.size();
    for(int i = 0; i < tamanio; i++){
        file_s >> b[i];
    }
    file_s.close();
}


template<class T>
void leerMatriz(const char*  file, Matriz<T>& A){
    ifstream file_s; file_s.open(file);
    for(int i = 0; i < A.cantFilas(); i++){
        for(int j = 0; j < A.cantColumnas(); j++){
            file_s >> A[i][j];
        }
        file_s.get();
    }
    file_s.close();
}
#endif
