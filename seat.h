
//seat.h
#ifndef SEATS
#define SEATS
#include <iostream>
using namespace std;

class Seat {
	public: 
		Seat();
		Seat(int r, int c);

		void set_row(int r);
		void set_col(int c);
		
		int get_row() const;
		int get_col() const;
		int get_seat_address(int address[]) const; 
	private:
		int row_S; //seat row number
		int col_S; //seat column number
};
#endif
