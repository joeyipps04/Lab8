//EECS 348 Lab 8 
//Perform matrix operations on an NxN matrix
//Inputs: 
//Outputs: 
//Myself, ChatGPT
//Joey Ippolito, 3114450
// 4/2/2025

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
//imports necessary libraries. Used chatgpt to know which libraries to import
using namespace std;
//avoids writing std::
class Matrix {  //class to represent a matrix
private:    //private variables
    int N;  //size of matrix
    vector<vector<int>> mtrx;   //vector of vectors to represent the matrix
public:   //public functions
    Matrix(int size) : N(size), mtrx(size, vector<int>(size, 0)) {} //initializes matrix of size N and all 0's

    void readfile(ifstream &inputfile) {    //reads matrix from file
        for (int i = 0; i < N; ++i) {       //iterates through rows
            for (int j = 0; j < N; ++j) {   //iterates through columns
                inputfile >> mtrx[i][j];    //reads values for iterations
            }
        }
    }
    //used chatgpt to help write readfile function
    void print() const {    //prints matrix
        for (const auto &row : mtrx) {  //iterates through rows
            for (int val : row) {  //iterates through columns
                cout << setw(4) << val; //sets width of output to 4 spaces
            }
            cout << endl;   //prints new line after each row
    }
    }
    Matrix add(const Matrix &other) const { //function to add two matrices
        Matrix added(N);    //creates empty matrix of size N to store results
        for (int i = 0; i < N; ++i) {   //iterates through rows
            for (int j = 0; j < N; ++j) {   //iterates through columns
                added.mtrx[i][j] = mtrx[i][j] + other.mtrx[i][j];   //adds values of two matrices
            }
        }
        return added;   //returns added matrix
    }

    Matrix multiply(const Matrix &other) const {    //function to multiply two matrices
        Matrix multiplied(N);   //creates empty matrix of size N to store results
        for (int i = 0; i < N; ++i) {   //iterates through rows
            for (int j = 0; j < N; ++j) {   //iterates through columns
                for (int k = 0; k < N; ++k) {   //iterates through columns of first matrix and rows of second matrix
                    multiplied.mtrx[i][j] += mtrx[i][k] * other.mtrx[k][j]; //multiplies values of two matrices
                }
            }
        }
        return multiplied;  //returns multiplied matrix
    }

    int diagonalsum() const {   //function add values of diagonal of matrix
        int sum = 0;    //initializes sum to 0
        for (int i = 0; i < N; ++i) {   //iterates through rows
            sum += mtrx[i][i];  //adds values of diagonal from top left to bottom right
            sum += mtrx[i][N-1-i];  //adds values of diagonal from top right to bottom left
        }
        return sum;  //returns sum of diagonals
    }

    void swaprows(int row1, int row2) { //function to swap two rows of matrix
        swap(mtrx[row1], mtrx[row2]);   //swaps rows using std swap function
    }
    //used chatgpt to help find swap function 
    void swapcolumns(int col1, int col2) {  //function to swap two columns of matrix
        for (int i = 0; i < N; ++i) {   //iterates through rows
            swap(mtrx[i][col1], mtrx[i][col2]); //swaps columns using std swap function
        }   //have to iterate through rows to swap columns, by swapping each value individually
    }

    void chngevalue(int row, int col, int value) {  //function to change value of matrix at given row and column
        mtrx[row][col] = value; //sets value at given row and column to new value
    }
};

int main() {
    string filename;    //initializes filename variable
    cout << "Enter the filename: "; //prompts user for file
    cin >> filename;    //rrecieves file from user

    ifstream inputfile(filename);   //opens file to be read
    if (!inputfile) {   //checks if file opened successfully
        cerr << "Error opening file." << endl;  //if not, prints error message
        return 1;   //exits program if error
    }
    int N;  //initializes N variable
    inputfile >> N; //reads size of matrix from file
    Matrix matrixA(N), matrixB(N);  //creates two matrices of size NxN
    matrixA.readfile(inputfile);    //reads first matrix
    matrixB.readfile(inputfile);    //reads second matrix
    inputfile.close();  //closes file
    
    cout << "Matrix A:\n"; matrixA.print(); //prints first matrix
    cout << "Matrix B:\n"; matrixB.print(); //prints second matrix

    cout << "A + B:\n"; matrixA.add(matrixB).print();   //adds two matrices and prints result
    cout << "A * B:\n"; matrixA.multiply(matrixB).print();  //multiplies two matrices and prints result
    cout << "Diagonal sum of A: " << matrixA.diagonalsum() << endl; //prints sum of diagonals of first matrix
    cout << "Diagonal sum of B: " << matrixB.diagonalsum() << endl; //prints sum of diagonals of second matrix

    cout << "Swapping rows 0 and 1 in A:\n"; matrixA.swaprows(0, 1); matrixA.print();   //swaps rows of first matrix and prints result
    cout << "Swapping columns 0 and 1 in A:\n"; matrixA.swapcolumns(0, 1); matrixA.print(); //swaps columns of first matrix and prints result
    cout << "Changing value at (0, 0) in A to 348:\n"; matrixA.chngevalue(0, 0, 348); matrixA.print();  //changes value of first matrix and prints result
    cout << "Changing value at (1, 1) in B to 348:\n"; matrixB.chngevalue(1, 1, 348); matrixB.print();  //changes value of second matrix and prints result

    return 0;   //exits program
}
