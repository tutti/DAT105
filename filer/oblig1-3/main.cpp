#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include "helpers.h"
#include "Menu.h"
#include "Manager.h"
#include "Engineer.h"
#include "Researcher.h"

using namespace std;

int main(int argc, char *argv[]) {
    vector<Employee*> employees;

    Menu mainmenu;
    Menu submenu;

    submenu.addOption("Add a Manager", [&employees]()->int {
        string fn, ln;
        int sl, mw, hy;
        cout << "First name: ";
        getline(cin, fn);
        cout << "Last name: ";
        getline(cin, ln);
        cout << "Salary: ";
        getint(cin, sl);
        cout << "Meetings per week: ";
        getint(cin, mw);
        cout << "Holidays per year: ";
        getint(cin, hy);
        Manager* m = new Manager(fn, ln, sl);
        m->setMeetingsPerWeek(mw);
        m->setHolidaysPerYear(hy);
        employees.push_back(m);
        return -1;
    });
    submenu.addOption("Add an Engineer", [&employees]()->int {
        string fn, ln, di, in;
        int sl, ye;
        bool kc;
        cout << "First name: ";
        getline(cin, fn);
        cout << "Last name: ";
        getline(cin, ln);
        cout << "Salary: ";
        getint(cin, sl);
        cout << "Knows C++? [y/n] ";
        getline(cin, in);
        kc = (in.at(0) == 'y');
        cout << "Years of experience: ";
        getint(cin, ye);
        cout << "Discipline: ";
        getline(cin, di);
        Engineer* e = new Engineer(fn, ln, sl);
        e->setKnowsCpp(kc);
        e->setExperience(ye);
        e->setDiscipline(di);
        employees.push_back(e);
        return -1;
    });
    submenu.addOption("Add a Researcher", [&employees]()->int {
        string fn, ln, ga, tt;
        int sl;
        cout << "First name: ";
        getline(cin, fn);
        cout << "Last name: ";
        getline(cin, ln);
        cout << "Salary: ";
        getint(cin, sl);
        cout << "Graduated at: ";
        getline(cin, ga);
        cout << "Thesis title: ";
        getline(cin, tt);
        Researcher* r = new Researcher(fn, ln, sl);
        r->setGraduatedAt(ga);
        r->setThesisTitle(tt);
        employees.push_back(r);
        return -1;
    });
    submenu.addExit("Cancel");

    mainmenu.addOption("Add an Employee", [&submenu]()->int {
        submenu.execute();
        return 0;
    });
    mainmenu.addOption("Delete an Employee", [&employees]()->int {
        string lastname, in;
        cout << "Last name of employee facing deletion: ";
        getline(cin, lastname);
        for (int i = 0; i < employees.size(); ++i) {
            if (employees[i]->getLastName() == lastname) {
                cout << employees[i]->toString() << endl;
                cout << "Delete this employee? [y/n] ";
                getline(cin, in);
                if (in.at(0) == 'y') {
                    employees.erase(employees.begin() + i);
                    cout << "Employee deleted." << endl;
                }
            }
        }
        return 0;
    });
    mainmenu.addOption("Save database", [&employees]()->int {
        string filename;
        cout << "Please supply a file name: ";
        getline(cin, filename);
        ofstream file;
        file.open(filename);
        for (int i = 0; i < employees.size(); ++i) {
            file << employees[i]->toDataString() << endl;
        }
        file.close();
        return 0;
    });
    mainmenu.addOption("Restore database", [&employees]()->int {
        employees.clear();
        string filename;
        cout << "Please supply a file name: ";
        getline(cin, filename);
        ifstream file;
        file.open(filename);
        string line;
        if(file.is_open()) {
            while(file.peek() != EOF) {
                getline(file, line);
                Employee* emp;
                if (line.substr(0, 7) == "MANAGER") {
                    emp = new Manager();
                } else if (line.substr(0, 8) == "ENGINEER") {
                    emp = new Engineer();
                } else if (line.substr(0, 10) == "RESEARCHER") {
                    emp = new Researcher();
                } else {
                    continue;
                }
                emp->fromDataString(line);
                employees.push_back(emp);
            }
            file.close();
        }

        return 0;
    });
    mainmenu.addOption("List Employees", [&employees]()->int {
        for (int i = 0; i < employees.size(); ++i) {
            cout << (i+1) << ". " << employees[i]->toString() << endl;
        }
        return 0;
    });
    mainmenu.addExit();
    mainmenu.execute();
}