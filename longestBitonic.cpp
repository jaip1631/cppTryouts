#include <iostream>
#include <vector>
using namespace std;

int getMax(int a, int b)
{
    return a>b?a:b;
}

void printVec(const vector<int> &arr)
{
    for(int i = 0; i < arr.size(); i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void fillLongestIncreasingSubsequence(const vector<int> &arr, vector<int> &res, bool directionLeftToRight)
{
    res.resize(arr.size(), 1);
    int start, end, inc;
    if(directionLeftToRight)
    {
        start = 0;
        end = arr.size();
        inc = 1;
    }
    else
    {
        start = arr.size();
        end = -1;
        inc = -1;
    }

    for(int i = start; i != end; i += inc)
    {
        for(int j = start; j != i; j += inc)
        {
            if(arr[j] < arr[i] && res[i] < res[j] + 1)
            {
                res[i] = 1 + res[j];
            }
        }
    }
    //printVec(res);    
}

int getLongestBitonicSubsequence(const vector<int> &arr)
{
    vector<int> LIS_LR, LIS_RL;
    fillLongestIncreasingSubsequence(arr, LIS_LR, true);
    printVec(LIS_LR);
    fillLongestIncreasingSubsequence(arr, LIS_RL, false);
    printVec(LIS_RL);

    int max = 1;
    for(int i = 0; i < arr.size(); i++)
    {
        max = getMax(max, LIS_LR[i]+LIS_RL[i]-1);
    }
    return max;
}

int main()
{
    vector<int> arr({60, 13, 46, 84});
    cout<<getLongestBitonicSubsequence(arr)<<endl;
    return 0;
}