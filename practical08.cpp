#include <iostream>
#include <memory>
#include <string>
using namespace std;
class Vehicle {
public: virtual void show() const = 0; virtual ~Vehicle()=default;
};
class Car : public Vehicle {
public: void show() const override { cout << "Car created" << endl; }
};
class Bike : public Vehicle {
public: void show() const override { cout << "Bike created" << endl; }
};
class VehicleFactory {
public:
    static unique_ptr<Vehicle> create(const string& type) {
        if(type=="car") return make_unique<Car>();
        if(type=="bike") return make_unique<Bike>();
        return nullptr;
    }
};
int main() {
    cout << "Student: Fatemeh sahranvard" << endl;
    auto a=VehicleFactory::create("car");
    auto b=VehicleFactory::create("bike");
    if (a) a->show();
    if (b) b->show();
}
