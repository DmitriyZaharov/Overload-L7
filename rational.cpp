#include <iostream>
#include <cmath>
#include "rational.h"

using namespace std;

bool operator > (Rational a, Rational b) {
    return (a.Numerator() / (double)a.Denominator()) > double(b.Numerator() / (double)b.Denominator());
}

bool operator < (Rational a, Rational b) {
    return (a.Numerator() / (double)a.Denominator()) < (b.Numerator() / (double)b.Denominator());
}

bool operator == (Rational a, Rational b)
{
    if ((a.Numerator() == b.Numerator()) && (a.Denominator() == b.Denominator()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

Rational operator + (Rational a, Rational b) {
    int p = (a.Numerator() * b.Denominator()) + (b.Numerator() * a.Denominator());
    int q = a.Denominator() * b.Denominator();
    return Rational(p, q);
}


Rational operator - (Rational a, Rational b) {
    int p = (a.Numerator() * b.Denominator()) - (b.Numerator() * a.Denominator());
    int q = a.Denominator() * b.Denominator();
    return Rational(p, q);
}


Rational operator * (Rational a, Rational b) {
    return Rational((a.Numerator()*b.Numerator()), (a.Denominator()*b.Denominator()));
}

Rational operator / (Rational a, Rational b) {
    return Rational((a.Numerator() * b.Denominator()), (a.Denominator() * b.Numerator()));
}

istream& operator >> (istream& stream, Rational& r) { //возвращать будем ссылку на поток
    //if (stream) return stream;
    int p, q;
    if (stream >> p && stream.ignore(1) && stream >> q) {
        r = { p, q };
    }
    return stream;
}

ostream& operator << (ostream& stream, const Rational& r) {
    stream << r.Numerator() << "/" << r.Denominator();
    return stream;
}
