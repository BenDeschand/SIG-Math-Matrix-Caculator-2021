// Reduced Echelon Form
// Matrix class with nested vectors
// Same class as the calculator
// Input the matrices
// Do inverse
// change
// LU factorization
#include <vector>
#include <vector>
#include <assert.h>
#include <stdexcept>
#include <iostream>

using namespace std;

class matrix
{
	// first row and col are considered 0
	private:
		vector<std::vector<double>> matrice;
		int row;  // matrice.size()
		int col;   // matrice[0].size()

	public:
		//Fix it to value[] instead of int[] value
		matrix(int row, int col, double value[]);   // done
		void switchRow(int r1, int r2);             // done
		void multiScal(int scalar, int row);        // done
		void addRow(int r1, int r2);                // done
		bool isReduced();                           // Christian
		void reduceMatrix();                        // done
		bool checkRow(int row);                     // Christian
		// void reduceRow(int row); 
		bool checkCol(int col);                     // done
		//Change to const reference optimize, avoid changing the value
		void reduceCol(const int& col);             // done?
		void print();                               // Sreten

		const int rowSize() const;  // helper fuction--Chris
};
