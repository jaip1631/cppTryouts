#include <iostream>
#include <vector>

using namespace std;

int getMax(int a, int b)
{
    return a>b?a:b;
}

int getLongestPalindromicSubSeqRec(string &str, int start, int end)
{
    if(start == str.size() || end <= 0 || start > end)
        return 0;
    
    if(start == end)
        return 1;
    
    if(str[start] == str[end])
        return 2 + getLongestPalindromicSubSeqRec(str, start+1, end-1);
    return getMax(getLongestPalindromicSubSeqRec(str, start+1, end),
                    getLongestPalindromicSubSeqRec(str, start, end-1));
}

int getLongestPalindromicSubSeqDP(string  &str)
{
    vector<vector<int>>DPMat(str.size()+1, vector<int>(str.size()+1));

    for(int palLen = 1; palLen <= str.size(); palLen++)
    {
        for(int i = 0; i <= str.size()-palLen; i++)
        {
            int start = i;
            int end = start+palLen-1;
            if(start == end)
                DPMat[start][end] = 1;
            else if(str[start] == str[end] && start == end-1)
                DPMat[start][end] = 2;
            else if(str[start] == str[end])
                DPMat[start][end] = 2 + DPMat[start+1][end-1];
            else
                DPMat[start][end] = getMax(DPMat[start][end-1], DPMat[start+1][end]);
        }
    }

    return DPMat[0][str.size()-1];  
}

int main(int argc, char const *argv[])
{
    string str = "BBAACXAXABB";   
    cout<<getLongestPalindromicSubSeqDP(str);
    return 0;
}
