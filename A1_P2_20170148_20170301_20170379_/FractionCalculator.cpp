#include "FractionCalculator.h"

FractionCalculator::FractionCalculator()
{
    Fraction frac1;
    Fraction frac2;
    print_menu();
    while(true)
    {
        char choice;
        cout << "Enter A Choose From The Menu :";
        cin >> choice;
        if(choice == '1')
        {
            cout << "Enter The First Fraction." << endl;
            cin >> frac1;

            cout << "Enter The Second Fraction." << endl;
            cin >> frac2;

            cout << frac1 + frac2 << endl;
        }
        else if(choice == '2')
        {
            cout << "Enter The First Fraction." << endl;
            cin >> frac1;

            cout << "Enter The Second Fraction." << endl;
            cin >> frac2;

            cout << frac1 - frac2 << endl;
        }
        else if(choice == '3')
        {
            cout << "Enter The First Fraction." << endl;
            cin >> frac1;

            cout << "Enter The Second Fraction." << endl;
            cin >> frac2;

            cout << frac1 * frac2 << endl;
        }
        else if(choice == '4')
        {
            cout << "Enter The First Fraction." << endl;
            cin >> frac1;

            cout << "Enter The Second Fraction." << endl;
            cin >> frac2;

            cout << frac1 / frac2 << endl;
        }
        else if(choice == '5')
        {
            cout << "Enter The First Fraction." << endl;
            cin >> frac1;

            cout << "Enter The Second Fraction." << endl;
            cin >> frac2;

            cout << (frac1 > frac2) << endl;
        }
        else if(choice == '6')
        {
            cout << "Enter The First Fraction." << endl;
            cin >> frac1;

            cout << "Enter The Second Fraction." << endl;
            cin >> frac2;

            cout << (frac1 < frac2) << endl;
        }
        else if(choice == '7')
        {
            cout << "Enter The First Fraction." << endl;
            cin >> frac1;

            cout << "Enter The Second Fraction." << endl;
            cin >> frac2;

            cout << (frac1 == frac2) << endl;
        }
        else if(choice == '8')
        {
            cout << "Enter The First Fraction." << endl;
            cin >> frac1;

            cout << "Enter The Second Fraction." << endl;
            cin >> frac2;

            cout << (frac1 >= frac2) << endl;
        }
        else if(choice == '9')
        {
            cout << "Enter The First Fraction." << endl;
            cin >> frac1;

            cout << "Enter The Second Fraction." << endl;
            cin >> frac2;

            cout << (frac1 <= frac2) << endl;
        }
        else if(choice == 'E')
        {
            break;
        }
        else
        {
            cin.ignore(1000, '\n');
            cout << "Invalid Input." << endl;
        }
    }
}
void FractionCalculator::print_menu()
{
    cout << "1- Adding." << endl;
    cout << "2- Subtracting." << endl;
    cout << "3- Multiplication." << endl;
    cout << "4- Division." << endl;
    cout << "5- Greater Than." << endl;
    cout << "6- Less Than." << endl;
    cout << "7- Equal." << endl;
    cout << "8- Greater Than or Equal." << endl;
    cout << "9- Less Than or Equal." << endl;
    cout << "E- Exit The Program." << endl;
}
