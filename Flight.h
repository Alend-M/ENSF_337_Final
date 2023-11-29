#ifndef FLIGHT
#define FLIGHT
#include <vector>
#include <string>
#include "passenger.h"
using namespace std;

class Flight{

    public:
    Flight();
    Flight(string Flight_Number, int tRows, int tColumns);
    ~Flight();

    string get_Flight_Number()const{return FNumber;};
    vector <Passenger> get_PassengerList()const{return passengers;};
    vector <vector<int>> get_seatmap()const{return seatmap;}; 
    int get_Trows()const{return Trows;};
    int get_TColumns()const{return TColumns;}; 

    void set_Trows();
    void set_TColumns();
    string addPassenger(Passenger newPassenger);
    void removePassenger(int IDnum);
    void set_Flight_Number(string newFlightNumber);

    private:
    string FNumber; //Flight number
    vector <Passenger> passengers; //list of passangers 
    vector <vector<int>> seatmap;  
    int Trows; //Total number of rows
    int TColumns; //Total number of columns
};
#endif