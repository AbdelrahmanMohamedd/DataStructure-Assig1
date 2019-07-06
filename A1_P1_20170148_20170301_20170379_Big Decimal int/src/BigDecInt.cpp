// Faculty of Computers and Information
/// CS214 - Data Structure - Assignment 1 - Task 1 : Big Decimal Int
// Date: 8/3/2019
/// Student 1: Abdelrahman Mohamed Ahmed Mahmoud  ID:20170148  G:10
/// Student 2: Monir Sabry yousef Ahmed          ID:20170301  G:10
/// Student 3: Mohamed Hassan ElDoma             ID:20170379  G:10
#include "BigDecInt.h"
///================================================================ Function for filling the smaller string with zeros.
void BigDecimalInt::fillZeros(int maxSize, string& str1, string& str2){
	int diff;
	if (str1.length() > str2.length())
	{
		diff = maxSize - str2.length();
		for (int i = 0; i < diff; i++)
			str2 = "0" + str2;
	}
	else if (str1.length() < str2.length())
	{
		diff = maxSize - str1.length();
		for (int i = 0; i < diff; i++)
			str1 = "0" + str1;
	}
}
///================================================================ Constractor: Initialize from string.
BigDecimalInt::BigDecimalInt(string decStr){
	str = decStr;
}
///================================================================ Constractor: Initialize from Converting integer to string.
BigDecimalInt::BigDecimalInt(int decStr = 0){
	stringstream conv;
	conv << decStr;
	str = conv.str();
}
///================================================================ Operator + to get the sum of two numbers
BigDecimalInt BigDecimalInt::operator+ (BigDecimalInt anotherDec){
	string first = str;
	string second = anotherDec.str;
	bool bothNegative = false;
	if (first[0] == '-' && second[0] == '-') //if both are negative, then add and append -ve sign to the result
	{
		bothNegative = true;
		first = first.substr(1);
		second = second.substr(1);
	}
	else if (first[0] == '-')
	{
		BigDecimalInt negative(first.substr(1)); // removing the -ve sign;
		return anotherDec - negative;
	}
	else if (second[0] == '-')
	{
		BigDecimalInt negative(second.substr(1)); // removing the -ve sign;
		BigDecimalInt thisStr(first);
		return thisStr - negative;
	}
	int maxSize = (first.length() > second.length()) ? first.length() : second.length();
	fillZeros(maxSize, first, second);
	string result = "";
	int temp;
	bool carry = false;
	for (int i = maxSize - 1; i >= 0; i--)
	{
		temp = (first[i] + second[i] - 48);
		if (carry)
			temp = (first[i] + second[i] - 48) + 1;
		if ((temp - 48) > 9)
		{
			temp -= 10;
			carry = 1;
		}
		else
			carry = 0;
		result = (char)(temp)+result;
	}
	if (carry)
		result = "1" + result;
	if (bothNegative)
		result = "-" + result;
	BigDecimalInt sum(result);
	return sum;
}
///================================================================ Operator - to get the difference between two numbers
BigDecimalInt BigDecimalInt::operator- (BigDecimalInt anotherDec){
	string first = str;
	string second = anotherDec.str;
	if (first[0] == '-' && second[0] == '-')	 //if both are negative, then anotherDec becomes +ve ; -123- (-200) = -123 + 200 = 200-123
	{
		first = first.substr(1);
		second = second.substr(1);
		string temp = first;		// swap the two numbers
		first = second;
		second = temp;
	}
	else if (first[0] == '-')
	{
		first = first.substr(1);		//(if the first is negative, then call + and add -ve sign to the result (-123 - 200) = -(123+200)
		BigDecimalInt temp(first);
		BigDecimalInt sum = temp + anotherDec;
		sum.str = "-" + sum.str;
		return sum;
	}
	else if (second[0] == '-')
	{
		//(if the second is negative, then call Add (100 - (-100) = 100+100)
		BigDecimalInt negative(second.substr(1)); // removing the -ve sign;
		BigDecimalInt thisStr(first);
		return thisStr + negative;
	}
	int maxSize = (first.length() > second.length()) ? first.length() : second.length();
	fillZeros(maxSize, first, second);
	bool secondIsGreater = false;
	if (second[0] > first[0])
	{
		// swap the two numbers and add -ve sign to the result
		string temp = first;
		first = second;
		second = temp;
		secondIsGreater = true;
	}
	string result = "";
	int temp;
	bool borrow = false;
	for (int i = maxSize - 1; i >= 0; i--)
	{
		temp = first[i];
		if (borrow)
		{
			temp = first[i] - 1;
			borrow = false;
		}
		if (temp >= second[i])
		{
			result = (char)(temp - second[i] + 48) + result;
			borrow = false;
		}
		else if (temp < second[i])  // borrow
		{
			temp += 10;
			borrow = true;
			result = (char)(temp - second[i] + 48) + result;
		}
	}
	if (secondIsGreater)
		result = "-" + result;
	BigDecimalInt sub(result);
	return sub;
}
///================================================================ Operator = to Equate between the two numbers
BigDecimalInt BigDecimalInt::operator= (BigDecimalInt anotherDec){
    string first = str;
	string second = anotherDec.str;
	cout<<first<<" = "<<second<<endl;
}
///================================================================ Operator << to print the result
ostream& operator << (ostream& out, BigDecimalInt printStr){
	out << printStr.str;
	return out;
}
