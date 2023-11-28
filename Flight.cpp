#include "Flight.h"
#include "passanger.h"
#include <string>
#include <vector>
using namespace std; 

Flight::Flight() {
    string FNumber("");
    Trows = 0;
    TColumns = 0;
    vector <Passanger> passangers;
    vector <vector<int>> seatmap;
    seatmap.resize(Trows, vector<int>(TColumns));
    for (int i = 0; i < Trows; ++i) {
        for (int j = 0; j < TColumns; ++j) {
            seatmap[i][j] = 0;
        }
    }
}

Flight::Flight(char *Flight_Number, int tRows, int tColumns, vector<Passanger>& p) {
    string FNumber(Flight_Number);
    Trows = tRows;
    TColumns = tColumns;
    vector <Passanger> passangers = p; 
    vector <vector<int>> seatmap;
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

vector<Passanger> Flight::get_PassangerList() const {
    return passangers;
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

void Flight::addPassanger(Passanger newPassanger) {
    passangers.push_back(newPassanger);
}

void Flight::removePassanger(string IDNum) {
    for (vector<Passanger>::iterator it = passangers.begin(); it != passangers.end(); ++it) {
        if (it->get_ID() == IDNum) {   
            passangers.erase(it);
            break;
        }
    }
}

void Flight::ClaimSeat(Passanger passenger, int row, int column) {
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
