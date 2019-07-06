#ifndef STUDENTNAME_H
#define STUDENTNAME_H
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class StudentName
{
    public:
        StudentName();
        void MakeName(const string&);
        void Print();
        bool Replace();
        virtual ~StudentName();
    private:
        string name;
};

#endif // STUDENTNAME_H
