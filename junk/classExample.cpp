#include <string>
#include <cmath>
#include <iostream>

class circle{
    private:
        double radius;
    public:
        void setRadius(double r);
        double getArea();
};

void circle::setRadius(double r){
    radius = r;

}

double circle::getArea(){
     return 3.14*pow(radius, 2);

}
using namespace std;
int main(){
    circle circleOne, circleTwo;
    circleOne.setRadius(2.4);
    circleTwo.setRadius(3);
    cout << "The area of circle 1 is " << circleOne.getArea() << endl;
    cout << "The area of circle 2 is " << circleTwo.getArea() << endl;
    return 0;
}