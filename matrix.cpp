#include "matrix.h"

// matrix constructor
// main constructor for the matrix class
matrix::matrix(int row, int col, double value[])
{
    assert(col > 0);
    assert(row > 0);

    for(int r = 0; r < row; r++)
    {
        vector<double> temp;

        for(int c = 0; c < col; c++)
        {
            temp.push_back(value[r + c]);
        }

        matrice.push_back(temp);
    }

}  // Ben Deschand - matrix constructor

void matrix::switchRow(int r1, int r2) {
	if (r1 >= row || r2 >= row || r1 < 0 || r2 < 0) {
		throw out_of_range("row is out of bounds");
	}

	matrice[r1].swap(matrice[r2]);	
} // Sreten Kljaic - switch row


bool matrix::checkRow()
{
    for(int i = 0; i < col-1; i++)
    {
        for(int j = 0; j < row; j ++;)
        {
            if(i == j)
                if(matrix[i][j] != 1)
                    return false;
            else
                if(matrix[i][j] != 0)
                    return false;
        }
    }

    return true;
}//Vivek Patel - checkRow

void matrix::addRow(int r1, int r2)
{
    for(int i = 0; i < col; i++) //Loop through each column
    {
        matrice[r1][i] += matrice[r2][i]; //Add each value in r2 to r1
    }
} // Vivek Patel - addRow


// multiply each element of the row by the scalar value
void matrix::multiScal(int scalar, int row) {

   for(int i=0;i<col;i++) {
     matrice[row][col] = matrice[row][col]*scalar; 
   }

}

void matrix::reduceCol(const int& col)
{
    //col muse be in bounds, and matrice must not be empty
    assert(col >= 0);
    assert(col < matrice.size());
    assert(!matrice.empty());


    //getting the pivot point from input Col
    const auto pivotNum = matrice.at(0).at(col);


    //TODO:iterate through the matrice
    //divide only the input col with the pivotNum
    //transforming the pivot location to 1
    for(auto row = 0; row < matrice.size(); ++row)
    {
        //using at() instead of operator[] to avoid undefined behavior
        //TODO: avoid case that 0 / num
        try{

            matrice.at(row).at(col) = ( matrice.at(row).at(col) != 0 ) ? ( matrice.at(row).at(col) / pivotNum) :  0;  
        }
        catch(const int& e)
        {
            //access out of bound
            throw logic_error("access index location is out of bound");
        }
    }


    //since the pivot number always start at index row 0 and fixed col, turns the remaining row in the col to 0
    for(auto row = 1; row < matrice.size(); ++row)
    {
        matrice.at(row).at(col) = 0;
    }


}//Chris- reduce column


// checkCol
// checks if the specfic column is reduced (every value 0 except the pivot value)
bool matrix::checkCol(int col)
{
    assert(this->col > col);

    bool isGood = true;

    for(int r = 0; r < row; r++)
    {
        if(r == col)
        {
            if(matrice.at(r).at(col) == 1)    // checks if value is at pivot value
            {
                isGood = true;
            }
            else
            {
                isGood = false;
            }
        }
        else
        {
            if(matrice.at(r).at(col) == 0)    // for every other value in the column
            {
                isGood = true;
            }
            else
            {
                isGood = false;
            }
        }
    }

    return isGood;
} // Ben Deschand - checkCol

// reduceMatrix
// uses other functions to reduce the matrix.

void matrix::reduceMatrix() {

    if(!isReduced) { // checks if matrix is already reduced
        for (int col = 0; col < matrice[0].size() - 1; ++col) { // does not reduce the last column
            reduceCol(col);
        }
    }
} // Ayush Patel - reduceMatrix
