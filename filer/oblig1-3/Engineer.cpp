#include "Engineer.h"
#include <string.h>
#include <vector>

using namespace std;

void Engineer::setKnowsCpp(bool knowsCpp) {
    _knowsCpp = knowsCpp;
}

void Engineer::setExperience(int experience) {
    this->experience = experience;
}

void Engineer::setDiscipline(string discipline) {
    this->discipline = discipline;
}

bool Engineer::knowsCpp() const {
    return _knowsCpp;
}

int Engineer::getExperience() const {
    return experience;
}

string Engineer::getDiscipline() const {
    return discipline;
}

string Engineer::toString() const {
    return getName() 
        + ", "
        + discipline
        + " engineer (salary "
        + to_string(salary)
        + ", "
        + (_knowsCpp ? "knows C++, " : "doesn't know C++, ")
        + to_string(experience)
        + " years experience)"
    ;
}

string Engineer::toDataString() const {
    return "ENGINEER\t"
        + firstname
        + "\t"
        + lastname
        + "\t"
        + to_string(salary)
        + "\t"
        + (_knowsCpp ? "knowsCpp" : "knowsNothing")
        + "\t"
        + to_string(experience)
        + "\t"
        + discipline
    ;
}

void Engineer::fromDataString(string data) {
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
    _knowsCpp = (split[4] == "knowsCpp" ? true : false);
    experience = stoi(split[5]);
    discipline = split[6];
}