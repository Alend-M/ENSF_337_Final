
//seat.h
#ifndef SEATS
#define SEATS

#include <iostream>
using namespace std;

class Seat {
	
	public:
		
		void set_row(int r);
		//Sets 'row_S' to an int based on the value of 'r' (Check needs to be done to see if in bounds)
		//'r' will be obtained from the 'passenger class'
		
		void set_col_letter_int(char c_s);
		//Sets 'col_letter_S' to a char and 'col_S' to an int based on the value of 'c' (Check needs to be done to see if in bounds)
		//'c' will be obtained from the 'passenger class'
		
		const int get_row() const;
		//Returns 'row_S'
		
		const char get_col_char() const;
		//Returns 'col_Letter_S'
		
		const char get_col_int() const;
		//Returns 'col_S'
		
		Seat(int r, char c);
		//REQUIRES: 'r' and 'c' refers to the row number and the character of the column (ex: 8A) 
	
	private:
	
		int row_S;				//seat row number
		int col_S;				//seat column number
		char col_letter_S;		//seat column (letter foramt)
		char status_S();		//to see if seat is already occupied
		
		int valid_row_S(int r);		//making sure row value is valid
		char valid_col_letter_S(char c);	//making sure char value is valid
}
#endif