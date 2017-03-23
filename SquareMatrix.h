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

class SquareMatrix : public MathMatrix {
private:
public:

	/*
		Default constructor initializes a 1x1 matrix
		with an initial value of 0
	*/
	SquareMatrix();

	/*
		Destructor - delete all allocated member variables
	*/
	~SquareMatrix();

	/*
		Constructs a size x size SquareMatrix with 
		initial values of initialValue.
	*/
	SquareMatrix(int size, int initialValue);

	/*
		Returns a new SquareMatrix that is of dimension
		size x size with 1's along the diagonal and 0
		in all other positions.
	*/
	SquareMatrix createIdentityMatrix(int size);

	/*
		Returns the determinant of the matrix.
	*/
	int getDeterminant();

	/*
		Returns true if SquareMatrix is equal to its
		transpose.
	*/
	bool isSymmetric();
};
