#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

struct drinks{
    string name;
    int quantity;
    float price;
};

class machine{

    private:
        drinks d[5] = {{"Cola", 20, 1.00},
                       {"Root Bear", 20, 1.00},
                       {"Orange Soda", 20, 1.00},
                       {"Grape Soda", 20, 1.50},
                       {"Bottled Water", 20, 1.50}};
        float totalAmount = 0;
        //Accepts, validates and returns amount of money input
        float inputMoney(int i){
            float money;
            cout<<"How much money has been inserted: $";
            cin>>money;
            while(!(money >= d[i].price)){
                cout<<"Not enough money, please enter $"<< fixed << setprecision(2) <<d[i].price<<" or more: $";
                cin>>money;
            }
            return money;
        }

        // Displays the daily sale report
        void dailyReport(){
            cout << "\n Drink Machine Daily Report \n";
            for(int i = 0; i < 5; i++){
                cout << d[i].name << "\t: " << d[i].quantity << endl;
                cout << "Total amount collected: $" << fixed << setprecision(2) << totalAmount;
            }
        }

    public:
        // Display menu of drinks
        void displayChoices(){
            cout<<"\nDrink Machine Menu\n";
            for(int i = 0; i < 5; i++){
                cout << i+1 << ". " << d[i].name<<": $" << fixed << setprecision(2) << d[i].price <<endl;
                cout << "6. " << "Quit Drink Machine\n";
                cout << "Please make a selection: ";
            }
        }

        void buyDrink(int i){
            char choice;
            if(d[i].quantity < 1){
                //Drink is out of stock!
                cout<<"Sorry. "<<d[i].name<<" is OUT OF STOCK\n";
                return;
            }

            float money = inputMoney(i);
            cout << "Do you still want to make a purchase? (Y/N): ";
            do{
                cin >> choice;

                if(choice == 'Y' || choice == 'y'){
                    cout<<"Here is your "<<d[i].name<<", and your change of $"<< fixed << setprecision(2) <<(money - d[i].price);
                    totalAmount += d[i].price;
                    d[i].quantity--;
                    break;
                }

                else{
                    if(choice == 'N' || choice == 'n'){
                        cout << "Thank You for stopping buy. Here is your $"<<money;
                        break;
                    }
                    
                    cout<<"Please enter Y or N: ";
                }
              } while(choice != 'Y' || choice != 'y' || choice != 'N' || choice != 'n');
        }

        //Destructor to call dailyReport
        ~machine(){
            dailyReport();
        }

};

// MAIN function
int main(){

    machine m;
    int option;

    while(1){
        m.displayChoices();
        cin >> option;
        while(option > 6 || option < 1){
            cout << "Please enter a valid choice(1-6): ";
            cin >> option;
        }
        if(option == 6){
            break;
        }
        m.buyDrink(option-1);
    }

    cout << "Thank You for shopping" << endl;
    return 0;
}