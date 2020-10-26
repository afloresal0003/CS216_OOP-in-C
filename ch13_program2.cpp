/*
    Programmer: Anthony Flores-Alvarez
    Course: CS 216 - OOP in C++
    Date: October 26, 2020
    Description: This program will take a text file and 
    print, for each letter of the English alphabet, the 
    number of times the letter appears in the file.

*/

// Header files for program functionality
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

// Allows us to not have to use std:: throughout program
using namespace std;

// MAIN Function
int main(){

    // Input stream for user's input file
    ifstream inputFile;

    // Declaring variables
    const int SIZE = 26;
    string userInpFileName,
           inpFileSentence;
    char characterInSentence, 
         capitalChar;
    int lettersInUserFile[SIZE] = {0};

    // Heading / INPUT
    cout << "-------------------------------------------------" << endl;
    cout << "Welcome to Letter Frequency Counter!" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "RULES:" << endl;
    cout << "- Enter the exact name of your input file. " << endl;
    cout << "- All input is case sensitive!" << endl;
    cout << "- If you enter a non-recognized input file name, the program will not continue." << endl;
    cout << "-------------------------------------------------" << endl;

    // Asking for input file
    cout << "Please enter the name of your file: ";
    cin >> userInpFileName;

    //Opening the input file
    inputFile.open(userInpFileName);

    // If the user entered unrecognized input file, 
    // error message and close program. 
    if(inputFile.fail()){
        cout << "\n-------------------------------------------------------------------------------------------------" << endl;
        cout << "Error! " << userInpFileName << " is an unrecognized file. Please restart the program and try again!" << endl;
        cout << "---------------------------------------------------------------------------------------------------" << endl;
        exit(0);
    }
    
    // Reading and counting the letters in the file
    while (getline(inputFile, inpFileSentence)){
        
        // For each character in the sentence
        for (int i = 0; i < inpFileSentence.length(); i++){
            characterInSentence = inpFileSentence[i];

            // If the character is a letter...
            if (isalpha(characterInSentence)){
                // ... capitalize it for displaying later
                capitalChar = toupper(characterInSentence);
                lettersInUserFile[(capitalChar - 65)]++;

            }
        
        }
    }

    // Closing the user's input file
    inputFile.close();

    // OUTPUT
    cout << "-------------------------------------------------" << endl;
    cout << "LETTER FREQUENCIES of " << userInpFileName << ": " << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "\nLetter\t\tCount" << endl;
    cout << "------\t\t-----" << endl;

    // Loops through all letters
    for(int i = 0; i < 26; i++){
        // Display the letter with its frequency.
        cout << (char)(65 + i) << "\t\t" << lettersInUserFile[i] << endl;  
    
    }

    // CLOSING
    cout << "\n-------------------------------------------------" << endl;
    cout << "Thank you for using Letter Frequency Counter! :)" << endl;
    cout << "-------------------------------------------------" << endl;

    // Terminating program
    return 0;
}