/**
* assignment-8.cpp
*
* Implementation of Poly member functions
*
* Authors:
* Ashkan Vafaee [av28837]
* Genki Oji [gto99]
*/
#include "SquareMatrix.h"

using namespace std;

SquareMatrix::SquareMatrix()
{
	vector<vector<int>> v(1, vector<int>(1));
	v[0][0] = 0;

	this->mat = v;
}

SquareMatrix::SquareMatrix(int size, int initialValue)
{

	vector<vector<int>> v(size, vector<int>(size));

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			v[i][j] = initialValue;
		}
	}

	this->mat = v;
}

SquareMatrix::~SquareMatrix()						
{
}

SquareMatrix SquareMatrix::createIdentityMatrix(int size)
{
	vector<vector<int>> v(size, vector<int>(size));

	for (int i = 0; i < size; i++) {
		v[i][i] = 1;
	}

	SquareMatrix result;
	result.mat = v;
	return result;
}

int SquareMatrix::getDeterminant()
{
	if (this->numRows() == 1) {									// 1x1 Matrix
		return(mat[0][0]);
	}

	if (this->numRows() == 2) {									// 2x2 Matrix
		return((mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]));
	}

	// 3x3 Matrix
	return((mat[0][0] * mat[1][1] * mat[2][2]) + (mat[0][1] * mat[1][2] * mat[2][0]) + (mat[0][2] * mat[1][0] * mat[2][1]) - (mat[0][2] * mat[1][1] * mat[0][2]) - (mat[0][1] * mat[1][0] * mat[2][2]) - (mat[0][0] * mat[1][2] * mat[2][1]));

}

bool SquareMatrix::isSymmetric()
{

	for (int i = 0; i < this->numRows(); i++) {
		for (int j = 0; j < this->numRows(); j++) {
			if (mat[i][j] != mat[j][i]){
			return false;
			}
		}
	}


	return true;
}
