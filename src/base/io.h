#ifndef IO_H
#define IO_H

#include "defines.h"
#include "fstream"
#include "defines.h"
#include <limits>

//Funciones de entrada salida pare leer y escribir datos en archivos.
///******TODO****//// Revisar y testear....

//Lee los datos basios del archivo. La primer linea.
void leerDatosBasicos(string file, Data& data){
    ifstream file_s; file_s.open(file);
    file_s >> data.rad_int >> data.rad_ext >> data.isoterma >> data.n >> data.m >> data.c;
    file_s.close();
}

//Lee los 2n elementos de la linea inst.
void leerDatosAvanzados(string file, Data& data, int inst){
    ifstream file_s; file_s.open(file);
    for(int i=0; i < inst; ++i){
        file_s.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    for(int i = 0; i < data.n; i++){
        file_s >> data.temp_int[i];// = file_s.get();
    }
    for(int i = 0; i < data.n; i++){
        file_s >> data.temp_ext[i];// = file_s.get();
    }

    file_s.close();
}

// Escribe los resultados en archivo de salida.
template<class T>
void escribirResultados(string file, vector<T>& b){
    ofstream file_s; file_s.open(file, fstream::app);
    int tamanio = b.size();
    for(int i = 0; i < tamanio; i++){
        file_s << b[i];
        if(i == tamanio-1){file_s << endl;}
        else{file_s << " ";}
    }
    file_s.close();
}

#endif
