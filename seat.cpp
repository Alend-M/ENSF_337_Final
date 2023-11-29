
//seat.cpp
#include "seat.h"
#include <iostream>
using namespace std;

Seat::Seat(){
  row_S = -1; 
  col_S = -1; 
}
Seat::Seat(int r, int c) {
  row_S = r;
  col_S = c;
}

void Seat::set_row(int r) {
  row_S = r;
}
void Seat::set_col(int c){
	col_S = c;
}

