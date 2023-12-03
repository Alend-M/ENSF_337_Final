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

void Flight::addPassenger(Passenger newPassenger) {
    bool breakout = false;
    for (vector<Passenger>::iterator it = passengers.begin(); it != passengers.end(); ++it) {
        //if id is already used on the flight return error
        if(newPassenger.getId() == it->getId()){
            cout <<"ID already taken!"<<endl;
            breakout = true;
        }

        //checks if the seat is alreadt occupied 
        if(newPassenger.getSeat().get_col() == it->getSeat().get_col() 
        && newPassenger.getSeat().get_row() == it->getSeat().get_row()){
            cout<< "Seat is already occupied!"<< endl;
            breakout = true;
        }
    }

    if(breakout != true){
    //checks list of passangers from bottom to top. If adding
    for (vector<Passenger>::iterator it = passengers.begin(); it != passengers.end(); ++it) {
        if (newPassenger.getId() < it->getId()) {
            // Insert the new passenger after the current passenger
            passengers.insert(it, newPassenger);
            //breakout  = true;
            break; // Once inserted, stop iterating
        }
    }
     
    
    if(passengers.empty()){
        passengers.insert(passengers.begin(), newPassenger);
    }else{
        // If Id is less than all passengers, insert to the beginning of the list
        if (newPassenger.getId() > passengers.back().getId()) {
            passengers.insert(passengers.end(), newPassenger);
        }
    }

    //Puting row and col into seatmap
    seatmap[newPassenger.getSeat().get_row()][newPassenger.getSeat().get_col()] = 1;
    }
}



void Flight::removePassenger(int IDNum) {
    for (vector<Passenger>::iterator it = passengers.begin(); it != passengers.end(); ++it) {
        if (it->getId() == IDNum) {  
            seatmap[it->getSeat().get_row()][it->getSeat().get_col()] = 0;
            passengers.erase(it);
            break;
        }
    }
}


