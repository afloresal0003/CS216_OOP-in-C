/*
    Programmer: Anthony Flores-Alvarez
    Course: CS 216 - OOP in C++
    Date: October 10, 2020
    Description: This program takes a string representing the month name and
    an integer representing a day of the year and tells you the day of the year it is, 
    the day that came before, and the day that came after it. 
*/

// Header files for program functionality
#include <iostream>
#include <string>

// Allows us to not have to use std:: throughout program
using namespace std;

// Constant integer for the size of our arrays
const int NUM_MONTHS = 12;

// Constant integer for the size of our arrays
class DayOfYear{
    
    private:
        const static string monthNames[NUM_MONTHS];
        const static int maxDaysInMonth[NUM_MONTHS];
       
        string month;            // To hold a month name
        int day;                    // To hold a day
        int dayNum;                 // To hold day number
        int arrayIndex;            // Stores an array index
        int count = 0;

    public:
        // Constructor
        DayOfYear(string, int);
       
        // Member functions
        bool validMonth(string);
        void print();

        // Getter for the month 
        string getMonth() const{ 
            
            return month; 
        }
        
        // Getter for the day
        int getDay() const{ 
            
            return day; 
        }
        
        // ++ preﬁx and postﬁx increment operators.
        /*  modifies the DayOfYear object so that it represents the next day. 
            If the day is already the end of the year, the new value of the 
            object will represent the ﬁrst day of the year. */
        DayOfYear operator++();
        DayOfYear operator++(int);
        
        // --  preﬁx and postﬁx decrement operators.
        /*  modifies the DayOfYear object so that it represents the previous day.
            If the day is already the ﬁrst day of the year, the new value of the 
            object will represent the last day of the year. */
        DayOfYear operator--();
        DayOfYear operator--(int);

};

// Definition of const static array member holding month names
const string DayOfYear::monthNames[] = {"January", "February", "March", "April", 
                                         "May", "June", "July", "August", "September", 
                                         "October", "November", "December"};

// Definition of const static array member holding the maximum day in each month 
const int DayOfYear::maxDaysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Constructor that takes two parameters: a string representing a month and an integer in the
// range 0 through 31 representing the day of the month.
DayOfYear::DayOfYear(string userMonth, int userDay){
    
    // Checks if valid month was entered
    if (validMonth(userMonth) == true){
        
        month = userMonth;
    }
    
    // Error message if not a valid month name
    else{
        
        cout << "\nError! " << userMonth << " is not a month." << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "Recall that all input is case sensitive and must" << endl;
        cout << "follow the format shown at the beginning of this program." << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "Please restart the program and try again!" << endl;
        exit(0);
    }
   
    // Checks if valid day was entered
    if (userDay >= 1 && userDay <= maxDaysInMonth[arrayIndex]){
        
        day = userDay;
    }
    
    // Error message if not a valid day
    else{
        
        cout << "\nError! " << userMonth << " starts with the 1st and has " << maxDaysInMonth[arrayIndex] << " days." << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "Therefore, enter a valid positive integer within this range." << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "Please restart the program and try again!" << endl;
        exit(0);
    }
    
    // Loops through month and day arrays to determine the day of the year number
    for (int i = 0; i < 12; i++){
           
           // Checks for userMonth in the months of the year
           if (monthNames[i] == userMonth){
               
               // Checks for userDay in the days of the respective month found
               if ( userDay > 0 && userDay <= maxDaysInMonth[i]){

                   dayNum = 0;
                   
                   for (int j = 0; j < i; j++){
                       
                       dayNum = dayNum + maxDaysInMonth[j];
                   }
                   
                   dayNum = dayNum + userDay;
                   cout << "\n-------------------------------------------------" << endl;
                   cout << "Day Number: " << dayNum << endl;
                   cout << "-------------------------------------------------" << endl;
               }
               
               // Error message if none was found
               else{
                   cout<<"Incorrect date or Day"<<endl;
                   exit(0);
               }
           }
    }
}

// User month is compared against
// the values in the monthNames array.
bool DayOfYear::validMonth(string userM){
    
    for (int count = 0; count < NUM_MONTHS; count++){
        
        if (userM == monthNames[count]){
            
            arrayIndex = count;
            return true;
        }
    }
    
    return false;
}

// Prefix ++
DayOfYear DayOfYear::operator++(){
    
    // Case when at the end of the year
    if (month == "December" && day == 31){
        arrayIndex = 0;
        month = monthNames[arrayIndex];
        day = 0;
    }
    
    else if (day == maxDaysInMonth[arrayIndex]){
        month = monthNames[++arrayIndex];
        day = 0;
    }
    
    ++day;

    return *this;
}


// Postfix ++
DayOfYear DayOfYear::operator++(int){
    
    DayOfYear temp = *this;
   
    // Case when at the end of the year
    if (month == "December" && day == 31){
        arrayIndex = 0;
        month = monthNames[arrayIndex];
        day = 0;
    }
    
    else if (day == maxDaysInMonth[arrayIndex]){
        month = monthNames[++arrayIndex];
        day = 0;
    }
    
    day++;

    return temp;
}

// Prefix --
DayOfYear DayOfYear::operator--(){
    
    if (day == 1){
        
        // Case when at the beginning of the year
        if (month == "January" && day == 1){
        
            arrayIndex = 11;
            month = monthNames[arrayIndex];
            day = 31;
        }
    
        else{       
       
            month = monthNames[--arrayIndex];
            day = maxDaysInMonth[arrayIndex];
        }
    }
    
    else{
        
        --day;
    }
    
    return *this;
}

// Postfix --
DayOfYear DayOfYear::operator--(int){
    
    DayOfYear temp = *this;

    if (day == 1){
        // Case when at the beginning of the year
        if (month == "January" && day == 1){
        
            arrayIndex = 11;
            month = monthNames[arrayIndex];
            day = 31;
        }
    
        else{       
       
            month = monthNames[--arrayIndex];
            day = maxDaysInMonth[arrayIndex];
        }
    }
    
    else{
        
        day--;
    }

    return temp;
}

// Function outputs month and day to screen.
void DayOfYear::print(){
    
    cout << getMonth() << " " << getDay() << ".";
}

// Main Function
int main(){
    
    // Heading
    cout << "-------------------------------------------------" << endl;
    cout << "Welcome to MODIFIED Day Number to Month-Day Calculator!" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "Notes:" << endl;
    cout << "- All input is case sensitive!" << endl;
    cout << "- Please enter a month name and day in the following format: " << endl;
    cout << "   -> 'January 1', 'April 10', 'December 31', etc." << endl;
    cout << "-------------------------------------------------" << endl;
    
    int day = 0;
    string monthName = "";

    // Asking for the calendar day of the year
    cout << "Please enter a month name and day: ";
    cin >> monthName >> day;

    // Create a DayOfYear object and passing the user input which will then print out the day number of the year
    DayOfYear dayOne(monthName, day);

    // The day before output
    cout << "Previous Day: ";
    --dayOne;
    dayOne.print();
    cout << "\n-------------------------------------------------" << endl;

    // Day after output
    cout << "Day After: ";
    dayOne++;
    dayOne++;
    dayOne.print();
    cout << "\n-------------------------------------------------" << endl;
    cout << "Thank you! : )" << endl;
    cout << "-------------------------------------------------" << endl;

    // Terminate program
    return 0;
}