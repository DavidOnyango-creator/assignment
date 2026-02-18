#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class Employee {
protected:
    string firstName;
    char initial;
    string lastName;

public:
    Employee(string f, char i, string l);
    virtual double calculateSalary() = 0;  // Pure virtual
    virtual ~Employee() {}
};

#endif
🔹 Employee.cpp
cpp
Copy code
#include "Employee.h"

Employee::Employee(string f, char i, string l) {
    firstName = f;
    initial = i;
    lastName = l;
}
🔹 SalariedEmployee.h
cpp
Copy code
#ifndef SALARIED_H
#define SALARIED_H
#include "Employee.h"

class SalariedEmployee : public Employee {
private:
    double monthlySalary;

public:
    SalariedEmployee(string f, char i, string l, double salary);
    double calculateSalary();
};

#endif
🔹 SalariedEmployee.cpp
cpp
Copy code
#include "SalariedEmployee.h"

SalariedEmployee::SalariedEmployee(string f, char i, string l, double salary)
: Employee(f, i, l) {
    monthlySalary = salary;
}

double SalariedEmployee::calculateSalary() {
    return monthlySalary;
}
🔹 HourlyEmployee.h
cpp
Copy code
#ifndef HOURLY_H
#define HOURLY_H
#include "Employee.h"

class HourlyEmployee : public Employee {
private:
    int hoursWorked;
    double ratePerHour;

public:
    HourlyEmployee(string f, char i, string l, int hours, double rate);
    double calculateSalary();
};

#endif
🔹 HourlyEmployee.cpp
cpp
Copy code
#include "HourlyEmployee.h"

HourlyEmployee::HourlyEmployee(string f, char i, string l, int hours, double rate)
: Employee(f, i, l) {
    hoursWorked = hours;
    ratePerHour = rate;
}

double HourlyEmployee::calculateSalary() {
    return hoursWorked * ratePerHour;
}
🔹 Application File (main.cpp)
cpp
Copy code
#include <iostream>
#include "SalariedEmployee.h"
#include "HourlyEmployee.h"
using namespace std;

int main() {
    SalariedEmployee s("Alice", 'M', "Smith", 60000);
    HourlyEmployee h("Bob", 'K', "Jones", 160, 20);

    cout << "Salaried Employee Salary: " 
         << s.calculateSalary() << endl;

    cout << "Hourly Employee Salary: " 
         << h.calculateSalary() << endl;

    return 0;
}