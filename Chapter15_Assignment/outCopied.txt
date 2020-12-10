/*
    Programmer: Anthony Flores-Alvarez
    Course: CS 216 - OOP in C++
    Date: November 5, 2020
    Description: This program demonstrates an abstract class
    that has a pure virtual member function as a stand-in for 
    an actual sequence, and two member functions that are passed
    two integer paremetesr k and m, where k < m.
*/

// Header files for program functionality
#include <iostream>
#include <cmath>
#include <sstream>
#include <cstdlib>

// Allows us to not have to use std:: throughout program
using namespace std;

// Class Declaration for program
class AbstractSeq{

    // Public member functions & variables
    public:

        // Pure virtual member function as a stand-in for 
        // an actual sequence
        virtual int fun(int k) = 0;

        // Prints all terms fun(k) through fun(m) of sequence
        void printseq(int k, int m){
            
            // Loop through sequence until m
            while(k <= m){
                
                // End of sequence
                if(k == m){

                    cout << fun(k) << ".";
                    k++;
                }

                // Term in sequence
                else{

                    cout << fun(k) <<",";
                    k++;
                }
                
            }
        }

        // Returns sum of terms in sequence
        int sumSeq(int k,int m){

            int sum = 0;

            // Loops through sequence
            while(k <= m){
                
                // Sums sequence/fun(k) terms
                sum += fun(k);
                k++;
            }

            // Returns sum
            return sum;
        }
};

// Square sequence subclass for AbstractSeq class demonstration
class SquareSeqDem:public AbstractSeq{

    public:
        // Sequence of squared values
        int fun(int k){
            
            return (pow((k + 1), 2));
        }
};

// Odd sequence subclass for AbstractSeq class demonstration
class OddSeqDem:public AbstractSeq{

    public:
        // Sequence of odd numbers
        int fun(int k){
            
            return 2 * k + 1;
        }
};

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
int main(){

    // Initialiazing integer parameters
    int k,
        m;

    // For value checking
    string k_string,
           m_string;

    // Initializing instances for class demonstration
    SquareSeqDem sqrObject;
    OddSeqDem oddObject;

    // INTRO/ HEADER
    cout << "-------------------------------------------------" << endl;
    cout << "Welcome to Sequence Sum!" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "RULES:" << endl;
    cout << "\n- This program will show you the square and odd sequences " << endl;
    cout << "  with your given starting (k) and ending (m) terms. " << endl;
    cout << "- Your k value MUST BE LESS THAN your m value! (k < m)" << endl;
    cout << "- Only POSITIVE INTEGERS will be accepted! " << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "REMINDER: " << endl;
    cout << "\n- 0 marks the beginning of the sequence. " << endl;
    cout << "-------------------------------------------------" << endl;

    // Storing user starting place/term in sequence
    cout << "\nEnter the starting term (k) for the sequences: ";
    cin >> k_string;

    // Checking if value is valid
    k_string = validateInput(k_string);
    // Storing valid value
    k = switchToInt(k_string);

    // Storing user ending place/term in sequence
    cout << "\nEnter the ending term of (m) for the sequences: ";
    cin >> m_string;

    // Checking if value is valid
    m_string = validateInput(m_string);
    // Storing valid value
    m = switchToInt(m_string);

    while(k >= m){

        // Helps in clearing the error flags which are set when cin fails to interpret the input.
        cin.clear();
        // Helps in removing the input contents that could've caused the read failure
        cin.ignore(1000,'\n');
        cout << "-------------------------------------------------" << endl;
        cout << "Error! (k) must be LESS than (m). " << endl;
        cout << "-------------------------------------------------" << endl;

        // Prompt to enter only positive integers
        cout << "Enter a VALID k value: ";
        cin >> k_string;
        // Checking if value is valid
        k_string = validateInput(k_string);
        // Storing valid value
        k = switchToInt(k_string);

        cout << "Enter a VALID m value: ";
        cin >> m_string;
        cout << "-------------------------------------------------" << endl;
        // Checking if value is valid
        m_string = validateInput(m_string);
        // Storing valid value
        m = switchToInt(m_string);
    }

    cout << "-------------------------------------------------" << endl;
    cout << "Your inputs: " << endl;
    cout << "\nStarting element in sequence (k): " << k << endl;
    cout << "Ending element in sequence (m): " << m << endl;

    /* SQUARE OUTPUTS */
    // Outputting square sequence
    cout << "\nSquare sequence w/ given inputs: ";
    sqrObject.printseq(k, m);
    // Outputting summed sequence terms
    cout << "\nSum of square sequence: " << sqrObject.sumSeq(k, m) << endl;

    /* ODD OUTPUTS */
    // Outputting odd sequence
    cout << "\nOdd sequence w/ given inputs: ";
    oddObject.printseq(k, m);
    // Outputting summed sequence terms
    cout << "\nSum of odd sequence: " << oddObject.sumSeq(k, m) << endl;

    // CLOSING
    cout << "-------------------------------------------------" << endl;
    cout << "Thank you! Have a nice day! :)" << endl;
    cout << "-------------------------------------------------" << endl;

    // Terminating program
    return 0;
}