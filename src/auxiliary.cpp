#include <sstream>
#include <string>

using namespace std;

int strToInt(string convertMe) {
	int result;	
	stringstream convert(convertMe);

	if ( !(convert >> result) )
    	result = 0;

    return result;
}

vector<vector<int>> generateMatrix(int total_radios, int total_angles) {
	vector<vector<int>> matrix;
	for(int j = 0; j < total_radios; j++) {
		for (int k = 0; k < total_angles; k++) {
			fillRow(matrix[j], total_radios, total_angles, j, k);
		}
	}

}

void fillRow (vecto<int> &row, int total_radios, int total_angles, int radio, int angle) {
	double neighbour_value;
	for(int j = 0; j < total_radios; j++) {
		for (int k = 0; k < total_angles; k++) {
			if (is_neighbour(radio, angle, j, k)) {
				neighbour_value = calculateNeighbourValue(radio, angle, j, k);
				row.push_back(neighbour_value);
			} else {
				row.push_back(0);
			}
		}
	} 
}

bool 
int getLeft (int deltaRadio) {
	return (1-deltaRadio) / (deltaRadio * deltaRadio);
}

int getUpper (int deltaAngle) {
	return 1 / (deltaAngle * deltaAngle);
}

int getRight (int deltaRadio) {
	return 1 / (deltaRadio * deltaRadio);
}

int getBottom (int deltaAngle) {
	return 1 / (deltaAngle * deltaAngle);	
}

int getCenter (int deltaRadio, int deltaAngle) {
	return ( ( -2 / (deltaRadio * deltaRadio) ) + ( 1 / deltaRadio) - ( 2 / (deltaAngle * deltaAngle) ) );
}