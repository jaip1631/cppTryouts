// https://www.geeksforgeeks.org/find-next-greater-number-set-digits/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> nextGreaterNumberSameDigit(const vector<int> &sourceVec)
{
    vector<int> vec = sourceVec;
    int i;
    for (i = vec.size() - 1; vec[i - 1] >= vec[i] && i >= 1; i--)
        ;
    if (i == 0)
        return {};

    int firstSmallerIndex = i - 1, nextGreaterIndex = i;
    while (i != vec.size())
    {
        if (vec[i] < vec[nextGreaterIndex] && vec[i] > vec[firstSmallerIndex])
            nextGreaterIndex = i;
        i++;
    }

    swap(vec[firstSmallerIndex], vec[nextGreaterIndex]);
    sort(vec.begin() + firstSmallerIndex + 1, vec.end());
    return vec;
}

void printNextGreaterNoSameDigit(const vector<int> &vec)
{
    if (vec.empty())
    {
        cout << "Not Possible\n";
        return;
    }

    for (int i = 0; i < vec.size(); i++)
    {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
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
        printNextGreaterNoSameDigit(nextGreaterNumberSameDigit(arr));
    }
    return 0;
}
