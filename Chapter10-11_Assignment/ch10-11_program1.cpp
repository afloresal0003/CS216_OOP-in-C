/*
    Programmer: Anthony Flores-Alvarez
    Course: CS 216 - OOP in C++
    Date: October 10, 2020
    Description: This program takes an integer representing a day of the year and 
    translates it to a string consisting of the month followed by using a class.
*/

// Header files for program functionality
#include <iostream>
#include <string>

// Allows us to not have to use std:: throughout program
using namespace std;

// Constant integer for the size of our arrays
const int NUM_MONTHS = 12;

// Creating DayOfYear Class
class DayOfYear{
    
    private:
        const static string monthNames[NUM_MONTHS];
        const static int maxDaysInMonth[NUM_MONTHS];
 
        int day;         // To hold a day
        int month = 0;   // To hold month num
        
    public:
    
        // Constructor
        DayOfYear(int);
    
        // Print function that prints the day in the month-day format
        void print();
};

// Definition of const static array member holding month names
const string DayOfYear::monthNames[] = {"January", "February", "March", "April",
                                   "May", "June", "July", "August", "September", 
                                   "October", "November", "December"};
                                
// Definition of const static array member holding the maximum day in each month 
const int DayOfYear::maxDaysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Constructor take as parameter an integer representing the day of the year
DayOfYear::DayOfYear(int userDay){
            
            day = userDay;

}
        
void DayOfYear::print(){
            
            /*
                Subtracting by the number of days for each month
                until no more whole months
            */
            for (int i = 0; i < 12; i++){
                
                // Exiting if there are no more whole months left
                if (day <= maxDaysInMonth[i])
                    break;
                    
                else{
                    
                    // Subtracting number of days of that month
                    day -= maxDaysInMonth[i];
                    // Incrementing number of months
                    month++;
                }
            }
    
            // Displaying the month day result
            cout << monthNames[month] << " " << day;
}

// MAIN Function
int main()
{
    // Heading
    cout << "-------------------------------------------------" << endl;
    cout << "Welcome to Day Number to Month-Day Calculator!" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "Notes: " << endl;
    cout << "- Please ensure that all inputs are positive integers within " << endl;
    cout << "  the range of 1 to 365. No other input will be accepted." << endl;
    cout << "-------------------------------------------------" << endl;

    // Asking the user for the day number
    int userDay;
    cout << "\nPlease enter a day number between 1-365: ";
    cin >> userDay;
    
    // Ensuring that the user enters a valid input
    while (userDay < 1 || userDay > 365){
        // Helps in clearing the error flags which are set when cin fails to interpret the input.
        cin.clear();
        // Helps in removing the input contents that could've caused the read failure
        cin.ignore(1000,'\n');
        cout << "Error! Invalid input. Please enter a valid input: ";
        cin >> userDay;
    }

    // Initializing a DayOfYear object with passing of user's number
    DayOfYear userDaybObj(userDay);
    
    // Displaying the corresponding month and day
    cout << "\n-------------------------------------------------" << endl;
    cout << "Day " << userDay << " would be ";
    userDaybObj.print();
    cout << "\n-------------------------------------------------" << endl;
    cout << "Thank you! : )" << endl;
    cout << "-------------------------------------------------" << endl;

    // Terminating the program
    return 0;
}