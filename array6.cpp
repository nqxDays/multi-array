#include <iostream>
using namespace std;

int main() {
    srand(time(0));

    int rows, cols;
    cout << "Rows: ";
    cin >> rows;
    cout << "Cols: ";
    cin >> cols;

    int** A = new int* [rows];
    int** B = new int* [rows];
    int** C = new int* [rows];

    for (int i = 0; i < rows; i++) 
    {
        A[i] = new int[cols];
        B[i] = new int[cols];
        C[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) 
        {
            A[i][j] = rand() % 21 - 10;
            B[i][j] = rand() % 21 - 10;
        }


    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            C[i][j] = A[i][j] + B[i][j];


    cout << "\nArray A:\n";
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }

    cout << "\nArray B:\n";
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++)
            cout << B[i][j] << " ";
        cout << endl;
    }

    cout << "\nSum:\n";
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < rows; i++) 
    {
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
    }

    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}
