#include<iostream>
#include<vector>
using namespace std;

int getPivot(const vector<int> &arr, int left, int right)
{
    if(left == right)
        return left;
    if(left == right-1)
        return arr[left]>arr[right]?left:right;

    int middle = left + (right-left)/2;
    if(arr[middle] > arr[middle + 1])
        return middle;
    if(arr[left] < arr[middle])
        return(getPivot(arr, middle+1, right));
    return(getPivot(arr,left, middle-1));
}

int getIndexOf(const vector<int> &arr, int num, int left, int right)
{
    if(left > right)
        return -1;
    
    int middle = left + (right-left)/2;
    if(arr[middle] == num)
        return middle;
    
    if(arr[middle] > num)
        getIndexOf(arr, num, left, middle-1);
    else
        getIndexOf(arr, num, middle+1, right);
}

int search(const vector<int> &arr, int num)
{
    int pivot = getPivot(arr, 0, arr.size()-1);
	
    int left = getIndexOf(arr, num, 0, pivot);
    int right = getIndexOf(arr, num, pivot+1, arr.size()-1);
    if(left == right && left == -1)
        return -1;
    if(left != -1)
        return left;
    return right;
}

bool doPairWithSumExist(const vector<int> &arr, int sum)
{
    int high = getPivot(arr, 0, arr.size()-1);
    int low = (high+1) % arr.size();

    while(high != low)
    {
        if(arr[high] + arr[low] == sum)
            return true;
        if(arr[high] + arr[low] > sum)
            high--;
        else
            low++;
        high = (high + arr.size()) % arr.size();
        low = (low) % arr.size();
    }
    return false;
}

int main() {
    vector<int> arr({30,40,50,60,70,80,90,100,10,20,21,22,23/*,25,26,27,28,29*/});
	cout<<doPairWithSumExist(arr, 30)<<endl;
    return 0;
}