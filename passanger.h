#ifndef PASSANGER
#define PASSANGER
#include <string>
#include "Seat.h"
using namespace std;

class Passanger{
	public: 
	Passanger();

	private:
	char Fname;
	char Lname;
	string phoneNumber; 
	int id;
	Seat seat;
};

#endif
