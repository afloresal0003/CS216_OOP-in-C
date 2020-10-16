//This program utilizes two methods of sorting;
//bubble sort and selection sort
//in order to numerically sort a random list of
//integers
#include <stdlib.h>
#include <iostream>

using namespace std;
//Defines variable SIZE to 100
#define SIZE 100
//Defines MAX_NUM to 1000
#define MAX_NUM 1000
//Initializes a function (printArray)
//that displays the integers
void printArray(int *array) {
    for (int i=0; i<SIZE; i++) {
        cout << array[i] << " ";
        if (i == 20 || i == 42 || i == 63 || i == 84)
        cout << endl;
    }
    cout << endl;
}
//Initializes a function (bubbleSort)
//that performs a bubble sort on the
//random numbers, counts
// the number of swaps it performed, 
// and displays both the sorted integers
// and the number of swaps
void bubbleSort(int *array) {
    cout << "                               RANDOM NUMBERS: " << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    printArray(array);
    
    bool swaped = true;
    int numSwap = 0;
    while (swaped) {
        swaped = false;
        for (int i=0; i<SIZE-1; i++) {
            if (array[i] > array[i+1]) {
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                swaped = true;
                numSwap++;
            }
        }
    }
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "\n                             SORTED NUMBERS: " << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    printArray(array);
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "BUBBLE SORT: " << numSwap << " swaps." << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
}
//Initializes a function(selectionSort)
//that performs a selection sort on the
//random numbers, counts the
//number of swaps performed, and displays
//both the sorted integers and the number 
//of swaps performed
void selectionSort(int *array) {
    cout << "                               RANDOM NUMBERS: " << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    printArray(array);
    
    int numSwap = 0;
    for (int begin=0; begin<SIZE-1; begin++) {
        int smallest = begin;
        for (int i=begin+1; i<SIZE; i++) {
            if (array[i] < array[smallest]) {
                smallest = i;
            }
        }
        int temp = array[begin];
        array[begin] = array[smallest];
        array[smallest] = temp;
        numSwap++;
    }
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "                            SORTED NUMBERS: " << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    printArray(array);
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "SELECTION SORT: " << numSwap << " swaps." << endl;
    cout << "-------------------------------------------------------------------------" << endl;
}
//MAIN FUNCTION
int main() {
    //TITLE and intro to program
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "                   Welcome to Sort Solutions Inc.!" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "RULES: " << endl;
    cout << "Two methods of sorting will be displayed:\n";
    cout << "-> Bubble Sort" << endl;
    cout << "-> Selection Sort" << endl;
    //BEGINNING of the program 
    cout << "--------------------------------------------------------------------------------" << endl;
    //Initializes two arrays for
    //holding the random numbers 
    //in order to perform bubble
    // and selection sorting
    int bubbleArray[SIZE];
    int selectionArray[SIZE];
    //For loop that generates the random numbers
    //and stores them into the respective arrays
    for (int i=0; i<SIZE; i++) {
        int aRandomNumber = rand() % MAX_NUM;
        bubbleArray[i] = aRandomNumber;
        selectionArray[i] = aRandomNumber;
    }
    //Calls the bubble and selection sorter functions
    //using the bubble and selection random integer arrays
    bubbleSort(bubbleArray);
    selectionSort(selectionArray);
    //Returns zero to the main function
    return 0;
}