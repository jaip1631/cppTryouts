#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

void createPatMap(unordered_map<char, vector<int>> &patMap, const string &pat)
{
    for(int i = 0 ; i < pat.length(); i++)
        patMap[pat[i]].push_back(i);
}

bool isMatching(const string &word, unordered_map<char, vector<int>> &patMap, const string &pat)
{
    for(int i = 0; i < word.length(); i++)
    {
        if(patMap.find(pat[i]) != patMap.end())
        {
            for(int j = 0; j < patMap[pat[i]].size(); j++)
            {
                if(word[i] != word[patMap[pat[i]][j]])
                    return false;
            }
            patMap.erase(word[i]);
        }
    }
    return true;
}

vector<string> printMatchingWordsFromDict(const vector<string> &dict, const string &pat)
{
    unordered_map<char, vector<int>>patMap;
    createPatMap(patMap, pat);
    vector<string> ans;
    for(string word: dict)
    {
        if(word.length() == pat.length() && isMatching(word, patMap, pat))
            ans.push_back(word);
    }
    return ans;
}

void printVec(const vector<string> &arr)
{
    for(int i = 0; i < arr.size(); i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}


int main()
{
    vector<string> dict = {"abb", "abc", "xyz", "xyy"};
    string pat = "foo";
    printVec(printMatchingWordsFromDict(dict, pat));
    return 0;
}