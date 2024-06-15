#include <iostream>

class Matrix {
private:
    double** data;
    int rows, cols;

    void allocateData() {
        data = new double*[rows];
        for (int i = 0; i < rows; ++i)
            data[i] = new double[cols]();
    }
    void deallocateData() {
        for (int i = 0; i < rows; ++i)
            delete[] data[i];
        delete[] data;
    }

public:
    Matrix(int row, int col) : rows(row), cols(col) {
        allocateData();
    }
    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
        allocateData();
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                data[i][j] = other.data[i][j];
    }
    ~Matrix() {
        deallocateData();
    }

    double& operator()(int i, int j) {
        return data[i][j]; 
    }

    friend std::istream& operator>>(std::istream& is, Matrix& matrix) {
        for (int i = 0; i < matrix.rows; ++i)
            for (int j = 0; j < matrix.cols; ++j)
                is >> matrix(i, j);
        return is;
    }
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        for (int i = 0; i < matrix.rows; ++i){
            for (int j = 0; j < matrix.cols; ++j) {
                if (j != 0) os << " ";
                os << matrix.data[i][j];
            }
            if (i != matrix.rows - 1) os << std::endl;
        }
        return os;
    }

    Matrix& operator+=(const Matrix& other) {
        if (rows != other.rows || cols != other.cols) {
            std::cout << "ERROR!" << std::endl;
            return *this;
        }
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                data[i][j] += other.data[i][j];
        return *this;
    }
    Matrix& operator *=(const Matrix& other) {
        if (cols != other.rows) {
            std::cout << "ERROR!" << std::endl;
            return *this;
        }
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < other.cols; ++j)
                for (int k = 0; k < cols; ++k)
                    result(i, j) += data[i][k] * other.data[k][j];
        *this = result;
        return *this;
    }
    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            deallocateData();
            rows = other.rows;
            cols = other.cols;
            allocateData();
            for (int i = 0; i < rows; ++i)
                for (int j = 0; j < cols; ++j)
                    data[i][j] = other.data[i][j];
        }
        return *this;
    }
};

int main() {
    int row1, col1, row2, col2;

    std::cin >> row1 >> col1;
    Matrix table1(row1, col1);
    std::cin >> table1;

    std::cin >> row2 >> col2;
    Matrix table2(row2, col2);
    std::cin >> table2;

    if (row1 / 2 < row1 && col1 / 2 < col1) 
        std::cout << table1(row1 / 2, col1 / 2) << std::endl;
     else 
        std::cout << "ERROR!" << std::endl;
    

    if (col1 == row2) {
        table1 *= table2;
        std::cout << table1 << std::endl;
    } else 
        std::cout << "ERROR!" << std::endl;


    if (row1 == row2 && col1 == col2) {
        table1 += table2;
        std::cout << table1 << std::endl;
    } else 
        std::cout << "ERROR!" << std::endl;

    table1 = table2;
    std::cout << table1 << std::endl;

    return 0;
}
