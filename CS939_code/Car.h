//Car Class declaration/ prototype of all functions 
//within the class.
class Car {
    //Declares these attributes as
    //private. 
    private: 
      int _year;            //Model year of the Car
      string _make;         //Make of the Car   
      int _speed;           //Current speed of the Car
    
    //Declares these attributes as
    //public
    public:
      //Prototype/ Declaration
      Car(int year, string make);
      //Prototype / Declaration
      int getYear();
      //Prototpe / Declaration
      string getMake();
      //Prototype / Declaration
      int getSpeed();
      
      //Functions that affect speed
      void accelerate();
      
      void brake();
};