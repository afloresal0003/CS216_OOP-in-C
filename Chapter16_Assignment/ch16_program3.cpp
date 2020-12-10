/*
    Programmer: Anthony Flores-Alvarez
    Course: CS 216 - OOP in C++
    Date: December 1, 2020
    Description: This program uses two template
    functions to rotate a vector of chars, ints, 
    doubles, and strings to the left until it is
    completely turned. 
*/

// Header files for program functionality
#include <iostream>
#include <vector>
#include <string>

// Allows us to not have to use std:: throughout program
using namespace std;

template <typename T>

// Performs a single circular left rotation on a vector
void rotateleft(vector <T>& v){

    // Storing first element in vector
    T firstElement = v[0];

    // Looping through vector moving each 
    // element to the left
    for(int i = 0; i < v.size()-1; i++){
        
        v[i] = v[i+1];
    }
    // Storing original first element to the end
    v[v.size()-1] = firstElement;
}

template <typename T>

// Prints out the vector passed to it as parameter
void output(vector <T> v){

    // Loops through vector
    for(int i = 0; i < v.size(); i++){

        // Prints each element with space
        cout << v[i] << " ";
    }
    // Newline to show rotation
    cout << endl;
}

// MAIN Function
int main(){

    // INTRO
    cout << "\033[2J\033[1;1H";
    cout << "-------------------------------------------------" << endl;
    cout << "Welcome to Rotate My Vector! :)" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "- This program will rotate vectors of different " << endl;
    cout << "  data types. Simply watch!" << endl;
    cout << "-------------------------------------------------\n" << endl;
  
    // Initializing integer vector and storing integers into it
    vector<int> intVector;
    intVector.push_back(1);
    intVector.push_back(3);
    intVector.push_back(5);
    intVector.push_back(7);

    // Initializing char vector and storing chars into it
    vector<char> charVector;
    charVector.push_back('a');
    charVector.push_back('b');
    charVector.push_back('c');
    charVector.push_back('d');
    charVector.push_back('e');

    // Initializing double vector and storing doubles into it
    vector<double> doubleVector;
    doubleVector.push_back(6.2);
    doubleVector.push_back(45.3);
    doubleVector.push_back(21.9);
    doubleVector.push_back(98.99);
    doubleVector.push_back(87.56);

    // Initializing string vector and storing strings into it
    vector<string> stringVector;
    stringVector.push_back("My");
    stringVector.push_back("name");
    stringVector.push_back("is");
    stringVector.push_back("Anthony");
    stringVector.push_back("Flores");

    /* OUTPUTS */

    /* INTEGERS */
    cout << "-------------------------------------------------" << endl;
    cout << " INTEGERS " << endl;
    cout << "-------------------------------------------------" << endl;
    // Rotation and output of ints using template functions
    for(int i = 0; i < 4; i++){
        output(intVector);
        rotateleft(intVector);
    }

    cout<< "\n";

    /* CHARS */
    cout << "-------------------------------------------------" << endl;
    cout << " CHARS " << endl;
    cout << "-------------------------------------------------" << endl;
    // Rotation and output of chars using template functions
    for(int i = 0; i < 5; i++){

        output(charVector);
        rotateleft(charVector);
    }

    cout<< "\n";

    /* DOUBLES */
    cout << "-------------------------------------------------" << endl;
    cout << " DOUBLES " << endl;
    cout << "-------------------------------------------------" << endl;
    // Rotation and output of doubles using template functions
    for(int i = 0; i < 5; i++){

        output(doubleVector);
        rotateleft(doubleVector);
    }

    cout<< "\n";

    /* STRINGS */
    cout << "-------------------------------------------------" << endl;
    cout << " STRINGS " << endl;
    cout << "-------------------------------------------------" << endl;
    // Rotation and output of strings using template functions
    for(int i = 0; i < 5; i++){

        output(stringVector);
        rotateleft(stringVector);
    }

    /* INTEGERS */
    cout << "\n-------------------------------------------------" << endl;
    cout << "Thank you for coming! :) " << endl;
    cout << "-------------------------------------------------" << endl;
    // Terminating program
    return 0;
}