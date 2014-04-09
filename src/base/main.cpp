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
    if(argc != 4){cerr << "Error: argumentos insuficientes" << endl;return -1;}
    Data data;
    leerDatosBasicos(argv[1], data);
    Matriz<double> A (data.n*data.m);    //Creo la matriz con ceros.
    vector<double> b (data.n*data.m, 0);    // Creo el vector b, nuevamente con ceros.

    for(int i = 0; i < data.c; i++){

        vector<double> res (data.n*data.m);
        cout << res.size();
        leerDatosAvanzados(argv[1], data, i+1);  //Leo datos avanzados.
        cout << res.size();
        plantearSistema(A, b, data, VECTOR_b);    // Planteo el sistema, es decir actualizo b.
        cout << res.size();
        if(atoi(argv[3]) == EG){
            if(i != 0){
                A = Matriz<double> (data.n*data.m);
                b = vector<double> (data.n*data.m, 0);
            }
            cout << res.size();
            plantearSistema(A, b, data);
            cout << res.size();
            gaussInf(A, b, NO_PIV);
            cout << res.size();
            backSubst(A, b, res);
            cout << res.size();

            // calculo de la isoterma
            // double rad = data.rad_ext - data.rad_int;
            // double delta_R = rad/(data.m-1);
            // double delta_Th = (2*pi)/data.n;
            // vector<double> isotermas (data.n);
            // isotermas = calcularIsotermas(res, data.m, data.n, data.isoterma, data.rad_int, delta_R, 0);
            
            // escribo ISOTERMAS
            //escribirVector(argv[2], isotermas);

            // escribo X
            escribirVector(argv[2], res);
        } else{
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
