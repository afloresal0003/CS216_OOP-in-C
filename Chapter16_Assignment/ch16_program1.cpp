/*
    Programmer: Anthony Flores-Alvarez
    Course: CS 216 - OOP in C++
    Date: December 1, 2020
    Description: This program calculates the square root of
    perfect squares. It throws exceptions if entered values
    are not perfect squares. 
*/

// Header files for program functionality
#include <iostream>
#include <exception>
#include <cmath>
#include <sstream>
#include <cstdlib>

// Allows us to not have to use std:: throughout program
using namespace std;

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
bool validateInput(string userInputString){

    // Storing character outcome and number form of user's values
    bool stringHere;
    double userInputValue;

    // Checking for string
    stringHere = isString(userInputString);
    // Storing number value
    userInputValue = switchToInt(userInputString);

    // Loops until user enters a positive integer
    if (!cin || userInputValue < 0 || stringHere == true || userInputValue != int(userInputValue)) {
        return false;
    }
    else{
        return true;
    }
}

// Function that accepts an integer parameter
// and returns its square root
int calcSquareRoot(int userInteger){

    // Stores string version of user input
    string userString = to_string(userInteger);
    // Cheks if integer is negative
    if(userInteger < 0){
        // Throws exception if negative value
        throw domain_error("Supplied integer is negative!");
    }

    // Holds square root of user input
    double userSquareRoot = sqrt(userInteger);

    // Holds integer version of user input
    int userSquareRootInt = (int)userSquareRoot;

    // Checks if integer and double of user integer are
    // the same (aka perfect square)
    if(userSquareRoot != userSquareRootInt){
        // Throws exception if not a perfect square
        throw invalid_argument("Please enter a valid perfect square!");
    }

    // Checks if user input is integer
    else if(validateInput(userString) == false){
        // Throws exception if not an integer
        throw invalid_argument("Please enter a valid integer!");
    }

    // return the value.
    return userSquareRootInt;
}

// MAIN Function
int main(){

    // Stores user input and square root of it
    int userInteger,
        userSquareRoot;

    // INTRO
    // Clears terminal screen
    cout << "\033[2J\033[1;1H";
    cout << "-------------------------------------------------" << endl;
    cout << "Welcome to Perfect Square Calculator! :)" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "RULES: " << endl;
    cout << "- Simply enter a positive integer and you will get" << endl;
    cout << "  the perfect square if it exists." << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "No other values will be accepted!" << endl;
    cout << "-------------------------------------------------" << endl;
    // Prompt the user to enter the number.
    cout << "Please enter your number: ";
    cin >> userInteger;

    // Tries to square root it 
    try{

        userSquareRoot = calcSquareRoot(userInteger);

        // If it is a perfect square, shows the user perfect square
        cout << "-------------------------------------------------" << endl;
        cout << "Square root of " << userInteger << " is " << userSquareRoot << "!" << endl;
        cout << "-------------------------------------------------" << endl;
    }

    // Catch block for negative values
    catch(domain_error errorMessage){

        // Displays negative value error 
        cout << "-------------------------------------------------" << endl;
        cout << "Error! " << errorMessage.what() << endl;
        cout << "-------------------------------------------------" << endl;
        cin.ignore();
        cout << "Press ENTER 2 times to continue: ";
        cin.get();
        // Helps in clearing the error flags which are set when cin fails to interpret the input.
        cin.clear();
        // Helps in removing the input contents that could've caused the read failure
        cin.ignore(1000,'\n');
        // Loops back until they close program with 'e'
        main();
    }

    // Catch block for other invalid inputs
    catch(invalid_argument errorMessage){

        // Displays invalid input error 
        cout << "-------------------------------------------------" << endl;
        cout << "Error! " << errorMessage.what() << endl;
        cout << "-------------------------------------------------" << endl;
        // Helps in clearing the error flags which are set when cin fails to interpret the input.
        cin.clear();
        cin.ignore();
        cout << "Press ENTER 2 times to continue: ";
        cin.get();
        // Helps in clearing the error flags which are set when cin fails to interpret the input.
        cin.clear();
        // Helps in removing the input contents that could've caused the read failure
        cin.ignore(1000,'\n');
        // Loops back until they close program with 'e'
        main();
    }

    // Stores user's selection
    char userChoice;
    cout << "Would you like to try another number (Enter 'c') or exit ( Enter 'e')?: ";
    cin >> userChoice;
    // Continues program
    if (userChoice == 'C' || userChoice == 'c'){
        
        main();
    }
    // Terminates program
    if(userChoice == 'E' || userChoice == 'e'){

        // CLOSING
        cout << "-------------------------------------------------" << endl;
        cout << "Thank you! Have a nice day! :)" << endl;
        cout << "-------------------------------------------------" << endl;
        // Terminating program
        exit(0);
    }
    // Loops until they choose to continue or exit
    else{

        while(userChoice != 'E' || userChoice != 'e' || userChoice != 'C' || userChoice != 'c'){
            // Helps in clearing the error flags which are set when cin fails to interpret the input.
            cin.clear();
            // Helps in removing the input contents that could've caused the read failure
            cin.ignore(1000,'\n');
            cout << "-------------------------------------------------" << endl;
            cout << "Error! You must choose 'e' or 'c'. " << endl;
            cout << "-------------------------------------------------" << endl;

            // Prompt to enter only positive integers
            cout << "Enter a VALID choice: ";
            cin >> userChoice;
        }
    }

    // Terminates program
    return 0;
}