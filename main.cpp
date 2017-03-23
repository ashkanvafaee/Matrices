//#include "MathMatrix.h"
#include "SquareMatrix.h"
using namespace std;

void test1(void);
void test2(void);
void test0(void);
void test4(void);
void test5(void);


int main()
{
	test5();
	test2();
	test1();
	test2();
	test5();
	test4();
	test0();
	test1();
	

	
	
	






	return 0;
}

void test2() {

	int mat[3][3] = {
		{ 1, 2, 3 } ,   /*  initializers for row indexed by 0 */
		{ 2, 1, 2 } ,   /*  initializers for row indexed by 1 */
		{ 3, 2, 1 }     /*  initializers for row indexed by 2 */
	};
	int* A[3] = { mat[0], mat[1], mat[2] };

	SquareMatrix test1(3, 1);
	test1.changeElement(0, 1, 2);
	test1.changeElement(0, 2, 3);
	test1.changeElement(1, 0, 2);							// Makes into Matrix A
	test1.changeElement(1, 2, 2);
	test1.changeElement(2, 0, 3);
	test1.changeElement(2, 1, 2);
	test1.changeElement(1, 1, -99);

	SquareMatrix temp(2,-3);
	temp.changeElement(0, 0, 5);
	temp.changeElement(0, 1, 6);

	int x = temp.getDeterminant();
	x = test1.isSymmetric();
	x = test1.getDeterminant();
	
	test1 = test1.createIdentityMatrix(4);
	test1 = SquareMatrix();
	test1.changeElement(0, 0, 3);
	x = test1.getDeterminant();
	test1 = SquareMatrix(2, 2);
	test1.changeElement(0, 0, 4);
	test1.changeElement(1, 1, 5);						//Makes into {4, 2, 2, 5}
	x = test1.getDeterminant();



	return;

}



void test5() {
	MathMatrix temp(1, 3, 2);
	MathMatrix temp2(3, 1, 3);
	MathMatrix tempy(4, 3, 1);
	//temp2 = temp2.scale(3);
	MathMatrix temp3 = temp2*temp;
	MathMatrix tempx = tempy*temp2;
	MathMatrix temp4 = temp*temp2;
	temp3 = temp2.getTranspose();
	int x = temp3.numCols();
	x = temp3.numRows();
	x = x;
}

void test4() {
	vector<vector<int>> v(3, vector<int>(1));
	MathMatrix temp4(v);


	MathMatrix temp(2, 3, 5);
	MathMatrix temp2(2, 3, 4);
	MathMatrix temp3(2, 3, 4);
	int x = temp == temp2;
	temp = temp.scale(0);
	temp = temp - temp2;
	temp.changeElement(1, 2, 99);
	x = temp.getVal(1,2);
	x = x;
}

void test0() {
	int mat[3][2] = {
		{ 0, 1 } ,   /*  initializers for row indexed by 0 */
		{ 2, 3 } ,   /*  initializers for row indexed by 1 */
		{ 4, 5 }     /*  initializers for row indexed by 2 */
	};
	int* A[3] = { mat[0], mat[1], mat[2] };
	MathMatrix temp(3, 2, A);
	int x = temp.numCols();
	x = temp.numRows();
	MathMatrix temp2(1, 3, 5);
	x = temp2.numCols();
	x = temp2.numRows();
	//MathMatrix temp2(1, 1, A);
	//temp = temp2;
	//MathMatrix temp2(temp);
	//MathMatrix temp2(1, 3, 5);
	MathMatrix temp3 = temp;

	int xx = 0;



}

void test1() {

	int mat[3][2] = {
		{ 0, 1 } ,   /*  initializers for row indexed by 0 */
		{ 2, 3 } ,   /*  initializers for row indexed by 1 */
		{ 4, 5 }     /*  initializers for row indexed by 2 */
	};
	int* A[3] = { mat[0], mat[1], mat[2] };



	MathMatrix test1(3, 2, A);					//A is 3X2 Matrix
	MathMatrix y = test1.getTranspose();
	y = y.getTranspose();
	MathMatrix test4(3, 2, A);
	int x = test1.numRows();
	x = test1.numCols();
	x = test1.equals(test4);
	x = test1 == test4;
	x = test1.getVal(1, 1);
	MathMatrix test2 = test1;
	test2 = test1.getTranspose();
	test2 = test1.multiply(test2);


}

