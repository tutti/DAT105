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
    // Vector of employee objects
    vector<Employee*> employees;

    // The main menu of the program, and the submenu for employee creation
    Menu mainmenu;
    Menu submenu;

    submenu.addOption("Add a Manager", [&employees]()->int {
        string fn, ln;
        int sl, mw, hy;
        // Get data from the user
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
        // Create the Manager and add it to the list
        Manager* m = new Manager(fn, ln, sl);
        m->setMeetingsPerWeek(mw);
        m->setHolidaysPerYear(hy);
        employees.push_back(m);
        // Exit the submenu (returning to the main menu)
        return -1;
    });
    submenu.addOption("Add an Engineer", [&employees]()->int {
        string fn, ln, di, in;
        int sl, ye;
        bool kc;
        // Get data from the user
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
        // Create the Engineer and add it to the list
        Engineer* e = new Engineer(fn, ln, sl);
        e->setKnowsCpp(kc);
        e->setExperience(ye);
        e->setDiscipline(di);
        employees.push_back(e);
        // Exit the submenu (returning to the main menu)
        return -1;
    });
    submenu.addOption("Add a Researcher", [&employees]()->int {
        string fn, ln, ga, tt;
        int sl;
        // Get data from the user
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
        // Create the Researcher and add it to the list
        Researcher* r = new Researcher(fn, ln, sl);
        r->setGraduatedAt(ga);
        r->setThesisTitle(tt);
        employees.push_back(r);
        // Exit the submenu (returning to the main menu)
        return -1;
    });
    submenu.addExit("Cancel");

    mainmenu.addOption("Add an Employee", [&submenu]()->int {
        // Starts the submenu for employee creation
        submenu.execute();
        return 0;
    });
    mainmenu.addOption("Delete an Employee", [&employees]()->int {
        string lastname, in;
        // Get the last name of the employee
        cout << "Last name of employee facing deletion: ";
        getline(cin, lastname);
        // Loop through the employees
        for (int i = 0; i < employees.size(); ++i) {
            if (employees[i]->getLastName() == lastname) {
                // If the last name matches, ask the user to confirm deletion
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
        // Ask the user for a file name
        cout << "Please supply a file name: ";
        getline(cin, filename);
        // Open the file as a stream
        ofstream file;
        file.open(filename);
        // Write each employee's data string to the file
        for (int i = 0; i < employees.size(); ++i) {
            file << employees[i]->toDataString() << endl;
        }
        // Close the file
        file.close();
        return 0;
    });
    mainmenu.addOption("Restore database", [&employees]()->int {
        // If the employee list has any employees, remove them.
        // This will also destruct the objects held within, according to 
        // documentation.
        employees.clear();
        string filename;
        // Ask the user for a file name
        cout << "Please supply a file name: ";
        getline(cin, filename);
        // Open the file for reading
        ifstream file;
        file.open(filename);
        string line;
        if(file.is_open()) {
            while(file.peek() != EOF) {
                // Read line by line, creating employee objects from the lines.
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
            // Close the file
            file.close();
        }

        return 0;
    });
    mainmenu.addOption("List Employees", [&employees]()->int {
        // Loop through the employees, print the human readable string for each.
        for (int i = 0; i < employees.size(); ++i) {
            cout << (i+1) << ". " << employees[i]->toString() << endl;
        }
        return 0;
    });
    mainmenu.addExit();
    mainmenu.execute();
}