#include <iostream>
#include <vector>

using namespace std;

int getMax(int a, int b)
{
    return a>b?a:b;
}
void getMaxValueBackTracking(int weight, int &maxVal, int curValue, const vector<int> &val, const vector<int> &wt)
{
    if(weight < 0)
        return;
    if(weight == 0)
        maxVal = maxVal < curValue ? curValue : maxVal;
    
    for(int i = 0; i < wt.size(); i++)
    {
        if(weight-wt[i] >= 0)
            getMaxValueBackTracking(weight-wt[i], maxVal, curValue+val[i], val, wt);
    }
}

int weight = 35;
vector<int> maxValueForWeightArray(weight + 1, -1);

int getMaxValueRec(int weight, const vector<int> &val, const vector<int> &wt)
{
    if(weight == 0)
        return 0;

    int max = 0;
    
    for(int i = 0; i < wt.size(); i++)
    {
        if(weight >= wt[i])
            max = getMax(max, val[i]+getMaxValueRec(weight-wt[i], val, wt));
    }

    return max;
}

int getMaxValueMem(int weight, const vector<int> &val, const vector<int> &wt)
{
    if(maxValueForWeightArray[weight] != -1)
        return maxValueForWeightArray[weight];

    if(weight == 0)
        return 0;

    int max = 0;
    
    for(int i = 0; i < wt.size(); i++)
    {
        if(weight >= wt[i])
            max = getMax(max, val[i]+getMaxValueMem(weight-wt[i], val, wt));
    }

    maxValueForWeightArray[weight] = max;

    return max;
}


int getMaxValueBottmUp(int weight, const vector<int> &val, const vector<int> &wt)
{
    if(weight == 0)
        return 0;

    vector<int> DP(weight+1);
    
    for(int i = 1; i <= weight; i++)
    {
        for(int j = 0; j < wt.size(); j++)
        {
            if(i >= wt[j])
                DP[i] = getMax(DP[i], val[j] + DP[i-wt[j]]);
        }
    }

    return DP[weight];
}

int main(int argc, char const *argv[])
{
    vector<int> val({10, 40, 50, 70}), wt({1, 3, 4, 5});
    int max = 0, curValue = 0;
    cout<<getMaxValueBottmUp(weight, val, wt);
    //cout<<max<<endl;
    return 0;
}
