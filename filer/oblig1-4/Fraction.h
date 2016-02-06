#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <string>
#include "ZeroDivisionException.h"

using namespace std;

class Fraction {
    public:
        Fraction();
        Fraction(int num, int den);

        Fraction operator+(int i);
        Fraction operator+(Fraction f);
        Fraction operator-(int i);
        Fraction operator-(Fraction f);
        Fraction operator*(int i);
        Fraction operator*(Fraction f);
        Fraction operator/(int i);
        Fraction operator/(Fraction f);

        bool operator==(Fraction f);
        bool operator!=(Fraction f);
        bool operator>(Fraction f);
        bool operator<(Fraction f);
        bool operator>=(Fraction f);
        bool operator<=(Fraction f);

        operator int() {
            return num / den;
        }
        operator float() {
            return (float) num / (float) den;
        }
        operator double() {
            return (double) num / (double) den;
        }

        friend ostream& operator<<(ostream& ostr, const Fraction& f) {
            ostr << f.num << "/" << f.den;
            return ostr;
        }

        friend istream& operator>>(istream& istr, Fraction& f) {
            int a, b;
            char c;
            istr >> a;
            istr >> c;
            istr >> b;

            if (c == '/') {
                if (b == 0) {
                    throw ZeroDivisionException("Division by NOTHING, fool!");
                }
                f.num = a;
                f.den = b;
            }

            f.reduce();

            return istr;
        }
    protected:
        int num;
        int den;
        void reduce();
};

#endif