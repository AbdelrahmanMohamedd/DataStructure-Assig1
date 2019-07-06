#include <iostream>
#include <cstdlib>

using namespace std;

#ifndef FRACTION_H
#define FRACTION_H

class Fraction
{
private:
    int numerator;
    int denumerator;
    //Tools.
    int get_min(const int&, const int&);
public:
    //Constructors.
    Fraction();
    Fraction(const int&, const int&);
    Fraction(const Fraction&);
    //Setters.
    void set_num(const int&);
    void set_denum(const int&);
    //Getters.
    int get_num();
    int get_denum();
    //Swapping the numerator with denumerator.
    //Doesn't effect the original Fraction.
    Fraction invert_fraction() const;
    //Reducing the fraction.
    void reduce_fraction();
    //Operators overloading.
    void operator= (const Fraction&);
    friend Fraction operator+ (const Fraction&, const Fraction&);
    friend Fraction operator- (const Fraction&, const Fraction&);
    friend Fraction operator* (const Fraction&, const Fraction&);
    friend Fraction operator/ (const Fraction&, const Fraction&);
    friend bool operator> (const Fraction&, const Fraction&);
    friend bool operator< (const Fraction&, const Fraction&);
    friend bool operator== (const Fraction&, const Fraction&);
    friend bool operator>= (const Fraction&, const Fraction&);
    friend bool operator<= (const Fraction&, const Fraction&);
    //I/O operators.
    friend istream& operator>> (istream&, Fraction&);
    friend ostream& operator<< (ostream&, Fraction);
};

#endif // FRACTION_H
