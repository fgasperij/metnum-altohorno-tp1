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