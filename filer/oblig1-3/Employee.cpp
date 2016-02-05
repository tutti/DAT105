#include "Employee.h"

using namespace std;

Employee::Employee() {
    firstname = "";
    lastname = "";
    salary = 0;
}

Employee::Employee(string firstname, string lastname) {
    this->firstname = firstname;
    this->lastname = lastname;
    salary = 0;
}

Employee::Employee(string firstname, string lastname, int salary) {
    this->firstname = firstname;
    this->lastname = lastname;
    this->salary = salary;
}

void Employee::setName(string firstname, string lastname) {
    this->firstname = firstname;
    this->lastname = lastname;
}

void Employee::setSalary(int salary) {
    this->salary = salary;
}

string Employee::getName() const {
    return firstname + " " + lastname;
}

string Employee::getFirstName() const {
    return firstname;
}

string Employee::getLastName() const {
    return lastname;
}

int Employee::getSalary() const {
    return salary;
}