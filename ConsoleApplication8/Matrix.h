#pragma once
#include <iostream>
using namespace std;

template<typename T>
class Matrix 
{
int rows;
int cols;
T** data;

public:
    Matrix(int rows, int cols);
    ~Matrix();
    void fillRandom();
    void fillFromKeyboard();
    void display();
    Matrix<T> operator+(const Matrix<T>& other) const;
    Matrix<T> operator-(const Matrix<T>& other) const;
    Matrix<T> operator*(const Matrix<T>& other) const;
    //Matrix<T> operator/(const Matrix<T>& other) const;
    T findMax() const;
    T findMin() const;
};

