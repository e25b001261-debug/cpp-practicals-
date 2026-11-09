#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    cout << "Student: Fatemeh sahranvard" << endl;
    ofstream out("students.csv");
    if(!out) { cerr << "Cannot open file"; return 1; }
    out << "ID,Name,Marks\n101,Fatemeh,90\n102,Sara,85\n103,Ali,88\n";
    cout << "Write position: " << out.tellp() << endl;
    out.close();
    ifstream in("students.csv");
    if(!in) { cerr << "Cannot read file"; return 1; }
    cout << "Read position: " << in.tellg() << endl;
    in.seekg(0); cout << "First line: ";
    string line; getline(in,line); cout << line << endl;
    cout << "Position after header: " << in.tellg() << endl;
    in.seekg(0); cout << "All records:\n";
    while(getline(in,line)) cout << line << endl;
    in.close();
    fstream file("students.csv", ios::in|ios::out);
    file.seekp(0,ios::end); cout << "End write position: " << file.tellp() << endl;
    file.seekp(0); cout << "Start write position: " << file.tellp() << endl;
    file.close();
}
