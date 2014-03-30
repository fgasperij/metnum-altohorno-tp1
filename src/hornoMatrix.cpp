#include "hornoMatrix.h"


hornoMatrix::hornoMatrix(int dRadio, int dAngle, vector<int> intTemperatures, vector<int> extTemperatures)
{
	internalTemperatures = intTemperatures;
	externalTemperatures = extTemperatures;
	deltaAngle = dAngle;
	deltaRadio = dRadio;
}

vector<vector<int> > hornoMatrix::generateMatrix(int total_radios, int total_angles) 
{
	vector<vector<int> > matrix;
	for(int j = 0; j < total_radios; j++) {
		for (int k = 0; k < total_angles; k++) {
			fillRow(matrix[j], total_radios, total_angles, j, k);
		}
	}

}

void hornoMatrix::fillRow (vector<int> &row, int total_radios, int total_angles, int radio, int angle) 
{
	double neighbour_value;
	for(int j = 0; j < total_radios; j++) {
		for (int k = 0; k < total_angles; k++) {
			// FIRST RADIO
			if (radio == 1 && k == angle) {
				row.push_back(internalTemperatures[angle]);
			} else if (radio == 1 && k != angle) {
				row.push_back(0);
			} 
			//LAST RADIO
			else if (radio == total_radios -1 && k == angle) {
				row.push_back(externalTemperatures[angle]);
			} else if (radio == 1 && k != angle) {
				row.push_back(0);
			}
			// EVERYTHING ELSE
			else if (is_neighbour(radio, angle, j, k)) {
				neighbour_value = calculateNeighbourValue(radio, angle, j, k);
				row.push_back(neighbour_value);
			} else {
				row.push_back(0);
			}
		}
	} 
}

bool hornoMatrix::is_neighbour(int radio, int angle, int j, int k) 
{
	bool left = (radio-1 == j) && (angle == k);
	bool center = (radio == j) && (angle == k);
	bool right = (radio+1 == j) && (angle == k);
	bool upper = (radio == j) && (angle+1 == k);
	bool bottom = (radio == j) && (angle-1 == k);
	
	return (left || center || right || upper || bottom);
}

int hornoMatrix::calculateNeighbourValue (int radio, int angle, int j, int k)
{
	bool left = (radio-1 == j) && (angle == k);
	bool center = (radio == j) && (angle == k);
	bool right = (radio+1 == j) && (angle == k);
	bool upper = (radio == j) && (angle+1 == k);
	bool bottom = (radio == j) && (angle-1 == k);

	if (left) 
		return getLeft();
	if (center)
		return getCenter();
	if(right)
		return getRight();
	if(upper)
		return getUpper();
	if (bottom)
		return getBottom();
}

int hornoMatrix::getLeft () 
{
	return (1-this->deltaRadio) / (this->deltaRadio * this->deltaRadio);
}

int hornoMatrix::getUpper () 
{
	return 1 / (this->deltaAngle * this->deltaAngle);
}

int hornoMatrix::getRight () 
{
	return 1 / (this->deltaRadio * this->deltaRadio);
}

int hornoMatrix::getBottom () 
{
	return 1 / (this->deltaAngle * this->deltaAngle);	
}

int hornoMatrix::getCenter () 
{
	return ( ( -2 / (this->deltaRadio * this->deltaRadio) ) + ( 1 / this->deltaRadio) - ( 2 / (this->deltaAngle * this->deltaAngle) ) );
}
