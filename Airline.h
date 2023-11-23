#ifndef AIRLINE
#define AIRLINE
#include "Flight.h"
#include <vector>
#include <string>
using namespace std;
class Airline{
    private: 
        string name();
        vector <Flight> flights; //Make linked list 
        int num_flights; 

};
#endif