// Faculty of Computers and Information
/// CS214 - Data Structure - Assignment 1 - Task 1 : Big Decimal Int
// Date: 8/3/2019
/// Student 1: Abdelrahman Mohamed Ahmed Mahmoud  ID:20170148  G:10
/// Student 2: Monir Sabry yousef Ahmed           ID:20170301  G:10
/// Student 3: Mohamed Hassan ElDoma              ID:20170379  G:10
///================================================================
#include <iostream>
#include <set>
using namespace std;

set<string>Permutations;
void RecPermute(string soFar, string rest)
{
    if (rest == "") /// No more characters

    {
        cout << soFar <<endl;    /// Print the word
    }
    else /// Still more chars
/// For each remaining char
        for (int i = 0; i < rest.length(); i++)
        {
            string next = soFar + rest[i]; // Glue next char
            string remaining = rest.substr(0, i)+ rest.substr(i+1);
            RecPermute(next, remaining);
        }
}
/// "wrapper" function
void ListPermutations(string s)
{
    RecPermute("", s);
}
int main()
{   string w;
    cout<<"ENTER A WORD : ";
    cin>>w;
    ListPermutations(w);
    set<string>::iterator x;
    for(x=Permutations.begin(); x!=Permutations.end(); x++)
    {
        cout<<*x<<endl;
    }
    return 0;
}
