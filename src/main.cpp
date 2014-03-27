#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h> 
#include "altoHorno.h"
#include "hornoMatrix.h"

using namespace std;

int main (int argc, char* argv[]) {
	
	if (argc < 4) {
		cout << "Wrong number of arguments. 4 and only 4.\n";
		//help message
	}
	// argv[1] = file.in; argv[2] = file.out; argv[3] = 0(EG) | 1(LU)
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
	 	// GET VARIABLES FOR ALL INSTANCES
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

 		int deltaRadios = (re - ri)/(radios-1);
 		int deltaAngles = 360/n;	// @TODO what happens if it's not a round result?

 		// GET INSTANCES
 		for (int i = 0; i < instances; i++) {
 			getline(input_file, line);
 			string delimiter(" ");
 			vector<string> arguments = explode(delimiter, line);


 			hornoMatrix matrixGenerator(deltaRadios, deltaAngles);
 			vector<vector<int>> myMatrix;
 			myMatrix = matrixGenerator.generateMatrix(radios, angles);

 		}
 			


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