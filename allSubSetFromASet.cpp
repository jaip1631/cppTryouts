// https://www.geeksforgeeks.org/find-distinct-subsets-given-set/

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

void fillSubSet(const vector<int> &collection, int index, vector<int> &curSet, set<vector<int>> &subSets)
{
    if (index == collection.size())
        return;

    curSet.push_back(collection[index]);
    if (subSets.find(curSet) == subSets.end())
        subSets.insert(curSet);

    fillSubSet(collection, index + 1, curSet, subSets);
    curSet.pop_back();
    fillSubSet(collection, index + 1, curSet, subSets);
}

set<vector<int>> getAllSubSets(const vector<int> &collection)
{
    set<vector<int>> subSets;
    vector<int> curSet;
    fillSubSet(collection, 0, curSet, subSets);
    return subSets;
}

void printSetOfVec(const set<vector<int>> subSets)
{
    set<vector<int>>::const_iterator itr_i = subSets.begin();
    bool first = true;

    cout << "()";
    while (itr_i != subSets.end())
    {
        vector<int>::const_iterator itr_j = (*itr_i).begin();
        cout << "(";
        first = true;
        while (itr_j != (*itr_i).end())
        {
            if (!first)
                cout << " ";
            cout << (*itr_j);
            itr_j++;
            first = false;
        }
        cout << ")";
        itr_i++;
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int testCase = 1, size = 5;
    cin >> testCase;
    while (testCase--)
    {
        cin>>size;
        vector<int> arr(size);
        for(int i = 0; i < size; i++)
             cin>>arr[i];

        sort(arr.begin(), arr.end());
        printSetOfVec(getAllSubSets(arr));
    }
    return 0;
}
