/**
* assignment-8.cpp
*
* Implementation of Poly member functions
*
* Authors:
* Ashkan Vafaee [av28837]
* Genki Oji [gto99]
*/

#include "MathMatrix.h"
using namespace std;

MathMatrix::MathMatrix()
{
	vector<vector<int>> v(1, vector<int>(1));
	v[0][0] = 0;

	this->mat = v;


}

MathMatrix::MathMatrix(int numRows, int numCols, int** mat)		//given an array
{
	vector<vector<int>> v(numRows, vector<int> (numCols));

	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < numCols; j++) {
			v[i][j] = mat[i][j];
		}
	}
	
	this->mat = v;


}

MathMatrix::MathMatrix(const vector<vector<int>>& mat)			//Copy Constructor
{
	this->mat = mat;
}

MathMatrix::MathMatrix(int numRows, int numCols, int initialValue)	//given initial values
{

	vector<vector<int>> v(numRows, vector<int>(numCols));

	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < numCols; j++) {
			v[i][j] = initialValue;
		}
	}

	this->mat = v;

}

MathMatrix::~MathMatrix()				
{
}

void MathMatrix::changeElement(int row, int col, int newValue)
{
	this->mat[row][col] = newValue;
	return;
}
int MathMatrix::numRows()
{
	return (this->mat.size());
}
int MathMatrix::numCols()
{
	return(this->mat[0].size());
}
int MathMatrix::getVal(int row, int col)
{
	return(this->mat[row][col]);
}
MathMatrix MathMatrix::add(const MathMatrix& rightHandSide)			// Assuming the two matrices are the same size
{
	MathMatrix result;
	result.mat = this->mat;

	for (int i = 0; i < this->numRows(); i++) {
		for (int j = 0; j < this->numCols(); j++) {
			result.mat[i][j] += rightHandSide.mat[i][j];
		}
	}

	return result;
}
MathMatrix MathMatrix::subtract(const MathMatrix& rightHandSide)		// Assuming the two matrices are the same size
{
	MathMatrix result;
	result.mat = this->mat;

	for (int i = 0; i < this->numRows(); i++) {
		for (int j = 0; j < this->numCols(); j++) {
			result.mat[i][j] -= rightHandSide.mat[i][j];
		}
	}
	return result;
}
MathMatrix MathMatrix::multiply(const MathMatrix& rightHandSide)		// Assuming the two matrices are compatible
{
	MathMatrix temp = rightHandSide;					//temp is a copy of rightHandSide

	vector<vector<int>> v(this->numRows(), vector<int>(temp.numCols()));

	for (int x = 0; x < temp.numCols(); x++) {

		for (int y = 0; y < this->numRows(); y++) {
			int count = 0;

			for (int z = 0; z < this->numCols(); z++) {
				count += this->mat[y][z] * temp.mat[z][x];
			}

			v[y][x] = count;
		}

	}





	MathMatrix result;
	result.mat = v;
	return result;
}

bool MathMatrix::equals(const MathMatrix& rightHandSide)
{
	if (this->mat == rightHandSide.mat) {
		return true;
	}
	else {
		return false;
	}
}

MathMatrix MathMatrix:: operator+(const MathMatrix& rightHandSide)
{
	return(this->add(rightHandSide));
}

MathMatrix MathMatrix:: operator-(const MathMatrix& rightHandSide)
{
	return(this->subtract(rightHandSide));
}
MathMatrix MathMatrix:: operator*(const MathMatrix& rightHandSide)
{
	return(this->multiply(rightHandSide));
}

bool MathMatrix:: operator==(const MathMatrix& rightHandSide)
{
	return(this->equals(rightHandSide));
}

MathMatrix MathMatrix::scale(int factor)
{
	vector<vector<int>> v = this->mat;

	for (int i = 0; i < this->numRows(); i++) {
		for (int j = 0; j < this->numCols(); j++) {
			v[i][j] *= factor;
		}
	}

	MathMatrix result;
	result.mat = v;
	return result;
}
MathMatrix MathMatrix::getTranspose()
{
	vector<vector<int>> v(this->numCols(), vector<int>(this->numRows()));


	for (int i = 0; i < this->numRows(); i++) {
		for (int j = 0; j < this->numCols(); j++) {
			v[j][i] = this->mat[i][j];
		}
	}

	MathMatrix result;
	result.mat = v;
	return result;
}
