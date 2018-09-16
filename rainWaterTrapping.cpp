// https://www.geeksforgeeks.org/trapping-rain-water/

#include <vector>
#include <iostream>
using namespace std;

int getMin(int a, int b)
{
    return a<b?a:b;
}

int getTrappedRainWater(const vector<int> &buildings)
{
    vector<int> nextHighest(buildings.size()), previousHighest(buildings.size());
    int highestIndex = 0, highestValue = buildings[highestIndex];
    int totalTrappedWater = 0;
    for (int i = 0; i < buildings.size(); i++)
    {
        if(highestValue <= buildings[i])
        {
            previousHighest[i] = -1;
            highestIndex = i;
            highestValue = buildings[i];
        }
        else
        {
            previousHighest[i] = highestIndex;
        }
    }

    highestIndex = buildings.size()-1, highestValue = buildings[highestIndex];
    for (int i = buildings.size()-1; i >= 0; i--)
    {
        if(highestValue <= buildings[i])
        {
            nextHighest[i] = -1;
            highestIndex = i;
            highestValue = buildings[i];
        }
        else
        {
            nextHighest[i] = highestIndex;
        }
    }


    for(int i = 0; i < buildings.size(); i++)
    {
        if(previousHighest[i] == -1 || nextHighest[i] == -1)
            continue;
        int minHighest = getMin(buildings[previousHighest[i]], buildings[nextHighest[i]]);
        totalTrappedWater += (minHighest - buildings[i]); 
    }

    return totalTrappedWater;
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
            cin>>arr[i];
        
        cout<<getTrappedRainWater(arr)<<endl;
    }
    return 0;
}
