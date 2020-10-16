/*
    Programmer: Anthony Flores-Alvarez
    Course: CS 216: OOP in C++
    Date: September 13, 2020
    Description: This program reads data from the file
    employeeSalary.txt about employee pay increases, and
    stores the output in the file employeeOutput.txt.

    The output follows the following format: 
    - firstName lastName updatedSalary (with 2 decimal places)

    It'll also print these results
*/

// Header files for program functionality
#include <iostream>
#include <iomanip>
#include <fstream>

/* Using standard notation, helps us avoid constantly using
 the "std::" syntax */
using namespace std;

// Main Function
int main(){
    cout << "\n-----------------------------------" << endl;
    cout << "Welcome to Employee Salary Updater!" << endl;
    cout << "-----------------------------------" << endl;
    
    /* Variables that will hold the names of our 
    employees from the input file */
    string empOneFirstName, 
           empOneLastName,

           empTwoFirstName,
           empTwoLastName,

           empThreeFirstName,
           empThreeLastName;

    /* Variables that will hold the starting salaries, percent
    pay increases, and final/updated salaries of our 
    employees from the input file */
    double empOneStartSalary, 
           empOnePayIncrease,
           empOneFinalSalary,

           empTwoStartSalary, 
           empTwoPayIncrease,
           empTwoFinalSalary,

           empThreeStartSalary, 
           empThreePayIncrease,
           empThreeFinalSalary;

    cout << "Opening employeeSalary.txt..." << endl;
    
    // INPUT FILE
    // File stream object  
    ifstream employeeInputFile;
    // Open the input file
    employeeInputFile.open("employeeSalary.txt");
    
    cout << "\nOpening employeeOutput.txt..." << endl;
    
    // OUTPUT FILE 
    // File stream object
    ofstream employeeOutputFile;
    // Open the output file
    employeeOutputFile.open("employeeOutput.txt");

    // Reading each employee's info from the file 
    employeeInputFile >> empOneLastName >> empOneFirstName >> empOneStartSalary >> empOnePayIncrease;
    employeeInputFile >> empTwoLastName >> empTwoFirstName >> empTwoStartSalary >> empTwoPayIncrease;
    employeeInputFile >> empThreeLastName >> empThreeFirstName >> empThreeStartSalary >> empThreePayIncrease;

    cout << "\nCalculating updated salaries..." << endl;
    
    // Calculating each employee's final salaries
    empOneFinalSalary = empOneStartSalary + ((empOneStartSalary * empOnePayIncrease) / 100);
    empTwoFinalSalary = empTwoStartSalary + ((empTwoStartSalary * empTwoPayIncrease) / 100);
    empThreeFinalSalary = empThreeStartSalary + ((empThreeStartSalary * empThreePayIncrease) / 100);

    // Printing the updated salaries of each employee
    cout << "-----------------------------------" << endl;
    cout << "Your updated salaries: " << endl;
    cout << " " << endl;
    cout << fixed << showpoint << setprecision(2);
    cout << empOneLastName << " " << empOneFirstName << " " << empOneFinalSalary << endl;
    cout << empTwoLastName << " " << empTwoFirstName << " " << empTwoFinalSalary << endl;
    cout << empThreeLastName << " " << empThreeFirstName << " " << empThreeFinalSalary << endl;
    cout << "-----------------------------------" << endl;
    cout << "\nStoring updated salaries in employeeOutput.txt..." << endl;
    
    // Writing the employees' info to the output file
    // Allows us to have the 2 spaces after the decimal
    employeeOutputFile << fixed << showpoint << setprecision(2);
    employeeOutputFile << empOneLastName << " " << empOneFirstName << " " << empOneFinalSalary << endl;
    employeeOutputFile << empTwoLastName << " " << empTwoFirstName << " " << empTwoFinalSalary << endl;
    employeeOutputFile << empThreeLastName << " " << empThreeFirstName << " " << empThreeFinalSalary << endl;

    cout << "\n-----------------------------------" << endl;
    cout << "\nClosing employeeSalary.txt..." << endl;
    cout << "\nClosing employeeOutput.txt..." << endl;
    
    // Closing our files
    employeeInputFile.close();
    employeeOutputFile.close();
    
    cout << "\n-----------------------------------" << endl;
    cout << "Thank you for choosing Employee Salary Updater! :)" << endl;
    cout << "-----------------------------------" << endl;
    cout << " " << endl;

    // Terminate program
    return 0;
}