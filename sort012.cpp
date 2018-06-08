#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void sort012(vector<int> &arr)
{
    int left = 0, right = arr.size()-1, mid = 0;

    while(mid <= right)
    {
        while(left < arr.size() && arr[left] == 0)
            left++;
        if(mid < left)
            mid = left;
        while(right >= 0 && arr[right] == 2)
            right--;
        if(arr[mid] == 2 && mid < right)
            swap(arr[mid], arr[right]);
        if(arr[mid] == 0 && mid > left)
            swap(arr[mid], arr[left]);
        mid++;
    }
}

void printVector(const vector<int> &arr)
{
    for(auto itr = arr.begin(); itr != arr.end(); itr++)
        cout<<(*itr)<<" ";
}

int main(int argc, char const *argv[])
{
    unsigned testCase, arrSize;
    cin>>testCase;
    testCase = 1;
    while(testCase--)
    {
        cin>>arrSize;
        vector<int> arr(arrSize);
        for(int i = 0; i < arrSize; i++)
            cin>>arr[i];
        sort012(arr);
        printVector((arr));
        cout<<endl;
    }
    return 0;
}
