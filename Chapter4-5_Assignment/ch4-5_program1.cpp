/*
    Programmer: Anthony Flores-Alvarez
    Course: CS 216: OOP in C++
    Date: September 13, 2020
    Description: This program will output a series of results, such as 
    cost of renting a room, discount on each room, total cost of rooms, etc.,
    that are all based on the price of renting a hotel room and 
    certain discounts appropiated by the amount of rooms booked
    and how many days booked.
*/

// Header file for program functionality
#include <iostream>

/* Using standard notation, helps us avoid constantly using
 the "std::" syntax */
using namespace std;

// Constants to store discount percentages
const float TEN_DISCOUNT = 0.10;
const float TWENTY_DISCOUNT = 0.20;
const float THIRTY_DISCOUNT = 0.30;
const float ADDITIONAL_DISCOUNT = 0.05;

// Main Function
int main(){

    // Header to make the UI/program look nice
    cout << "\n-----------------------------------" << endl;
    cout << "Welcome to Hotel Bill Calculator!" << endl;
    cout << "-----------------------------------" << endl;

    // Variables to store user and calculated input
    float rentCost, 
          taxPercentage;

    int numRoomsBooked, 
        numDaysBooked;

    float roomCost = 0,
          roomDiscount = 0,
          totalRoomsCost = 0,
          totalSalesTax = 0,
          totalBillAmt = 0;
    
    // Inputs
    cout << "\nEnter the cost of renting one room: $";
    cin >> rentCost;

    cout << "Enter the number of rooms you booked: ";
    cin >> numRoomsBooked;

    cout << "Enter number of days the rooms were booked: ";
    cin >> numDaysBooked;

    cout << "Enter the sales tax % (EX: 15% -> enter: '15'): ";
    cin >> taxPercentage;

    // Figuring out the discount % depending on the number of rooms booked
    if (numRoomsBooked >= 10){
        roomDiscount = TEN_DISCOUNT;
    }
    else if (numRoomsBooked >= 20){
        roomDiscount = TWENTY_DISCOUNT;
    }
    else if (numRoomsBooked >= 30){
        roomDiscount = THIRTY_DISCOUNT;
    }
    else{
        roomDiscount = 0;
    }

    // Figuring out if the additional discount will be applicable
    if (numDaysBooked >= 3){
        roomDiscount += ADDITIONAL_DISCOUNT;
    }
    
    // Calculating the cost of renting one room
    roomCost = rentCost - (rentCost * roomDiscount);

    // Calculating the total cost for all the rooms
    totalRoomsCost = roomCost * numRoomsBooked * numDaysBooked;

    // Calculating the sales tax
    totalSalesTax = totalRoomsCost * (taxPercentage / 100);

    // Calculating the total billing amount
    totalBillAmt = totalRoomsCost + totalSalesTax;

    // Outputs
    cout << "\n-----------------------------------" << endl;
    cout << "\nRECEIPT: " << endl;
    cout << "\nCost of renting one room: $" << roomCost << endl;
    cout << "\nNumber of rooms booked: " << numRoomsBooked << endl;
    cout << "\nNumber of days rooms were booked: " << numDaysBooked << endl;
    cout << "\nYour discount on each room: " << (roomDiscount * 100) << "%" << endl;
    cout << "\nTotal cost of rooms: $" << totalRoomsCost << endl;
    cout << "\nTotal Sales Tax: $" << totalSalesTax << endl;
    cout << "\nTotal Billing Amount: $" << totalBillAmt << endl;

    // Footer to make UI/program look nice
    cout << "\n-------------------------------------------" << endl;
    cout << "Thank you for using Hotel Bill Calculator! :)" << endl;
    cout << "---------------------------------------------" << endl;
    cout << " " << endl;

    // Terminate program
    return 0;
}