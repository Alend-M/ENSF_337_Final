#include "passenger.h"
#include <string>

using namespace std;

Passanger::Passanger((string fn, string ln, string phone_num, int id_num, int r, int c){
	fname = fn;
	lname = ln; 
	phone = phone_num;
	id = id_num;
	Seat(r, c);
}
