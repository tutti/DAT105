#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <sstream>
#include <string>

using namespace std;

class Employee {
    public:
        Employee();
        Employee(string firstname, string lastname);
        Employee(string firstname, string lastname, int salary);
        void setName(string firstname, string lastname);
        void setSalary(int salary);
        string getName() const;
        string getFirstName() const;
        string getLastName() const;
        int getSalary() const;
        virtual string toString() const = 0;
        virtual string toDataString() const = 0;
        virtual void fromDataString(string data) = 0;
    protected:
        string firstname;
        string lastname;
        int salary;
};

#endif