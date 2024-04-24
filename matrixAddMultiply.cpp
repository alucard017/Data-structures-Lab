#include <iostream>
using namespace std;

const int MAX_ROWS = 100;
const int MAX_COLS = 100;

void addMatrices(int mat1[MAX_ROWS][MAX_COLS], int mat2[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void multiplyMatrices(int mat1[MAX_ROWS][MAX_COLS], int mat2[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS], int rows1, int cols1, int cols2)
{
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++)
            {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void displayMatrix(int mat[MAX_ROWS][MAX_COLS], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int mat1[MAX_ROWS][MAX_COLS], mat2[MAX_ROWS][MAX_COLS], result[MAX_ROWS][MAX_COLS];
    int rows1, cols1, rows2, cols2;

    cout << "Enter dimensions of the first matrix (rows cols): ";
    cin >> rows1 >> cols1;

    cout << "Enter elements of the first matrix:\n";
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols1; j++)
        {
            cin >> mat1[i][j];
        }
    }

    cout << "Enter dimensions of the second matrix (rows cols): ";
    cin >> rows2 >> cols2;

    cout << "Enter elements of the second matrix:\n";
    for (int i = 0; i < rows2; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            cin >> mat2[i][j];
        }
    }

    if (rows1 != rows2 || cols1 != cols2)
    {
        cout << "Matrices cannot be added or multiplied due to incompatible dimensions.\n";
        return 0;
    }

    cout << "Matrix 1:\n";
    displayMatrix(mat1, rows1, cols1);

    cout << "Matrix 2:\n";
    displayMatrix(mat2, rows2, cols2);

    addMatrices(mat1, mat2, result, rows1, cols1);
    cout << "Sum of matrices:\n";
    displayMatrix(result, rows1, cols1);

    multiplyMatrices(mat1, mat2, result, rows1, cols1, cols2);
    cout << "Product of matrices:\n";
    displayMatrix(result, rows1, cols2);

    return 0;
}
