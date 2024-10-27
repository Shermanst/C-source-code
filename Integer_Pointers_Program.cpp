//============================================================================
// Name        : Integer_Pointers_Program.cpp
// Author      : Steve Sherman
// Version     :
// Copyright   : Your copyright notice
// Description : Integer Pointers Program in C++, Ansi-style
//============================================================================

#include <iostream>
#include <limits>  // For numeric limits (used in clearing input buffer)
using namespace std;

// Function validates integer input that ensures user enters valid integer and returns it
int GetValidInteger(const string& promptMessage) {
    int userInput;
    bool validInput = false;

    // Input validation loop
    while (!validInput) {
        cout << promptMessage; // Display prompt message
        cin >> userInput; // Take user input

        // Check if input is not a valid integer
        if (cin.fail()) { // Corrected `cin fail()` to `cin.fail()`
            cout << "Invalid input. Please enter a valid integer." << endl; // Corrected message punctuation
            cin.clear(); // Clear input stream error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input from stream (newline is `\n`)
        } else {
            validInput = true; // If input is valid, exit loop
        }
    }
    return userInput; // Return validated integer
}

// Function to deallocate memory and reset pointer to nullptr
void DeallocateMemory(int*& pointer) {
    if (pointer != nullptr) {
        delete pointer;
        pointer = nullptr;
    }
}

int main() {
    // Declare three integer pointers
    int *ptr1 = nullptr, *ptr2 = nullptr, *ptr3 = nullptr;

    try {
        // Get valid integers from user
        int num1 = GetValidInteger("Enter the first integer: ");
        int num2 = GetValidInteger("Enter the second integer: ");
        int num3 = GetValidInteger("Enter the third integer: "); // Fixed typo "integet" to "integer"

        // Dynamically allocate memory for integers
        ptr1 = new int;
        ptr2 = new int;
        ptr3 = new int;

        // Store input values in dynamically allocated memory
        *ptr1 = num1;
        *ptr2 = num2;
        *ptr3 = num3;

        // Display contents of dynamically allocated memory and memory addresses of pointers
        cout << "Value of num1: " << *ptr1 << ", Memory address: " << ptr1 << endl;
        cout << "Value of num2: " << *ptr2 << ", Memory address: " << ptr2 << endl;
        cout << "Value of num3: " << *ptr3 << ", Memory address: " << ptr3 << endl;
    } catch (const bad_alloc& e) {
        // Catch block to handle memory allocation failure
        cout << "Error: Memory allocation failed." << endl;
    }

    // Ensure memory is deallocated
    DeallocateMemory(ptr1);
    DeallocateMemory(ptr2);
    DeallocateMemory(ptr3);

    return 0; // End program
}
