//This file declares a Car class and includes a client program
// that uses  a Car object to simulate accelerating and breaking. 
#include <iostream>
#include <string>
#include "Car.cpp"
using namespace std;
//MAIN FUNCTION
int main()
{
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "                                       CAR CLASS " << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    //Creates the car object 
    Car carOne(2018, " Ferrari 488 GTB\n");
    cout << carOne.getYear();
    cout << carOne.getMake();
    cout << "Current Speed: " << carOne.getSpeed() << " mph " << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "                                       SCENARIO" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "\n You want to test your new ride. You get in for a drive." << endl;
    cout << "\n*HITS THE GAS PEDAL*" << endl;

//  ACCELERATION for-loop that increments and displays the miles
//  per hour of the car after every iteration until reaching 25 mph
    for (int accelerateCount = 1; accelerateCount <= 5; accelerateCount++)
    {
        carOne.accelerate();
        cout << "Current Speed: " << carOne.getSpeed() << " mph " << endl;
    }
    cout << "\nWATCH OUT! You see a dog crossing the road in front of you!" << endl;
    cout << "\n*HITS THE BRAKES*" << endl;
    
//  DECELERATION for-loop that decrements and displays the miles
//  per hour of the car after every iteration until reaching 0 mph
    for (int decelerateCount = 1; decelerateCount <= 5; decelerateCount++)
    {
        carOne.brake();
        cout << "Current Speed: " << carOne.getSpeed() << " mph " << endl;
    }
// RESOLUTION
    cout << "\n--------------------------------------------------------------------------------" << endl;
    cout << "                                You go back home!" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    
    return 0;
}