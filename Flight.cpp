#include "Flight.h"

Flight::Flight() {
    Trows = 0;
    TColumns = 0;
    vector <Passanger> passangers;
    vector <vector<Seat>> seatmap;
}

Flight::Flight(const string& flightNumber, int tRows, int tColumns) {
    this->flightNumber = flightNumber;
    this->Trows = tRows;
    this->TColumns = tColumns;

    // Allocate memory for the 2D seat map
    seatmap.resize(tRows, vector<Seat>(tColumns));

    // Initialize all seats to empty
    for (int i = 0; i < tRows; i++) {
        for (int j = 0; j < tColumns; j++) {
            seatmap[i][j] = Seat();
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