/*
    Programmer: Anthony Flores-Alvarez
    Course: CS 216 - OOP in C++
    Date: December 1, 2020
    Description: This program demonstrates a driver program in which 
    a list class is mofified by adding a member function for inserting 
    a new item at a specified position:
        void insert(double x, int pos);
    It also adds a member function for deleting a node at a specified position:
        void remove(int pos);
*/

// Header file for program functionality
#include <iostream>
#include <sstream>
#include <cstdlib>

// Allows us to not have to use std:: throughout program
using namespace std;

// Class declaration
class LinkedList{

    private:
        // Declares a list structure
        struct ListNode{
            // Stores node value
            int value;        
            // Stores pointer of next node
            struct ListNode *next;
        };
        // Pointer to head node
        ListNode *head;      

    public:
        // Class Constructor.
        LinkedList(){ 

            head = NULL; 
        }
        
        // Class Destructor
        ~LinkedList();
        
        // Linked list class operations.
        void appendNode( int );
        void insertNode( int );
        void deleteNode( int );
        void reverseNodes();
        int search(int);
        void display() const;

        // For Prog challenge #8
        void insert(double,int);

        // For Prog challenge #9
        void remove(int);
};

// Appends a node to the end of the node list
void LinkedList::appendNode(int num){

   // Point to a new node.
   ListNode *newNode; 
   ListNode *nodePtr;

   // Allocating new node to store new value there.
   newNode = new ListNode;
   newNode->value = num;
   newNode->next = NULL;

   // If no nodes exist...
   if ( !head ){
      // ...set newNode as first node.
      head = newNode;
   }
    // Otherwise
   else{
      // Initialize nodePtr to head of list.
      nodePtr = head;

      // Find last node
      while ( nodePtr->next ){
         nodePtr = nodePtr->next;
      }

      // Set newNode as the last node.
      nodePtr->next = newNode;
   }

   display();   
}

// Displays all linked list nodes/values           
void LinkedList::display() const{

    // To move through the list
    ListNode *nodePtr; 

    if (!head){

        cout << "\n-------------------------------------------------" << endl;
        cout << "Error! The list is empty! Try appending nodes!";
        cout << "-------------------------------------------------" << endl;
        return;
    }

    // Set nodePtr as head of the list.
    nodePtr = head;
    // Displau list contents
    cout << "\n-------------------------------------------------" << endl;
    cout << "List Contents:" << endl;
    cout << "-------------------------------------------------\n" << endl;
   // While node exists
    while (nodePtr){

        // Display node value
        cout << nodePtr->value << " -> ";

        // Move to next node.
        nodePtr = nodePtr->next;
    }
    cout << "Null";
    cout << "\n-------------------------------------------------ç" << endl;
}

// Flips list in reverse order
void LinkedList::reverseNodes(){

    // For node management and pointing
    ListNode *nodePtr;
    ListNode *next;
    ListNode *result=NULL;
    // If no nodes, 
    if (!head){

        cout << "\n-------------------------------------------------" << endl;
        cout << "Error! The list is empty. Try appending values!";
        cout << "-------------------------------------------------" << endl;
        return;
    }
    // Position nodePtr at the head of the list.
    nodePtr = head;
    // While node exists
    while(nodePtr!=NULL){

        // reverse it.
        next = nodePtr->next;
        nodePtr->next = result;
        result = nodePtr;
        nodePtr = next;
    }

    head = result;
    display();
}


// Inserts a node to list              
void LinkedList::insertNode( int num ){

    // For node management
    ListNode *newNode;             
    ListNode *nodePtr;            
    ListNode *previousNode = NULL; 

    // Allocate a new node and storing value
    newNode = new ListNode;
    newNode->value = num;
    newNode->next = NULL;
  
    // If no nodes exist
    if (!head){

        // Make newNode the first node.
        head = newNode;
    }
    // Otherwise, 
    else{
        // Position nodePtr at the head of list.
        nodePtr = head;

        // Setting previousNode to NULL.
        previousNode = NULL;

        // Skipping all nodes whose value is less than num.
        while (nodePtr != NULL && nodePtr->value < num){
            
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        // If the new node is to be the 1st in the list,
        // insert it before all other nodes.
        if (previousNode == NULL){
            
            head = newNode;
            newNode->next = nodePtr;
        }

         // Otherwise,
        else{

            // insert after previous node.
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    } 
      
    display();   
}  

// PROG CHAL 8
// Inserts a node at pos at a certain position
void LinkedList::insert(double num ,int pos){

    ListNode *newNode;            
    ListNode *nodePtr;            
    ListNode *previousNode = NULL; 
    int i=0;
    // Allocate a new node and store num there.
    newNode = new ListNode;
    newNode->value = num;
    newNode->next = NULL;
    // Position nodePtr at the head of list.
    nodePtr = head;
        
    if(pos == 0){  
        newNode->next=head;
        head = newNode;
    }
    else{
    //loop to reach position.
        while(nodePtr != NULL && i<pos){  
                
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
            i++;
        }
        //position not found.
        if(nodePtr == NULL){

            cout << "\n-------------------------------------------------" << endl;
            cout << "Error! Invalid Position: " << endl;
            cout << "-------------------------------------------------" << endl;
        }
        //inserts node.
        else{

            newNode->next = nodePtr;
            previousNode->next = newNode;
        }
    }
    // Display List
    display();
}

// PROG CHAL 9
// Deletes a node at a specied position
void LinkedList::remove(int pos){
    
    ListNode *nodePtr;       
    ListNode *previousNode;
    int i = 0;
    // If the list is empty, do nothing.
    if(!head){
        cout << "\n-------------------------------------------------" << endl;
        cout << "Error! Failed to delete because list is empty."; 
        cout << "-------------------------------------------------" << endl;  
        return;
    }

    // Position nodePtr at the head of list.
    nodePtr = head;

    if(pos == 0){  
        
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
    else{
        // Loop to reach position.
        while(nodePtr != NULL && i<pos){  

            previousNode=nodePtr;
            nodePtr=nodePtr->next;
            i++;
        }
        if (nodePtr){

            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
        else{
            cout << "\n-------------------------------------------------" << endl;
            cout << "Error! Failed to delete position because "<< pos<< " was not found .";
        }
    } 

    display();   
}

// Searches for a node with num as its value.   
void LinkedList::deleteNode( int num ){

    // To traverse the list.
    ListNode *nodePtr;       
    //To point to the previous node.
    ListNode *previousNode; 

    // If the list is empty, do nothing.
    if ( !head ){

        cout << "\n-------------------------------------------------" << endl;
        cout << "Error! Failed to delete because the list is empty."; 
        cout << "-------------------------------------------------" << endl;  
        return;
    }

    // Determine if the first node is the one.
    if ( head->value == num ){

        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }

    else{
        // Initialize nodePtr to head of list.
        nodePtr = head;

        // Skip all nodes whose value member is not equal to num.
        while (nodePtr != NULL && nodePtr->value != num){
            
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        // If nodePtr is not at the end of the list,
        // link the previous node to the node after nodePtr, then delete nodePtr.
        if ( nodePtr ){

            previousNode->next = nodePtr->next;
            delete nodePtr;
        }

        else{
            cout << "\n-------------------------------------------------" << endl;
            cout << "Error! Failed to delete because " << num << " was not found in the list.";
            cout << "-------------------------------------------------" << endl;
        }
    }  
    // Display list
    display();   
} 

// Searches for value and returns position if found returns -1 if not found.
int LinkedList::search(int value)
{
    // To move through the list.
    ListNode *nodePtr; 
    int pos=-1;

    if (!head){
        cout << "\n-------------------------------------------------" << endl;
        cout << "Error! The list is empty.";
        cout << "-------------------------------------------------\n" << endl;
        return-1;
    }

    // Position nodePtr at the head of the list.
    nodePtr = head;

    while (nodePtr){  

        pos++;
        if(nodePtr->value == value){
               
            return pos;
        }
        else{

            nodePtr = nodePtr->next;
        }
    }

    return -1;
}

// Destructor
LinkedList::~LinkedList(){

     // To traverse the list.
    ListNode *nodePtr;
    // To point to the next node.
    ListNode *nextNode;
    // Position nodePtr at the head of the list.
    nodePtr = head;

    // While nodePtr is not at the end of the list.
    while ( nodePtr != NULL ){

        // Save a pointer to the next node.
        nextNode = nodePtr->next;

        // Delete the current node.
        delete nodePtr;

        // Position nodePtr at the next node.
        nodePtr = nextNode;
    }
}   

// Switches string to a number
double switchToNum(string userString){

    // Stores number form of user's string
    double userValue;

    // Creating object from the stringstream class
    stringstream uStr(userString);

    // Passing the string value to the variable 
    // that'll hold it as an integer type
    uStr >> userValue;

    // Giving back the switched value type
    return userValue;
}

// Checks if a string has a character in it
bool isString(string userInputString){
    
    // Storing whether or not there is a character
    bool stringHere;
    
    // Checking user string for character
    for (int i = 0; i < userInputString.length(); i++){

        // If there's none
        if(isalpha(userInputString[i]) != true){
            stringHere = false;
            continue;
        }
        // If there is
        else{
            stringHere = true;
            break;
        }
    }

    // Giving back if there is or isn't a character
    return stringHere;
}

// Ensures that the user enters a valid input
string validateInput(string userInputString){


    // Storing character outcome and number form of user's values
    bool stringHere;
    double userInputValue;

    userInputValue = switchToNum(userInputString);

    // Checking for string
    stringHere = isString(userInputString);

    // Loops until user enters an integer
    while (!cin || userInputValue < 0 || stringHere == true) {
        // Helps in clearing the error flags which are set when cin fails to interpret the input.
        cin.clear();
        // Helps in removing the input contents that could've caused the read failure
        cin.ignore(1000,'\n');
        cout << "-------------------------------------------------" << endl;
        // Prompt to enter only positive integers
        cout << "Error! Please enter a valid number: ";
        cin >> userInputString;
        userInputValue = switchToNum(userInputString);
        stringHere = isString(userInputString);
    }
    // Giving back admissible value
    return userInputString;

}

// MAIN Function
int main()
{
    // Initializing linked list
    LinkedList myList;

    // To store user info
    char choice;
    string choiceString;
    double userNodeNumber;
    string userString;
    string userPositionString;


    // INTRO/ HEADER
    cout << "-------------------------------------------------" << endl;
    cout << "Welcome to Node Linked-List Manipulator" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "RULES:" << endl;
    cout << "\n- This program will allow you to manipulate a linked list " << endl;
    cout << "  through menu options. Simply enter the character for it!" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "PAY ATTENTION TO ENTRIES. THEY ARE CASE-SENSITIVE!" << endl;
    cout << "-------------------------------------------------" << endl;

    
    do {
        // MENU
        cout << "Menu" << endl;
        cout << "\nEnter 'A' to append a node: ";
        cout << "\nEnter 'I' to insert a node: ";
        cout << "\nEnter 'D' to delete a node: ";
        cout << "\nEnter 'S' to search for a node: ";
        cout << "\nEnter 'R' to reverse nodes: ";
        cout << "\n\nTwo options below are for Challenges 8 & 9: " << endl;
        cout << "\n\nEnter 'P' to insert node at an index: ";
        cout << "\nEnter 'T' to remove node at index: ";
        cout << "\n\nEnter 'Q' to quit the program";

        // Asking for menu selection
    cout << "\n-------------------------------------------------" << endl;
        cout << "\nEnter your choice: ";
        cin >> choiceString;

        // Loops until user enters an integer
        while (!cin || choiceString.length() != 1) {
            // Helps in clearing the error flags which are set when cin fails to interpret the input.
            cin.clear();
            // Helps in removing the input contents that could've caused the read failure
            cin.ignore(1000,'\n');
            cout << "-------------------------------------------------" << endl;
            // Prompt to enter only positive integers
            cout << "Error! Please enter a valid menu option (1 character): ";
            cin >> choiceString;
        }

        choice = choiceString[0];

        // CASES
        switch ( choice )
        {
            // Append a node: 
            case 'A' :
            case 'a' :
                // Asking for user integer to insert
                cout << "Enter an integer: ";
                cin >> userString;
                userString = validateInput(userString);
                userNodeNumber = switchToNum(userString);

                // Append user's input into list.   
                myList.appendNode(userNodeNumber);
                break;

            // Insert a node: 
            case 'I' :
            case 'i' :
                // Asking for user integer to insert
                cout << "Enter an integer: ";
                cin >> userString;
                userString = validateInput(userString);
                userNodeNumber = switchToNum(userString);

                // Insert user input into list.   
                myList.insertNode(userNodeNumber);
                break;

            // Delete a node: 
            case 'D' :
            case 'd' :
                // Ask user for node to delete
                cout << "Enter an integer : ";
                cin >> userString;
                userString = validateInput(userString);
                userNodeNumber = switchToNum(userString);

                // Deleting it  
                myList.deleteNode(userNodeNumber);
                break;
            
            // Reverse nodes:
            case 'R':    
            case 'r': 
                // Reversing nodes of list.
                myList.reverseNodes();
                break;

            // Search for a node:  
            case 'S':
            case 's':  
                int elementIndex;
                // Ask user for element to search 
                cout << "Enter element to be searched:";
                cin >> userString;
                userString = validateInput(userString);
                userNodeNumber = switchToNum(userString);

                // Search element.
                elementIndex = myList.search(userNodeNumber);

                if(elementIndex == -1){
                    cout << "Element not found in the list"<< endl;
                }
                else{
                    cout << "Element found at:"<< elementIndex << endl;
                }
                break;

            // PROG CHAL 8
            // Insert node at: 
            case 'P':
            case 'p': 
                int userLocation;
                // Asking for integer to insert
                cout << "Enter an integer: ";
                cin >> userString;
                userString = validateInput(userString);
                userNodeNumber = switchToNum(userString);
                
                // Asking for position of insertion
                cout << "Enter position to be inserted:";
                cin >> userString;
                userString = validateInput(userString);
                userLocation = switchToNum(userString);
                myList.insert(userNodeNumber, userLocation);
                cin.ignore();
                cout << "Press ENTER 2 times to continue: ";
                cin.get();
                // Helps in clearing the error flags which are set when cin fails to interpret the input.
                cin.clear();
                // Helps in removing the input contents that could've caused the read failure
                cin.ignore(1000,'\n');
                break;
                       
            // PROG CHAL 9
            // Remove node at specified place
            case 'T':
            case 't':  
                int userPosition;
                
                // Ask user for index to delete 
                cout << "Enter element position to be deleted:";
                cin >> userPositionString;
                userPositionString = validateInput(userPositionString);
                userPosition = switchToNum(userPositionString);
                myList.remove(userPosition);
                cin.ignore();
                cout << "Press ENTER 2 times to continue: ";
                cin.get();
                // Helps in clearing the error flags which are set when cin fails to interpret the input.
                cin.clear();
                // Helps in removing the input contents that could've caused the read failure
                cin.ignore(1000,'\n');
                break;

            // Quit program:         
            case 'Q' :
            case 'q' :
                cout << "\n-------------------------------------------------" << endl;
                choice = 'q';
                cout << " Have a nice day !" << endl;
                cout << "-------------------------------------------------\n" << endl;
        }
    // Break case
    } while (choice != 'q' );

    // Terminating program
    return 0;    
}            