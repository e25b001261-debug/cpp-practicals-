#include <iostream>
using namespace std;
class Shape {
public:
    virtual double area() const = 0; // pure virtual function
    virtual ~Shape() = default;
};
class Circle : public Shape {
    double r;
public: Circle(double x):r(x){}
    double area() const override { return 3.14159*r*r; }
};
class Rectangle : public Shape {
    double w,h;
public: Rectangle(double x,double y):w(x),h(y){}
    double area() const override { return w*h; }
};
class Triangle : public Shape {
    double b,h;
public: Triangle(double x,double y):b(x),h(y){}
    double area() const override { return 0.5*b*h; }
};
int main() {
    cout << "Student: Fatemeh sahranvard" << endl;
    Circle c(2); Rectangle r(4,5); Triangle t(6,3);
    Shape* shapes[] = {&c,&r,&t};
    for (Shape* s : shapes) cout << "Area = " << s->area() << endl;
}
