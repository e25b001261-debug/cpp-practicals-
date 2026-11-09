#include <iostream>
#include <cmath>
using namespace std;
double add(int a,int b) { return a+b; }
double add(double a,double b) { return a+b; }
class ComplexNumber {
    double real, imag;
public:
    ComplexNumber(double r=0,double i=0):real(r),imag(i){}
    ComplexNumber operator+(const ComplexNumber& x) const {
        return ComplexNumber(real+x.real, imag+x.imag);
    }
    void display() const { cout << real << (imag>=0?" + ":" - ") << abs(imag) << "i"; }
};
int main() {
    cout << "Student: Fatemeh sahranvard" << endl;
    cout << "Integer sum: " << add(2,3) << endl;
    cout << "Decimal sum: " << add(2.5,3.5) << endl;
    ComplexNumber a(2,3), b(1,4), c=a+b;
    cout << "Complex sum: "; c.display(); cout << endl;
}
