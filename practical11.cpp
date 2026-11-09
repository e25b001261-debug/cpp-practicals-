
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    cout << "Student: Fatemeh Sahranvard" << endl;

    ofstream out("students.csv");
    if (!out) {
        cerr << "Cannot open file";
        return 1;
    }

    out << "ID,Name,Marks\n"
        << "101,Fatemeh,90\n"
        << "102,Sara,85\n"
        << "103,Ali,88\n";

    if (!out) {
        cerr << "Writing to students.csv failed";
        return 1;
    }

    cout << "Write position: " << out.tellp() << endl;
    out.close();

    ifstream in("students.csv");
    if (!in) {
        cerr << "Cannot read file";
        return 1;
    }

    cout << "Read position: " << in.tellg() << endl;

    in.seekg(0);

    cout << "First line: ";
    string line;
    getline(in, line);
    cout << line << endl;

    cout << "Position after header: " << in.tellg() << endl;

    in.seekg(0);
    cout << "All records:\n";

    while (getline(in, line)) {
        cout << line << endl;
    }

    in.close();

    fstream file("students.csv", ios::in | ios::out);
    if (!file) {
        cerr << "Cannot open file for position demo";
        return 1;
    }

    file.seekp(0, ios::end);
    cout << "End write position: " << file.tellp() << endl;

    file.seekp(0);
    cout << "Start write position: " << file.tellp() << endl;

    file.close();

    return 0;
}
