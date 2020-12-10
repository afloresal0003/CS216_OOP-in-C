/*
    Programmer: Anthony Flores-Alvarez
    Course: CS 216 - OOP in C++
    Date: December 1, 2020
    Description: This program demonstrates a driver program that will
    return the minimum and maximum values of two given values for 
    various data types using templates. 
*/

// Header files for program functionality
#include <iostream>
#include <sstream>
#include <cstdlib>

// Allows us to not have to use std:: throughout program
using namespace std;

// Min template that accepts two arguments and returns the lowest one
template <class T>
T Min(T userValOne, T userValTwo){

	if (userValOne < userValTwo){
		return userValOne;
    }

	else{
		return userValTwo;
    }
}

// Max template that accepts two arguments and returns the highest one
template <class T>
T Max(T userValOne, T userValTwo){

	if (userValOne > userValTwo){
		return userValOne;
    }

	else{
		return userValTwo;
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

// Switches string to a float
float switchToFloat(string userString){

    // Stores number form of user's string
    float userValue;

    // Conversion
    userValue = stof(userString);

    // Giving back the switched value type
    return userValue;
}

// Switches string to a float
double switchToDouble(string userString){

    // Stores number form of user's string
    double userValue;

    // Conversion
    userValue = stod(userString);

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
string validateInput(string userInputString, string userDataType){

    // Integers Checking
    if(userDataType == "integer"){
        // Storing character outcome and number form of user's values
        bool stringHere;
        double userInputValue;

        // Checking for string
        stringHere = isString(userInputString);
        // Storing number value
        userInputValue = switchToInt(userInputString);

        // Loops until user enters an integer
        while (!cin || stringHere == true || userInputValue != int(userInputValue)) {
            // Helps in clearing the error flags which are set when cin fails to interpret the input.
            cin.clear();
            // Helps in removing the input contents that could've caused the read failure
            cin.ignore(1000,'\n');
            cout << "-------------------------------------------------" << endl;
            // Prompt to enter only positive integers
            cout << "Error! Please enter an INTEGER: ";
            cin >> userInputString;
            userInputValue = switchToInt(userInputString);
            stringHere = isString(userInputString);
        }
        // Giving back admissible value
        return userInputString;
    }

    // Floats Checking
    if(userDataType == "float" || userDataType == "double"){
        // Storing character outcome and number form of user's values
        bool stringHere;

        // Checking for string
        stringHere = isString(userInputString);

        // Loops until user enters an integer
        while (!cin || stringHere == true) {
            // Helps in clearing the error flags which are set when cin fails to interpret the input.
            cin.clear();
            // Helps in removing the input contents that could've caused the read failure
            cin.ignore(1000,'\n');
            cout << "-------------------------------------------------" << endl;
            // Prompt to enter only positive integers
            if(userDataType == "float"){
                cout << "Error! Please enter a valid float: ";
            }
            else{
                cout << "Error! Please enter a valid double: ";
            }
            cin >> userInputString;
            stringHere = isString(userInputString);
        }
        // Giving back admissible value
        return userInputString;
    }

    // Chars Checking
    if(userDataType == "char" ){

        // Loops until user enters an integer
        while (!cin || userInputString.length() != 1) {
            // Helps in clearing the error flags which are set when cin fails to interpret the input.
            cin.clear();
            // Helps in removing the input contents that could've caused the read failure
            cin.ignore(1000,'\n');
            cout << "-------------------------------------------------" << endl;
            // Prompt to enter only positive integers
            cout << "Error! Please enter a valid char (1 character): ";
            cin >> userInputString;
        }

        return userInputString;
    }

    // Catch
    else{
        cout << "Data type does not need checking!" << endl;
    }
}

// MAIN Function
int main(){

    // Variables to hold user input and temporary validating variables
	int userIntOne, userIntTwo;
    string userIntOneString, userIntTwoString;
    float userFloatOne, userFloatTwo;
    string userFloatOneString, userFloatTwoString;
	double userDoubOne, userDoubTwo;
    string userDoubOneString, userDoubTwoString;
	char userCharOne, userCharTwo;
    string userCharOneString, userCharTwoString;
    string userStrOne, userStrTwo;

    // INTRO
    cout << "\033[2J\033[1;1H";
    cout << "-------------------------------------------------" << endl;
    cout << "Welcome to MinMax Calculator! :)" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "- Simply enter the values that are requested and" << endl;
    cout << "  the program will output the minimum and maximum" << endl;
    cout << "  of the two values." << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "Pay attention to the TYPE of value that's asked!!" << endl;
    cout << "-------------------------------------------------" << endl;

    /* INTEGERS */
	// Ask user to enter two integers and validating them
	cout << "Enter an integer value: ";
	cin  >> userIntOneString;
    userIntOneString = validateInput(userIntOneString, "integer");
    userIntOne = switchToInt(userIntOneString);
    cout << "Enter another integer value: ";
    cin >> userIntTwoString;
    userIntTwoString = validateInput(userIntTwoString, "integer");
    userIntTwo = switchToInt(userIntTwoString);
    // Min/ Max of the integers
    cout << "\n-------------------------------------------------" << endl;
	cout << "Lesser: " <<  Min(userIntOne, userIntTwo) << endl;
	cout << "Greater: " << Max(userIntOne, userIntTwo) << endl;
    cout << "-------------------------------------------------" << endl;

    /* FLOATS */
	// Ask user to enter two floats and validating them
	cout << "\nEnter a float value: ";
	cin  >> userFloatOneString;
    userFloatOneString = validateInput(userFloatOneString, "float");
    userFloatOne = switchToFloat(userFloatOneString);
    cout << "Enter another float value: ";
    cin >> userFloatTwoString;
    userFloatTwoString = validateInput(userFloatTwoString, "float");
    userFloatTwo = switchToFloat(userFloatTwoString);
    // Min/ Max of the valid floats
    cout << "\n-------------------------------------------------" << endl;
	cout << "Lesser: " << Min(userFloatOne, userFloatTwo) << endl;
	cout << "Greater: " << Max(userFloatOne, userFloatTwo) << endl;
    cout << "-------------------------------------------------" << endl;

    /* DOUBLES */
    // Ask user to enter two doubles and validating them
	cout << "\nEnter a double value: ";
	cin  >> userDoubOneString;
    userDoubOneString = validateInput(userDoubOneString, "double");
    userDoubOne = switchToDouble(userDoubOneString);
    cout << "Enter another double value: ";
	cin  >> userDoubTwoString;
    userDoubTwoString = validateInput(userDoubTwoString, "double");
    userDoubTwo = switchToDouble(userDoubTwoString);
    // Min/ Max of the valid doubles
    cout << "\n-------------------------------------------------" << endl;
	cout << "Lesser: " << Min(userDoubOne, userDoubTwo) << endl;
	cout << "Greater: " << Max(userDoubOne, userDoubTwo) << endl;
    cout << "-------------------------------------------------" << endl;

    /* CHARS */
	// Ask user to enter two chars and validating them
	cout << "\nEnter a char value: ";
	cin >> userCharOneString;
    userCharOneString = validateInput(userCharOneString, "char");
    userCharOne = userCharOneString[0];
    cout << "Enter another char value: ";
	cin >> userCharTwoString; 
    userCharTwoString = validateInput(userCharTwoString, "char");
    userCharTwo = userCharTwoString[0];
    // Min/ Max of the valid chars
    cout << "\n-------------------------------------------------" << endl;
	cout << "Lesser: " << Min(userCharOne, userCharTwo) << endl;
	cout << "Greater: " << Max(userCharOne, userCharTwo) << endl;
    cout << "-------------------------------------------------" << endl;

    /* STRINGS */
    // Ask user to enter two strings and store it
	cout << "\nEnter a string value: ";
	cin >> userStrOne;
    cout << "Enter another string value: ";
	cin >> userStrTwo; 
    // Min/ Max of the strings
    cout << "\n-------------------------------------------------" << endl;
	cout << "Lesser: " << Min(userStrOne, userStrTwo) << endl;
	cout << "Greater: " << Max(userStrOne, userStrTwo) << endl;

    // CLOSING
    cout << "\n-------------------------------------------------" << endl;
    cout << "Thank you! Have a nice day! :)" << endl;
    cout << "-------------------------------------------------" << endl;
	return 0;
}