/*
    Programmer: Anthony Flores-Alvarez
    Course: CS 216 - OOP in C++
    Date: November 5, 2020
    Description: This program is a file filter with 
    an abstract file filter class that performs encryption,
    another that transforms a file to all uppercase, and 
    another that creates an unchanged copy of the original file. 
*/

// Header files for program functionality
#include <iostream>
#include <fstream>
#include <cstdlib>

// Allows us to not have to use std:: throughout program
using namespace std;

// Abstract file filter class definition
class AbsFileFilter{

    public:

        // Virtual transform function with given prototype
        virtual char transform(char ch) = 0;
        
        // Performs the actual filtering
        void doFilter(ifstream &in, ofstream &out){
            
            //Storing chars read & updated
            char ch, 
                 updatedChar;

            // Loop through each char in file
            while(in.get(ch)){

                // Transforming character & storing it in output file
                updatedChar = transform(ch);
                out.put(updatedChar);
            }
        }

};

// Subclass that performs encryption
class FileEncrypter:public AbsFileFilter{
    
    private:
        int encryptKey;

    public:
        // Default constructor setting random encryption key
        FileEncrypter(){

            encryptKey = rand();
        }

        // Constructor that takes an integer as
        // an argument and uses it as the encryption key
        FileEncrypter(int k){

            encryptKey = k;
        }

        // Encrypting function with given prototype
        virtual char transform(char ch){

            // Adding key to char to encrypt it
            // and storing it in output file
            return ch + encryptKey;
        }
};

// Subclass that transforms a file to all uppercase
class FileUppercaser:public AbsFileFilter{
    
    public:

        // Uppercasing function with given prototype
        virtual char transform(char ch){
            
            // Uppercasing each character
            // and storing it in output file
            return toupper(ch);
        }
};

// Subclass that creates an unchanged copy of original file
class FileCopier:public AbsFileFilter{
    
    public:

        // Copying function with given prototype
        virtual char transform(char ch){

            // Simply storing char in output file
            return ch;
        }
};

// MAIN Function
int main(){

    // Streaming input file
    ifstream inputFile;
    // Storing user's file name
    string userInputFileName;

    // INTRO/ HEADER
    cout << "-------------------------------------------------" << endl;
    cout << "Welcome to File Filter 2.0!" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "RULES:" << endl;
    cout << "\n- This program will encrypt, uppercase, and \n  duplicate a file of your choice. " << endl;
    cout << "\n- Simply enter in the name of your input file and \n  the rest will be taken care of." << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "Program will not proceed until you enter a valid input file! " << endl;
    cout << "Ensure that your file is in the same folder as this program!" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "Enter the name of your file: ";
    cin >> userInputFileName;

    // Opening user's input file
    inputFile.open(userInputFileName);

    // If the user entered unrecognized input file, 
    // loops until they do
    while(inputFile.fail()){
        // Helps in clearing the error flags which are set when cin fails to interpret the input.
        cin.clear();
        // Helps in removing the input contents that could've caused the read failure
        cin.ignore(1000,'\n');
        cout << "-------------------------------------------------" << endl;
        cout << "Error! " << userInputFileName << " is an unrecognized file. Please restart the program and try again!" << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "Enter the correct name of your file: ";
        cin >> userInputFileName;

        inputFile.open(userInputFileName);
    }
    cout << "\n-------------------------------------------------" << endl;
    cout << "" << userInputFileName << " found! File opened for reading..." << endl;
    cout << "-------------------------------------------------" << endl;

    /* UPPERCASING */
    cout << "\noutUppercased.txt created & opened to store uppercased version..." << endl;
    // Output file streaming
    ofstream outputFile("outUppercased.txt");
    // Creating object of uppercasing class
    FileUppercaser upperCaseFilter;
    // Uppercasing file with object
    upperCaseFilter.doFilter(inputFile, outputFile);
    // Closing output file to move onto new filter output file
    outputFile.close();
    cout << "Uppercasing done!" << endl;

    // Clearing input file flags and moving read position
    // to the first byte
    inputFile.clear();
    inputFile.seekg(0L, ios::beg);

    /* ENCRYPTING */
    cout << "\nCreating and opening outEncrypted.txt to store encrypted version...\n";
    outputFile.open("outEncrypted.txt");
    // Creating object of encrypting class
    FileEncrypter encryptionFilter;
    // Encrypting file with object
    encryptionFilter.doFilter(inputFile, outputFile);
    // Closing output file to move onto new filter output file
    outputFile.close();
    cout << "Encrypting done!" << endl;

    // Clearing input file flags and moving read position
    // to the first byte
    inputFile.clear();
    inputFile.seekg(0L, ios::beg);

    /* COPYING */
    cout << "\nCreating and opening outCopied.txt to store file copy...\n";
    outputFile.open("outCopied.txt");
    // Creating object of copying class
    FileCopier copyFilter;
    // Copying file with object
    copyFilter.doFilter(inputFile, outputFile);
    // Closing input and output files
    inputFile.close();
    outputFile.close();
    cout << "Copying done!" << endl;

    // CLOSING
    cout << "\n-------------------------------------------------" << endl;
    cout << "Thank you! Have a nice day! :)" << endl;
    cout << "-------------------------------------------------\n" << endl;

    // Terminating program
    return 0;
}