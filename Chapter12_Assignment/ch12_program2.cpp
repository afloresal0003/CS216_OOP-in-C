/*
    Programmer: Anthony Flores-Alvarez
    Course: CS 216 - OOP in C++
    Date: October 21, 2020
    Description: This program accepts a string from the user and
    uses three functions(upper, lower, & flip) to modify the string.
    - Upper uppercases everything in the string
    - Lower lowercases everything in the string
    - Flip flips everything in the string to the opposite case. 
    Each is outputted to the user. It will ONLY accept letters
    because only LETTERS can be uppercased or lowercased. No other
    input (like spaces, non-letter characters, etc.) will be accepted. 
*/

// Header files for program functionality
#include <iostream>
#include <cstdlib>

// Allows us to not have to use std:: throughout program
using namespace std;

// upper function - Uppercases the letters in the string
void upper(char *userString){
    
    // For counter
    int i = 0;

    // Loops until the end of the string
    while(userString[i] != '\0'){

        // Uppercasing each character
        userString[i] = toupper(userString[i]);

        // Displaying it by character
        cout << userString[i];

        ++i;
    }
}

// lower function - Lowercases the letters in the string
void lower(char* userString){
   
   // For counter
    int i = 0;

    // Loops until the end of the string
    while (userString[i] != '\0'){

        // Lowercasing each character
        userString[i] = tolower(userString[i]);

        // Displaying it by character
        cout << userString[i];

        ++i;
    }
}

// flip function - Flips each letters' case in the string
void flip(char *userString){
    
    // For counter
    int i = 0;

    // Loops until the end of the string
    while(userString[i] != '\0'){

        // To flip from lowercase to uppercase
        if(userString[i] == tolower(userString[i])){
            userString[i] = toupper(userString[i]);
        }

        // To flip from uppercase to lowercase
        else{
            userString[i] = tolower(userString[i]);
        }

        // Displaying finalized, flipped user string, by character
        cout << userString[i];
        ++i;
    }
}

// Check if the user's input is valid
bool isNumber(string userInput) {

    // Loops through whole string
    for (int i = 0; i < userInput.length(); i++)

    // Checks if there is a number or non-alphabetic character
    if (isdigit(userInput[i]) == true || isalpha(userInput[i]) == false)
      return true;
      return false;
}

// MAIN Function
int main (){
    
    // Stores user's string input
    char userString[100];
    char userInput;

    // Heading / INPUT
    cout << "-------------------------------------------------" << endl;
    cout << "Welcome to Case Changer!" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "RULES:" << endl;
    cout << "- All input is case sensitive!" << endl;
    cout << "- Please enter a string of your choice. Ensure that your string ONLY " << endl;
    cout << "  contains LETTERS from the alphabet." << endl;
    cout << "- You cannot uppercase, lowercase, or flip numbers or characters, " << endl;
    cout << "  ONLY letters." << endl;
    cout << "   -> Acceptable: 'Abc', 'AFUESBFUE', etc." << endl;
    cout << "   -> NOT Acceptable: '123', 'A b c', '-fewf', etc. " << endl;
    cout << "- If you enter a non-acceptable input, you will have to press enter 2 times and enter a valid input. " << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "Please enter a string: ";
    cin.getline(userString, 100);

    // Loops until user enters valid digit set
    while (isNumber(userString) == true){
        // Helps in clearing the error flags which are set when cin fails to interpret the input.
        cin.clear();
        // Helps in removing the input contents that could've caused the read failure
        cin.ignore(1000,'\n');
        cout << "Error! Please enter a VALID string: ";
        cin.getline(userString,100);
    }

    cout << endl;

    // OUTPUT
    cout << "-------------------------------------------------" << endl;
    cout << "RESULTS: \n" << endl;

    cout << "User Input: " << userString << endl << endl;

    cout << "Flipped Version: ";
    flip(userString);
    cout << endl << endl;

    cout << "Uppercased Version: ";
    upper(userString);
    cout << endl << endl;

    cout << "Lowercased Version: ";
    lower(userString);
    cout << endl;

    cout << "-------------------------------------------------" << endl;
    cout << "Thank you!" << endl;
    cout << "-------------------------------------------------" << endl;

    // Terminates program
    return 0;
}