/* 
 Programmer: Anthony Flores-Alvarez
 Course: CS216 - OOP in C++
 Date: October 5, 2020
 Description: This program simulates and manages a soft drink machine.
 It allows the user to choose from soft drinks and complete the
 transaction. The program will also report the daily report which will
 tell the machine manager about the sales report for that day.
*/
// Header files for program functionality
#include <iostream>
#include <iomanip>
#include <string>

/* Using standard notation, helps us avoid constantly using
 the "std::" syntax */
using namespace std;

/* 
    Structure that has data members to hold the drink name, 
    the drink price, and the number of drinks of that type 
    currently in the machine. 
*/
struct drinks{
    string nameOfBeverage;
    int beverageQuantity;
    float beveragePrice;
};

// Class that simulates the soft drink machine with functions that each 
// do something different. 
class machine{

    private:
        // The drinks that our machine will have (with names, quantity, and price)
        drinks menu[5] = {{"Cola", 20, 1.00},
                       {"Root Bear", 20, 1.00},
                       {"Orange Soda", 20, 1.00},
                       {"Grape Soda", 20, 1.50},
                       {"Bottled Water", 20, 1.50}};
        float netProfit = 0;

        // Called by buyDrink() to accept, validate, and return (to buyDrink) the amount of money input
        float inputMoney(int drinkChoice){
            float money;
            cout << "Enter amount you are paying: $";
            cin >> money;
            while(!(money >= menu[drinkChoice].beveragePrice) || cin.fail()){
                cin.clear();
                cin.ignore(10000,'\n');
                cout << "\n----------------------------------------------" << endl;
                cout << "Error! Not enough money. Please insert $" << fixed << setprecision(2) << menu[drinkChoice].beveragePrice << " or more: $";
                cin >> money;
            }
            return money;
        }

        // Called by destructor to report how many of each drink type remain in the machine
        // at the end of the day and how much money was collected.
        void dailyReport(){
            cout << "\n----------------------------------------------" << endl;
            cout << "Drink Machine Daily Report: " << endl;
            cout << "----------------------------------------------" << endl;
            for(int i = 0; i < 5; i++){
                cout << menu[i].nameOfBeverage << " Quantity: " << menu[i].beverageQuantity << endl;
                cout << endl;
            }
            cout << "Total amount collected: $" << fixed << setprecision(2) << netProfit << endl;
            cout << "----------------------------------------------" << endl;
            cout << endl;
        }

    public:
        // Displays menu of drink names and prices
        void displayChoices(){
            cout << "\n----------------------------------------------" << endl;
            cout << "Anthony's Beverages Menu :)\n";
            cout << "----------------------------------------------" << endl;
            cout << "Item #      Name ($Price)" << endl;
            for(int i = 0; i < 5; i++){
                cout << i+1 << ")          " << menu[i].nameOfBeverage << " ($" << fixed << setprecision(2) << menu[i].beveragePrice << ")         " << endl;
            }
            cout << "----------------------------------------------" << endl;
            cout << "Enter your beverage's item #. Alternatively, enter '6' to exit.\n";
            cout << "----------------------------------------------" << endl;
            cout << "Your selection: ";
        }
        // Handles the sale of drinks
        void buyDrink(int drinkChoice){
            char choice;
            if(menu[drinkChoice].beverageQuantity < 1){
                //Drink is out of stock!
                cout << "Sorry. " << menu[drinkChoice].nameOfBeverage << " is OUT OF STOCK\n";
                return;
            }
            // Calling inputMoney to get user's money and passing it their choice
            float money = inputMoney(drinkChoice);

            // Asking if user still wants to carry out purchase
            cout << "\n----------------------------------------------" << endl;
            cout << "Would you still like to make the purchase? (Y/N): ";
            do{
                cin >> choice;
                // If yes, it will do this
                if(choice == 'Y' || choice == 'y'){
                    cout << "\n----------------------------------------------" << endl;
                    cout << "Here's your " << menu[drinkChoice].nameOfBeverage << endl;
                    cout << "Your change of $" << fixed << setprecision(2) << (money - menu[drinkChoice].beveragePrice) << endl;
                    netProfit += menu[drinkChoice].beveragePrice;
                    menu[drinkChoice].beverageQuantity--;
                    break;
                }

                else{
                    // If not, it will do this
                    if(choice == 'N' || choice == 'n'){
                        cout << "----------------------------------------------" << endl;
                        cout << "Thank you for choosing Anthony's Beverages! Here is your $" << money << endl;
                        cout << "----------------------------------------------" << endl;
                        break;
                    }
                    cin.clear();
                    cin.ignore(10000,'\n');
                    cout << "Please enter Y or N: ";
                }
                // Loops until they enter yes or no
              } while(choice != 'Y' || choice != 'y' || choice != 'N' || choice != 'n');
        }

        //Destructor to call dailyReport
        ~machine(){
            dailyReport();
        }

};

// MAIN function
int main(){
    // Creates machine object called anthonysBeverages
    machine anthonysBeverages;
    int userChoice;

    /*
        Main processing loop which calls the
        displayChoices class member function and allows 
        the patron to either pick a drink or quit the program. 
    */ 
    while(true){
        // Displays the menu
        anthonysBeverages.displayChoices();

        // Stores the user's drink choice
        cin >> userChoice;

        // Loops until appropiate input is given
        while(userChoice > 6 || userChoice < 1 || cin.fail()){
            cin.clear();
            cin.ignore(10000,'\n');
            cout << "Please enter a valid choice(1 - 6): ";
            cin >> userChoice;
        }
        // exit key
        if(userChoice == 6 || userChoice == 6){
            break;
        }
        // Completes transaction
        anthonysBeverages.buyDrink(userChoice-1);
    }
    // CLOSING
    cout << "----------------------------------------------" << endl;
    cout << "Thank You for shopping at Anthony's Beverages! :)" << endl;
    cout << "----------------------------------------------" << endl;
    
    // Terminating the program
    return 0;
}