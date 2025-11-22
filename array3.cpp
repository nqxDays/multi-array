#include <iostream>
using namespace std;
void addRowAtPos(int**& arr, int& rows, int cols, int pos)
{
	if (pos < 0) pos = 0;
	if (pos > rows) pos = rows;

	int** newArr = new int* [rows + 1];

	for (int i = 0; i < pos; i++)
	{
		newArr[i] = arr[i];
	}
	newArr[pos] = new int[cols];
	for (int j = 0; j < cols; j++)
	{
		newArr[pos][j] = 0;
	}

	for (int i = pos; i < rows; i++)
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
	int rows = 3, cols = 3;

	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = i * 10 + j;
		}
	}
	cout << "Initial array:\n";
	printArray(arr, rows, cols);

	int pos;
	cout << "\n Enter position for paste row:";
	cin >> pos;

	addRowAtPos(arr, rows, cols, pos);

	cout << "\nAfter paste string: \n";
	printArray(arr, rows, cols);

	for (int i = 0; i < rows; i++)
		delete[] arr[i];
	delete[] arr;

}

