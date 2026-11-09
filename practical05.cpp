#include <iostream>
#include <string>
using namespace std;
class Person {
protected:
    string name; int age;
public:
    Person(string n,int a):name(n),age(a){}
};
class Student : public Person {
protected:
    int studentId; string course;
public:
    Student(string n,int a,int id,string c):Person(n,a),studentId(id),course(c){}
    void display() const {
        cout << "Student: " << name << ", Age: " << age
             << ", ID: " << studentId << ", Course: " << course << endl;
    }
};
class GraduateStudent : public Student {
    string topic;
public:
    GraduateStudent(string n,int a,int id,string c,string t)
      :Student(n,a,id,c),topic(t){}
    void displayGraduate() const {
        display(); cout << "Research: " << topic << endl;
    }
};
int main() {
    cout << "Student: Fatemeh sahranvard" << endl;
    Student s("Fatemeh",27,101,"Data Science"); s.display();
    GraduateStudent g("Ali",25,102,"Computer Science","Artificial Intelligence");
    g.displayGraduate();
}
