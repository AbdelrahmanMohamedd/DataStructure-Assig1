// Faculty of Computers and Information
/// CS214 - Data Structure - Assignment 1 - Task 1 : Big Decimal Int
// Date: 8/3/2019
/// Student 1: Abdelrahman Mohamed Ahmed Mahmoud  ID:20170148  G:10
/// Student 2: Monir Sabry yousef Ahmed           ID:20170301  G:10
/// Student 3: Mohamed Hassan ElDoma              ID:20170379  G:10
///================================================================
#include <iostream>
#include <sstream>
#include <string>
#include "BigDecInt.h"
using namespace std;
int main()
{
    BigDecimalInt num1("123456789012345678901234567890");
    BigDecimalInt num2("113456789011345678901134567890");
    BigDecimalInt num3 = num2 + num1;
    BigDecimalInt num4 = num2 - num1;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;
    cout << "num2 + num1 = " << num3 << endl;
    cout << "num2 - num1 = " << num4 << endl;
    cout<< endl;
///================================================================ Example 1
	BigDecimalInt num5("333333333333333333333333333333");
	BigDecimalInt num6("-111111111111111111111111111111");
	BigDecimalInt num7 = num5 + num6;
	BigDecimalInt num8 = num5 - num6;
	cout << "num5 = " << num5 << endl;
	cout << "num6 = " << num6 << endl;
	cout << "num5 + num6 = " << num7 << endl;
	cout << "num5 - num6 = " << num8 << endl;
    cout << endl;
///================================================================ Example 2
	BigDecimalInt num9("-333333333333333333333333333333");
	BigDecimalInt num10("111111111111111111111111111111");
	BigDecimalInt num11 = num9 + num10;
	BigDecimalInt num12 = num9 - num10;
	cout << "num9 = " << num9 << endl;
	cout << "num10 = " << num10 << endl;
	cout << "num9 + num10 = " << num11 << endl;
	cout << "num9 - num10 = " << num12 << endl;
    cout << endl;
///================================================================ Example 3
	BigDecimalInt num13("-333333333333333333333333333333");
	BigDecimalInt num14("-111111111111111111111111111111");
	BigDecimalInt num15 = num13 + num14;
	BigDecimalInt num16 = num13 - num14;
	cout << "num13 = " << num13 << endl;
	cout << "num14 = " << num14 << endl;
	cout << "num13 + num14 = " << num15 << endl;
	cout << "num13 - num14 = " << num16 << endl;
    cout << endl;
///================================================================ Example 4
	BigDecimalInt num17("333333333333333333333333333333");
	BigDecimalInt num18("111111111111111111111111111111");
	BigDecimalInt num19 = num17 + num18;
	BigDecimalInt num20 = num17 - num18;
	cout << "num17 = " << num17 << endl;
	cout << "num18 = " << num18 << endl;
	cout << "num17 + num18 = " << num19 << endl;
	cout << "num17 - num18 = " << num20 << endl;
    cout << endl;
///================================================================
}
