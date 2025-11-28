#include <iostream>
using namespace std;

int main() {
    srand(time(0));

    int rows, cols;
    cout << "Rows: ";
    cin >> rows;
    cout << "Cols: ";
    cin >> cols;


    int** a = new int* [rows];
    for (int i = 0; i < rows; i++)
        a[i] = new int[cols];


    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            a[i][j] = rand() % 11 - 5;


    cout << "\nInitial array:\n";
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }

    int newRows = 0;
    for (int i = 0; i < rows; i++) 
    {
        bool zeroFound = false;
        for (int j = 0; j < cols; j++)
            if (a[i][j] == 0) zeroFound = true;

        if (!zeroFound) newRows++;
    }


    int** b = new int* [newRows];
    int idx = 0;

    for (int i = 0; i < rows; i++) 
    {
        bool zeroFound = false;
        for (int j = 0; j < cols; j++)
            if (a[i][j] == 0) zeroFound = true;

        if (!zeroFound) 
        {
            b[idx] = new int[cols];
            for (int j = 0; j < cols; j++)
                b[idx][j] = a[i][j];
            idx++;
        }
    }


    cout << "\nArray not rows in zero:\n";
    for (int i = 0; i < newRows; i++) {
        for (int j = 0; j < cols; j++)
            cout << b[i][j] << " ";
        cout << endl;
    }


    for (int i = 0; i < rows; i++) 
        delete[] a[i];
    delete[] a;

    for (int i = 0; i < newRows; i++) 
        delete[] b[i];
    delete[] b;

    return 0;
}
