/*
    Programmer: Anthony Flores-Alvarez
    Course: CS 216: OOP in C++
    Date: September 24, 2020
    Description: This program will calculate and output the
    charges for a patient's hospital stay, through retrieval
    of user input, such as daily rate and medication charges.
    This program will use overloaded functions to compute the 
    total charges for the patienets. Input will also be validated 
    using a separate function.
*/
// Header files for program functionality
#include <iostream>
#include <iomanip>

/* Using standard notation, helps us avoid constantly using
 the "std::" syntax */
 using namespace std;

// Function to ensure that input is not less than 0
double validateInput(double input){
    // If there is a negative number or input that is not a number...
    if (input < 0 || cin.fail()){
        // ...loop until correct input is inputted.
        while (input<0 || cin.fail()){
            cin.clear();
            cin.ignore(10000,'\n');            
            cout << "Enter a positive number: ";
            cin >> input;
        }
    }

    // Return the validated input
    return input;
}

// Overloaded function 1 to calculate the charges for an in-patient
double calculateCharges(double days, double rate, double hospitalCosts, double medicationPrice){
    double totalCharges;
    totalCharges = (days * rate) + hospitalCosts + medicationPrice;
    return totalCharges;
}

// Overloaded function 2 to calculate the charges for an out-patient
double calculateCharges(double hospitalCosts, double medicationPrice){
    double totalCharges;
    totalCharges = hospitalCosts + medicationPrice;
    return totalCharges;
}

// Main Function
int main(){
    // Header to make the UI/program look nice
    cout << "\n-----------------------------------" << endl;
    cout << "Welcome to Hospital Stay Calculator!" << endl;
    cout << "-----------------------------------" << endl;
    // Variables to store user input
    char patientStatus;
    double numDays,
           dailyRate,
           serviceCosts,
           medicationCosts;

    // Determine patient status (in or out)
    cout << "Was the patient admitted as in-patient ('I') or an out-patient ('O')?: ";
    cin >> patientStatus;
    cout << "-----------------------------------" << endl;

    // Actions if patient is an in-patient
    if(patientStatus == 'I' || patientStatus == 'i'){
        /* 
            - Collect and store user inputs for days spent in hospital, 
              hospital rate, hospital costs, and medication costs 
            - Then ensure every input is a positive number
        */

        cout << "Enter the number of days they spent in the hospital: ";
        cin >> numDays;
        numDays = validateInput(numDays);

        cout << "\nEnter the daily rate: $";
        cin >> dailyRate;
        dailyRate = validateInput(dailyRate);

        cout << "\nEnter the charges for hospital services (lab tests, etc.): $";
        cin >> serviceCosts;
        serviceCosts = validateInput(serviceCosts);

        cout << "\nEnter the hospital medication charges: $";
        cin >> medicationCosts;
        medicationCosts = validateInput(medicationCosts);

        // Display the total charges for the in-patient with 2 spaces after decimal
        cout << "\n-----------------------------------" << endl;
        cout << fixed << setprecision(2);
        cout << "Total Charges: $" << calculateCharges(numDays, dailyRate, serviceCosts, medicationCosts) << endl;
        cout << "-----------------------------------" << endl;
        cout << "Thank you for using Hospital Stay Calculator! :)" << endl;
        cout << "-----------------------------------\n" << endl;
    }
    // Actions if patient is an out-patient
    else if(patientStatus == 'O' || patientStatus == 'o'){
        
        /* 
           - Collect and store user inputs for hospital and medication costs
           - Then ensure every input is a positive number
        */
        cout << "\nEnter the charges for hospital services (lab tests, etc.): $";
        cin >> serviceCosts;
        numDays = validateInput(serviceCosts);

        cout << "\nEnter the hospital medication charges: $";
        cin >> medicationCosts;
        medicationCosts = validateInput(medicationCosts);

        // Display the total charges for the out-patient with 2 spaces after decimal
        cout << "-----------------------------------" << endl;
        cout << fixed << setprecision(2);
        cout << "\nTotal Charges: $" << calculateCharges(serviceCosts, medicationCosts) << endl;
        cout << "-----------------------------------" << endl;
        cout << "Thank you for using Hospital Stay Calculator! :)" << endl;
        cout << "-----------------------------------\n" << endl;
   }

    // If any other input is entered, prompt them to enter correct input
    else{
        cin.clear();
        cin.ignore(10000,'\n');
        cout << "Sorry! Please enter 'I' or 'O'."  << endl;
        cout << "-----------------------------------" << endl;
        main();
    }

    // Terminate program
    return 0;
}
