#include <iostream>
#include <stack>
#include <string>
#include <stdexcept>
using namespace std;
template <class T>
class MyStack {
    stack<T> values;
public:
    void push(const T& x) { values.push(x); }
    void pop() {
        if(values.empty()) throw underflow_error("Stack is empty");
        values.pop();
    }
    T top() const {
        if(values.empty()) throw underflow_error("Stack is empty");
        return values.top();
    }
    bool empty() const { return values.empty(); }
};
int main() {
    cout << "Student: Fatemeh sahranvard" << endl;
    MyStack<int> a; a.push(10); cout << "int: " << a.top() << endl;
    MyStack<float> b; b.push(2.5f); cout << "float: " << b.top() << endl;
    MyStack<string> c; c.push("Hello"); cout << "string: " << c.top() << endl;
    try { a.pop(); a.pop(); } catch(const exception& e) { cout << e.what() << endl; }
}
