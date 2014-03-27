#include <vector>

class hornoMatrix
{
	int deltaRadio;
	int deltaAngle;
	vector<int> internalTemperatures;
	vector<int> externalTemperatures;

	public:
		hornoMatrix(int dRadio, int dAngle);
		vector<vector<int>> generateMatrix(int total_radios, int total_angles);

	private:
		void fillRow (vecto<int> &row, int total_radios, int total_angles, int radio, int angle);
		bool is_neighbour(radio, angle, j, k); 
		int calculateNeighbourValue (radio, angle, j, k) ;
		int getLeft (); 
		int getUpper (); 
		int getRight (); 
		int getBottom (); 
		int getCenter (); 
}