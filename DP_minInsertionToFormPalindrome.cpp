#include <iostream>
#include <vector>
using namespace std;

int getMax(int a, int b)
{
    return a>b?a:b;
}
int getMin(int a, int b)
{
    return a<b?a:b;
}

int minInsertionToFormPalindromeRec(string &str, int start, int end)
{
    if(start >= end)
        return 0;
    
    if(start == end-1)
        return str[start] == str[end] ? 0 : 1;

    if(str[start] == str[end])
        return minInsertionToFormPalindromeRec(str, start+1, end-1);
    
    return 1 + getMin(minInsertionToFormPalindromeRec(str, start+1, end),
                    minInsertionToFormPalindromeRec(str, start, end-1));
}

int minInsertionToFormPalindromeDP(string str)
{
    vector<vector<int>>DPMat(str.size()+1, vector<int>(str.size()+1));

    for(int i = 1; i <= str.size(); i++)
        DPMat[i][i] = 0;
    
    for(int len = 1; len <=str.size(); len++)
    {
        for(int j = 0; j <=str.size()-len; j++)
        {
            int start = j;
            int end = j+len-1;
            if(start == end)
                DPMat[start][end] = 0;
            else if(start == end-1)
                DPMat[start][end] = str[start] == str[end] ? 0 : 1;
            else if(str[start] == str[end])
                DPMat[start][end] = DPMat[start+1][end-1];
            else
                DPMat[start][end] = 1 + getMin(DPMat[start+1][end], DPMat[start][end-1]);
        }
    }

    return DPMat[0][str.size()-1];
}

int main(int argc, char const *argv[])
{
    string str = "abcda";
    cout<<minInsertionToFormPalindromeDP(str);
    return 0;
}
