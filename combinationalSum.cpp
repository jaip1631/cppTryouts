// https://practice.geeksforgeeks.org/problems/combination-sum/0

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void fillCombinationalSumVector(const vector<int> &sourceArr, int index, int reqSum, 
        vector<int> &curCombinationalSum, vector<vector<int>> &combinationalSumVector) {
    if(index == sourceArr.size())
        return;
    else if(reqSum < sourceArr[index])
        return;
    
    curCombinationalSum.push_back(sourceArr[index]);

    if(reqSum == sourceArr[index]) {
        combinationalSumVector.push_back(curCombinationalSum);
        curCombinationalSum.pop_back();
        return;
    }

    fillCombinationalSumVector(sourceArr, index, reqSum-sourceArr[index], curCombinationalSum, combinationalSumVector);
    curCombinationalSum.pop_back();

    fillCombinationalSumVector(sourceArr, index+1, reqSum, curCombinationalSum, combinationalSumVector);
}

vector<vector<int>> getCombinationalSum(vector<int> &sourceArr, int reqSum) {
    vector<int> curCombinationalSum;
    vector<vector<int>> combinationalSumVector;
    
    sort(sourceArr.begin(), sourceArr.end());
    sourceArr.erase( unique( sourceArr.begin(), sourceArr.end() ), sourceArr.end() );
    fillCombinationalSumVector(sourceArr, 0, reqSum, curCombinationalSum, combinationalSumVector);

    return combinationalSumVector;
}

void printCombinationalSum(const vector<vector<int>> &combinationalSumVector) {
    if(combinationalSumVector.empty()){
        cout<<"Empty"<<endl;
        return;
    }
    
    vector<vector<int>> ::const_iterator itr_i = combinationalSumVector.begin();
    bool first = true;

    while(itr_i != combinationalSumVector.end()) {
        vector<int> ::const_iterator itr_j = (*itr_i).begin();
        cout<<"(";
        first = true;
        while(itr_j != (*itr_i).end()) {
            if(!first)
                cout<<" ";
            cout<<(*itr_j);
            itr_j++;
            first = false;
        }
        cout<<")";
        itr_i++;
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    int testCase, arrSize, reqSum;
    vector<int> sourceArr;
    cin>>testCase;
    while(testCase--) {
        cin>>arrSize;
        sourceArr.resize(arrSize);

        for(int i = 0; i < arrSize; i++)
            cin>>sourceArr[i];
        
        cin>>reqSum;

        printCombinationalSum(getCombinationalSum(sourceArr, reqSum));
    }
    return 0;
}
