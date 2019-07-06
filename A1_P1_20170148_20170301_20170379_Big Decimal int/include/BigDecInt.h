// Faculty of Computers and Information
/// CS214 - Data Structure - Assignment 1 - Task 1 : Big Decimal Int
// Date: 8/3/2019
/// Student 1: Abdelrahman Mohamed Ahmed Mahmoud   ID:20170148  G:10
/// Student 2: Monir Sabry yousef Ahmed            ID:20170301  G:10
/// Student 3: Mohamed Hassan ElDoma               ID:20170379  G:10
///================================================================
#ifndef BIGDECIMALINT_H
#define BIGDECIMALINT_H
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;

class BigDecimalInt
{
private:
	string str;
	void fillZeros(int maxSize, string& str1, string& str2);  // filling the another smaller string with zeros
public:
    int size();
    BigDecimalInt (string decStr);          // Initialize from string and rejects bad input
    BigDecimalInt (int decInt);             // Initialize from integer
    BigDecimalInt operator+ (BigDecimalInt anotherDec);
    BigDecimalInt operator- (BigDecimalInt anotherDec);
    BigDecimalInt operator= (BigDecimalInt anotherDec);
    friend ostream& operator << (ostream& out, BigDecimalInt printStr);
};
#endif
