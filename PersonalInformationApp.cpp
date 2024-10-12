//============================================================================
// Name        : PersonalInformationApp.cpp
// Author      : Steve Sherman
// Version     :
// Copyright   : Your copyright notice
// Description : PersonalInformationApp in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main()
{
	// Declare variables
	string firstName = "John";
	string lastName = "Doe";
	string streetAddress = "123 Main St";
	string city = "AnyCity";
	string state = "AnyState";
	string zipCode = "12345";

	// Print information
	cout << "First Name: " <<firstName << endl; // prints first mane
	cout << "Last Name: " <<lastName << endl;  // prints last name
	cout << "Street Address: " <<streetAddress << endl;  // prints street address
	cout << "City: " << city << endl;  // prints city
	cout << "State: " << state << endl;  // prints state
	cout << "Zip Code: " << zipCode << endl;  // prints zip code

	return 0;
}
