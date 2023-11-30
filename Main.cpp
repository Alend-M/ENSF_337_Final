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
void PassengerInfo();
void AddPassanger();
void RemovePassanger();
void Save();



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
    
    #if 0
    char file[] = "Flights.txt";
    Flight populate_flight (*file);
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
            PassengerInfo();

            cout << "<<< Press Return to Continue>>>" << endl;
            cin.get();
            break;

        case 3:

            // Add a new passenger.
            AddPassanger();
            cout << "<<< Press Return to Continue>>>" << endl;
            cin.get();
            break;

        case 4:

            // Remove an existing passenger.
            RemovePassanger();
            cout << "<<< Press Return to Continue>>>" << endl;
            cin.get();
            break;

        case 5:

            // Save the data.
            Save();
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
    #if 0
    //should be every 20 character 
    ifstream in;
    in.open(file, ios::in);
    if (in.fail()){
        cout <<"Error opening file...quitting\n";
        exit(1);
    }
    do{
        in.get(s,'21','\n');
        if(int.eof())break; 
        fname = s;
        fname = (string) trimtraling_spaces(fname); //removes the trailing spaces 
    }
    #endif
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
void PassengerInfo(){
    
}

void AddPassanger(){
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
    //FlightName.addPassenger(newpassenger);
}

void RemovePassanger(){

}

void Save(){
//out<< iosflage(ios::left)
//<<setw(20)<<fname;
}