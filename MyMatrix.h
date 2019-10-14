/*
Name: Justin Mendoza
Class: CSS342
Prof: Dr. Peng Du
Filename: MyMatrix.h
*/

#pragma once
#include<iostream>
using namespace std;

template<class T>
class MyMatrix
{

// Matrix Size Variables
private:
	T* data; // Data will be stored as a 1D array. 

	int rows;
	int columns;
	int sizeTotal;

public:
	MyMatrix(int inputRows, int inputColumns, T inputArray[]); // Constructor
	MyMatrix(const MyMatrix<T>& inputCopyMatrix); // Copy Constructor 
	void add(MyMatrix& inputAddMatrix); // Adding 2 Matrcies together
	T getDataCell(int index); // Return Data Cell of matrix
	virtual ~MyMatrix(); // Destructor 

};
// Constructor
template <class T>
inline MyMatrix<T>::MyMatrix(int inputRows, int inputColumns, T inputArray[])
{
	rows = inputRows;
	columns = inputColumns;
	sizeTotal = rows * columns; 

	data = new T[rows * columns];

	for (int i = 0; i < sizeTotal; i++)
	{
		data[i] = inputArray[i];
	}

}

// Copy constructor
template <class T>
inline MyMatrix<T>::MyMatrix(const MyMatrix<T>& inputCopyMatrix)
{
	rows = inputCopyMatrix.rows;
	columns = inputCopyMatrix.columns;
	sizeTotal = inputCopyMatrix.sizeTotal;

	for (int i = 0; i < sizeTotal; i++)
	{
		data[i] = inputCopyMatrix.data[i];
	}
}

template <class T>
inline void MyMatrix<T>::add(MyMatrix& inputAddMatrix)
{
	// Compares Matrix Diam. If they do not match, throws exception. 
	try
	{

		if (rows != inputAddMatrix.rows || columns != inputAddMatrix.columns)
		{
			string errorMsg = "Matrix sizes do not match.\n";

			throw errorMsg;
		}
	}
	catch (string e)
	{
		cout << "Error Found: " << e;
		
	}

	for (int i = 0; i < sizeTotal; i++)
	{
		data[i] = data[i] + inputAddMatrix.data[i];
	}

}

// Function to retrieve matrix cell
template<class T>
inline T MyMatrix<T>::getDataCell(int index)
{
	return data[index];
}

// Destructor
template <class T>
inline MyMatrix<T>::~MyMatrix()
{
	delete[] data;
}
