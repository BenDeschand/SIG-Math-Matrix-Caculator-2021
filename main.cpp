#include "matrix.h"

int main()
{
    int row, col;

    cout << "Welcome to SIG Math's Matrix Calculator!" << endl;
    cout << "Enter the number of rows:";
    cin >> row;
    cout << "Enter the number of columns:";
    cin >> col;

    int size = row * col;
    double* val = new double[size];
    int value = 0;

    for(int r = 0; r < row; r++)
    {
        for(int c = 0; c < col; c++)
        {
            cout << "(" << r << ", " << c << "): ";
            cin >> value;
            val[(r * col) + c] = value;
        }
    }

    matrix M(row, col, val);
    cout << "Matrix: " << endl;
    M.print();
    cout << "Reduced matrix is: " << endl;
    M.reduceMatrix();
    M.print();
}