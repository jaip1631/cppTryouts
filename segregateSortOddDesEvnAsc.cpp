#include<iostream>
#include<algorithm>
using namespace std;

int swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int inplaceSeg(int *arr, int size)
{
    int left = 0, right = size-1;
    while(left < right)
    {
        while(left < size && arr[left]&1)
            left++;
        while(right >= 0 && !(arr[right]&1))
            right--;

        if(left < right)
            swap(arr[left], arr[right]);
    }
    return left-1;
}

void printArr(int *arr, int size)
{
    for(int i = 0; i < size; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main()
{
    int arr[] = {3, 2, 5, 4, 1, 7, 8, 9, 6, 10};

    printArr(arr, sizeof(arr)/sizeof(int));
    int left = inplaceSeg(arr, sizeof(arr)/sizeof(int));
    sort(arr, arr+left, greater<int>());
    sort(arr+left+1, arr+sizeof(arr)/sizeof(int));
    printArr(arr, sizeof(arr)/sizeof(int));
    return 0;
}