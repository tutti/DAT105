#include "Manager.h"
#include <string.h>
#include <vector>

using namespace std;

void Manager::setMeetingsPerWeek(int meetings) {
    meetingsPerWeek = meetings;
}

void Manager::setHolidaysPerYear(int holidays) {
    holidaysPerYear = holidays;
}

int Manager::getMeetingsPerWeek() const {
    return meetingsPerWeek;
}

int Manager::getHolidaysPerYear() const {
    return holidaysPerYear;
}

string Manager::toString() const {
    return getName() 
        + ", manager (salary "
        + to_string(salary)
        + ", "
        + to_string(meetingsPerWeek)
        + " meetings/week, "
        + to_string(holidaysPerYear)
        + " holidays/year)"
    ;
}

string Manager::toDataString() const {
    return "MANAGER\t"
        + firstname
        + "\t"
        + lastname
        + "\t"
        + to_string(salary)
        + "\t"
        + to_string(meetingsPerWeek)
        + "\t"
        + to_string(holidaysPerYear)
    ;
}

void Manager::fromDataString(string data) {
    vector<string> split;
    char* cstr = new char[data.length()+1];
    strcpy(cstr, data.c_str());

    char * p = strtok(cstr, "\t");
    while (p != 0)
    {
        split.push_back(p);
        p = strtok(NULL, "\t");
    }

    firstname = split[1];
    lastname = split[2];
    salary = stoi(split[3]);
    meetingsPerWeek = stoi(split[4]);
    holidaysPerYear = stoi(split[5]);
}