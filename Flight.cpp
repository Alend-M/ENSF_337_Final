#include "Flight.h"
#include "passenger.h"
#include <string>
#include <vector>
using namespace std; 

Flight::Flight() {
    string FNumber("");
    Trows = 0;
    TColumns = 0;
    passengers.clear(); 
    seatmap.clear();
}

Flight::Flight(string Flight_Number, int tRows, int tColumns) {
    FNumber = Flight_Number; 
    Trows = tRows;
    TColumns = tColumns;
    passengers.clear(); //Sets that there are 0 passangers on this flight
    vector<vector<int>> seatmap;         //Sets the map of seats and set to empty cause flight is empty
    seatmap.resize(Trows, vector<int>(TColumns));
    for (int i = 0; i < Trows; ++i) {
        for (int j = 0; j < TColumns; ++j) {
        seatmap[i][j] = 0; 
    }
  }
}

Flight::~Flight() {
    // Free memory allocated for the 2D seat map
    for (int i = 0; i < Trows; i++) {
        seatmap[i].clear();
    }
    seatmap.clear();
}

string Flight::get_Flight_Number() const {
    return FNumber;
}

vector<Passenger> Flight::get_PassengerList() const {
    return passengers;
}

vector<vector<int>> Flight::get_seatmap() const {
    return seatmap;
}

int Flight::get_Trows() const {
    return Trows;
}

int Flight::get_TColumns() const {
    return TColumns;
}

void Flight::set_Flight_Number(string newFlightNumber) {
    FNumber = newFlightNumber;
}

void Flight::addPassenger(Passenger newPassenger) {
    passengers.push_back(newPassenger);
}

void Flight::removePassenger(string IDNum) {
    for (vector<Passenger>::iterator it = passengers.begin(); it != passengers.end(); ++it) {
        if (it->get_ID() == IDNum) {   
            passengers.erase(it);
            break;
        }
    }
}

void Flight::ClaimSeat(Passenger passenger, int row, int column) {
    if (row < 0 || row >= Trows || column < 0 || column >= TColumns) {
        cout << "Invalid seat coordinates" << endl;
        return;
    }

    if (seatmap[row][column] == 1) {
        cout << "Seat is already occupied" << endl;
        return;
    }

    seatmap[row][column] = 1;
    passenger.setStatus(true);
    passenger.setRow(row);
    passenger.setColumn(column);
}

void Flight::freeSeat(int row, int column) {
    if (row < 0 || row >= Trows || column < 0 || column >= TColumns) {
        cout << "Invalid seat coordinates" << endl;
        return;
    }

    if (seatmap[row][column] == 0) {
        cout << "Seat is already empty" << endl;
        return;
    }

    seatmap[row][column] = 0;
}
