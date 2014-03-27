#include <iostream>
#include <vector>
#include <list>
#include <chrono>		//tests
#include <cmath>

#include "Matriz.h"
#include "io.h"
#include "misc.h"
#include "gauss.h"
#include "defines.h"
#include "display.h"




int main(int argc, char** argv){
    Data data;
//	Matriz<double> A (3, 3);
    leerDatosBasicos(argv[1], data);
    for(int i = 0; i < data.c; i++){
        Matriz<double> A (data.n*data.m, data.n*data.m);    //Creo la matriz con ceros.
        vector<double> b (data.n*data.m, 0);    // Creo el vector b, nuevamente con ceros.
        leerDatosAvanzados(argv[1], data, i+1);  //Leo datos avanzados.
        plantearSistema(A, b, data);    // Planteo el sistema, es decir actualizo A y b.
        if(atoi(argv[3]) == EG){if(eliminacionGauss(A, b) == -1){cout << "error " << i << endl;}}
        resolverSistema(A, b); //Resuelvo el sistema.
        escribirResultados(argv[2], b); //Escribo los resultados.
    }
    //
//	A[1][0] = 2;
//	A[0][1] = 1;
//	A[0][2] = 1;
//	A[0][0] = 1;
//	A[1][1] = 1;
//	A[2][2] = 1;
//	vector<double> b (3);
//	b[0] = 1;
//	b[1] = 1;
//	b[2] = 1;
//
////	leerMatrix(A);
//    A.mostrarMatriz();
//	if(eliminacionGauss(A,b) == -1){return -1;};
//	mostrarVector(b); cout << endl;
	return 0;
}
