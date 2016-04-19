#include <iostream>
#include <algorithm>
#include <stdexcept>
template <class T>
class Matrix {
    int rows;
    int cols;
    T *m;
public:
    enum { ROWS_MAX = 16384, COLS_MAX = 16384, MEM_MAX = 1073741824 }; 
    Matrix(int rows, int cols, T default_value = T()) {
        if (rows > ROWS_MAX || rows <= 0 ||
            cols > COLS_MAX || cols <= 0) {
            throw std::invalid_argument("!");
        }
        if (rows * cols * sizeof(T) > MEM_MAX) {
            throw std::invalid_argument("!!");
        }
        this->rows = rows;
        this->cols = cols;
        m = new T[rows * cols];
        for (int i = 0; i < rows * cols; ++i) {
            m[i] = default_value;
        }
        // +need to add constructing T array and add 
        // +need to addd mem check
    }
    Matrix(const Matrix &matr) {
        rows = matr.rows;
        cols = matr.cols;
        m = new T[rows * cols];
        std::copy(matr.m, matr.m + cols * rows, m);
        // +need to add copy of array T
    }
    ~Matrix() {
        delete[] m;
        // +need to add destroying of array T
    }
    Matrix& operator=(Matrix matr) {
        std::swap(rows, matr.rows);
        std::swap(cols, matr.cols);
        std::swap(m, matr.m);
        return *this;
    }
    int get_rows() const {
        return rows;
    }
    int get_cols() const {
        return cols;
    }
    T& at(int r, int c) {
        if (r >= rows || r < 0 || c >= cols || c < 0) {
            throw std::range_error("at(r,c) error");
        }
        return m[r * cols + c];
    }
    T at(int r, int c) const {
        if (r >= rows || r < 0 || c >= cols || c < 0) {
            throw std::range_error("at(r,c) const error");
        }
        return m[r * cols + c];
    }
    void print() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << m[i * cols + j] << ' ';
            }
            std::cout << std::endl;
        }
    }
};

/*
int main() {
    Matrix<int> m(5, 5, 1);
    Matrix<int> m2(m);
    m.at(0,0) = 2;
    m.print();
    m2.print();
    Matrix<int> m3(1, 1, 0);
    m3 = m;
    m3.at(0, 1) = 3;
    std::cout << std::endl;
    m.print();
    m2.print();
    m3.print();
}*/
