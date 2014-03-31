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
    int tam_b = b.size();
    int tam_A = A.cantFilas();
    //Parte superior e inferior de A y b de la expresion Ax = b.
    // (lo que no se llena queda en 0)
    for(int i = 0; i < data.n; i++){
        b[i] = data.temp_int[i];
        A[i][i] = 1;
        A[tam_A-i-1][tam_A-i-1] = 1;
        b[tam_b-i-1] = data.temp_ext[i];
    }

    //Parte del medio de A y de b
    int lim = (data.n*data.m)-data.n; // tiene que ser menor a esto para ser del medio
    //Los delta son siempre los mismos para cada r y theta respectivamente
    T r = data.rad_ext - data.rad_int;
    T delta_R = r/(data.m-1);
    T delta_Th = (2*pi)/data.n;
    //Como son constantes, los multiplicadores (que no usan a r) de las incognitas también
    //Calculamos lo que no cambia y luego agregamos en el for lo que falta
    T t_ant_este = 1/pow(delta_R,2); //Se completará con el R
    T t_este_este = -2/pow(delta_R,2); //Se completará con el R
    T t_sig_este = 1/pow(delta_R,2); //No cambia
    T t_este_ant = 1/pow(delta_Th,2); //Se completará con el r
    T t_este_sig = 1/pow(delta_Th,2); //Se completará con el r

    //Acomodamos todo según la ecuación de derivadas
    for(int i = data.n; i < lim; i++){
    	//Calculamos el radio de esta pos
	// i=k*data.n+resto ==> k=(i-resto)/n y tiene que dar exacto
	int pos_radio = i/data.n; //dado que (i-r)/n = floor(i/n) <= i/n
	int radio = data.rad_int * (pos_radio*delta_R); // calculo la magnitud del r_(pos_radio)

        b[i] = 0;
        A[i][i-data.n] = t_ant_este - 1/(radio*delta_R); //t_j-1_k
        A[i][i] = t_este_este + 1/(radio*delta_R) - 2/(pow(radio,2)*pow(delta_Th,2)); //t_j_k
        A[i][i+data.n] = t_sig_este; //t_j+1_k
        A[i][i-1] = t_este_ant * 1/pow(radio,2); //t_j_k-1
        A[i][i+1] = t_este_sig * 1/pow(radio,2); //t_j_k+1
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



#endif
