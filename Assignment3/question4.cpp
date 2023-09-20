#include<iostream>
using namespace std;

#include <iostream>

class Matrix {
private:
    int** data;
    int rows;
    int cols;

public:
    
    Matrix() {
        data = nullptr;
        rows = 0;
        cols = 0;
    }

    
    Matrix(int numRows, int numCols) {
        rows = numRows;
        cols = numCols;
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
        }
    }

    
    ~Matrix() {
        if (data != nullptr) {
            for (int i = 0; i < rows; ++i) {
                delete[] data[i];
            }
            delete[] data;
        }
    }

    
    void accept() {
        cout << "Enter matrix elements row-wise:" <<endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cin >> data[i][j];
            }
        }
    }

    
    void print() {
        cout << "Matrix:" <<endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << " ";
            }
            cout <<endl;
        }
    }

    
    Matrix add(const Matrix& other) {
        if (rows != other.rows || cols != other.cols) {
            cerr << "Matrix dimensions do not match for addition." <<endl;
            return Matrix();
        }

        Matrix result(rows, cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }

        return result;
    }

   
    Matrix subtract(const Matrix& other) {
        if (rows != other.rows || cols != other.cols) {
            std::cerr << "Matrix dimensions do not match for subtraction." << std::endl;
            return Matrix();
        }

        Matrix result(rows, cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }

        return result;
    }

    
    Matrix multiply(const Matrix& other) {
        if (cols != other.rows) {
            std::cerr << "Matrix dimensions are incompatible for multiplication." << std::endl;
            return Matrix();
        }

        Matrix result(rows, other.cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }

        return result;
    }

   
    Matrix transpose() {
        Matrix result(cols, rows);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[j][i] = data[i][j];
            }
        }

        return result;
    }
};

int main() {
    
    Matrix matrix1;
    Matrix matrix2;

   
    cout << "Enter matrix 1 dimensions (rows columns): ";
    int rows1, cols1;
   cin >> rows1 >> cols1;
    matrix1 = Matrix(rows1, cols1);
    matrix1.accept();

    cout << "Enter matrix 2 dimensions (rows columns): ";
    int rows2, cols2;
   cin >> rows2 >> cols2;
    matrix2 = Matrix(rows2, cols2);
    matrix2.accept();

    
    matrix1.print();
    matrix2.print();

    
    Matrix sum = matrix1.add(matrix2);
    Matrix difference = matrix1.subtract(matrix2);
    Matrix product = matrix1.multiply(matrix2);
    Matrix transpose1 = matrix1.transpose();
    Matrix transpose2 = matrix2.transpose();

    
    cout << "Sum of matrices:" << endl;
    sum.print();

    cout << "Difference of matrices:" << endl;
    difference.print();

    cout << "Product of matrices:" << endl;
    product.print();

    cout << "Transpose of matrix 1:" << endl;
    transpose1.print();

   cout << "Transpose of matrix 2:" << endl;
    transpose2.print();

    return 0;
}