// Reduced Echelon Form
// Matrix class with nested vectors
// Same class as the calculator
 
// Input the matrices
 
 
// Do inverse
 
// LU factorization


class matrix
{
	// first row and col are considered 0
	private:
		vector<vector<double>> matrice;
		int row;  // matrice.size()
		int col;   // matrice[0].size()

	public:
		matrix(int row, int col, int[] value);
		void switchRow(int r1, int r2);
		void multiScal(int scalar, int row);
		void addRow(int r1, int r2);
		bool isReduced();
		void reduceMatrix();
		bool checkRow(int row);
		void reduceRow(int row);
		bool checkCol(int col);
		void reduceCol(int col);
		void print();
};
