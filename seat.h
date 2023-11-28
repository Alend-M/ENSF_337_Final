
//seat.h
#ifndef SEATS
#define SEATS
#include <iostream>
using namespace std;

class Seat {
	public: 
		Seat(int r, char c);
		//REQUIRES: 'r' and 'c' refers to the row number and the character of the column (ex: 8A) 

		void set_row(int r);
		void set_col(int c);
		
		int get_row() const;
		char get_col_int() const;
		int get_seat_address(int address[]) const; 
	private:
		int row_S;				//seat row number
		int col_S;				//seat column number
};
#endif