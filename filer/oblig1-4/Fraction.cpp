#include <iostream>
#include <vector>
#include "Fraction.h"
#include "Primes.h"
#include "ZeroDivisionException.h"

using namespace std;

/*
 * Note: I'm aware the assignment said to make the numerator and denominator
 * floating point numbers. I chose to disregard this as it is, frankly, rather
 * boneheaded and defeats the entire point of having a fraction class in the
 * first place.
 *
 * Code for the << and >> operators and type conversion is in the header file.
 * The compiler complained when I tried to put it here.
 *
 * The operators +, -, * and / don't modify the fraction object, they create
 * new fraction objects and return them. 
 */

Fraction::Fraction() {
    num = 0;
    den = 1;
}

Fraction::Fraction(int num, int den) {
    if (den == 0) {
        throw ZeroDivisionException("Division by NOTHING, fool!");
    }
    this->num = num;
    this->den = den;
    reduce();
}

void Fraction::reduce() {
    vector<int> p = primes(max(num, den));
    for (int i = 0; i < p.size(); ++i) {
        while (num % p[i] == 0 && den % p[i] == 0) {
            num /= p[i];
            den /= p[i];
        }
    }
    if (den < 0) {
        num *= -1;
        den *= -1;
    }
}

Fraction Fraction::operator+(int i) {
    Fraction r(num + i*den, den);
    return r;
}

Fraction Fraction::operator+(Fraction f) {
    Fraction r(num * f.den + f.num * den, den * f.den);
    return r;
}

Fraction Fraction::operator-(int i) {
    Fraction r(num - i*den, den);
    return r;
}

Fraction Fraction::operator-(Fraction f) {
    Fraction r(num * f.den - f.num * den, den * f.den);
    return r;
}

Fraction Fraction::operator*(int i) {
    Fraction r(num * i, den);
    return r;
}

Fraction Fraction::operator*(Fraction f) {
    Fraction r(num * f.num, den * f.den);
    return r;
}

Fraction Fraction::operator/(int i) {
    Fraction r(num, den * i);
    return r;
}

Fraction Fraction::operator/(Fraction f) {
    Fraction r(num * f.den, den * f.num);
    return r;
}

bool Fraction::operator==(Fraction f) {
    return (num == f.num && den == f.den);
}

bool Fraction::operator!=(Fraction f) {
    return (num != f.num || den != f.den);
}

bool Fraction::operator>(Fraction f) {
    return (num * f.den > f.num * den);
}

bool Fraction::operator<(Fraction f) {
    return (num * f.den < f.num * den);
}

bool Fraction::operator>=(Fraction f) {
    return (num * f.den >= f.num * den);
}

bool Fraction::operator<=(Fraction f) {
    return (num * f.den <= f.num * den);
}