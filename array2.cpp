#include <iostream>
using namespace std;
void addRowToStart(int**& arr, int& rows, int cols)
{
	int** newArr = new int* [rows + 1];

	newArr[0] = new int[cols];
	for (int j = 0; j < cols; j++)
		newArr[0][j] = 0;

	for (int i = 0; i < rows; i++)
	{
		newArr[i + 1] = arr[i];
	}

	delete[] arr;

	arr = newArr;
	rows++;
	
}

void printArray(int** arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}


int main()
{
	int rows = 2, cols = 3;

	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = i + j + 1;
		}
	}
	cout << "Initial array:\n";
	printArray(arr, rows, cols);

	addRowToStart(arr, rows, cols);

	cout << "\nAfter add string: \n";
	printArray(arr, rows, cols);

	for (int i = 0; i < rows; i++)
		delete[] arr[i];
	delete[] arr;

}

