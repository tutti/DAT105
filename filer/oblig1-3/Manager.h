#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"

class Manager : public Employee {
    public:
        using Employee::Employee;
        void setMeetingsPerWeek(int meetings);
        void setHolidaysPerYear(int holidays);
        int getMeetingsPerWeek() const;
        int getHolidaysPerYear() const;
        string toString() const;
        string toDataString() const;
        void fromDataString(string data);
    protected:
        int meetingsPerWeek;
        int holidaysPerYear;
};

#endif