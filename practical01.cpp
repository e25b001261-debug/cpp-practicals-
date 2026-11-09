#include <iostream>
using namespace std;
int main() {
    cout << "Student: Fatemeh sahranvard" << endl;
    const double PI = 3.14159;
    int radius;
    cout << "Enter radius: ";
    cin >> radius;
    double area = PI * radius * radius;
    cout << "Radius = " << radius << endl;
    cout << "Area = " << area << endl;
    cout << "Is radius positive? " << (radius > 0) << endl;
    cout << "Valid input? " << (radius > 0 && area > 0) << endl;
    return 0;
}
