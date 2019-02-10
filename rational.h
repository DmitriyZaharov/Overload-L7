#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {
public:
    Rational() //Конструктор по умолчанию должен создавать дробь с числителем 0 и знаменателем 1
    {
        num = 0;
        den = 1;
    }


    Rational(int numerator, int denominator)
    {
        if (denominator < 0)
        {
            if (numerator < 0)
            {
                denominator = abs(denominator);
                numerator = abs(numerator);
            }
            else
            {
                denominator = abs(denominator);
                numerator = numerator - 2 * numerator;
            }
        }
        if (numerator == 0) { denominator = 1; }
        int nod = GetGCD(abs(numerator), abs(denominator));

        num = numerator / nod;
        den = denominator / nod;
    }

    int Numerator() const
    {
        return num;
    }

    int Denominator() const
    {
        return den;
    }

private:
    int num; //числитель
    int den; //знаменатель

    int GetGCD(int a, int b)
    {
        while (a > 0 && b > 0)
        {
            if (a > b)
            {
                a %= b;
            }
            else
            {
                b %= a;
            }
        }
        return a + b;
    }
};

/*
int GetGCD(int x, int y)
{
    if (y == 0)
    {
        return x;
    }
    else
    {
        return gcd(y, x % y);
    }
}

 static int getGCD(int x, int y) {
    while (x != y)
      if (x > y) x -= y; else y -= x;
    return x;
  }

*/
bool operator == (Rational a, Rational b);
Rational operator + (Rational a, Rational b);
Rational operator - (Rational a, Rational b);
Rational operator * (Rational a, Rational b);
Rational operator / (Rational a, Rational b);
std::istream& operator >> (std::istream& stream, Rational& r);
std::ostream& operator << (std::ostream& stream, const Rational& r);
#endif // RATIONAL_H
