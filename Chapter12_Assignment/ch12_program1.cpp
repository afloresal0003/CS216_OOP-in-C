/*
    Programmer: Anthony Flores-Alvarez
    Course: CS 216 - OOP in C++
    Date: October 21, 2020
    Description: This program asks the user to enter a series of
    single-digit numbers with nothing separating them. Then it 
    displays their sum, highest digit, and lowest digit. 
*/

// Header files for program functionality
#include <iostream>
#include <cstdlib>

// Allows us to not have to use std:: throughout program
using namespace std;

// Check if the user's input is indeed a set of positive digits with no spaces
bool isValid(string userInput) {

    for (int i = 0; i < userInput.length(); i++)
    if (isdigit(userInput[i]) == false || userInput[i] == ' ')
      return false;
      return true;
}

// MAIN FUNCTION
int main(){

    // Variable declarations
    char userDigitString[100];
    int numDigits,
        userDigitNums,
        sumOfDigits = 0,
        lastDigit,
        lowestDigit,
        highestDigit; 

    // Heading / INPUT
    cout << "-------------------------------------------------" << endl;
    cout << "Welcome to Digit Set Calculator!" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "RULES:" << endl;
    cout << "- All input is case sensitive!" << endl;
    cout << "- Please enter a series of POSITIVE single-digit numbers with nothing separating them: " << endl;
    cout << "   -> Acceptable: '123456', '394384', etc. " << endl;
    cout << "   -> NOT Acceptable: 'abc', '1 2 3', '-12-5-2', etc. " << endl;
    cout << "- If you enter a non-acceptable input, you will have to press enter 2 times and enter a valid input. " << endl;
    cout << "-------------------------------------------------" << endl;
    cout  << "Please enter your single-digit set: ";
    cin.getline(userDigitString,100,'\n');
    cout << "-------------------------------------------------" << endl;
    
    // Loops until user enters valid digit set
    while (isValid(userDigitString) != true){
        // Helps in clearing the error flags which are set when cin fails to interpret the input.
        cin.clear();
        // Helps in removing the input contents that could've caused the read failure
        cin.ignore(1000,'\n');
        cout << "Error! Please enter a VALID single-digit set: ";
        cin.getline(userDigitString,100,'\n');
    }
    
    // Converting user's string-type digits to integer-type digits
    userDigitNums = atoi(userDigitString);

    // Storing last digit from digit set
    lastDigit = userDigitNums % 10;

    // Last digit becomes largest and smallest
    lowestDigit = lastDigit;
    highestDigit = lastDigit;
    
    // Will loop until all digits have been
    // checked, going from right to left
    while (userDigitNums > 0){  
        
        // Storing last digit of the set of digits
        lastDigit = userDigitNums % 10;

        // Checking if it is the smallest
        if (lowestDigit > lastDigit){ 
            // If so, setting it to smallest
            lowestDigit = lastDigit;
        }

        // Checking if it is the largest
        if (highestDigit < lastDigit){
            // If so, setting it to largest
            highestDigit = lastDigit;    
        }  

        // Adding it to the sum
        sumOfDigits = sumOfDigits + lastDigit;

        // Moving left onto the next digit in the digit set
        userDigitNums = userDigitNums / 10;
    
    }

    // OUTPUT
    cout << "-------------------------------------------------" << endl;
    cout << "RESULTS: \n" << endl;
    // Outputting the sum of the digits entered
    cout << "Digit Sum: " << sumOfDigits << endl;

    // Outputting the lowest and highest digits
    cout << "Lowest Digit: " << lowestDigit << endl;
    cout << "Highest Digit: " << highestDigit << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "Thank you!" << endl;
    cout << "-------------------------------------------------" << endl;

    // Terminating program
    return 0;
}

