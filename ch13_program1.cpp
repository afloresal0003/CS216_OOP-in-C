/*
    Programmer: Anthony Flores-Alvarez
    Course: CS 216 - OOP in C++
    Date: October 26, 2020
    Description: This program is a filter. It asks the user for two
    file names. The first file will be opened for input, and the second 
    file will be opened for output. The program will read the contents 
    of the first file and change all the letters other than the first 
    letter of sentences to lowercase. First letter of sentences should 
    be made uppercase. The revised contents should be stored in the 
    second file. It is assumed user's sentences end in periods.

*/

// Header files for program functionality
#include <iostream>
#include <string>
#include <fstream>

// Allows us to not have to use std:: throughout program
using namespace std;

// MAIN Function
int main()
{
    // Input/output stream for user's input/output files
    ifstream inputFile;
    ofstream outputFile;
    
    // Stores user file names and sentence
    string userInpFileName,
           userOutpFileName,
           inpFileSentence;

    // Heading / INPUT
    cout << "-------------------------------------------------" << endl;
    cout << "Welcome to Sentence Filter!" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "RULES:" << endl;
    cout << "- Enter the exact names of your input and output files. " << endl;
    cout << "- All input is case sensitive!" << endl;
    cout << "- If you enter a non-recognized input file name, the program will not continue." << endl;
    cout << "- If you enter a non-recognized OUTPUT file name, one with the name you provided, will be created." << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "- It is assumed your sentences end with a PERIOD ('.')" << endl;
    cout << "-------------------------------------------------" << endl;
    // Asking for input file
    cout << "Please enter the name of your input file: ";
    cin >> userInpFileName;

    // Opening user's input file
    inputFile.open(userInpFileName);   

    // If the user entered unrecognized input file, 
    // error message and close program. 
    if(inputFile.fail()){
        cout << "Error! " << userInpFileName << " is an unrecognized file. Please restart the program and try again!" << endl;
        return 0;
    }

    // Asking for output file
    cout << "Please enter the name of your output file: ";
    cin >> userOutpFileName;

    // Opening user's output file
    outputFile.open(userOutpFileName);

    // Getting each sentence from the input file (ending with a period)
    while(getline(inputFile, inpFileSentence, '.')){
        
        // Variable to help find letters that are already capitalized
        bool capitalLetter = false;

        // Looping through each character in the sentence
        for(int characterCount = 0; characterCount < inpFileSentence.length(); characterCount++){
            
            // For non-alphabetic characters, simply outputting them.
            if(!isalpha(inpFileSentence[characterCount])){
                outputFile << inpFileSentence[characterCount];
                continue;
            }

            // For non-capitalized letters, capitalizing & outputting them.
            if(!capitalLetter && isalpha(inpFileSentence[characterCount])){
                outputFile << (char)toupper(inpFileSentence[characterCount]);
                capitalLetter = true;
            }

            // For capitalized letters in the middle of sentences, lowercasing & outputting them.
            else if(capitalLetter){
                outputFile << (char)tolower(inpFileSentence[characterCount]);
            }
        }
        // Putting period at the end of output sentence
        outputFile << ".";
    }

    // Closing files
    inputFile.close();
    outputFile.close();

    cout << "-------------------------------------------------" << endl;
    cout << "Thank you for using File Filter! :)" << endl;
    cout << "-------------------------------------------------" << endl;

    // Terminating program
    return 0;
}