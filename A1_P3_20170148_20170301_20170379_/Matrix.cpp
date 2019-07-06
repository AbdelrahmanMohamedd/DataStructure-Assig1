#include "Matrix.h"

Matrix::Matrix()
{
    rows = 0;
    columns = 0;
    data = NULL;
}
Matrix::Matrix(const int& rows, const int& columns)
{
    this -> rows = rows;
    this -> columns = columns;
    //Creating the Matrix.
    data = new int*[rows];
    for(int i = 0 ; i < rows ; i++)
    {
        data[i] = new int[columns];
    }
    //Filling the Matrix with initial values(0).
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            data[i][j] = 0;
        }
    }
}
Matrix::Matrix(const int& rows, const int& columns, int** copied_data)
{
    this -> rows = rows;
    this -> columns = columns;
    //Creating the Matrix.
    data = new int*[rows];
    for(int i = 0; i < rows; i++)
    {
        data[i] = new int[columns];
    }
    //Filling the Matrix with the data.
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            data[i][j] = copied_data[i][j];
        }
    }
}
Matrix::Matrix(const Matrix& copied_matrix)
{
    rows = copied_matrix.rows;
    columns = copied_matrix.columns;
    //Creating the Matrix.
    data = new int*[rows];
    for(int i = 0 ; i < rows ; i++)
    {
        data[i] = new int[columns];
    }
    //Filling the Matrix with the data.
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            data[i][j] = copied_matrix.data[i][j];
        }
    }
}
Matrix::~Matrix()
{
    if((rows != 0) && (columns != 0))
    {
        for(int i = 0; i < rows; i++)
        {
            delete[] data[i];
        }
        delete[] data;
    }
}
int Matrix::get_rows()
{
    return rows;
}
int Matrix::get_cols()
{
    return columns;
}
//Matrix Transpose.
Matrix Matrix::transpose()
{
    //Creating an Array for storing the transpose.
    int** temp_data;
    temp_data = new int*[columns];
    for(int i = 0; i < columns; i++)
    {
        temp_data[i] = new int[rows];
    }
    //Filling the Array.
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            temp_data[j][i] = data[i][j];
        }
    }
    Matrix transpose_mat(columns, rows, temp_data);
    for(int i = 0; i < columns; i++)
    {
        delete[] temp_data[i];
    }
    delete[] temp_data;
    return transpose_mat;
}
// Operators Overloading.
void Matrix::operator= (const Matrix& copied_mat)
{
    //Case where the Matrix has previous data.
    if((rows != 0) && (columns != 0))
    {
        for(int i = 0; i < rows; i++)
        {
            delete[] data[i];
        }
        delete[] data;
    }
    //Creating the Matrix.
    rows = copied_mat.rows;
    columns = copied_mat.columns;
    data = new int*[rows];
    for(int i = 0; i < rows; i++)
    {
        data[i] = new int[columns];
    }
    //filling the Matrix from another Matrix.
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            data[i][j] = copied_mat.data[i][j];
        }
    }
}
Matrix operator+ (const Matrix& mat1, const Matrix& mat2)
{
    if((mat1.rows != mat2.rows) || (mat1.columns != mat2.columns))
    {
        cout << "The Two Matrices Doesn't Have The Same Dimensions"
             << ", Summation Can't be done." << endl
             << "Program Will Terminate." << endl;
        exit(1);
    }
    int** temp_data;
    //Creating the Matrix.
    temp_data = new int*[mat1.rows];
    for(int i = 0; i < mat1.rows; i++)
    {
        temp_data[i] = new int[mat1.columns];
    }
    //Filling the Matrix with the Summation.
    for(int i = 0; i < mat1.rows; i++)
    {
        for(int j = 0; j < mat1.columns; j++)
        {
            temp_data[i][j] = mat1.data[i][j] + mat2.data[i][j];
        }
    }
    Matrix sum_mat(mat1.rows, mat1.columns, temp_data);
    for(int i = 0; i < mat1.rows; i++)
    {
        delete[] temp_data[i];
    }
    delete[] temp_data;
    return sum_mat;
}
Matrix operator- (const Matrix& mat1, const Matrix& mat2)
{
    if((mat1.rows != mat2.rows) || (mat1.columns != mat2.columns))
    {
        cout << "The Two Matrices Doesn't Have The Same Dimensions"
             << ", Subtraction Can't be done." << endl
             << "Program Will Terminate." << endl;
        exit(1);
    }
    int** temp_data;
    //Creating the Matrix.
    temp_data = new int*[mat1.rows];
    for(int i = 0; i < mat1.rows; i++)
    {
        temp_data[i] = new int[mat1.columns];
    }
    //Filling the Matrix with the subtraction.
    for(int i = 0; i < mat1.rows; i++)
    {
        for(int j = 0; j < mat1.columns; j++)
        {
            temp_data[i][j] = mat1.data[i][j] - mat2.data[i][j];
        }
    }
    Matrix sub_mat(mat1.rows, mat2.columns, temp_data);
    for(int i = 0; i < mat1.rows; i++)
    {
        delete[] temp_data[i];
    }
    delete[] temp_data;
    return sub_mat;
}
Matrix operator* (const Matrix& mat1, const Matrix& mat2)
{
    //Test Case.
    if(mat1.columns != mat2.rows)
    {
        cout << "The Number of Rows of The First Matrix Doesn't Equal"
             << " The Number of Columns of The Second Matrix." << endl
             << "Multiplication Can't Be Done, Program Will Terminate." << endl;
        exit(1);
    }
    //Creating a Matrix for the result.
    int** temp_data;
    temp_data = new int*[mat1.rows];
    for(int i = 0; i < mat1.rows; i++)
    {
        temp_data[i] = new int[mat2.columns];
    }
    //Filling the Matrix with the multiplication.
    for(int i = 0; i < mat1.rows; i++)
    {
        for(int index = 0; index < mat2.columns; index++)
        {

            int sum = 0;
            for(int j = 0; j < mat1.columns; j++)
            {
                sum += mat1.data[i][j] * mat2.data[j][index];
            }
            temp_data[i][index] = sum;
        }
    }
    Matrix product_mat(mat1.rows, mat2.columns, temp_data);
    for(int i = 0; i < mat1.rows; i++)
    {
        delete[] temp_data[i];
    }
    delete[] temp_data;
    return product_mat;
}
istream& operator>> (istream& in, Matrix& mat)
{
    //The case where the matrix has previous data.
    if((mat.rows != 0) && (mat.columns != 0))
    {
        for(int i = 0; i < mat.rows; i++)
        {
            delete[] mat.data[i];
        }
        delete[] mat.data;
    }
    cout << "Enter The Number of Rows :";
    cin >> mat.rows;

    cout << "Enter The Number of Columns :";
    cin >> mat.columns;
    //Creating the Matrix.
    mat.data = new int*[mat.rows];
    for(int i = 0; i < mat.rows; i++)
    {
        mat.data[i] = new int[mat.columns];
    }
    //Filling the Matrix from the user.
    for(int i = 0; i < mat.rows; i++)
    {
        cout << "Enter The " << i +1 << " Row :";
        for(int j = 0; j < mat.columns; j++)
        {
            cin >> mat.data[i][j];
        }
    }
    return in;
}
ostream& operator<< (ostream& out, Matrix mat)
{
    cout << "The Data of The Matrix." << endl;
    for(int i = 0; i < mat.rows; i++)
    {
        for(int j = 0; j < mat.columns; j++)
        {
            cout << mat.data[i][j] << " ";
        }
        cout << endl;
    }
    return out;
}
