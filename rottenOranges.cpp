#include <iostream>

using namespace std;

void markAdjacent(int **arr, int row, int col, bool &conversion, bool &onePresent)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(arr[i][j] == 2)
            {
                if(i != 0 && arr[i-1][j] == 1)
                {
                    conversion = true;
                    arr[i-1][j] = -1;
                }
                if(i != row-1 && arr[i+1][j] == 1)
                {
                    conversion = true;
                    arr[i+1][j] = -1;
                }
                if(j != 0 && arr[i][j-1] == 1)
                {
                    conversion = true;
                    arr[i][j-1] = -1;
                }
                if(j != col-1 && arr[i][j+1] == 1)
                {
                    conversion = true;
                    arr[i][j+1] = -1;
                }
            }
            if(arr[i][j] == 1)
                onePresent = true;
        }
    }
}

void setRotten(int **arr, int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(arr[i][j] == -1)
            {
                arr[i][j] = 2;
            }
        }
    }
}

int getRottenTime(int **arr, int row, int col)
{
    int count = 0;
    bool conversion = false;
    bool onePresent = false;
    
    while(1)
    {
        conversion = false;
        onePresent = false;
        markAdjacent(arr, row, col, conversion, onePresent);
        if(!conversion)
            break;
        count++;
        setRotten(arr, row, col);
    }

    if(onePresent)
        return -1;
        
    return count;
}

int main(int argc, char const *argv[])
{
    int testCase;
    int row, col;
    cin>>testCase;

    while(testCase--)
    {
        cin>>row>>col;
        int **arr = new int *[row];
        for(int i = 0; i < row; i++)
            arr[i] = new int [col];
        
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                cin>>arr[i][j];

        cout<<getRottenTime(arr, row, col)<<endl;;
    }
    return 0;
}
