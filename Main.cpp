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
    char file[] = "Flights.txt";
    Flight populate_flight (*file);

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
    ifstream f;
    f.open(file, ios::in);
    if (f.fail()){
        cout <<"Error opening file...quitting\n";
        exit(1);
    }
    cout <<"I CAN READ THE FILE!!!";
}

void SeatMap(){
    //Displays the SeatMap
    void SeatMap() {
    vector<vector<int>> seatmap = flight.get_seatmap();

    cout << "Aircraft Seat Map" << endl;
    cout << "  ";
    for (int i = 0; i < seatmap[0].size(); i++) {
        cout << i << " ";
    }
    cout << endl;

    // Print the seat map rows.
    for (int i = 0; i < seatmap.size(); i++) {
        cout << i << " ";
        for (int j = 0; j < seatmap[i].size(); j++) {
            if (seatmap[i][j] == 0) {
                cout << "O ";
            } else {
                cout << "X ";
            }
        }
        cout << endl;
    }
}
}

void PassengerInfo(){
    
}

void AddPassanger(){

}

void RemovePassanger(){

}

void Save(){

}