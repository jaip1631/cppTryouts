// https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/

#include <iostream>
#include <vector>
using namespace std;

int getMax(int a, int b)
{
    return a>b?a:b;
}

int getMaxSumSubArray(const vector<int> &arr)
{
    int maxSum = INT32_MIN, sumTillNow = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        sumTillNow = sumTillNow + arr[i];
        maxSum = getMax(maxSum, sumTillNow);
        if(sumTillNow < 0)
            sumTillNow = 0;
    }

    return maxSum;
}

int main(int argc, char const *argv[])
{
    int testCase, arrSize;
    vector<int> arr;
    cin>>testCase;
    while(testCase--)
    {
        cin>>arrSize;
        arr.resize(arrSize);

        for(int i = 0; i < arrSize; i++)
        {
            cin>>arr[i];
        }
        cout<<getMaxSumSubArray(arr)<<endl;
    }
    return 0;
}
