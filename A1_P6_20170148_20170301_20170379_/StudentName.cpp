#include "StudentName.h"
#include <iostream>
using namespace std;



StudentName::StudentName()
{
    string n;
    cout<<"ENTER YOUR FULL NAME : "<<endl;
    getline(cin, n);
    name=n;
    MakeName(name);

}

void StudentName:: MakeName(const string& s)
{

int  num_of_space=0;
    for (int i=0;i<s.length();i++)
        if(s[i]==' ')
        num_of_space++;
    cout<<num_of_space;
    if(num_of_space==0)
    {

        string x=s.substr(0,s.length());
        name=x+' '+x+' '+x;
    }

    else if (num_of_space==1)
    {
        int i=0;
        while(s[i]!=' ')i++;
        string x=s.substr(i+1,s.length());
        name=name+' '+x;
    }

}

bool StudentName::Replace()
{
    cout<<"ENTER POSITION X AND Y FOR REPLACE :M"<<endl;
    int x,y;
    cin>>x>>y;
    vector<string> Newname;

    int i=0;

    while (i != name.size())
    {
     while (i != name.size() && name[i]==' ')
     {
        i++;
    }
     int k = i;
     while (k != name.size() && name[k]!=' ')k++;
        Newname.push_back(name.substr(i, k - i));
        i = k;
    }

    if ( x<1 || x>Newname.size() || y<1 || y>Newname.size())
        {
            cout<<"ERROR "<<endl;

            return false;
        }
    else
    {
        string temp ;
        temp=Newname[x-1];
        Newname[x-1]=Newname[y-1];
        Newname[y-1]=temp;

        name="";
        for(unsigned int i=0;i<Newname.size();i++)
            {   if(i==Newname.size()-1)
                    name+=Newname[i];
                else
                    name+=Newname[i]+' ';
            }

        return true;
    }
}

void StudentName::Print()
{

    int i=0,j=0;
    while (i != name.size())
    {
     while (i != name.size() && name[i]==' ')i++;
     int k = i;
     while (k != name.size() && name[k]!=' ')k++;

        cout<<++j<<")"<<name.substr(i, k - i)<<endl;
        i = k;
    }
}

StudentName::~StudentName()
{

}
