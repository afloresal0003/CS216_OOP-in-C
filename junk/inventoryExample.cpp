#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//Class declaration
class InventoryItem{
    //member variables
    private:
        int partNum;
        string description;
        int onHand;
        double price;
    //member functions
    public:
        void setStoreInfo(int , string , int , double);
        int getPartNum(){ return partNum;}
        string getDescription(){return description;}
        int getOnHand(){ return onHand; }
        double getPrice(){return price;}
};
//class setter function.
/* 
    Instead of making individual setter functions we can just
    make one setter function that can modify the values of
    all of our member variables. 
*/
void InventoryItem::setStoreInfo(int p, string d, int oh, double cost){
    partNum = p;
    description = d;
    onHand = oh;
    price = cost;
}

//Prototype of functions
void storeValues(InventoryItem&);
void showValues(InventoryItem);

//Client or main program
int main(){
    InventoryItem part; //part is an object/instance of the InventoryItem class
    storeValues(part);
    showValues(part);
    return 0;
}

//Function definition
void showValues(InventoryItem item){
    cout << fixed << showpoint << setprecision(2) << endl;
    cout << "Part Num : " << item.getPartNum() << endl;
    cout << "Description : " << item.getDescription() << endl;
    cout << "Units on Hand : " << item.getOnHand() << endl;
    cout << "Price : $" << item.getPrice() << endl;
}
//Function definition

/*
    Pass the object by reference so that when you send it to the
    functions it'll actually modify the original value and not just
    make a copy of it to change
*/
void storeValues(InventoryItem &item){
    int partNum; //local variables for this function holds user input
    string description;
    int qty;
    double price;

    cout << "Enter data for the new part number \n";
    cout << "Part Number : ";
    cin >> partNum;
    cout << "Description : ";
    cin.get();
    getline(cin, description);
    cout << "Quantity : ";
    cin >> qty;
    cout << "Unit Price : ";
    cin >> price;

    /*
    All the user inputs from above will set the object using the
    setter function setStoreInfo()
    item is the name of the object that was passed and then we set 
     the values using the .set()
     */
    item.setStoreInfo(partNum, description, qty, price);

}

