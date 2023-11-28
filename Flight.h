#ifndef FLIGHT
#define FLIGHT
#include <vector>
#include <string>
#include "Seat.h"
#include "passanger.h"
using namespace std;
class Flight{

    public:
    Flight();
    Flight(char *Flight_Number, int tRows, int tColumns,vector<Passanger>& p);
    ~Flight();

    string get_Flight_Number()const;
    vector <Passanger> get_PassangerList()const;
    vector <vector<int>> get_seatmap()const; 
    int get_Trows()const;
    int get_TColumns()const; 

    void set_Trows();
    void set_TColumns();
    void addPassanger(Passanger newPassanger);
    void removePassanger(string IDnum);
    void set_Flight_Number(string newFlightNumber);
    void ClaimSeat(Passanger passenger, int row, int column);
    void freeSeat();

    private:
    string FNumber(); //Flight number
    vector <Passanger> passangers; //list of passangers 
    vector <vector<int>> seatmap;  
    int Trows; //Total number of rows
    int TColumns; //Total number of columns
};
#endif