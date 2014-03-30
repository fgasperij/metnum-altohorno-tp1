#include <vector>

using namespace std;
class hornoMatrix
{
	int deltaRadio;
	int deltaAngle;
	vector<int> internalTemperatures;
	vector<int> externalTemperatures;

	public:
		hornoMatrix(int dRadio, int dAngle, vector<int> intTemperatures, vector<int> extTemperatures);
		vector<vector<int> > generateMatrix(int total_radios, int total_angles);

	private:
		void fillRow (vector<int> &row, int total_radios, int total_angles, int radio, int angle);
		bool is_neighbour(int radio, int angle, int j, int k); 
		int calculateNeighbourValue (int radio, int angle, int j, int k) ;
		int getLeft (); 
		int getUpper (); 
		int getRight (); 
		int getBottom (); 
		int getCenter (); 
};
