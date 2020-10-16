/* 
 Programmer: Anthony Flores-Alvarez
 Course: CS216 - OOP in C++
 Date: October 5, 2020
 Description: This program uses two identical arrays of 8 integers.
 First, it displays the contents of the ﬁrst array. Then it calls a function 
 to sort it using an ascending order bubble sort, modiﬁed to print out 
 the array contents after each pass of the sort. Next the program displays 
 the contents of the second array, then calls a function to sort it using an 
 ascending order selection sort, modiﬁed to print out the array contents after 
 each pass of the sort.
*/

// Header files for program functionality
#include <iostream>
using namespace std;

// Defining the array size
#define ARRAY_SIZE 8

// Shows the arrays when called
void showArray(int array[]){
    for(int i = 0; i < ARRAY_SIZE; i++){
        cout << array[i] << ", ";
    }
    cout << endl;
}

// Does the bubblesort on given array when called
void BubbleSort(int array[]){
    for(int i = ARRAY_SIZE - 2; i >= 0; i--){
        for(int j = 0; j <= i; j++){
            if(array[j] > array[j+1]){
                // Swapping
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                // To show the array after each pass
                cout << "\nPASS: " << endl;
                showArray(array);
            } 
        } 
    } 
}

// Does the selection sort on given array when called
void SelectionSort(int array[]){
    for(int i = 0;i < ARRAY_SIZE-1; i++){
        for(int j = i + 1; j < ARRAY_SIZE; j++){
            if(array[i] > array[j]){
                // Swapping
                int temp = array[i];
                array[i] = array[j];
                array[j] =temp;
                // To show the array after each pass
                cout << "\nPASS: " << endl;               
                showArray(array);
            }
        }
    }
}

// MAIN Function
int main(){
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
    // Initializing our identical arrays
    int firstArray[] = {2, 95, 34, 35, 12, 5, 43, 92};
    int secondArray[] = {2, 95, 34, 35, 12, 5, 43, 92};

    // Shows the first array
    cout << "First Array: " << endl;
    showArray(firstArray);
    cout << "--------------------------------------------------------------------------------" << endl;

    // Doing the bubble sort on the first array
    cout << "Bubble Sort: " << endl;
    BubbleSort(firstArray);

    // Shows the second array
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "Second Array: " << endl;
    showArray(secondArray);
    cout << "--------------------------------------------------------------------------------" << endl;

    // Doing the selection sort on the second array
    cout << "Selection Sort: " << endl;
    SelectionSort(secondArray);
    cout << endl;

    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "DONE! Thank you for coming!" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    // Terminating program
    return 0;

} 