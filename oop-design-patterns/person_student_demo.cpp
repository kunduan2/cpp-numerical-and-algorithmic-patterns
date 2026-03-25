/* 
Problem Statement:
Design a simple class hierarchy to model different types of people 
(e.g., Person, Student, Employee) with shared and specialized behavior.

Objectives:
- Demonstrate inheritance (Student, Employee inherit from Person)
- Show runtime polymorphism using virtual functions
- Enable behavior overriding via print()

Key Concepts:
1. Encapsulation:
   - Private data members (name_, id_)
   - Access via public methods

2. Inheritance:
   - "is-a" relationship (Student is-a Person)

3. Polymorphism:
   - Base pointer (Person*) can refer to derived objects
   - Correct print() method resolved at runtime

4. Virtual Functions:
   - Base class defines virtual print()
   - Derived classes override it

5. Extensibility:
   - New types (e.g., GraduateStudent) can be added
   - No change required in existing code

Usage Pattern:
- Store heterogeneous objects in a base pointer container
- Call common interface (print()) without knowing exact type

Design Notes:
- Avoid logic in constructors (only initialize state)
- Use virtual destructor for safe polymorphic deletion
- Prefer const correctness for read-only methods
*/

#include <iostream>
#include <string>
using namespace std;

// ---------------- Base Class ----------------
class Person {
private:
    std::string name_;
    int idSsn_;
public:
    Person(const string name, const int idSsn): name_(name), idSsn_(idSsn) {
        // cout<<"defined main constrctor" << "\n";
    }
    Person(const string name): name_(name) {
        idSsn_ = 000;
        // cout<<"\ndefined 2nd constrctor: SSN id not known " ;
    }

    // getters
    string getName() const{
        return name_;
    }
    int getIdSsn() const {
        return idSsn_;
    }

     // setters
    string setName(const string& newName){
        return name_ = newName;
    }
    int setIdSsn(const int& newIdSsn){
        return idSsn_ = newIdSsn;
    }

    // polymorphic function
    virtual void print() const{
        cout << "Person (Base/parent Class) -> ";
        cout << "Name: " << name_ << ", SSN: " << idSsn_ << "\n";
    }
};

// ---------------- Derived: Student ----------------
class Student : public Person {
private:
    string major_; // major subject
    int gradYear_; // graduation year
public:
    // deafult Constructor
    Student(): Person("Default", 000000), major_("Not provided"), gradYear_(0000) {
        cout<<"Deafult Student constrctor\n";
    }
    // Constructor
    Student(const string& name, const int& idSsn, const string& major, const int& gradYear): Person(name, idSsn), major_(major), gradYear_(gradYear) {
        cout << "Calling Main Student constrctor\n";
    }
    // . . .
    void print() const {
        // cout<<"---- Printing from Student class ----\n";
        cout << "Student (Derived/child Class) -> \n";
        Person:: print();
        cout << "Major: " << major_
            << "\nGradYear: " << gradYear_ << "\n";
    }

    void changeMajor(const string& newMajor) {
        major_ = newMajor;
    }
};

// ---------------- More Derived: GraduateStudent ----------------
class GraduateStudent : public Student {
private:
    std::string thesisTopic_;
public:
    GraduateStudent(const string& name, const int& idSsn,
                    const string& major, const int& gradYear,
                    const string& thesisTopic
                )
        : Student(name, idSsn, major, gradYear), thesisTopic_(thesisTopic) {}
    
    void print() const override{
        cout << "Graduate Student (More-derived/grand children Class) -> ";
        Student::print();
        cout << "  Thesis: " << thesisTopic_ << "\n";
    }
};

// ---------------- Another Branch: Employee ----------------
class Employee : public Person {
private:
    double salary_;

public:
    Employee(const string& name, int idSsn, double salary)
        : Person(name, idSsn), salary_(salary) {}

    void raiseSalary(double amount) {
        salary_ += amount;
    }

    void print() const override {
        cout << "Employee  (Another derived/clild Class) -> ";
        Person::print();
        cout << "  Salary: " << salary_ << "\n";
    }
};

// ---------------- Main ----------------
int main() {

    Person p("Mary", 123);
    Student s("Aron", 456, "Physics", 2026);
    GraduateStudent g("Tanmoy", 789, "Math", 2025, "Quantum Materials");
    Employee e("Alice", 999, 50000);

    cout << "\n--- Direct Calls ---\n";
    p.print();
    cout << "\n";
    s.print();
    cout << "\n";
    g.print();
    cout << "\n";
    e.print();

    cout << "\n--- Polymorphism (base pointer) ---\n";

    Person* people[4];
    people[0] = &p;
    people[1] = &s;
    people[2] = &g;
    people[3] = &e;

    for (int i = 0; i < 4; i++) {
        people[i]->print();   // runtime polymorphism
    }

    return 0;
}