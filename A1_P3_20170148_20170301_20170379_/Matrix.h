#include <iostream>
#include <cstdlib>
using namespace std;

#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
private:
    int rows;
    int columns;
    int** data;

public:
    Matrix();
    Matrix(const int&, const int&);
    Matrix(const int&, const int&, int**);
    Matrix(const Matrix&);
    ~Matrix();

    int get_rows();
    int get_cols();
    Matrix transpose(); //Doesn't Change The Original Matrix.

    void operator= (const Matrix&);
    friend Matrix operator+ (const Matrix&, const Matrix&);
    friend Matrix operator- (const Matrix&, const Matrix&);
    friend Matrix operator* (const Matrix&, const Matrix&);

    friend istream& operator>> (istream&, Matrix&);
    friend ostream& operator<< (ostream&, Matrix);

};

#endif // MATRIX_H
