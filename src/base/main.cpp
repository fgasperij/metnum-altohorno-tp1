#include <iostream>
#include <vector>
#include <list>
//#include <chrono>		//tests
#include <cmath>
#include <cstdlib>

#include "Matriz.h"
#include "io.h"
#include "misc.h"
#include "gauss.h"
#include "defines.h"
#include "display.h"
#include "time.h"


int main(int argc, char** argv){
    if(argc != 4){cerr << "Error: argumentos insuficientes" << endl;return -1;}
    Data data;
    leerDatosBasicos(argv[1], data);
    Matriz<double> A (data.n*data.m);    //Creo la matriz con ceros.
    vector<double> b (data.n*data.m, 0);    // Creo el vector b, nuevamente con ceros.

    for(int i = 0; i < data.c; i++){

        vector<double> res (data.n*data.m);
        leerDatosAvanzados(argv[1], data, i+1);  //Leo datos avanzados.
        plantearSistema(A, b, data, VECTOR_b);    // Planteo el sistema, es decir actualizo b.
        if(atoi(argv[3]) == EG){
            if(i != 0){
                A = Matriz<double> (data.n*data.m);
                b = vector<double> (data.n*data.m, 0);
            }
            plantearSistema(A, b, data);
            gaussInf(A, b, NO_PIV);
            backSubst(A, b, res);
            escribirVector(argv[2], res); //Escribo los resultados.
        }
        else{
            if(i == 0){
                plantearSistema(A, b, data, MATRIZ_A); gaussInf(A, b, NO_PIV, LU);
            }
            forwSubst(A, b, res, LU);
            vector<double> res_lu = vector<double> (data.n*data.m);
            backSubst(A, res, res_lu);
            escribirVector(argv[2], res_lu); //Escribo los resultados.
        }

    }


	return 0;
}
