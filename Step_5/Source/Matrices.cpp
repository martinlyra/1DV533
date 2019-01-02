//-----------------------------------------------------------------------
// Object: Task 7 - Write a Matrix calculator
//-----------------------------------------------------------------------
// File: Matrices.cpp
// Summary: This program takes several numbers until a non-number is 
// given, then prints the output.
// Version: 1.0
// Owner: Martin Lyrå
//-----------------------------------------------------------------------
// Log:			2019-01-01:	Created by Martin	
//-----------------------------------------------------------------------
#include <iostream>
#include <iomanip>
using namespace std;

// Constants
const int MAXDIM = 5;

// Typedefs
typedef double Matrix[MAXDIM][MAXDIM];

// Prototypes
void readMatrix(Matrix& M, int& row, int& col);
void multMatrix(const Matrix A, const Matrix B, Matrix& C, int m, int n, int p);
void printMatrix(const Matrix M, int row, int col);

// Entry point
int main() {
	Matrix A, B, C;
	int m, n, p;

	cout	<< "Matrix Multiplication\n"
			<< "---------------------\n";

	// Ask input
	cout << "\nMatrix A:\n";
	readMatrix(A, m, p);
	cout << "\nMatrix B:\n";
	readMatrix(B, p, n);

	// Multiplication
	multMatrix(A, B, C, m, n, p);

	// End
	cout << "-------------------------\n";
	cout << "Answer:\n\n";
	printMatrix(C, m, n);
	cout << '\n';

	cout << "Press any key to continue...\n";
	cin.get();
	return 0;
}

// void readMatrix(Matrix&, int&, int&)
//
// Reads one matrix with row rows and col columns
void readMatrix(Matrix& M, int& row, int& col)
{
	cout << "Enter matrix dimensions (Row & Col): ";
	cin >> row >> col;

	cout << "Enter the matrix in free form (" << row * col << " numbers expected): ";
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> M[i][j];

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// void multMatrix(const Matrix, const Matrix, Matrix&, int, int, int)
//
// Multiplies m•p-matrix A with p•n matrix B and stores the result in the m•n-matrix C
void multMatrix(const Matrix A, const Matrix B, Matrix& C, int m, int n, int p)
{
	for (int row = 0; row < m; row++) {
		for (int col = 0; col < n; col++) {
			C[row][col] = 0; // initialize value
			for (int i = 0; i < p; i++) {
				C[row][col] += A[row][i] * B[i][col];
			}
		}
	}
}

// void printMatrix(const Matrix, int, int)
//
// Prints the matrix M
void printMatrix(const Matrix M, int row, int col)
{
	for (int y = 0; y < row; y++) {
		for (int x = 0; x < col; x++) {
			cout << setw(12) << setprecision(2) << fixed;
			cout << M[y][x] << " ";
		}
		cout << '\n';
	}
}
