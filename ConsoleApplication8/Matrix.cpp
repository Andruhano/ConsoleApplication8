#include "Matrix.h"

template class Matrix<int>;

template<typename T>
Matrix<T>::Matrix(int rows, int cols) : rows(rows), cols(cols) 
{
    data = new T * [rows];
    for (int i = 0; i < rows; i++) 
    {
        data[i] = new T[cols];
    }
}

template<typename T>
Matrix<T>::~Matrix() 
{
    for (int i = 0; i < rows; i++) 
    {
        delete[] data[i];
    }
    delete[] data;
}

template<typename T>
void Matrix<T>::fillRandom() 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            data[i][j] = static_cast<T>(rand() % 100); 
        }
    }
}

template<typename T>
void Matrix<T>::fillFromKeyboard() 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            cout << "Enter value for element (" << i << ", " << j << "): ";
            cin >> data[i][j];
        }
    }
}

template<typename T>
void Matrix<T>::display() 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            cout << data[i][j] << ' ';
        }
        cout << endl;
    }
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const 
{
    Matrix<T> result(rows, cols);
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& other) const 
{
    Matrix<T> result(rows, cols);
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other) const 
{
    if (cols != other.rows) 
    {
        cout << "Error: Number of columns in the first matrix must be equal to the number of rows in the second matrix for multiplication." << endl;
        return Matrix<T>(0, 0);
    }

    Matrix<T> result(rows, other.cols); 

    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < other.cols; j++) 
        {
            result.data[i][j] = 0;
            for (int k = 0; k < cols; k++) 
            {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }

    return result;
}


//template<typename T>
//Matrix<T> Matrix<T>::operator/(const Matrix<T>& other) const {};

template<typename T>
T Matrix<T>::findMax() const 
{
    T max = data[0][0];
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            if (data[i][j] > max) 
            {
                max = data[i][j];
            }
        }
    }
    return max;
}

template<typename T>
T Matrix<T>::findMin() const 
{
    T min = data[0][0];
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            if (data[i][j] < min) 
            {
                min = data[i][j];
            }
        }
    }
    return min;
}
