#include <sstream>
#include <string>
#include <vector>

using namespace std;

int strToInt(string convertMe) {
	int result;	
	stringstream convert(convertMe);

	if ( !(convert >> result) )
    	result = 0;

    return result;
}

vector<string> explode( const string &delimiter, const string &str)
{
    vector<string> arr;
 
    int strleng = str.length();
    int delleng = delimiter.length();
    if (delleng==0)        
        return arr;
 
    int i=0;
    int k=0;
    while( i<strleng ) {
        int j=0;
        while (i+j<strleng && j<delleng && str[i+j]==delimiter[j])
            j++;
        
        // found delimiter
        if (j == delleng) {
            arr.push_back(  str.substr(k, i-k) );
            i+=delleng;
            k=i;
        } else {
            i++;
        }
    }
    arr.push_back(  str.substr(k, i-k) );
    return arr;
}