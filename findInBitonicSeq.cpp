#include <iostream>
#include<vector>
using namespace std;

int getPivot(const vector<int> &arr, int left, int right)
{
    if(left > right)
        return -1;
    
    if(left == right -1)
        return arr[left]>arr[right]?left:right;
    
    int middle = left + (right-left)/2;
    if(arr[middle] > arr[middle+1] && 
        arr[middle] > arr[middle-1])
        return middle;
    if(arr[middle] > arr[middle-1])
        return getPivot(arr, middle+1, right);
    else
        return getPivot(arr, left, middle-1);
}

int getIndexOfInc(const vector<int> &arr, int num, int left, int right)
{
    if(left > right)
        return -1;
    
    int middle = left + (right-left)/2;
    if(arr[middle] == num)
        return middle;
    
    if(arr[middle] > num)
        getIndexOfInc(arr, num, left, middle-1);
    else
        getIndexOfInc(arr, num, middle+1, right);
}

int getIndexOfDec(const vector<int> &arr, int num, int left, int right)
{
    if(left > right)
        return -1;
    
    int middle = left + (right-left)/2;
    if(arr[middle] == num)
        return middle;
    
    if(arr[middle] < num)
        getIndexOfDec(arr, num, left, middle-1);
    else
        getIndexOfDec(arr, num, middle+1, right);
}

int search(const vector<int> &arr, int num)
{
    int pivot = getPivot(arr, 0, arr.size()-1);
	
    int left = getIndexOfInc(arr, num, 0, pivot);
    int right = getIndexOfDec(arr, num, pivot+1, arr.size()-1);
    if(left == right && left == -1)
        return -1;
    if(left != -1)
        return left;
    return right;
}


int main() {
	int testCase, arrSize, N;
	cin>>testCase;
	
	while(testCase--)
	{
	    cin>>arrSize>>N;
	    vector<int> arr(arrSize);
	    for(int i = 0; i < arrSize; i++)
	        cin>>arr[i];
        int index = search(arr, N);
        if(index == -1)
            cout<<"OOPS! NOT FOUND";
        else
            cout<<index;
        cout<<endl;
	}
	return 0;
}