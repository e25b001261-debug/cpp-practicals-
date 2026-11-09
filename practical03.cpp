#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
class IntArray {
    int* data; int size;
public:
    IntArray() : data(nullptr), size(0) {}                 // default
    explicit IntArray(int n) : data(new int[n]{}), size(n) {} // parameterized
    IntArray(const IntArray& x) : data(x.size ? new int[x.size] : nullptr), size(x.size) { // copy
        if (size > 0) copy(x.data, x.data + size, data);
    }
    IntArray& operator=(const IntArray& x) {               // copy assignment
        if (this != &x) {
            int* p = x.size ? new int[x.size] : nullptr;
            if (x.size > 0) copy(x.data, x.data + x.size, p);
            delete[] data; data = p; size = x.size;
        }
        return *this;
    }
    IntArray(IntArray&& x) noexcept : data(x.data), size(x.size) { // move
        x.data = nullptr; x.size = 0;
    }
    IntArray& operator=(IntArray&& x) noexcept {           // move assignment
        if (this != &x) {
            delete[] data; data = x.data; size = x.size;
            x.data = nullptr; x.size = 0;
        }
        return *this;
    }
    ~IntArray() { delete[] data; }                         // destructor
    void set(int i, int v) { if (i >= 0 && i < size) data[i] = v; }
    void show() const { for (int i=0;i<size;i++) cout<<data[i]<<" "; cout<<endl; }
};
int main() {
    cout << "Student: Fatemeh sahranvard" << endl;
    IntArray a(3); a.set(0,10); a.set(1,20); a.set(2,30);
    IntArray b(a); IntArray c; c = a;
    IntArray d(move(a)); IntArray e; e = move(b);
    cout << "Moved array: "; d.show();
    cout << "Copied array: "; e.show();
    cout << "Copy-assigned array: "; c.show();
}
