#include <iostream>
#include <string>
using namespace std;
class BankAccount {
private:
    string holder;       // private: protected account data
    double balance;
public:
    BankAccount(string name, double amount) : holder(name), balance(amount) {}
    void deposit(double amount) {
        if (amount > 0) balance += amount;
    }
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) balance -= amount;
        else cout << "Invalid withdrawal\n";
    }
    void display() const {
        cout << holder << " - Balance: Rs. " << balance << endl;
    }
};
int main() {
    cout << "Student: Fatemeh sahranvard" << endl;
    BankAccount a("Fatemeh", 5000), b("Sara", 3000);
    a.deposit(1000); a.withdraw(500);
    b.withdraw(400);
    a.display(); b.display();
    return 0;
}
