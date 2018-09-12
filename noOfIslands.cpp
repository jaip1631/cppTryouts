// https://www.geeksforgeeks.org/find-number-of-islands/

#include <iostream>
#include <vector>

using namespace std;
short dir_x[] = {-1, -1, 0, 1, 1, 1, 0, -1};
short dir_y[] = {0, 1, 1, 1, 0, -1, -1, -1};


void printMatrix(const vector<vector<bool>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int curRow, int curCol, int rowSize, int colSize)
{
    return ((curRow >= 0 && curRow < rowSize) &&
            (curCol >= 0 && curCol < colSize));
}

bool noOfIslandsRec(const vector<vector<bool>> &sourceMatrix,
                int curRow, int curCol, vector<vector<bool>> &isVisited)
{
    int rowSize = sourceMatrix.size();
    int colSize = sourceMatrix[0].size();
    int newRow, newCol;

    if (!isSafe(curRow, curCol, rowSize, colSize))
        return false;

    if (!isVisited[curRow][curCol])
    {
        isVisited[curRow][curCol] = true;
        if (sourceMatrix[curRow][curCol])
        {
            for (int dir = 0; dir < 8; dir++)
            {
                newRow = curRow + dir_y[dir];
                newCol = curCol + dir_x[dir];
                if (isSafe(newRow, newCol, rowSize, colSize) &&
                    !isVisited[newRow][newCol] && sourceMatrix[newRow][newCol])
                {
                    noOfIslandsRec(sourceMatrix, newRow, newCol, isVisited);
                }
            }
            return true;
        }
    }
    return false;
}

int getNoOfIslands(const vector<vector<bool>> &sourceMatrix)
{
    if (sourceMatrix.empty())
        return 0;

    int rowSize = sourceMatrix.size();
    int colSize = sourceMatrix[0].size();

    vector<vector<bool>> isVisited(rowSize, vector<bool>(colSize, false));
    int noOfIslands = 0;
    for (int i = 0; i < sourceMatrix.size(); i++)
    {
        for (int j = 0; j < sourceMatrix[i].size(); j++)
        {
            if(noOfIslandsRec(sourceMatrix, i, j, isVisited))
                noOfIslands++;
            //printMatrix(isVisited);
        }
    }

    return noOfIslands;
}

int main(int argc, char const *argv[])
{
    vector<vector<bool>> matrix({{1, 1, 1}, {0, 0, 0}, {1, 0, 1}});
    cout<<getNoOfIslands(matrix);
    return 0;
}
