#include "Researcher.h"
#include <string.h>
#include <vector>

using namespace std;

void Researcher::setGraduatedAt(string graduated) {
    graduatedAt = graduated;
}

void Researcher::setThesisTitle(string title) {
    thesisTitle = title;
}

string Researcher::getGraduatedAt() const {
    return graduatedAt;
}

string Researcher::getThesisTitle() const {
    return thesisTitle;
}

string Researcher::toString() const {
    return getName() 
        + ", researcher (salary "
        + to_string(salary)
        + ", graduated at "
        + graduatedAt
        + ", thesis title: "
        + thesisTitle
        + ")"
    ;
}

string Researcher::toDataString() const {
    return "RESEARCHER\t"
        + firstname
        + "\t"
        + lastname
        + "\t"
        + to_string(salary)
        + "\t"
        + graduatedAt
        + "\t"
        + thesisTitle
    ;
}

void Researcher::fromDataString(string data) {
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
    graduatedAt = split[4];
    thesisTitle = split[5];
}