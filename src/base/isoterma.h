#ifndef ISOT_H
#define ISOT_H

#include <vector>
#include <cmath>
#include <stdlib.h>
#include <assert.h>



vector<double> algoritmoExacto(vector<double> temps, int cant_r, int cant_a, double isot){
  //Itero todas las temps para buscar el radio que se parezca más a la isoterma bucada para un
  //ángulo dado.
  vector<double> res (cant_a);
  for(int angulo=0; angulo<cant_a; angulo++){
   double r_mas_cerca=0;
   double r_mas_cerca_por = abs(temps[angulo*cant_a] - isot);
   for(int i=0; i < cant_r; i++){
     double cerca_por = abs(temps[cant_a*i+angulo] - isot);
     if (cerca_por < r_mas_cerca_por){
       r_mas_cerca = i;
       r_mas_cerca_por = cerca_por;
       }
    res[angulo] = r_mas_cerca;
   }
    //Ya iteró todos los radios de un ángulo fijo
  }
  return res;
}

vector<double> algoritmoHeuristico(vector<double> temps, int cant_r, int cant_a, double isot, int r_pivote, int dist_max){
  //No itero todas las temps por un ángulo dado. Empiezo con un radio dado y después sólo miraré 
  //de los radios del ángulo de su lado "anticlockwise" una cantidad que se aleje tanto del radio
  //en donde estoy parado como lo indique la variable "dist_max" que está en radios.
  //¡¡r_pivote se va actualizando a medida se elige un radio!!

  //ASUMO QUE:
  assert(dist_max <= cant_r);
  assert(r_pivote < cant_r);


  vector<double> res (cant_a);
  for(int angulo=0; angulo<cant_a; angulo++){
   double r_mas_cerca_por = abs(temps[angulo*cant_a+r_pivote] - isot);
   
   int radio_min;
   if(0>r_pivote-dist_max) radio_min=0;
   else radio_min = r_pivote-dist_max;

   for(int radio=radio_min; (radio < dist_max+r_pivote && radio < cant_r); radio+=cant_a){
     double cerca_por = abs(temps[angulo*cant_a+radio] - isot);
     if (cerca_por < r_mas_cerca_por){
       r_pivote = radio;
       r_mas_cerca_por = cerca_por;
       }
   }
    //Ya iteró todos los radios en un intervalo de radios de un ángulo fijo
    res[angulo] = r_pivote;
  }
  return res;
}

#endif
