//This program initializes an array with lottery ticket numbers 
//and lets the player enter this week's winning five-digit number;
//performing a linear search in order to determine whether or not the user
//won or lost.
#include <iostream>
#include <string>

using namespace std;
//Initializes NUMS to 10
#define NUMS 10
//MAIN FUNCTION
int main()
{
    //Initializes winningNum variable
    double winningNum;
    //Initializes the luckyNums array with the lottery ticket numbers
    int luckyNums[NUMS] = { 13579, 26791, 26792, 33445, 55555, 62483, 77777,  79422, 85647, 93121};
    //Prompts the user to enter the lucky combination
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
    cout << "Enter this week's lucky combination: "  << endl;
    //Saves the user input into winningNum variable
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
    //For loop that loops through the array searching for a match\
    // between the week‚Äôs lucky combination and the lottery ticket
    // numbers
    for (int i=0; i< NUMS; i++){
       if (luckyNums[i] == winningNum){
        //If found, the user wins and gets congratulated
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "Congratulations, you got this week's lucky numbers!" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        return 0;
        
       }
          
      }
      //If it is not found, the user did not win and is prompted so 
      cout << "--------------------------------------------------------------------------------" << endl;
      cout << "You didn't win! ";
      cout << "--------------------------------------------------------------------------------" << endl;
  //Returns zero to the main function
  //aka terminates the program
  return 0;
}