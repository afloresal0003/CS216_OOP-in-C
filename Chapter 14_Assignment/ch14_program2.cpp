/*
    Programmer: Anthony Flores-Alvarez
    Course: CS 216 - OOP in C++
    Date: November 5, 2020
    Description: This program accepts two arguments into the parameters 
    x and y of a function that returns the value of x times y, recursively
    NOTE: The original problem says ARGUMENTS. Meaning all numbers are
    admissible: Decimals, Negatives, Positives, Integers, etc. IF it had
    said positive integers, I would have made it only positive integers, but 
    because it only said arguments, I allowed for negatives and decimals.  
        
    7 * 4 = 4 + 4 + 4 + 4 + 4 + 4 + 4 

*/

// Header files for program functionality
#include <iostream>
#include <cstdlib>
#include <sstream>

// Allows us to not have to use std:: throughout program
using namespace std;

// Recursive function to multiply 2 numbers
double recursiveMultiplier(double x, double y){

    // If either are 0
    if (x == 0 || y == 0){
        return 0;
    }
    
    // Recursive call (positive)
    if (y > 0){
        return x + recursiveMultiplier(x, y - 1);
    }

    // Recursive call (negative)
    if (y < 0){
        return -recursiveMultiplier(x, -y);
    }

}

// Switches string to a number
double switchToNum(string userString){

    // Stores number form of user's string
    double userValue;

    // Creating object from the stringstream class
    stringstream uStr(userString);

    // Passing the string value to the variable 
    // that'll hold it as a number type
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
    userInputValue = switchToNum(userInputString);

    // Loops until user enters a positive integer
    while (!cin || stringHere == true) {
        // Helps in clearing the error flags which are set when cin fails to interpret the input.
        cin.clear();
        // Helps in removing the input contents that could've caused the read failure
        cin.ignore(1000,'\n');
        cout << "-------------------------------------------------" << endl;
        // Prompt to enter only positive integers
        cout << "Error! Please enter an actual value: ";
        cin >> userInputString;
        userInputValue = switchToNum(userInputString);
        stringHere = isString(userInputString);
    }
    // Giving back admissible value
    return userInputString;
}

// Counts how many spaces after the decimal there are
int countDecimals(double userInput){
    string s,
           t;
    stringstream out;
    out << userInput;
    s = out.str();
    t = s.substr(s.find(".") + 1);
    return (t.length());
}

// Converts a whole number into its original decimal one
double makeDecimal(double numValue, int numDecimals){
    for (int i = 0; i < numDecimals; i++){
            numValue /= 10; 
        }
    return numValue;
}

// MAIN Function
int main(){

    // Variables
    double x,             // holds x value
           y,             // holds y value
           product;       // holds result of calculation

    int numDecimalsX,     // hold decimal places
        numDecimalsY;

    bool xHadDecimals = false,   // hold decimal condition
         yHadDecimals = false;

    string xString,       // holds x value in string form
           yString;       // holds y value in string form

    // Heading / INPUT
    cout << "-------------------------------------------------" << endl;
    cout << "Welcome to Recursion Multiplication!" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "RULES:" << endl;
    cout << "- Only values will be accepted. No characters! " << endl;
    cout << "- I can multiply both positive and negative values recursively!" << endl;
    cout << "-------------------------------------------------" << endl;
    // Asking for x value
    cout << "Enter an x-value: ";
    cin >> xString;
    
    // Checking if it's valid
    xString = validateInput(xString);
    // If it is, setting it to x
    x = switchToNum(xString);

    // If x is a decimal
    if (x != int(x)){
        xHadDecimals = true;
        // Count the number of decimal spots
        numDecimalsX = countDecimals(x);
        // Make whole number
        for (int i = 0; i < numDecimalsX; i++){
            x = recursiveMultiplier(x, 10); 
        }
    }

    // Asking for y value
    cout << "Enter a y-value: ";
    cin >> yString;
    // Checking if it's valid
    yString = validateInput(yString);
    // If it is, setting it to y
    y = switchToNum(yString);

    // If y is a decimal
    if (y != int(y)){
        yHadDecimals = true;
        // Count the number of decimal spots
        numDecimalsY = countDecimals(y);
        // Make whole number
        for (int i = 0; i < numDecimalsY; i++){
            y *= 10; 
        }
    }

    // Calculating product
    product = recursiveMultiplier(x,y);

    // DISPLAY
    cout << "-------------------------------------------------" << endl;
    // If x had decimals
    if (xHadDecimals == true){
        // Make X a decimal again
        x = makeDecimal(x, numDecimalsX);

        // If y also had decimals
        if (yHadDecimals == true){
            // Make decimal again
            y = makeDecimal(y, numDecimalsY);

            // Turn product into decimal
            product = makeDecimal(product, (numDecimalsX + numDecimalsY));
        }

        // If y did not have decimals
        else{
            // Turn product into decimal
            product = makeDecimal(product, numDecimalsX);
        }
    }

    // If y had decimals but x did not
    else if (yHadDecimals == true && xHadDecimals != true){
        
        // Make y decimal again
        y = makeDecimal(y, numDecimalsY);

        // Turn product into decimal
        product = makeDecimal(product, numDecimalsY);
        
    }
    // Display product to user
    cout << x << " * " << y << " = " << product << endl;

    // CLOSING
    cout << "-------------------------------------------------" << endl;
    cout << "Thank You!" << endl;
    cout << "-------------------------------------------------" << endl;
    
    // Terminating program
    return 0;
}

