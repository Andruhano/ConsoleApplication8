#include <iostream>
#include "Matrix.h"

int main() {
    srand(time(0)); 

    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    Matrix<int> mat(rows, cols);

    cout << "Fill the matrix with random values." << endl;
    mat.fillRandom(); 

    cout << "Matrix:" << endl;
    mat.display(); 

    cout << "Max element: " << mat.findMax() << endl;
    cout << "Min element: " << mat.findMin() << endl;

    cout << "Create a second matrix with the same dimensions." << endl;
    Matrix<int> mat2(rows, cols);
    cout << "Fill the second matrix with random values." << endl;
    mat2.fillRandom(); 

    cout << "Second matrix:" << endl;
    mat2.display(); 

    cout << "Sum of matrices:" << endl;
    (mat + mat2).display(); 

    cout << "Difference of matrices:" << endl;
    (mat - mat2).display();

    cout << "Product of matrices:" << endl;
    (mat * mat2).display();

    return 0;
}
