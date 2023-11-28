#include <string>


#ifndef Passenger
#define Passenger

#include "Seat.h"
#include <string>
#include <vector>

using namespace std;

class Passenger{
	public:
	Passenger(string fn, string ln, string num, int id_num, Seat seat);
	
	string getFname() const {return fname};
	string getLname() const {return lname};
	string getPhone() const {return phone};
	string getId() const {return id};
	Seat getSeat() const (return seat);
	
	private:
	string fname;
	string lname;
	string phone;
	int id;
	Seat seat;
};
#endif
