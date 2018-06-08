#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int getMaxProdSubArray(const vector<int> &arr)
{
    int max = arr[0];
    int maxNeg = 0, maxPos = 0;
    for(unsigned i = 0; i < arr.size(); i++)
    {
        maxNeg *= arr[i];
        maxPos *= arr[i];
        if(arr[i] < 0)
        {
            swap(maxNeg, maxPos);
        }
        if(maxPos == 0 && arr[i] > 0)
            maxPos = arr[i];
        if(maxNeg == 0 && arr[i] < 0)
            maxNeg = arr[i];
        
        if(max < maxPos)
            max = maxPos;
    }

    return max;
}

int main(int argc, char const *argv[])
{
    vector<int> arr({-1000,10,-10,10,10,-10});
    cout<<getMaxProdSubArray(arr);
    return 0;
}
