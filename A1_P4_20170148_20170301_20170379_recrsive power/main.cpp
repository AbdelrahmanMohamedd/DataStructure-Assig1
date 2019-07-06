// Faculty of Computers and Information
/// CS214 - Data Structure - Assignment 1 - Task 1 : Big Decimal Int
// Date: 8/3/2019
/// Student 1: Abdelrahman Mohamed Ahmed Mahmoud  ID:20170148  G:10
/// Student 2: Monir Sabry yousef Ahmed           ID:20170301  G:10
/// Student 3: Mohamed Hassan ElDoma              ID:20170379  G:10
///================================================================
#include <iostream>
#include <cmath>

using namespace std;

double power(double x1, int y1)
{
    if (y1==0){return 1;}
    else if (y1<0)
    {
        y1=abs(y1);
        return 1/(x1*power(x1,y1-1));
    }
    else return x1*power(x1,y1-1);

}
int power1(int b1, int z1)
{

    if (z1==0)return 1;
    else if(z1%2==0)return power1(b1 , z1/2)*power1(b1 , z1/2);
    else return b1*power1(b1 , z1-1);
    }


int main()
{

    int x;
    int y;
    cout<<"enter number for x : "<<endl;
    cin>>x;
    cout<<"enter number for y : "<<endl;
    cin>>y;
    cout<<x<<"  power  "<<y<<" = "<<power(x,y)<<endl;
    cout<<x<<"  power  "<<y<<" = "<<power1(x,y)<<endl;


    return 0;
}
