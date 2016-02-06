#include <iostream>
#include "Menu.h"

/**
 * Menu
 *
 * This is a menu system for displaying a menu to the user.
 * The user is presented with a number of options, and will be asked to enter
 * a number based on the option they want.
 *
 * To add an option to a menu, create a lambda function performing that option's
 * code, and then pass it to addOption() along with the name that will be
 * displayed for that option. When the user selects that option, the lambda
 * function is called. If the lambda function returns -1, the menu will exit;
 * otherwise it will be displayed again after the lambda function has finished.
 *
 * The addExit() method is a shortcut to add a method that only returns -1, i.e.
 * a method that stops the menu execution and returns control to the code that
 * started it.
 *
 * After creating the menu, use the execute() function to hand over control to
 * the menu. If you just want to print the options, use the print() method
 * instead.
 */

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
    int ret = 0;
    int in;
    while (ret != -1) {
        print();
        do {
            getint(cin, in);
            if (in < 1 || in > options.size()) {
                cout << "Please choose a valid option." << endl;
            }
        } while (in < 1 || in > options.size());
        auto func = options[in-1].second;
        ret = func();
    }
}