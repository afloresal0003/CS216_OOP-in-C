/*
    Programmer: Anthony Flores-Alvarez
    Course: CS 216 - OOP in C++
    Date: October 10, 2020
    Description: This program dynamically allocates an array large 
    enough to hold a user-defined number of test scores. Then, the
    test scores entered are sorted in ascending order & displayed
    all entered scores are shown, and then the average of the scores 
    is calculated and shown.
*/

// Header files for program functionality
#include <iostream>
#include <iomanip>

// Allows us to not have to use std:: throughout program
using namespace std;

// Function to sort array in ascending order
void ascendingSort(double *testPtr, int numOfTests){
    // To help in swapping
    double temp;

    // Will control when array is done sorting
    bool stillSwapping = true;

    // While still swapping... 
    while(stillSwapping){

        stillSwapping = false;

        // Loops through all test scores
        for(int counter = 0; counter < numOfTests - 1; counter++){

            // Checks if following score is greater than current score
            if(*(testPtr+counter) > *(testPtr+counter+1)){
                
                // If so, swap them
                temp = *(testPtr+counter+1);
                *(testPtr+counter+1) = *(testPtr+counter);
                *(testPtr+counter) = temp;

                // Updates the control variable
                stillSwapping = true;

            }

        } 

    } 
}

// Function to get the average of the scores
double calcAverage(double *testPtr, int numOfTests){
    
    // Holds total of scores
    double scoreSum = 0.0;

    // Loops through all test scores
    for(int counter = 0; counter < numOfTests; counter++){
        scoreSum += *(testPtr + counter);
    }

    // Returning the average with double typecast to prevent integer division
    return (double)scoreSum/numOfTests;
}

// MAIN FUNCTION
int main()
{
    // Number of tests being entered
    int numTests;

    // Heading
    cout << "-------------------------------------------------" << endl;
    cout << "Welcome to Test Score Sorter and Calculator!" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "Notes: " << endl;
    cout << "- Please ensure that all inputs are positive values. " << endl;
    cout << "-------------------------------------------------" << endl;
    // Asking for test scores amount
    cout << "Please enter the number of test scores: ";
    cin >> numTests;
    while (numTests < 0 || !cin){
        // Helps in clearing the error flags which are set when cin fails to interpret the input.
        cin.clear();
        // Helps in removing the input contents that could've caused the read failure
        cin.ignore(1000,'\n');
        cout << "Error! Invalid input. Please enter a valid input: ";
        cin >> numTests;
    }

    // Dynamically allocate array large enough for number of test scores
    double *testScores = new double[numTests];

    // OUTPUT
    cout << "-------------------------------------------------" << endl;
    cout << "INPUTTED SCORES: \n" << endl;
    // Store values into array using for loop
    for(int counter = 0; counter < numTests; counter++){
        cout << "Test " << counter + 1 << ": ";

        // Using pointer notation
        cin >> *(testScores + counter);

        // Validating the user input
        while(*(testScores + counter) < 0 || !cin){
            // Helps in clearing the error flags which are set when cin fails to interpret the input.
            cin.clear();
            // Helps in removing the input contents that could've caused the read failure
            cin.ignore(1000,'\n');
            cout << "ERROR! Invalid input. Please enter valid inputs: ";
            cin >> *(testScores + counter);
        }
    }
    cout << "-------------------------------------------------" << endl;
    // Sorting the test scores with sort function
    ascendingSort(testScores, numTests);

    // To ensure output has 2 decimal space formatting
    cout << fixed << setprecision(1);

    // Output array
    cout << "Ascending Order of Test Scores: \n";
    for(int counter = 0; counter < numTests; counter++){

        cout << *(testScores + counter) << " ";
    }
    cout << endl;
    cout << "\n-------------------------------------------------" << endl;

    // Output Average Score
    cout << "Average Score: " << calcAverage(testScores, numTests) << endl;

    cout << "\n-------------------------------------------------" << endl;
    cout << "Thank You!" << endl;
    cout << "-------------------------------------------------" << endl;

    // Terminating program
    return 0;
}