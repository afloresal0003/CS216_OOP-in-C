//Car class definitions (place where you actually
//perform all the code within the class).
using namespace std;
#include "Car.h"
//Constructor with default parameters
Car::Car(int year = 2010, string make = "Unknown")
      {
          _year = year;
          _make = make;
          _speed = 0;
      }
//Accessors (basically the "get" functions)
// Goes to the private year variable and
// retrieves the year of the car object 
int Car::getYear()
      {
          return _year;
      }
// Goes to the private make variable and
// retrieves the make of the car object
string Car::getMake()
      {
          return _make;
      }
// Goes to the private speed variable and
// retrieves the current speed of the car object
int Car::getSpeed()
      {
          return _speed;
      }
// Functions that affect the speed either through increase or decrease in speed. 
// INCREASE
void Car::accelerate()
      {
          _speed += 5;
      }
// DECREASE
void Car::brake()
      {
          if (_speed >= 5)
          {
              _speed -=5;
          }
          else
          {
              _speed = 0;
          }
      }