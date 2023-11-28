
//seat.cpp
#include "seat.h"
#include <iostream>
using namespace std;

Seat::Seat(int r, char c) {
  row_S = r;
  col_S = c;
}

void Seat::set_row(int r) {
  row_S = r;
}
void Seat::set_col(int c){
	col_S = c;
}

int Seat::get_row() const {
  return row_S;
}

// Returns the seat address in the format "row_numbercolumn_letter" (e.g., "8A")
int Seat::get_seat_address(int address[]) const {
	address[0]= row_S;
	address[1] = col_S;
}
