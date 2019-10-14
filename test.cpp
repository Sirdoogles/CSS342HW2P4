/*
Name: Justin Mendoza
Class: CSS342
Prof: Dr. Peng Du
Filename: test.cpp
*/

#include "MyMatrix.h"
using namespace std;
#include <iostream>
#include <fstream>

int main()
{
	// Test Message. Hello!
	cout << "Hello World!" << endl;

	int matrixOneData[25];
	int matrixTwoData[25];
	// Fills matrixOneData cells with values of 2. 
	for (int i = 0; i < 25; i++)
	{
		matrixOneData[i] = 2;
	}
	
	for (int j = 0; j < 25; j++)
	{
		matrixTwoData[j] = 2;
	}

	// Creating MyMatrix objects. 
	MyMatrix<int> testMatrixOne(5, 5, matrixOneData);
	MyMatrix<int> testMatrixTwo(5, 5, matrixTwoData);

	// Adds 2 matrices with values of 2. Expected result should be matrix of all 4s. 
	testMatrixOne.add(testMatrixTwo);
	
	int testQuota = 25;
	int testCount = 0;

	for (int k = 0; k < 25; k++)
	{
		if (testMatrixOne.getDataCell(k) == 4)
		{
			testCount++;
		}

	}

	if (testCount == testQuota)
	{
		cout << "add() test: PASSED\n";
	}

	else
	{
		cout << "add() test: FAILED\n";
	}




}