#include <iostream>
#include <sstream>

using namespace std;

void getint(istream &stream, int &i) {
    string in;
    getline(stream, in);
    stringstream(in) >> i;
}