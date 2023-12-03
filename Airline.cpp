#include "Airline.h"

Airline::Airline(string AirlineName, int Nflight){
this->AirlineName = AirlineName;
head = nullptr; // Pointer to the head of the list
this->num_flights = Nflight;
}

Airline::~Airline() {
  Node* current = head;
  while (current) {
    Node* next = current->next;
    delete current;
    current = next;
  }
  head = nullptr;
  num_flights = 0;
}

// Add an integer to the list
void Airline::addFlight(Flight newFlight) {
  Node* newNode = new Node; // Allocate memory for a new node
  newNode->flight = newFlight; // Set the node's data
  newNode->next = head; // Add the new node to the beginning of the list
  head = newNode;
}