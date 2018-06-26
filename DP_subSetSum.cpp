#include <iostream>
#include <vector>
using namespace std;

int isSubSetSumRec(vector<int> &arr, int sum, int i)
{
    if(sum == 0)
        return true;
    
    if(i == arr.size() || sum < 0)
        return false;

    if(arr[i] > sum)
        return isSubSetSumRec(arr, sum, i+1);
        
    return isSubSetSumRec(arr, sum, i+1) || isSubSetSumRec(arr, sum-arr[i], i+1);
}

int isSubSetSumDP(vector<int> &arr, int sum)
{
    vector<vector<bool>> DPMat(arr.size()+1, vector<bool>(sum+1, false));
    DPMat[0][0] = true;

    for(int arrIndex = 1; arrIndex <= arr.size(); arrIndex++)
    {
        for(int expSum = 0; expSum <= sum; expSum++)
        {
            if(expSum == 0)
                DPMat[arrIndex][expSum] = true;
            else
            {
                if(arr[arrIndex-1] > expSum)
                    DPMat[arrIndex][expSum] = DPMat[arrIndex-1][expSum];
                else
                    DPMat[arrIndex][expSum] = DPMat[arrIndex-1][expSum] || DPMat[arrIndex-1][expSum-arr[arrIndex-1]];
            }
        }
    }    

    return DPMat[arr.size()][sum];
}

int main(int argc, char const *argv[])
{
    vector<int>arr({1, 5, 12, 5});
    cout<<isSubSetSumDP(arr, 11);
    return 0;
}
