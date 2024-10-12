//============================================================================
// Name        : CSC450_CT1_mod1-2.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : CSC450_CT1_mod1-2 in C++, Ansi-style
//============================================================================

#include<iostream>
//#include<conio.h>  commented out not needed
#include <iomanip>  // Include iomanip for setprecision and fixed

//Standard namespace declaration  added // since this is a comment
using namespace std;

//Main Function  added // since this is a comment
int main()
{
	double myMoney = 1000.50; //this should be printed out
	//Standard Ouput Statement  added // since this is a comment
	cout <<"Please be sure to correct all syntax errors in this program"<<endl;

	cout <<"I have corrected all errors for this program." <<endl;  //added " to end of print statement

	// Set precision to 2 decimal places
	cout << fixed << setprecision(2);
	cout <<"The total amount of money available is = "<< myMoney <<endl;

	// Wait For Output Screen
	// Wait for the user to press Enter before closing the console window
	cout << "Press Enter to exit..." << endl;
	cin.get();  // Pauses the program until Enter is pressed

	// Main Function return Statement  added // since this is a comment
	return 0;
}

