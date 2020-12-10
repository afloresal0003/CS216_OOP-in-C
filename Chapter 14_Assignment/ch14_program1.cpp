/*
    Programmer: Anthony Flores-Alvarez
    Course: CS 216 - OOP in C++
    Date: November 5, 2020
    Description: 
    Converting the following function to one that uses recursion:
        void sign(int n){
            while (n > 0){
                cout << "No parking \n";
                n--;
            }
        }
    Demonstrating the function with a driver program.
*/

// Header files for program functionality
#include <iostream>
#include <cstdlib>
#include <sstream>

// Allows us to not have to use std:: throughout program
using namespace std;

// sign function with recursive implementation
void sign (int n) {

    if (n > 0) {
        cout << "-------------------------------------------------" << endl;
        cout << "\nNo Parking!\n";
        cout << "\n-------------------------------------------------" << endl;
        // Recursion
        sign(--n);
    }
}

// Switches string to an integer
double switchToInt(string userString){

    // Stores number form of user's string
    double userValue;

    // Creating object from the stringstream class
    stringstream uStr(userString);

    // Passing the string value to the variable 
    // that'll hold it as an integer type
    uStr >> userValue;

    // Giving back the switched value type
    return userValue;
}

// Checks if a string has a character in it
bool isString(string userInputString){
    
    // Storing whether or not there is a character
    bool stringHere;
    
    // Checking user string for character
    for (int i = 0; i < userInputString.length(); i++){

        // If there's none
        if(isalpha(userInputString[i]) != true){
            stringHere = false;
            continue;
        }
        // If there is
        else{
            stringHere = true;
            break;
        }
    }

    // Giving back if there is or isn't a character
    return stringHere;
}

// Ensures that the user enters a valid input
string validateInput(string userInputString){

    // Storing character outcome and number form of user's values
    bool stringHere;
    double userInputValue;

    // Checking for string
    stringHere = isString(userInputString);
    // Storing number value
    userInputValue = switchToInt(userInputString);

    // Loops until user enters a positive integer
    while (!cin || userInputValue < 0 || stringHere == true || userInputValue != int(userInputValue)) {
        // Helps in clearing the error flags which are set when cin fails to interpret the input.
        cin.clear();
        // Helps in removing the input contents that could've caused the read failure
        cin.ignore(1000,'\n');
        cout << "-------------------------------------------------" << endl;
        // Prompt to enter only positive integers
        cout << "Error! Please enter a POSITIVE INTEGER: ";
        cin >> userInputString;
        userInputValue = switchToInt(userInputString);
        stringHere = isString(userInputString);
    }
    // Giving back admissible value
    return userInputString;
}

// MAIN Function
int main() {

    // Storing the number that the user enters
    double userNumber;
    string userNumberString;
    bool stringHere = false;
    // Heading / INPUT
    cout << "-------------------------------------------------" << endl;
    cout << "Welcome to Recursion Driver!" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "RULES:" << endl;
    cout << "- Only POSITIVE INTEGERS will be accepted! " << endl;\
    cout << "-------------------------------------------------" << endl;
    // Asking for user integer
    cout << "Please enter a positive integer: ";
    cin >> userNumberString;

    // Checking if it's valid
    userNumberString = validateInput(userNumberString);
    // Storing valid value
    userNumber = switchToInt(userNumberString);

    // Calling the recursive function
    sign(userNumber);

    // Closing
    cout << "-------------------------------------------------" << endl;
    cout << "Thank you!" << endl;
    cout << "-------------------------------------------------" << endl;

    // Terminating program
    return 0;
}