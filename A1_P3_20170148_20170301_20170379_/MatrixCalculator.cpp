#include "MatrixCalculator.h"

MatrixCalculator::MatrixCalculator()
{
    Matrix mat1;
    Matrix mat2;

    char choice;
    print_menu();
    while(true)
    {
        cout << "Enter A Choice From The Menu :";
        cin >> choice;
        if(choice == '1')
        {
            while(true)
            {
                cout << "Enter The First Matrix." << endl;
                cin >> mat1;
                cout << endl;
                cout << "Enter The Second Matrix." << endl;
                cin >> mat2;
                cout << endl;
                if((mat1.get_rows() != mat2.get_rows())
                || (mat1.get_cols() != mat2.get_cols()))
                {
                    cout << "The Matrices Must Have The Same Dimensions." << endl << endl;
                    continue;
                }
                break;
            }
            cout << "The Summation IS." << endl;
            cout << mat1 + mat2 << endl;
        }
        else if(choice == '2')
        {
            while(true)
            {
                cout << "Enter The First Matrix." << endl;
                cin >> mat1;
                cout << endl;
                cout << "Enter The Second Matrix." << endl;
                cin >> mat2;
                cout << endl;
                if((mat1.get_rows() != mat2.get_rows())
                || (mat1.get_cols() != mat2.get_cols()))
                {
                    cout << "The Matrices Must Have The Same Dimensions." << endl << endl;
                    continue;
                }
                break;
            }
            cout << "The Subtraction IS." << endl;
            cout << mat1 - mat2 << endl;
        }
        else if(choice == '3')
        {
             while(true)
            {
                cout << "Enter The First Matrix." << endl;
                cin >> mat1;
                cout << endl;
                cout << "Enter The Second Matrix." << endl;
                cin >> mat2;
                cout << endl;
                if(mat1.get_cols() != mat2.get_rows())
                {
                    cout << "The #OF Columns OF The First Matrix Must Equal The"
                         << " #OF Rows OF The Second Matrix." << endl << endl;
                    continue;
                }
                break;
            }
            cout << "The Multiplication IS." << endl;
            cout << mat1 * mat2 << endl;
        }
        else if(choice == '4')
        {
            cout << "Enter The Matrix." << endl;
            cin >> mat1;
            cout << "The Transpose IS." << endl;
            cout << mat1.transpose() << endl;
        }
        else if(choice == 'E' || choice == 'e')
        {
            return;
        }
        else
        {
            cout << "Invalid Input." << endl;
            cin.ignore(1000, '\n');
        }
    }
}
void MatrixCalculator::print_menu()
{
    cout << "Welcome To Our Team Matrix Calculator." << endl
         << "-----------------------------------------" << endl << endl;

    cout << "1- Perform Matrix Addition." << endl
         << "2- Perform Matrix Subtraction." << endl
         << "3- Perform Matrix Multiplication." << endl
         << "4- Matrix Transpose." << endl
         << "E- Exit The Program." << endl << endl;
}
