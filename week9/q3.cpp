#include <iostream>
using namespace std;

void transpose(int a[][10], int result[][10], int rows, int columns)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            result[j][i] = a[i][j];
}

int main()
{
    int rows, columns, a[10][10], result[10][10];
    cin >> rows >> columns;
    if (rows > 10)
        rows = 10;
    if (columns > 10)
        columns = 10;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            cin >> a[i][j];
    transpose(a, result, rows, columns);
    for (int i = 0; i < columns; i++)
    {
        for (int j = 0; j < rows; j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
    return 0;
}
