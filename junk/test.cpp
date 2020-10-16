#include <iostream>
#include <iomanip>
using namespace std;
int main(){

    double One = 5;
    double Two = 2;
    int Three = One / Two;

    double number = 5.5;
    double val = 2;
    val = static_cast<int>(number) / val;
    cout << "Your tax cut is " << fixed << showpoint << setprecision(2) << val << endl;
}