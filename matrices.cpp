//EECS 348 Lab 8 
//Perform matrix operations on an NxN matrix
//Inputs: 
//Outputs: 
//Myself, ChatGPT
//Joey Ippolito, 3114450
// 4/2/2025

#include <iostream>
#include <fstream>
#include <vestor>
#include <iomanip>

using namespace std;

class Matrix {
private:
    int N;
    vector<vector<int>> mtrx;
public:
    Matrix(int size) : N(size), mtrx(size, vector<int>(size, 0)) {}

    void readfile(ifstream &inputfile) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                inputfile >> mtrx[i][j];
            }
        }
    }

    void print() cons {
        for (const auto &row : mtrx) {
            for (int val : row)
                cout << setw(4) << val;
            cout << endl;
        }
    }

    Matrix add(const Matrix &other) const {
        matrix result(N);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                added.mtrx[i][j] = mtrx[i][j] + other.mtrx[i][j];
        return added;
            }
        }
    }

    Matrix multiply(const Matrix &other) const {
        Matrix result(N);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int k = 0; k < N; ++k) {
                    multiplied.mtrx[i][j] += mtrx[i][k] * other.mtrx[k][j];
                return multiplied;
                }
            }
        }
    }

    int diagonalsum() const {
        int sum = 0;
        for (int i = 0; i < N; ++i) {
            sum += mtrx[i][i];
            sum += mtrx[i][N-1-i];
        }
        return sum;
    }

    void swap rows(int row1, int row2) {
        swap(mtrx[row1], mtrx[row2]);
    }

    void swap columns(int col1, int col2) {
        for (int i = 0; i < N; ++i) {
            swap(mtrx[i][col1], mtrx[i][col2]);
        }
    }

    void chngevalue(int row, int col, int value) {
        mtrx[row][col] = value;
    }
};

int main() {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    ifstream inputfile(filename);
    if (!inputfile) {
        cerr << "Error opening file." << endl;
        return 1;
    }
    int N;
    inputfile >> N;
    Matrix matrixA(N), matrixB(N);
    matrixA.readfile(inputfile);
    matrixB.readfile(inputfile);
    inputfile.close();
    
    cout << "Matrix A:\n"; matrixA.print();
    cout << "Matrix B:\n"; matrixB.print();

    cout << "A + B:\n"; matrixA.add(matrixB).print();
    cout << "A * B:\n"; matrixA.multiply(matrixB).print();
    cout << "Diagonal sum of A: " << matrixA.diagonalsum() << endl;
    cout << "Diagonal sum of B: " << matrixB.diagonalsum() << endl;

    cout << "Swapping rows 0 and 1 in A:\n"; matrixA.swap_rows(0, 1); matrixA.print();
    cout << "Swapping columns 0 and 1 in A:\n"; matrixA.swap_columns(0, 1); matrixA.print();
    cout << "Changing value at (0, 0) in A to 99:\n"; matrixA.chngvalue(0, 0, 99); matrixA.print();
    cout << "Changing value at (1, 1) in B to 99:\n"; matrixB.chngvalue(1, 1, 99); matrixB.print();

    return 0;
}
