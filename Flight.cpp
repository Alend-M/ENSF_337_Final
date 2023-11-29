#include "Flight.h"
#include "passenger.h"
#include "Seat.h"
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

void Flight::set_Flight_Number(string newFlightNumber) {
    FNumber = newFlightNumber;
}

string Flight::addPassenger(Passenger newPassenger) {
    for (vector<Passenger>::iterator it = passengers.begin(); it != passengers.end(); ++it) {
        //if id is already used on the flight return error
        if(newPassenger.getId() == it->getId()){
            return "ID already taken!";
        }

        //checks if the seat is alreadt occupied 
        if(newPassenger.getSeat().get_col() == it->getSeat().get_col() 
        && newPassenger.getSeat().get_row() == it->getSeat().get_row()){
            return "Seat is already occupied!";
        }
    }

    //checks list of passangers from bottom to top. If adding 
    for (vector<Passenger>::reverse_iterator it = passengers.rbegin(); it != passengers.rend(); ++it) {
        if (newPassenger.getId() > it->getId()) {
            // Insert the new passenger after the current passenger
            passengers.insert(it.base() + 1, newPassenger);
            break; // Once inserted, stop iterating
        }
    }
    //If Id is less then all passangers insert to the begining of the list 
    if (passengers.empty() || newPassenger.getId() < passengers.front().getId()) {
        passengers.insert(passengers.begin(), newPassenger);
    }

    //Puting row and col into seatmap
    seatmap[newPassenger.getSeat().get_row()][newPassenger.getSeat().get_col()] = 1;
}


void Flight::removePassenger(int IDNum) {
    for (vector<Passenger>::iterator it = passengers.begin(); it != passengers.end(); ++it) {
        if (it->getId() == IDNum) {   
            passengers.erase(it);
            break;
        }
    }
}


