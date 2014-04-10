#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <cstdlib>

#include "Matriz.h"
#include "io.h"
#include "misc.h"
#include "gauss.h"
#include "defines.h"
#include "display.h"
#include "time.h"
#include "isoterma.h"

using namespace std;

int main(int argc, char** argv){
    if(argc != 5){cerr << "Error: argumentos insuficientes" << endl;return -1;}
    Data data;
    leerDatosBasicos(argv[1], data);
    Matriz<double> A (data.n*data.m);    //Creo la matriz con ceros.
    vector<double> b (data.n*data.m, 0);    // Creo el vector b, nuevamente con ceros.

    for(int i = 0; i < data.c; i++){

        vector<double> temps (data.n*data.m);
	vector<double> res_final (data.n*data.m);
        leerDatosAvanzados(argv[1], data, i+1);  //Leo datos avanzados.
        plantearSistema(A, b, data, VECTOR_b);    // Planteo el sistema, es decir actualizo b.
        if(atoi(argv[3]) == EG){
	//Gauss:
            if(i != 0){
                A = Matriz<double> (data.n*data.m);
                b = vector<double> (data.n*data.m, 0);
            }
            plantearSistema(A, b, data);
            gaussInf(A, b, NO_PIV);
            backSubst(A, b, temps);

	    res_final = temps;

        } else{
	//LU:
            if(i == 0){
                plantearSistema(A, b, data, MATRIZ_A); gaussInf(A, b, NO_PIV, LU);
            }
            forwSubst(A, b, temps, LU);
            vector<double> temps_lu = vector<double> (data.n*data.m);
            backSubst(A, temps, temps_lu);
            res_final = temps_lu;
        }
	if(atoi(argv[4]) == ISO){
	//Escribir Isoterma 
            // calculo de la isoterma
            double rad = data.rad_ext - data.rad_int;
            double delta_R = rad/(data.m-1);
            double delta_Th = (2*pi)/data.n;
            vector<double> isotermas (data.n);
            isotermas = calcularIsotermas(res_final, data.m, data.n, data.isoterma, data.rad_int, delta_R, 0);
            
            // escribo ISOTERMAS
            escribirVector(argv[2], isotermas);
	}
	else{
	//Escribir vector de Temps
	escribirVector(argv[2], res_final);
        }

    }
	return 0;
}
