#include <string>

#ifndef Passenger
#define Passenger

#include "Seat.h"
#include <string>
#include <vector>

using namespace std;

class Passenger{
	public:
	Passenger(string first_name, string last_name, string _num, int id_num, Seat seat);
	void setFname(const char* fname);
	void setLname(const char* lname);
	void setId(const string* id);
	void setPhone(const string* phone);
	Passenger get_all() const {return Passenger}
	
	Passenger getPassenger() const;
	
	private:
	string fname;
	string lname;
	string phone;
	int id;
	Seat seat;
	
};

#endif
