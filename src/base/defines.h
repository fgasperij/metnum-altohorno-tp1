#ifndef DEFINES_H
#define DEFINES_H

#include <vector>

using namespace std;

typedef vector<int> Pos;


//Datos del problema, descripcion autocontenida.
struct Data{
    double rad_int;
    double rad_ext;
    double isoterma;
    int n;
    int m;
    int c;
    vector<double> temp_int;
    vector<double> temp_ext;
};

//Algunas constantes

#define SUP 1
#define INF 0

#define EG 0
#define LU 1

#define PIV 1
#define NO_LU 0
#define LU 1

#define pi 3.1415926
#define CERO 1e-16


#endif
