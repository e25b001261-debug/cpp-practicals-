#include <iostream>
#include <memory>
using namespace std;
struct Item { int value; Item(int v):value(v){} };
int main() {
    cout << "Student: Fatemeh sahranvard" << endl;
    unique_ptr<Item> one = make_unique<Item>(10);
    cout << "unique_ptr value: " << one->value << endl;
    shared_ptr<Item> first = make_shared<Item>(20);
    shared_ptr<Item> second = first; // shared ownership
    cout << "shared_ptr value: " << second->value << endl;
    cout << "Owners: " << first.use_count() << endl;
    return 0; // smart pointers release memory automatically
}
