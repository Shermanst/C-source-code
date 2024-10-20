//============================================================================
// Name        : Console_Input.cpp
// Author      : Steve Sherman
// Version     :
// Copyright   : Your copyright notice
// Description : console application in C++, Ansi-style
//============================================================================

#include <iostream>  // Includes the i/o stream library to use std::cin and std::cout
#include <string>  // Includes the string library to use std::string class
#include <vector>  // Includes the vector library to store concatenated results

int main() {
	std::vector<std::string> results;  // Vector to store the concatenated results

	// Loop to get input and print output three times
	for (int i = 1; i <= 3; ++i){ // Loop runs 3 times to take input from user 3 times
		std::string str1,str2,concatenated;  // Declare three string variables to hold the inputs and concatenated results

		// Prompt the user for the first string
		std::cout << "Enter the first string (Input " << i <<"):";  // Display message to prompt the user user for input
		std::getline(std::cin,str1);  // Use std::getline to read the entire input, including spaces, into str1

		// Prompt user for the second string
		std::cout << "Enter the second string (Input " << i << "):";  // Prompt user for second string
		std::getline(std::cin,str2);  // Use std::getline to read the entire input. including spaces, into str2

		// Concatenate the two strings
		concatenated = str1 + " " + str2;  // Use the + operator to concatenate str1 and str2, storing the results in concatenated

		// Print the concatenated result
		std::cout << "Concatenated result (Input " << i << "): " << concatenated << std::endl;

		// Store the concatenated result in the vector
		results.push_back(concatenated);
	}

	// After the loop, print all concatenated results
	std::cout << "All concatenated results: " << std::endl;
	for (const auto& result : results) { // Loop through the vector to print each result
		std::cout << result << std::endl;
	}
	return 0; // Return 0 indicates successful
}
