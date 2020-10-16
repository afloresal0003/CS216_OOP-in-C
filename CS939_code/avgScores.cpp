//This program calculates the total and average
//of the scores of any number of tests
//with figures being stored in a dynamically
//allocated array
#include <iostream>
#include <iomanip>

using namespace std;
//Main function
int main()
{
    //Initialization in order to dynamically
    //allocate the array
    double *tests = nullptr;
    //Holds the total of the test scores
    double testTotal;
    //Holds the average of the test scores
    double totalAverage;
    //Holds the number of test scores 
    int numOfTests;
    
    //TITLE and intro to program
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "                   Welcome to The Test Score Calculator!" << endl;
    //DESCRIPTION of program
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "REGULATIONS: " << endl;
    cout << "This program calculates the:" << endl;
    cout << "-> Total of scores" << endl;
    cout << "-> Average of scores" << endl;
    cout << "Simply enter the amount of test scores you‚Äôll be entering." << endl;
    cout << "Then, enter the test scores!" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "                     *Please enter positive integers only!*" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "PROCESS: " << endl;
    
    //Prompts the user to enter the amount of test scores
    cout << "Please enter the amount of test scores: ";
    cin >> numOfTests;
    //Validator
    while (!cin || numOfTests < 0){
        cout << "Error! Enter a valid amount: $" ;
        //Helps in clearing the error flags which are set when std::cin fails to interpret the input.
        cin.clear();
        //Helps in removing the input contents that could've caused the read failure
        cin.ignore(1000,'\n');
        cin >> numOfTests;
    }
    
    //Assigns the user input as the size of the tests array
    tests = new double[numOfTests];
    
    //For loop that continuously prompts the user 
    //to enter the test scores 
    for (int i = 0; i < numOfTests; i++)
    {
        cout << "Please enter test #" << i + 1 << ": ";
        //Stores the test score into the tests array
        cin >> tests[i];
        //Validator
        while (!cin || tests[i] < 0){
            cout << "Error! Enter a valid amount: $" ;
            //Helps in clearing the error flags which are set when std::cin fails to interpret the input.
            cin.clear();
            //Helps in removing the input contents that could've caused the read failure
            cin.ignore(1000,'\n');
            cin >> tests[i];
        }
    }
    
    //Loops through the test scores from the array
    //and sums them up, storing the value into testTotal
    for (int i = 0; i < numOfTests; i++)
    {
        testTotal = testTotal + tests[i];
    }
    
    //Calculates the average of the test scores
    //and stores the value into totalAverage
    totalAverage = testTotal / numOfTests;
    
    //Displays the total and average score with a precision
    //two decimal spaces after the decimal point
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "                                   RESULTS: " << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << setprecision(2) << fixed << showpoint;
    cout << "Score Total: " << testTotal << endl;
    cout << "Average Score: " << totalAverage << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    
    //Deletes the dynamic memory allocation tests array
    //in order to prevent memory leak
    delete [] tests;
    //Resets the pointer to null
    tests = nullptr;
    
    //Returns zero to main function; terminating program
    return 0;
}
