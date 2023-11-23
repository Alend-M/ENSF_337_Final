#ifndef FLIGHT
#define FLIGHT
#include <vector>
#include <string>
#include "Seat.h"
#include "passanger.h"
using namespace std;
class Flight{

    public:
    //Flight();
    //Flight(int fNumber, int tRows, int tColumns);

    private:
    string FNumber(); //Flight number
    vector <Passanger> passangers; //list of passangers  //CAN CHANGE LINKED LIST 
    vector <vector<Seat>> seatmap; 
    int *HeadM; // !!Change 
    int Trows; //Total number of rows
    int TColumns; //Total number of columns
};
#endif