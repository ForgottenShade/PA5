#include <stdlib.h>
#include <string>

#include "Slashes.h"

using namespace std;

string getSlashes(){
    string slash;
    #ifdef _WIN32
		slash = "\\";        
	#elif __linux__
		slash = "/";
    #endif

    return slash;
}