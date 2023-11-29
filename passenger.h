#ifndef PASSENGER
#define PASSENGER

#include "Seat.h"
#include <string>
#include <vector>
using namespace std;

class Passenger{
	public:
	Passenger();
	Passenger(string fn, string ln, string phone_num, int id_num, int r, int c);
	
	string getFname() const {return fname;};
	string getLname() const {return lname;};
	string getPhone() const {return phone;};
	int getId() const {return id;};
	
	void set_ID(int idInput){id = idInput;};
	
	private:
	string fname;
	string lname;
	string phone;
	int id;
	Seat seat;
};
#endif