//This program determines the median of an 
//array of sorted integers 
#include <iostream>
#include <string>
#define SIZE 5
#define MAX_NUM 100
using namespace std;

//Median function that determines the 
//median of an array of integers
double median(int *sortedArray, int size) {
    if (size%2 == 0) {
        return (double)(sortedArray[size/2] + sortedArray[size/2-1])/2;
    } 
    else {
        return sortedArray[size/2];
    }
}

//Main function
int main()
{
    //Initializes the variables that
    //will be used later on in the program
    string choice;
    int i,
        j,
        temp;
    //TITLE and intro to program
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "                           Welcome to Find My Median!" << endl;
    //DESCRIPTION of program
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "REGULATIONS: " << endl;
    cout << "This program determines the median of a list of integers." << endl;
    cout << "Simply enter 'E' or 'e' to enter the five integers you'd like, " << endl;
    cout << "and the median will be provided." << endl;
    cout << "Or enter 'D' or 'd' to run the default of five integers" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "                                    PROCESS" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    //Prompts the user to enter a choice
    cout << "Would you like to input your integers (E) or use a default(D)?: ";
    //Stores choice into choice variable
    cin >> choice;
    //IF the user enters ‚ÄùD‚Äù this happens:
    if (choice == "D" || choice == "d"){
        //Initializes the array of integers
        int integerArray[SIZE] = {};
        //For loop that stores random integers
        //within the array
        for (int i=0; i<SIZE; i++) {
            int aRandomNumber = rand() % MAX_NUM;
            integerArray[i] = aRandomNumber;
        }
        //DISPLAY
        cout << "\n--------------------------------------------------------------------------------" << endl;
        cout << "                                    RESULTS" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        //Displays the random integer array
        cout << "Random Integer Array: ";
        for (int i=0; i<SIZE; i++){
            cout << integerArray[i] << ", ";
        }
        cout << endl;
        //Sorts the array of integers
        //into ascending order
    	for(i=0;i<SIZE;i++)
    	{		
    		for(j=i+1;j<SIZE;j++)
    		{
    			if(integerArray[i]>integerArray[j])
    			{
    				temp=integerArray[i];
    				integerArray[i]=integerArray[j];
    				integerArray[j]=temp;
    			}
    		}
    	}
	//Displays the sorted array
	cout<<"Sorted Integer Array: ";
	for (int i=0; i<SIZE; i++){
            cout << integerArray[i] << ", ";
        }
        cout << endl;
        //Displays the median by calling the median function
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "Median: " << median(integerArray, 5) << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        return 0;
    }
    //IF user enters ‚ÄùE‚Äù this happens:
    if (choice == "E" || choice == "e"){
        //Initializes the integer variable
        int integer;
        //Initializes the array of integers
        int integerArray[SIZE] = {};
        //For loop that prompts the user to enter
        //the integers that are then stored into the array
        for (int count = 0; count<SIZE; count++){
            cout << "Enter integer: ";
            cin >> integer;
            //Validator
            while (!cin) 
            {
                cout << "Error! Enter a valid amount: $" ;
                //Helps in clearing the error flags which are set when std::cin fails to interpret the input.
                cin.clear();
                //Helps in removing the input contents that could've caused the read failure
                cin.ignore(1000,'\n');
                cin >> integer;
            }
            integerArray[count] = integer;
        }
        //DISPLAY
        cout << "\n--------------------------------------------------------------------------------" << endl;
        cout << "                                    RESULTS" << endl;
        cout << "--------------------------------------------------------------------------------" << endl;
        //Displays the user integer array
        cout << "User Integer Array: ";
        for (int i=0; i<SIZE; i++){
            cout << integerArray[i] << ", ";
        }
        cout << endl;
        //Sorts the array of integers
        //into ascending order
    	for(i=0;i<SIZE;i++)
    	{		
    		for(j=i+1;j<SIZE;j++)
    		{
    			if(integerArray[i]>integerArray[j])
    			{
    				temp=integerArray[i];
    				integerArray[i]=integerArray[j];
    				integerArray[j]=temp;
    			}
    		}
    	}
    	//Displays the sorted array
    	cout<<"Sorted Integer Array: ";
    	for (int i=0; i<SIZE; i++){
                cout << integerArray[i] << ", ";
            }
            cout << endl;
            //Displays the median by calling the median function
            cout << "--------------------------------------------------------------------------------" << endl;
            cout << "Median: " << median(integerArray, 5) << endl;
            cout << "--------------------------------------------------------------------------------" << endl;
            return 0;
        }
        //If neither of the choices are entered
        //the program is terminated
        else{
            cout << "Please enter E or D!" << endl;
            return 0;
        }
}
