#ifndef RESEARCHER_H
#define RESEARCHER_H

#include <string>
#include "Employee.h"

class Researcher : public Employee {
    public:
        using Employee::Employee;
        void setGraduatedAt(string grad);
        void setThesisTitle(string title);
        string getGraduatedAt() const;
        string getThesisTitle() const;
        string toString() const;
        string toDataString() const;
        void fromDataString(string data);
    protected:
        string graduatedAt;
        string thesisTitle;
};

#endif