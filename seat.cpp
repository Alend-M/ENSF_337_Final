
//seat.cpp

#include "seat.h"
#include <iostream>
using namespace std;

//Validation Functions
int Seat::valid_row_S(int row) {
	//row ranges from 0 to 24
	if(row >= 0 && row <= 24) {										
        return 1;
    } else {
		//Need to add a way to return to the passenger class
        return 0;
    }
}
char Seat::valid_col_letter_S(char col) {
	//col ranges from A/a to F/f
	if((col >= 'A' && col <= 'F') || (col >= 'a' && col <= 'f') {	
        return 1;
    } else {
		//Need to add a way to retrun to the passenger class
        return 0;
    }
}
char Seat::status_S() {
	
	//if statment needed to check and compare with 'flight class' to see if a seat is already occupied
	//this class will be access from the 'passenger class' to see the status of the seat
	
}
Seat::Seat(int r, int c) {
	
	//needs to access the vector matrix from the 'flight class'
	//will insert the neccessary value from here into the matrix in 'flight class' 
	
}



//Setter Functions
void Seat::set_row(int r) {
    if(valid_row_S(r)){
        row_S = r;
    } else {
		cout << "An Error has occured. Terminating Program." << endl;
		exit(1); 
    }
}
void Seat::set_col_letter_int(char c_s) {
    if(valid_col_S(c_s)){
        col_letter_S = c_s;
		if (col_letter_S >= 'A' && col_letter_S <= 'F') {
			col_S = col_letter_S - 'A';
		} else if (col_letter_S >= 'a' && col_letter_S <= 'f') {
			col_S = col_letter_S - 'a';
		}
    } else {
       cout << "An Error has occured. Terminating Program." << endl;
		exit(1); 
    }
}


//Getter Functions
const int Seat::get_row() const {
	return row_S;
}
const int Seat::get_col_int() const {
	return col_S;
}
const char Seat::get_col_char() const {
	return col_letter_S;
}





