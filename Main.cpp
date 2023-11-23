#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
//#include "Flight.h"
using namespace std;
//*****NOTES*****
// Use vector use for list
// Use String C++ class for strings
// Bonus mark if we use a link list  (10%)
//*****ENDNOTE*****

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

    //Main Program loop
    while (true)         
    {
        //Generates data
        Flight f;
        f = populate_flight("Flights.txt");
           
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

void SeatMap(){

}

void PassengerInfo(){
    //Use linked list 
}

void AddPassanger(){

}

void RemovePassanger(){

}

void Save(){

}