// https://www.geeksforgeeks.org/largest-rectangle-under-histogram/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void printVector(const vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
}

vector<int> getNextSmallestElement(const vector<int> &arr)
{
    stack<int> smallestStack;
    vector<int> nextSmallestElement(arr.size());

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (!smallestStack.empty() && arr[i] < arr[smallestStack.top()])
            smallestStack.pop();
        nextSmallestElement[i] = smallestStack.empty() ? arr.size() : smallestStack.top();
        smallestStack.push(i);
    }

    return nextSmallestElement;
}

vector<int> getPreviousSmallestElement(const vector<int> &arr)
{
    stack<int> smallestStack;
    vector<int> previousSmallestElement(arr.size());

    for (int i = 0; i < arr.size(); i++)
    {
        while (!smallestStack.empty() && arr[i] < arr[smallestStack.top()])
            smallestStack.pop();
        previousSmallestElement[i] = smallestStack.empty() ? -1 : smallestStack.top();
        smallestStack.push(i);
    }

    return previousSmallestElement;
}

int getMax(int a, int b)
{
    return a > b ? a : b;
}

int getLargestAreaUnderHistogram(const vector<int> &histogram)
{
    vector<int> nextSmallest = getNextSmallestElement(histogram),
                previousSmallest = getPreviousSmallestElement(histogram);

    int maxSum = -1;

    for (int i = 0; i < histogram.size(); i++)
    {
        maxSum = getMax(maxSum, histogram[i] * (nextSmallest[i] - previousSmallest[i] - 1));
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
        cout<<getLargestAreaUnderHistogram(arr)<<endl;
    }
    return 0;
}
