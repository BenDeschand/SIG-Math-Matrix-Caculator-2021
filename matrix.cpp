//TODO
#include <vector>
#include <iostream>
#include "matrix.h"

void Matrix::reduceCol(const int& col)
{
    //getting the pivot point from input Col
    auto& pivotNum = matrice[0][col];

    //iterate through the matrice divide by the pivot point
    for(auto i = 0; i < row; i++)
    {
        for(auto j  = 0; j < col; j++)
        {
            (matrice[i][j] <= 0) ? : matrice[i][j] = matrice[i][j] / pivotNum; 

        }
    }

    

}