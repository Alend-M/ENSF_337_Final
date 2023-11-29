#ifndef FLIGHT
#define FLIGHT
#include <vector>
#include <string>
#include "Seat.h"
#include "passenger.h"
using namespace std;
class Flight{

    public:
    Flight();
    Flight(string Flight_Number, int tRows, int tColumns);
    ~Flight();

    string get_Flight_Number()const;
    vector <Passenger> get_PassengerList()const;
    vector <vector<int>> get_seatmap()const; 
    int get_Trows()const;
    int get_TColumns()const; 

    void set_Trows();
    void set_TColumns();
    void addPassenger(Passenger newPassenger);
    void removePassenger(string IDnum);
    void set_Flight_Number(string newFlightNumber);
    void ClaimSeat(Passenger passenger, int row, int column);
    void freeSeat(int row, int column);

    private:
    string FNumber; //Flight number
    vector <Passenger> passengers; //list of passangers 
    vector <vector<int>> seatmap;  
    int Trows; //Total number of rows
    int TColumns; //Total number of columns
};
#endif