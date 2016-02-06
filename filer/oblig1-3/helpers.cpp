#include <iostream>
#include <sstream>

using namespace std;

void getint(istream &stream, int &i) {
    // Reads an integer from the input stream.
    // After reading, clears the rest of the line.
    string in;
    getline(stream, in);
    stringstream(in) >> i;
}