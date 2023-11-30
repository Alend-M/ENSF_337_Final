#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include "Flight.h"
#include <fstream>
using namespace std;
//*****NOTES*****
// Use vector use for list
// Use String C++ class for strings
// Bonus mark if we use a link list  (10%)
//*****ENDNOTE*****

Flight populate_flight (char * file);
void ChoicePage(int *UserInput);
void SeatMap();
void PassengerInfo(Flight& SkyCar);
void AddPassanger(Flight& SkyCar);
void RemovePassanger(Flight& SkyCar);
void Save(Flight& SkyCar);



int main()
{
    int UserInput;
    cout << "\nVersion 1.0" << endl;
    cout << "Term Project - Flight Management Program in C++" << endl;
    cout << "Produced by: Alend Maci" << endl; // Add other group members names!!!!!!!
    cout << "Year: 2023" << endl;
    cout << "<<< Press Return to Continue>>>" << endl;
    cin.get(); 

    //Pull data from file 
    
    #if 1
    char file[] = "Flights.txt";
    Flight F1 = populate_flight (*file);
    #endif

    //Main Program loop
    while (true)         
    {
        ChoicePage(&UserInput);
        switch (UserInput)
        {
        case 1:
            // Display the flight seat map.
            SeatMap();

            cout << "<<< Press Return to Continue>>>" << endl;
            cin.get();
            break;

        case 2:

            // Display the passengers information.
            PassengerInfo(F1);

            cout << "<<< Press Return to Continue>>>" << endl;
            cin.get();
            break;

        case 3:

            // Add a new passenger.
            AddPassanger(F1);
            cout << "<<< Press Return to Continue>>>" << endl;
            cin.get();
            break;

        case 4:

            // Remove an existing passenger.
            RemovePassanger(F1);
            cout << "<<< Press Return to Continue>>>" << endl;
            cin.get();
            break;

        case 5:

            // Save the data.
            Save(F1);
            cout << "<<< Press Return to Continue>>>" << endl;
            cin.get();
            break;

        case 6:
    
            // Quit the program.
            cout << "Program Terminated..." << endl;
            exit(0);

        default:

            // Invalid choice.
            cout << "\nInvalid choice."<<endl;
            cout << "<<< Press Return to Continue>>>" << endl;
            cin.get();
            break;

        }
    }
    return 0;
}

//All Functions 
void ChoicePage(int *UserInput)
{
    cout << "Please select one of the following options:\n";
    cout << "1. Display Flight Seat Map.\n";
    cout << "2. Display Passengers Information.\n";
    cout << "3. Add a New Passenger.\n";
    cout << "4. Remove an Existing Passenger\n";
    cout << "5. Save data\n";
    cout << "6. Quit.\n";
    cout << "Enter your choice: (1, 2, 3, 4, 5 or 6)"<<endl;
    cin >> *UserInput;
    cin.get();
}

Flight populate_flight (char * file){
    ifstream in;
	in.open(file, ios::in);
    
	if (in.fail()) {
        cout <<"Error opening file...quitting\n";
        exit(1);
	}
        in.getline(s0, 7, '\n');
		string FlightNum = (string) s0;
		in.seekg(6, std::ios::beg);

        in.getline(r, 3, '\n');
		int FlightTrow = (int) r;
		in.seekg(2, std::ios::cur);

        in.getline(c, 2, '\n');
		int FlightTcol = (int) c;
		in.seekg(1, std::ios::cur);

        Flight F1(FlightNum, FlightTrow, FlightTcol);
	do {
        
        //FName
		in.getline(s1, 21, '\n');
		string fname;
		fname = (string) trimtraling_spaces(s1);
		in.seekg(20, std::ios::cur);
		
		//LName
		in.getline(s2, 21, '\n');
		string lname;
		lname = (string) trimtraling_spaces(s2);
		in.seekg(20, std::ios::cur);
		
		//Phone
		in.getline(s3, 13, '\n');
		string phone;
		phone = (string) trimtraling_spaces(s3);
		in.seekg(12, std::ios::cur);
		
		//Seat
		in.getline(s4, 3, '\n');
		int rowS = (int) s4[0];
		int colS = (int) s4[1] - 65;
		in.seekg(2, std::ios::cur);
		
		//ID Number
		in.getline(s5, 6, '\n');
		int idnum = (int) s5;
		in.seekg(5, std::ios::cur);
        Passenger newpassenger(fname, lname, phone, idnum, rowS, colS);
        F1.addPassenger(newpassenger);
	} while(!in.eof());
    return F1;
   }



void SeatMap() {
    //vector<vector<int>> seatmap = //NAMEOFFLIGHT//.get_seatmap();    //THIS GRABS THE VECTOR WE NEED FILE READ TO WORK THO!
    #if 1
    vector<vector<int>> seatmap;
    seatmap.resize(6, vector<int>(4)); // Create a 6x4 vector of integers

    // Manually set the seatmap values
    seatmap[0][0] = 1; // Occupied seat
    seatmap[1][3] = 1; // Occupied seat
    seatmap[3][2] = 1; // Occupied seat
    seatmap[5][1] = 1; // Occupied seat
    #endif

    cout << "Aircraft Seat Map" << endl;
    cout <<"     ";
    for (int i = 0; i < seatmap[0].size(); i++) {
        cout << (char) (i + 65) <<"   ";
    }
    cout << endl;

    //Holds the position of the Seatmap
    int row = 0;
    int col = 0; 
    for(int j = 0; j < seatmap.size(); j++){
        cout << "   +";
        for(int i = 0; i < seatmap[0].size(); i++){
            cout<<"---+";
        }
        cout<<endl;

        cout << " " << row << " "<< "|";
        for(int i = 0; i < seatmap[0].size(); i++){
            char a = ' ';
            if(seatmap[row][col] == 1){
                a = 'X';
            }
            //cout << row<< col;
            cout << " " << a << " " << "|";
            col++;
        } 
        cout <<endl;
        row++;
        col = 0; 
    }
    cout << "   +";
        for(int i = 0; i < seatmap[0].size(); i++){
            cout<<"---+";
        }
        cout<<endl;
}
void PassengerInfo(Flight& SkyCar){
    
}

void AddPassanger(Flight& SkyCar){
    int idInput,phoneNum1,phoneNum2,phoneNum3,rowInput; 
    string FnameInput,LnameInput; 
    char colInput;

    // Get user input
    cout << "Please enter the passenger ID: ";
    cin >> idInput;
    cout << "Please enter the passenger's first name: ";
    cin >> FnameInput;
    cout << "Please enter the passenger's last name: ";
    cin >> LnameInput;
    cout << "Please enter the passenger's phone number: ";
    cin >> phoneNum1 >> phoneNum2 >> phoneNum3;
    cout <<endl;
    cout << "Please enter the passenger's desired row: ";
    cin >> rowInput;
    cout << "Please enter the passenger's desired seat: ";
    cin >> colInput;

    string fullPhoneNumber = "";
    fullPhoneNumber += to_string(phoneNum1) + "-" + to_string(phoneNum2) + "-" + to_string(phoneNum3);


    Passenger newpassenger(FnameInput, LnameInput, fullPhoneNumber, idInput, rowInput, colInput);
    SkyCar.addPassenger(newpassenger);
}

void RemovePassanger(Flight& SkyCar){
    int IDInput; 
    cout << "Please enter the id of the passenger that needs to be removed: ";
    cin >> IDInput;
    SkyCar.removePassenger(IDInput);
}

void Save(Flight& SkyCar){
//out<< iosflage(ios::left)
//<<setw(20)<<fname;
}