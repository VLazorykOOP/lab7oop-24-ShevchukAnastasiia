#include <iostream>
using namespace std;

template<typename T>
class Matrix {
private:
    int rows, cols;
    T** data;

public:
    // Конструктор
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new T*[rows];
        for (int i = 0; i < rows; i++)
            data[i] = new T[cols]();
    }

    // Копіюючий конструктор
    Matrix(const Matrix& other) {
        rows = other.rows;
        cols = other.cols;
        data = new T*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new T[cols];
            for (int j = 0; j < cols; j++)
                data[i][j] = other.data[i][j];
        }
    }

    // Деструктор
    ~Matrix() {
        for (int i = 0; i < rows; i++)
            delete[] data[i];
        delete[] data;
    }

    // Оператор присвоєння =
    Matrix& operator=(const Matrix& other) {
        if (this == &other) return *this;

        // Очистити старі дані
        for (int i = 0; i < rows; i++)
            delete[] data[i];
        delete[] data;

        // Копіювання
        rows = other.rows;
        cols = other.cols;
        data = new T*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new T[cols];
            for (int j = 0; j < cols; j++)
                data[i][j] = other.data[i][j];
        }

        return *this;
    }

    // Оператор [] — доступ до рядка
    T* operator[](int index) {
        return data[index];
    }

    // Оператор + (додавання двох матриць)
    Matrix operator+(const Matrix& other) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    // Оператор +=
    Matrix& operator+=(const Matrix& other) {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                data[i][j] += other.data[i][j];
        return *this;
    }

    // Вивід матриці
    void print() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                cout << data[i][j] << "\t";
            cout << endl;
        }
    }
};

// === Тестування ===
int main() {
    Matrix<int> A(2, 2);
    Matrix<int> B(2, 2);

    // Ініціалізація
    A[0][0] = 1; A[0][1] = 2;
    A[1][0] = 3; A[1][1] = 4;

    B[0][0] = 5; B[0][1] = 6;
    B[1][0] = 7; B[1][1] = 8;

    cout << "Matrix A:\n"; A.print();
    cout << "Matrix B:\n"; B.print();

    Matrix<int> C = A + B;
    cout << "Matrix C = A + B:\n"; C.print();

    A += B;
    cout << "Matrix A after A += B:\n"; A.print();

    return 0;
}
