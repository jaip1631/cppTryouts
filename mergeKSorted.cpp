// https://www.geeksforgeeks.org/merge-k-sorted-arrays/

#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    int arrayKey;
    int arrayKeyIndex;
};

class MinHeap
{
  private:
    vector<Node> arr;
    int size;
    int lastIndex;
    void heapify(int);

  public:
    Node extractMin();
    bool addNode(Node);
    bool isEmpty();
    void decreaseSizeBy(int);
    MinHeap(int size) : arr(size), size(size), lastIndex(-1) {}
    ~MinHeap()
    {
        arr.clear();
        size = 0;
        lastIndex = -1;
    }
};

void MinHeap::heapify(int rootIndex)
{
    int leftIndex = rootIndex * 2 + 1;
    int rightIndex = rootIndex * 2 + 2;
    int smallextIndex = rootIndex;

    if (leftIndex <= lastIndex && arr[leftIndex].data < arr[smallextIndex].data)
        smallextIndex = leftIndex;
    if (rightIndex <= lastIndex && arr[rightIndex].data < arr[smallextIndex].data)
        smallextIndex = rightIndex;
    if (smallextIndex != rootIndex)
    {
        swap(arr[smallextIndex], arr[rootIndex]);
        heapify(smallextIndex);
    }
}

Node MinHeap::extractMin()
{
    if (lastIndex == -1)
        return {-1, -1};

    Node minNode = arr[0];
    arr[0] = arr[lastIndex];
    lastIndex--;

    if (lastIndex != -1)
        heapify(0);

    return minNode;
}

bool MinHeap::addNode(Node node)
{
    if (lastIndex == size - 1)
        return false;
    arr[++lastIndex] = node;
    for (int i = lastIndex / 2; i >= 0; i--)
        heapify(i);
}

bool MinHeap::isEmpty()
{
    return lastIndex == -1;
}

void MinHeap::decreaseSizeBy(int n)
{
    arr.resize(arr.size()-n);
}

vector<int> mergeKSorted(const vector<vector<int>> &kSortedVec)
{
    int kSortedVecSize = kSortedVec.size();
    vector<int> mergedVec;
    vector<int> vecIndex(kSortedVecSize);

    MinHeap minHeap(kSortedVecSize);
    for (int i = 0; i < kSortedVecSize; i++)
    {
        Node n;
        n.data = kSortedVec[i][0];
        n.arrayKey = i;
        n.arrayKeyIndex = 0;
        minHeap.addNode(n);
    }

    while (!minHeap.isEmpty())
    {
        Node n = minHeap.extractMin();
        mergedVec.push_back(n.data);
        if(n.arrayKeyIndex == kSortedVec[n.arrayKey].size()-1)
            minHeap.decreaseSizeBy(1);
        else
        {
            n.data = kSortedVec[n.arrayKey][++n.arrayKeyIndex];
            minHeap.addNode(n);
        }
    }

    return mergedVec;
}

void printVector(const vector<int> &vec)
{
    for(int i = 0; i < vec.size(); i++)
        cout<<vec[i]<<" ";
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    int testCase, size;
    cin>>testCase;
    while(testCase--)
    {
        cin>>size;
        vector<vector<int>> kSortedArray(size, vector<int>(size));
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                cin>>kSortedArray[i][j];
            }
        }
        printVector(mergeKSorted(kSortedArray));
    }
    return 0;
}
