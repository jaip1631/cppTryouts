#include <iostream>
#include <vector>
using namespace std;

int noOfWaysForSumRec(int diceCount, int facesCount, int expectedSum)
{
    if(expectedSum == 0 && diceCount == 0)
        return 1;
    if(diceCount <= 0 || expectedSum <= 0)
        return 0;

    int sum = 0;

    for(int i = 1; i  <= facesCount; i++)
    {
        if(expectedSum >= i)
            sum +=  noOfWaysForSumRec(diceCount-1, facesCount, expectedSum-i);
    }

    return sum;
}

int noOfWaysForSumDP(int diceCount, int facesCount, int expectedSum)
{
    vector<vector<int>> DPMat(diceCount+1, vector<int>(expectedSum+1, 0));
    DPMat[0][0] = 1;

    for(int i = 1; i <= diceCount; i++)
    {
        for(int j = 1; j <= expectedSum; j++)
        {
            for(int faceVal = 1; faceVal <= facesCount && faceVal <= j; faceVal++)
            {
                DPMat[i][j] += DPMat[i-1][j-faceVal];
            }
        }
    }

    return DPMat[diceCount][expectedSum];
}

int main(int argc, char const *argv[])
{
    int diceCount, facesCount, expectedSum;
    cout<<noOfWaysForSumDP(3, 6, 8)<<endl;
    return 0;
}
