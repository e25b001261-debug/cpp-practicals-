#include <iostream>
#include <stdexcept>
using namespace std;
class InvalidAmount : public runtime_error {
public: InvalidAmount():runtime_error("Amount must be positive"){}
};
class InsufficientFunds : public runtime_error {
public: InsufficientFunds():runtime_error("Insufficient balance"){}
};
class BankAccount {
    double balance;
public:
    BankAccount(double b):balance(b){}
    void withdraw(double amount) {
        if(amount<=0) throw InvalidAmount();
        if(amount>balance) throw InsufficientFunds();
        balance-=amount;
        cout << "Withdrawal successful. Balance: " << balance << endl;
    }
};
int main() {
    cout << "Student: Fatemeh sahranvard" << endl;
    BankAccount account(1000);
    try { account.withdraw(300); } catch(const exception& e) { cout<<e.what()<<endl; }
    try { account.withdraw(0); } catch(const InvalidAmount& e) { cout<<e.what()<<endl; }
    try { account.withdraw(900); } catch(const InsufficientFunds& e) { cout<<e.what()<<endl; }
}
