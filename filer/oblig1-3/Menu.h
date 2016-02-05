#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>
#include <utility>
#include <functional>
#include "helpers.h"

using namespace std;

class Menu {
    public:
        void addOption(string name, function<int()> func);
        void addExit();
        void addExit(string name);
        void print() const;
        void execute();
    private:
        vector<pair<string, function<int()>>> options;
};

#endif