#ifndef ENGINEER_H
#define ENGINEER_H

#include <string>
#include "Employee.h"

class Engineer : public Employee {
    public:
        using Employee::Employee;
        void setKnowsCpp(bool knowsCpp);
        void setExperience(int experience);
        void setDiscipline(string discipline);
        bool knowsCpp() const;
        int getExperience() const;
        string getDiscipline() const;
        string toString() const;
        string toDataString() const;
        void fromDataString(string data);
    protected:
        bool _knowsCpp;
        int experience;
        string discipline;
};

#endif