#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h> 
#include "altoHorno.h"

using namespace std;
/**
 * Parametros de entrada:
 * ri, re, m+1, n, isoterma, Ti, Te(tita)
 *
 *
 */
int main (int argc, char* argv[]) {
	// argv[1] = file.in; argv[2] = file.out; argv[3] = 0(EG) | 1(LU)
	if (argc < 4) {
		cout << "Wrong number of arguments. 4 and only 4.\n";
		//help message
	}
	
	char* input_filename = argv[1];
	char* output_filename = argv[2];
	int resolution_method = atoi(argv[3]);  // @TODO is this the correct way to turn the string to an int? 
	
	// parse file.in
	/**
	 * Primera linea
	 * ri , re , m + 1, n, iso, ninst
	 * Ninst lineas
	 * n valores de la pared interna (T(tita_0)...T(tita_n-1)), n valores de la pared externa 
	 */

	 
	 ifstream input_file(input_filename);
	 if (input_file.is_open()) {
 		string line;
 		getline(input_file, line);
 		
 		string delimiter(" ");
 		vector<string> arguments = explode(delimiter, line);
 		
 		int ri = strToInt(arguments[0]);
 		int re = strToInt(arguments[1]);
 		int radios = strToInt(arguments[2]);
 		int angles = strToInt(arguments[3]);
 		int isoterm = strToInt(arguments[4]);
 		int instances = strToInt(arguments[5]);

 		printf("ri: %i re: %i radios: %i angles: %i isoterm %i isntances %i \n", ri, re, radios, angles, isoterm, instances);
	 	input_file.close();
	 }
	 

	 /*
	 ofstream output_file(output_filename);
	 if (output_file.is_open()) {


	 	output_file.close();
	 }
	*/
	// write file.out

	return 0;
}