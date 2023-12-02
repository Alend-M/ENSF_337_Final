#include <vector>
#include <string>
#include <iomanip>
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
void SeatMap(Flight& SkyCar);
void PassengerInfo(Flight& SkyCar);
void AddPassanger(Flight& SkyCar);
void RemovePassanger(Flight& SkyCar);
void Save(Flight& SkyCar);
string trimtraling_spaces(const string& str);

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
    Flight F1 = populate_flight(file);
    #endif

    //Main Program loop
    while (true)         
    {
        ChoicePage(&UserInput);
        switch (UserInput)
        {
        case 1:
            // Display the flight seat map.
            SeatMap(F1);

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

Flight populate_flight (char* file){
    ifstream in;
	in.open(file, ios::in);
    
	if (in.fail()) {
        cout <<"Error opening file...quitting\n";
        exit(1);
	}
        char s0[10];
        in.get(s0, 10);
		string FlightNum = (string) s0;

        char r[7];
        in.get(r, 7);
		int FlightTrow = atoi(r);
    
        char c[2];
        in.get(c, 2);
		int FlightTcol = atoi(c);
		in.seekg(1, std::ios::cur);

        Flight F1(FlightNum, FlightTrow, FlightTcol);
         
	while(true){
        //FName
        char s1[21];
		in.get(s1, 21);
		string fname;
		fname = (string) trimtraling_spaces(s1);
        //Breaks the loops once it hits the end of file
        if(in.eof()){
            break;
        }

		//LName
        char s2[21];
		in.get(s2, 21);
		string lname;
		lname = (string) trimtraling_spaces(s2);
		
		//Phone
        char s3[21];
		in.get(s3, 21);
		string phone;
		phone = (string) trimtraling_spaces(s3);
		

		//Seat
        char s4[4];
        int hold = 0; 
        int colS;
		in.get(s4, 4);
        for(int i = 0; i < 3; i++){
            if(48 <= s4[i] && s4[i] <= 57){
                if(hold == 0 ){
                    hold = s4[i]- 48;
                }else{
                hold = (hold * 10) + (s4[i] - 48);
                }
            }else{
                if(65 <= s4[i] && s4[i] <= 90){
                    colS = s4[i] - 64;
                }
            }
        }
		int rowS = hold;

		//ID Number
        char s5[7];
		in.get(s5, 7);
		int idnum = atoi(s5);

        in.seekg(1, std::ios::cur);
        Passenger newpassenger(fname, lname, phone, idnum, rowS, colS);
        F1.addPassenger(newpassenger); 
	}
    return F1;
   }

void SeatMap(Flight& SkyCar) {
    vector<vector<int>> seatmap = SkyCar.get_seatmap();    //THIS GRABS THE VECTOR WE NEED FILE READ TO WORK THO!
    #if 0
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
        if(row > 9){
            cout << " " << row << "|";
        }else{
            cout << " " << row << " "<< "|";
        }
        
        for(int i = 0; i < seatmap[0].size(); i++){
            char a = ' ';
            if(seatmap[row][col+1] == 1){
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
    vector<Passenger> passengers = SkyCar.get_PassengerList();

	cout << left << setw(20) << "First Name" << setw(20) << "Last Name" << setw(20) << "Phone" << setw(7) << "Row" << setw(5) << "Seat" << right << setw(6) << "ID" << endl;
	cout << "---------------------------------------------------------------------------------" << endl;
	
	for (size_t i=0; i < passengers.size(); i++) {
		cout << left << setw(20) << passengers[i].getFname() 
			 << setw(20) << passengers[i].getLname()
			 << setw(20) << passengers[i].getPhone()
			 << right << setw(4) << passengers[i].getSeat().get_row() 
			 << setw(5) << (char) (passengers[i].getSeat().get_col() + 64)     
			 << setw(10) << passengers[i].getId() << endl;

		cout << "---------------------------------------------------------------------------------" << endl;
	}	
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


    Passenger newpassenger(FnameInput, LnameInput, fullPhoneNumber, idInput, rowInput, (colInput- 64));
    SkyCar.addPassenger(newpassenger);
}

void RemovePassanger(Flight& SkyCar){
    int IDInput; 
    cout << "Please enter the id of the passenger that needs to be removed: ";
    cin >> IDInput;
    SkyCar.removePassenger(IDInput);
}

void Save(Flight& SkyCar){
    ofstream out("Flights.txt");
    if (out.fail()) {
        cerr << "Error Opening File" << endl;
        return;
    }

    vector<Passenger> passengers = SkyCar.get_PassengerList();

    out << setw(9) << left <<  SkyCar.get_Flight_Number() << setw(6)<< left << SkyCar.get_Trows() << SkyCar.get_TColumns();
    string row_col_holder = "";
    for (size_t i=0; i<passengers.size(); i++) {
        row_col_holder.clear();
        row_col_holder += to_string(passengers[i].getSeat().get_row());
        row_col_holder += (char)(passengers[i].getSeat().get_col() + 64);

        out <<endl << setw(20) << left << passengers[i].getFname()
            << setw(20) << left << passengers[i].getLname()
            << setw(20) << left << passengers[i].getPhone()
            << setw(4) << left << row_col_holder
            <<setw(5) << left << passengers[i].getId();
    }

    out.close();
}

string trimtraling_spaces(const string& str) {
  int i = str.length() - 1;
  while (i >= 0 && str[i] == ' ') {
    i--;
  }

  return str.substr(0, i + 1);
}
