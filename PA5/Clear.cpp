#include <stdlib.h>
#include <iostream>


using namespace std;

void clear(){
	#ifdef _WIN23
		system("CLS");
	#elif __linux__
		system("clear");
    #endif
}