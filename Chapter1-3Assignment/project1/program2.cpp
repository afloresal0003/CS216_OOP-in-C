/*
    Programmer: Anthony Flores-Alvarez
    Course: CS 216 - OOP in C++
    Date: September 3, 2020
    Description: This program calculates a theater’s gross and net
                 box ofﬁce proﬁt for a night by asking for the name of the movie, 
                 and how many adult and child tickets were sold.
*/

// Header files needed for program functionality
#include <iostream> 
#include <string>
#include <iomanip>
using namespace std;

// Main function
int main(){
    cout << endl;

    // Variables used for appearance enhancement
    string welcome = "Welcome! ";
    string report = "Box Office Profit: ";
    string closing = "Have a nice day :) !";
    string borders;

    // Outputs the welcome heading
    borders.assign(welcome.length(), '-');
    cout << borders << endl;
    cout << welcome << endl;
    cout << borders << endl;

    // Constant variables given by problem
    double adultTicketCost = 6.00;
    double childTicketCost = 3.00;
    double theaterPercentKept = 0.20;
    
    // Variables used to store values
    double adultTicketAmt,
           childTicketAmt,
           grossRevenue,
           distributorRevenue,
           netTheaterRevenue;
    string movieName;
    
    // Getting the user input
    cout << "\nEnter the name of the movie: ";
    getline(cin, movieName);
    cout << "\nEnter how many Adult tickets were sold for " << movieName << ": ";
    cin >> adultTicketAmt;
    cout << "\nEnter how many Child tickets were sold for " << movieName << ": ";
    cin >> childTicketAmt;

    // Calculations
    grossRevenue = (adultTicketAmt * adultTicketCost) + (childTicketAmt * childTicketCost);
    netTheaterRevenue = grossRevenue * theaterPercentKept;
    distributorRevenue = grossRevenue - netTheaterRevenue;

    // Outputs the box office report heading
    borders.assign(report.length(), '-');
    cout << endl;
    cout << borders << endl;
    cout << report << endl;
    cout << borders << endl;
    cout << endl;

    //Outputs results
    cout << setw(30) << left << "Movie Name: " << setw(15) << right << movieName << endl;
    cout << setw(30) << left << "Adult Tickets Sold: " << setw(15) << right << adultTicketAmt << endl;
    cout << setw(30) << left << "Child Tickets Sold: " << setw(15) << right << childTicketAmt << endl;
    cout << fixed << showpoint << setprecision(2);    
    cout << setw(30) << left << "Gross Box Office Profit: " << setw(10) << right << "$" << grossRevenue << endl;
    cout << setw(30) << left << "Amount Paid to Distributor: " << setw(10) << right << "$" <<  distributorRevenue << endl;
    cout << setw(30) << left << "Net Box Office Profit: " << setw(10) << right << "$" <<  netTheaterRevenue << endl;

    // Outputs the closing heading
    borders.assign(closing.length(), '-');
    cout << endl;
    cout << borders << endl;
    cout << closing << endl;
    cout << borders << endl;
    cout << endl;

    //Exits main function
    return 0;
}