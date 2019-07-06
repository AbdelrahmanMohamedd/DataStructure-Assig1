#include "Fraction.h"

Fraction::Fraction()
{
    numerator = 1;
    denumerator = 1;
}
Fraction::Fraction(const int& num, const int& denum)
{
    if(denum == 0)
    {
        cout << "Denumerator Can't Be Zero." << endl;
        exit(1);
    }
    numerator = num;
    denumerator = denum;
    this->reduce_fraction();
}
Fraction::Fraction(const Fraction& rhs)
{
    if(rhs.denumerator == 0)
    {
        cout << "Denumerator Can't Be Zero." << endl;
        exit(1);
    }
    numerator = rhs.numerator;
    denumerator = rhs.denumerator;
    this->reduce_fraction();
}
//Setters.
void Fraction::set_num(const int& num)
{
    numerator = num;
}
void Fraction::set_denum(const int& denum)
{
    if(denum == 0)
    {
        cout << "Denumerator Can't Be Zero, Operation Cancelled" << endl;
        return;
    }
    denumerator = denum;
}
//Getters.
int Fraction::get_num()
{
    return numerator;
}
int Fraction::get_denum()
{
    return denumerator;
}
//Swapping the numerator with denumerator.
Fraction Fraction::invert_fraction() const
{
    Fraction temp;
    temp.set_num(this -> denumerator);
    temp.set_denum(this -> numerator);
    return temp;
}
//Reducing the fraction.
void Fraction::reduce_fraction()
{
    int minimum = get_min(numerator, denumerator);
    int GCD = 1;
    for(int i = 2 ; i <= minimum ; i++)
    {
        if((numerator % i == 0) && (denumerator % i == 0))
        {
            GCD = i;
        }
    }
    numerator = numerator / GCD;
    denumerator = denumerator / GCD;
}
//Operators overloading.
void Fraction::operator= (const Fraction& rhs)
{
    if(rhs.denumerator == 0)
    {
        cout << "Denumerator Can't Be Zero, Operation Cancelled" << endl;
        return;
    }
    numerator = rhs.numerator;
    denumerator = rhs.denumerator;
}
Fraction operator+ (const Fraction& LHS, const Fraction& RHS)
{
    Fraction sum;
    if(LHS.denumerator == RHS.denumerator)
    {
        sum.set_denum(LHS.denumerator); //OR RHS.denumerator.
        sum.set_num(LHS.numerator + RHS.numerator);
    }
    else
    {
        sum.set_denum(LHS.denumerator * RHS.denumerator);
        sum.set_num((LHS.numerator * RHS.denumerator) + (RHS.numerator * LHS.denumerator));
    }
    sum.reduce_fraction();
    return sum;
}
Fraction operator- (const Fraction& LHS, const Fraction& RHS)
{
    Fraction sub;
    if(LHS.denumerator == RHS.denumerator)
    {
        sub.set_denum(LHS.denumerator); //OR RHS.denumerator.
        sub.set_num(LHS.numerator - RHS.numerator);
    }
    else
    {
        sub.set_denum(LHS.denumerator * RHS.denumerator);
        sub.set_num((LHS.numerator * RHS.denumerator) - (RHS.numerator * LHS.denumerator));
    }
    sub.reduce_fraction();
    return sub;
}
Fraction operator* (const Fraction& LHS, const Fraction& RHS)
{
    Fraction product;
    product.set_num(LHS.numerator * RHS.numerator);
    product.set_denum(LHS.denumerator * RHS.denumerator);
    product.reduce_fraction();
    return product;
}
Fraction operator/ (const Fraction& LHS, const Fraction& RHS)
{
    Fraction invert(RHS.invert_fraction());
    Fraction quotient(LHS * invert);
    quotient.reduce_fraction();
    return quotient;
}
bool operator> (const Fraction& LHS, const Fraction& RHS)
{
    double ftod1 = static_cast<double>(LHS.numerator) / LHS.denumerator;
    double ftod2 = static_cast<double>(RHS.numerator) / RHS.denumerator;
    return ftod1 > ftod2;
}
bool operator< (const Fraction& LHS, const Fraction& RHS)
{
    double ftod1 = static_cast<double>(LHS.numerator) / LHS.denumerator;
    double ftod2 = static_cast<double>(RHS.numerator) / RHS.denumerator;
    return ftod1 < ftod2;
}
bool operator== (const Fraction& LHS, const Fraction&RHS)
{
    return !((LHS > RHS) || (LHS < RHS));
}
bool operator>= (const Fraction& LHS, const Fraction& RHS)
{
    return ((LHS > RHS) || (LHS == RHS));
}
bool operator<= (const Fraction& LHS, const Fraction& RHS)
{
    return ((LHS < RHS) || (LHS == RHS));
}
istream& operator>> (istream& in, Fraction& fraction)
{
    cout << "Enter The Numerator :";
    cin >> fraction.numerator;
    while(true)
    {
            cout << "Enter The Denumerator :";
            cin >> fraction.denumerator;
            if(fraction.denumerator == 0)
            {
                cout << "Denumerator Can't Be Zero." << endl;
                continue;
            }
            break;
    }
    return in;
}
ostream& operator<< (ostream& out, Fraction fraction)
{
    cout << fraction.numerator << " / " << fraction.denumerator;
    return out;
}
//Tools.
int Fraction::get_min(const int& first_number, const int& second_number)
{
    if(first_number < second_number)
    {
        return first_number;
    }
    return second_number;
}
