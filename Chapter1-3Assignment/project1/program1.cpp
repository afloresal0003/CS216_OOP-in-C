/*
    Programmer: Anthony Flores-Alvarez
    Course: CS 216 - OOP in C++
    Date: September 1, 2020
    Description: This program is an I/O program
                 that asks the user for pay rate/hr and num hours
                 then outputs a list of things, such as income 
                 before and after taxes. 
    Notes: I wanted to challenge myself a bit and see if I recalled 
           how to use classes that's why I used one in this program.
           I hope that does not cause any inconveniences.
*/

//Header files used for program functionality
#include <iostream> 
#include <iomanip>
#include <string>
using namespace std;

// Creating a class called employeeExpenses
class employeeExpenses{
    private:
        // Member Variables given by problem: 
        double weeksWorked;
        double taxRate;
        double clothesPrcnt;
        double schoolSupPrcnt;
        double yourSavingsPrct;
        double parentSpendPrct;

        // Other Member Variables to store essential values:
        double payRate,
               hoursWorked,
               grossInc,
               adjustedInc,
               clothesAmt,
               schoolSupAmt,
               yourSavAmt,
               parentSpendAmt;
    public:
    // Constructor to set initial member variables' values:
        employeeExpenses(){
            weeksWorked = 5;
            taxRate = 0.14;
            clothesPrcnt = 0.10;
            schoolSupPrcnt = 0.01;
            yourSavingsPrct = 0.25;
            parentSpendPrct = 0.50;
        }
        // Member Functions :

        //Set functions to allow me to modify the values of some of the private member variables
        void setPayRate(){
            cout << "\nPlease enter your pay rate for an hour: $";
            cin >> payRate;
        }
        void setHoursWorked(){
            cout << "\nPlease enter the number of hours you worked each week: ";
            cin >> hoursWorked;
        }

        //Get functions to calculate and return the desired values to the user
        double getGrossInc(){ 
            grossInc = (payRate * hoursWorked) * weeksWorked; 
            return grossInc;
        }
        double getAdjustedInc(){
            adjustedInc = grossInc - (grossInc * taxRate);
            return adjustedInc;
        }
        double getClothesAmt(){
            clothesAmt = adjustedInc * clothesPrcnt;
            return clothesAmt;
        }
        double getSchoolSuppAmt(){
            schoolSupAmt = adjustedInc * schoolSupPrcnt;
            adjustedInc -= (schoolSupAmt + clothesAmt);
            return schoolSupAmt;
        }
        double getYourSavAmt(){
            yourSavAmt = adjustedInc * yourSavingsPrct;
            return yourSavAmt;
        }
        double getParentSpendAmt(){
            parentSpendAmt =  (static_cast<int>(yourSavAmt)) * parentSpendPrct;
            return parentSpendAmt;
        }

};

// Main function
int main(){
    cout << endl;

    // Variables used for appearance enhancement
    string welcome = "Welcome! ";
    string report = "5 WEEK REPORT: ";
    string closing = "Goodbye !";
    string borders;

    // Outputs the welcome heading
    borders.assign(welcome.length(), '-');
    cout << borders << endl;
    cout << welcome << endl;
    cout << borders << endl;

    //Creates an employee object and sets pay rate & hours worked of object/employee
    employeeExpenses employeeOne;
    employeeOne.setPayRate();
    employeeOne.setHoursWorked();

    // Outputs the report heading
    cout << endl;
    borders.assign(report.length(), '-');
    cout << borders << endl;
    cout << report << endl;
    cout << borders << endl;

    // Outputs results
    cout << "\n(a1) Your income before taxes: $" << fixed << showpoint << setprecision(2) << employeeOne.getGrossInc() << endl;
    cout << "\n(a2) Your income after taxes: $" << fixed << showpoint << setprecision(2) << employeeOne.getAdjustedInc() << endl;
    cout << "\n(b) Money spent on clothes and other accessories: $" << fixed << showpoint << setprecision(2) << employeeOne.getClothesAmt() << endl;
    cout << "\n(c)Money spent on school supplies: $"<< fixed << showpoint << setprecision(2) << employeeOne.getSchoolSuppAmt() << endl;
    cout << "\n(d) Money spent to buy savings bonds: $" << fixed << showpoint << setprecision(2) << employeeOne.getYourSavAmt() << endl;
    cout << "\n(e) Money your parents spent to buy additional savings bonds for you: $" << fixed << showpoint << setprecision(2) << employeeOne.getParentSpendAmt() << endl;
    
    // Outputs the closing heading
    cout << endl;
    borders.assign(closing.length(), '-');
    cout << borders << endl;
    cout << closing << endl;
    cout << borders << endl;
    cout << endl;

    //Closes program
    return 0;
}