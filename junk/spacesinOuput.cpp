//This program illustrates the use of the left and right manipulators
#include <iostream> 
#include <iomanip> //Header file needed to use stream manipulators 
#include <string> //Header file needed to use string objects
using namespace std;

int main(){

    string month1 = "January",
            month2 = "February",
            month3 = "March";

    int days1 = 31, 
        days2 = 28,
        days3 = 31;

    double high1 = 22.6, 
            high2 = 37.4,
            high3 = 53.9;
    
    cout << fixed << showpoint << setprecision(1);
    cout << left << setw(12) <<"Month" << right << setw(4) << "Days " << setw(9) << "High\n";
    cout << left << setw(12) << month1 
         << right << setw(4) << days1 << setw(9) << high1 << endl;
    cout << left << setw(12) << month2 
         << right << setw(4) << days2 << setw(9) << high2 << endl;
    cout << left << setw(12) << month3 
         << right << setw(4) << days3 << setw(9) << high3 << endl;
    cout << left << setw(1) << " " <<right << setw(50) << "Hello"<< endl;
    return 0;
}