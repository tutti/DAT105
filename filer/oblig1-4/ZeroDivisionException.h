#ifndef ZERODIVISIONEXCEPTION_H
#define ZERODIVISIONEXCEPTION_H

#include <exception>
#include <stdexcept>

using namespace std;

class ZeroDivisionException : public runtime_error {
    public:
        using runtime_error::runtime_error;
};

#endif