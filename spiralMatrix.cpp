#include<iostream>
using namespace std;

void printSpiral(int **arr, int row, int col)
{
    int counter = 1;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++, counter++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    int startRow = 0, startCol = 0, endRow = row, endCol = col;
    while(startRow < endRow && startCol < endCol)
    {
        for(int i = startCol; i < endCol-1; i++)
            cout<<arr[startRow][i]<<" ";
        
        for(int i = startRow; i < endRow-1; i++)
            cout<<arr[i][endCol-1]<<" ";

        for(int i = endCol-1; i > startCol; i--)
            cout<<arr[endRow-1][i]<<" ";
        
        for(int i = endRow-1; i > startRow; i--)
            cout<<arr[i][startCol]<<" ";
        startRow++;
        startCol++;
        endRow--;
        endCol--;
    }

    cout<<endl;
}
int main(int argc, char const *argv[])
{
    int row = 3, col = 4;
    int **mat = new int *[row];
    for(int i = 0; i < row; i++)
        mat[i] = new int[col];

    int counter = 1;
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++, counter++)
            mat[i][j] = counter;
    
    printSpiral(mat, row, col);
    return 0;
}
