#include <iostream>
#include <vector>

using namespace std;

int getMax(int a, int b)
{
    return a>b?a:b;
}

int getMaxSumIncreasingSubsequenceDP(const vector<int> &arr)
{
    vector<int> maxSumVec(arr);
    int maxSum = 0;
    for(int endAt = 0; endAt < arr.size(); endAt++)
    {
        for(int start = 0; start < endAt; start++)
        {
            if(arr[start] < arr[endAt])
                maxSumVec[endAt] = getMax(maxSumVec[start] + arr[endAt], maxSumVec[endAt]);
        }
        maxSum = getMax(maxSum, maxSumVec[endAt]);
    }

    return maxSum;
}

int main(int argc, char const *argv[])
{
    vector<int> arr({1, 101, 2, 3, 100, 4, 5});
    cout<<getMaxSumIncreasingSubsequenceDP(arr);
    return 0;
}
