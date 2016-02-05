#include <iostream>
#include "Menu.h"

using namespace std;

void Menu::addOption(string name, function<int()> func) {
    pair<string, function<int()>> p (name, func);
    options.push_back(p);
}

void Menu::addExit() {
    auto func = []()->int { return -1; };
    pair<string, function<int()>> p ("Exit", func);
    options.push_back(p);
}

void Menu::addExit(string name) {
    auto func = []()->int { return -1; };
    pair<string, function<int()>> p (name, func);
    options.push_back(p);
}

void Menu::print() const {
    int i;
    for (i = 0; i < options.size(); ++i) {
        cout << (i+1) << ". " << options[i].first << endl;
    }
}

void Menu::execute() {
    //string _;
    int ret = 0;
    int in;
    while (ret != -1) {
        print();
        do {
            getint(cin, in);
            //getline(cin, _); // Clear the rest of the line
            if (in < 1 || in > options.size()) {
                cout << "Please choose a valid option." << endl;
            }
        } while (in < 1 || in > options.size());
        auto func = options[in-1].second;
        ret = func();
    }
}