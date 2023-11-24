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
	//*Phone number make linked list
	int id;
	Seat seat;
	
};

#endif
