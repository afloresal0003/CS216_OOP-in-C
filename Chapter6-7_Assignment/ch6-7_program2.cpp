/*
    Programmer: Anthony Flores-Alvarez
    Course: CS 216: OOP in C++
    Date: September 25, 2020
    Description: This program will create an Inventory class that
    will hold info for an item in a retail store's inventory. It
    will also ensure that all user inputs are not negative values.
*/

class Inventory
{
    //Private member variables that will be used
private:
    // An int that holds the item’s number.
    int _itemNumber;
    // An int that holds the quantity of the item on hand.
    int _quantity;
    // A double that holds the wholesale per-unit cost of the item
    double _cost;
    // A double that holds the total cost
    double _totalCost;
    
public:
    // Default constructor that sets all the member variables to 0.
    Inventory(){
        _itemNumber = 0;
        _quantity = 0;
        _cost = 0;
        _totalCost = 0;
    }

    /* Constructor #2 that:
        - Accepts an item’s number, quantity, and cost as arguments. 
        - Calls other class functions to copy these values into the appropriate member variables.                                            
        - Then calls the setTotalCost function.
    */
    Inventory(int newItemNumber, int newQuantity, double newCost){
        _itemNumber = newItemNumber;
        _quantity = newQuantity;
        _cost = newCost;
        setTotalCost(_quantity, _cost);
    }

    // Class functions

    // Accepts an int argument and copies it into the itemNumber member variable.
    void setItemNumber(int itemNumber){
        _itemNumber = itemNumber;
    }
    // Accepts an int argument and copies it into the quantity member variable.
    void setQuantity(int quantity){
        _quantity = quantity;
    }
    // Accepts a double argument and copies it into the cost member variable.
    void setCost(double cost){
        _cost = cost;
    }
    /* Calculates the total cost and then assigns the total
        calculated cost to the private member variable of 
        total cost */
    void setTotalCost(int quantity, double cost){
        _totalCost = getTotalCost(quantity, cost);
    }
    
    // Returns the value in itemNumber.
    int getItemNumber(){
        return _itemNumber;
    }
    //  Returns the value in quantity.
    int getQuantity(){
        return _quantity;
    }
    // Returns the value in cost.
    double getCost(){
        return _cost;
    }
    // Computes and returns the totalCost.
    double getTotalCost(int quantity, double cost){
        _totalCost = quantity * cost;
        return _totalCost;
    }
};

// Header files for program functionality
#include <iostream>
#include <iomanip> 
/* Using standard notation, helps us avoid constantly using
 the "std::" syntax */
using namespace std;

// Ensures input is a positive number
double validateInput(double input){
    if (input < 0 || cin.fail()){
        while (input < 0 || cin.fail()){
                cin.clear();
                cin.ignore(10000,'\n'); 
                cout << "Error. Please enter a positive value: ";
                cin >> input;
            }
    } 
    return input;
}

// Main function
int main()
{
    //TITLE and intro to program
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "                        Welcome to the Inventory Class!" << endl;
    //DESCRIPTION of program
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "REGULATIONS: " << endl;
    cout << "This program holds the information for an item in a retail store's inventory." << endl;
    cout << "Enter your item's information such as the item number, item quantity, and " << endl;
    cout << "item's cost." << endl;
    cout << "The program will calculate your total cost." << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "                     * Please enter positive numbers only! *" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    
    //BEGINNING of the program 
    cout << "PROCESS: " << endl;
    //Declares variables for inventory number, quantity, cost
    //within the main function
    double itemNumber, 
           quantity,
           cost,
           totalCost;
    
    //Creates an Inventory object using the default constructor
    Inventory();       
    {
        double itemNumber = 0;
        double quantity = 0;
        double cost = 0;
        double totalCost = 0;
    }
        //Collects and validates the item number
        cout << "Please enter the item number: ";	
        cin >> itemNumber;
        itemNumber = validateInput(itemNumber);

        //Collects and validates the item quantity
        cout << "Please enter the item quantity: "; 
        cin >> quantity;
        quantity = validateInput(quantity);

        //Collects and validates the item cost
        cout << "Please enter the item cost: $"; 
        cin >> cost;
        cost = validateInput(cost);

        //Passes all user-collected data into an information object
        Inventory information(itemNumber, quantity, cost);
        
        totalCost = information.getTotalCost(quantity, cost);
        //Changes the inventory number using the setItemNumber() member function
        itemNumber = information.getItemNumber();   
        //Changes the quantity using the setQuantity() member function
        quantity = information.getQuantity();    
        //Changes the cost using the setCost() member function
        cost = information.getCost();  
        
        // DISPLAY 
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "                               Transaction Summary" << endl;   
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "Item Number: " << itemNumber << endl;
        cout << "Item Quantity: " << quantity << endl;
        cout << "Item Cost: " << cost << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        // Displays the total cost with value two decimal spaces after the zero
        cout << fixed << showpoint << "Total Cost: $" << setprecision(2) << totalCost << endl;  
        cout << "--------------------------------------------------------------------------------" << endl;
        
        // Terminate program
        return 0;
    }