#include<iostream>
using namespace std;

void printMat(int **mat, int matSize)
{
    for(int i = 0; i < matSize; i++)
    {
        for(int j = 0; j < matSize; j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

void rotate(int **mat, int matSize)
{
    for(int i = 0; i < matSize/2; i++)
    {
        for(int j = i; j < matSize-i-1; j++)
        {
            int temp = mat[i][j];
            mat[i][j] = mat[j][matSize-i-1];
            mat[j][matSize-i-1] = mat[matSize-i-1][matSize-j-1];
            mat[matSize-i-1][matSize-j-1] = mat[matSize-j-1][i];
            mat[matSize-j-1][i] = temp;
            printMat(mat, matSize);
        }
    }
}

int main()
{
    int **mat, matSize;
    cin>>matSize;
    mat = new int *[matSize];
    for(int i = 0; i < matSize; i++)
        mat[i] = new int[matSize];
    
    for(int i = 0, count = 1; i < matSize; i++)
    {
        for(int j = 0; j < matSize; j++, count++)
            mat[i][j] = count;
    }

    printMat(mat, matSize);

    rotate(mat, matSize);

    printMat(mat, matSize);
    return 0;
}