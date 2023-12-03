#ifndef AIRLINE
#define AIRLINE
#include "Flight.h"
#include <vector>
#include <string>
using namespace std;

struct Node {
  Flight flight; // The data value
  Node* next; // Pointer to the next node in the list
};

class Airline{
    public: 
        Airline(string AirlineName, int Nflight);
        ~Airline();
        
        string getAirlineName() const {return AirlineName;};
        int getNumFlights() const {return num_flights;};

        void addFlight(Flight newFlight);
    private: 
        string AirlineName;
        Node* head;  
        int num_flights; 
};


#endif