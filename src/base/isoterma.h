#ifndef ISOT_H
#define ISOT_H

#include <vector>
#include <cmath>
#include <stdlib.h>
#include <assert.h>


/**
 * Se asume que hay una unica isoterma.
 */

vector<double> calcularIsotermas(vector<double> temps, int cant_r, int cant_a, double isoterma, 
  double ri, double delta_r, bool interpolacion_lineal){
  vector<double> radiosIsoterma (cant_a);
  vector<int> radiosMasCerca = calcularRadiosMasCerca(temps, cant_r, cant_a, isoterma);

  for (int angulo = 0; angulo < cant_a; angulo++) {
    int radio_mas_cerca = radiosMasCerca[angulo]
    int temp_radio_mas_cerca = temps[ ( radio_mas_cerca * cant_a ) + angulo ];
    int temp_derecha = temps[ ( ( radio_mas_cerca + 1 ) * cant_a ) + angulo ];
    int temp_izquierda = temps[ ( ( radio_mas_cerca - 1 )  * cant_a ) + angulo ];
    
    if ( (temp_radio_mas_cerca < isoterma && temp_derecha > isoterma) || 
      (temp_radio_mas_cerca > isoterma && temp_derecha < isoterma)) {
      if (interpolacion_lineal) {
        radiosIsoterma[angulo] = interpolacionLineal(radio_mas_cerca, temp_radio_mas_cerca, 
          radio_mas_cerca+1, temp_derecha, ri, delta_r, isoterma);
      } else {
        radiosIsoterma[angulo] = promedioRadios(radio_mas_cerca, ri, delta_r);         
      }
      
    
    } else if ((temp_radio_mas_cerca < isoterma && temp_izquierda > isoterma) || 
      (temp_radio_mas_cerca > isoterma && temp_izquierda < isoterma)) {
      if (interpolacion_lineal) {
        radiosIsoterma[angulo] = interpolacionLineal(radio_mas_cerca, temp_radio_mas_cerca, 
          radio_mas_cerca-1, temp_derecha, ri, delta_r);
      } else {
        radiosIsoterma[angulo] = promedioRadios(radio_mas_cerca-1, ri, delta_r);       
      }

    }
  }
  
  return radiosIsoterma;
}

vector<double> interpolacionLineal(int radio1, double temp1, int radio2, double temp2, 
  double ri, double delta_r, double isoterma){
  double temp_diff = abs(temp1-temp2);
  double k = delta_r / temp_diff;

  if (temp1 < temp2) {
    double isoterma_diff = abs(temp1 - isoterma);
    return ri + (delta_r * radio1) + (isoterma_diff * k);
  } else {
    double isoterma_diff = abs(temp2 - isoterma);
    return ri + (delta_r * radio2) - (isoterma_diff * k);
  }
}

/**
 * Calcula la distancia entre el centro del horno y la mitad entre dos radios.
 *
 * Toma un radio, el mas cercano al horno, y calcula su distancia mas la mitad
 * de delta_r, que es la distancia al radio que le sigue.
 *
 */
double promedioRadios(int radio, double ri, double delta_r) {
  return ri + (radio*delta_r) + (delta_r/2);
}

vector<int> calcularRadiosMasCerca(vector<double> temps, int cant_r, int cant_a, double isot) {
  vector<int> radiosMasCerca (cant_a);
  for(int angulo = 0; angulo < cant_a; angulo++){
    double r_mas_cerca = 0;
    double r_mas_cerca_por = abs(temps[angulo] - isot);
    for(int radio = 0; radio < cant_r; radio++){
      double cerca_por = abs(temps[cant_a*radio+angulo] - isot);
      if (cerca_por < r_mas_cerca_por){
        r_mas_cerca = radio;
        r_mas_cerca_por = cerca_por;
      }      
    }
    radiosMasCerca[angulo] = r_mas_cerca;
  }
}

#endif
