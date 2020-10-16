// This program initializes an array with lottery ticket numbers 
// and lets the user this week‚Äôs winning combination; performing
// a binear search in order to determine whether or not the user won
#include <iostream>
#include <string>

using namespace std;
//Defines NUMS to hold a value of 10
#define NUMS 10
//Main function
int main()
{
    //TITLE and intro to program
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "                   Welcome to the California Lottery!" << endl;
    //DESCRIPTION of program
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "REGULATIONS: " << endl;
    cout << "This program determines whether or not the lottery ticket" << endl;
    cout << "numbers we recieved, won this week!" << endl;
    cout << "Simply enter this week‚Äôs lucky combination number!" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "                     *Please enter positive integers only!*" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "PROCESS: " << endl;
    //Initializes a double variable called winningNum
    double winningNum;
    //Initializes an integer array that witholds the 
    //lottery ticket numbers 
    int luckyNums[NUMS] = { 13579, 26791, 26792, 33445, 55555, 62483, 77777,  79422, 85647, 93121};
    //Prompts the user to enter the weekly lucky combination
    cout << "Enter this week's lucky combination: "  << endl;
    //Stores the user entered value into a variable, winningNum
    cin >> winningNum; 
    //Validator
    while (!cin || winningNum < 0) 
    {
        cout << "Error! Enter a valid amount: $" ;
        //Helps in clearing the error flags which are set when std::cin fails to interpret the input.
        cin.clear();
        //Helps in removing the input contents that could've caused the read failure
        cin.ignore(1000,'\n');
        cin >> winningNum;
    }
    //Initializes an integer variable left to 0
    int left = 0;
    //Initializes an integer variable right to NUMS minus 1
    int right = NUMS - 1;
    //While loop that performs the binary search through the array
    //splitting the array into left and right and reviewing the mid
    //value(s)
    while (left <= right){
        int mid = (left + right)/2;
        if (luckyNums[mid] == winningNum){
            cout << "--------------------------------------------------------------------------------" << endl;
            cout << "Congratulations, you got this week‚Äôs lucky numbers!" << endl;
            cout << "--------------------------------------------------------------------------------" << endl;
            return 0;
        }
        else if (luckyNums[mid] < winningNum){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    //If the binary search did not determine a match,
    //the user is prompted that they lost
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "Sorry :(. You did not win! " << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
  //Returns zero to the main function
  return 0;
}