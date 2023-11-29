#include "passenger.h"
#include "Seat.h"
#include <string>

using namespace std;
Passenger::Passenger(){
	fname = "N/A";
	lname = "N/A"; 
	phone = "N/A";
	id = 0;
	seat = Seat();
}
Passenger::Passenger(string fn, string ln, string phone_num, int id_num, int r, int c){
	fname = fn;
	lname = ln; 
	phone = phone_num;
	id = id_num;
	seat = Seat(r, c);
}