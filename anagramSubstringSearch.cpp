#include <iostream>
#include <unordered_map>
using namespace std;

void fillMap(unordered_map<char, int> &expMap, unordered_map<char, int> &curMap, const string &pat)
{
    for(int i = 0; i < pat.length(); i++)
        expMap[pat[i]]++;
    
    unordered_map<char, int>::iterator itr = expMap.begin();
    while(itr != expMap.end())
    {
        curMap[itr->first] = 0;
        itr++;
    }
}

void getAnagramIndex(const string &text, const string &pat)
{
    unordered_map<char, int> expMap, curMap;
    int expCount = pat.length(), curCount = 0;
    fillMap(expMap, curMap, pat);

    for(int i = 0; i < pat.length(); i++)
    {
        if(expMap.find(text[i]) != expMap.end())
        {
            if(curMap[text[i]] < expMap[text[i]])
                curCount++;

            curMap[text[i]]++;
        }
    }

    for(int i = pat.length(); i < text.length(); i++)
    {
        if(curCount == expCount)
            cout<<i-pat.length()<<endl;
        
        if(expMap.find(text[i]) != expMap.end())
        {
            if(curMap[text[i]] < expMap[text[i]])
                curCount++;

            curMap[text[i]]++;
        }
        if(expMap.find(text[i-pat.length()]) != expMap.end())
        {
            if(curMap[text[i-pat.length()]] <= expMap[text[i-pat.length()]])
                curCount--;
            
            curMap[text[i-pat.length()]]--;
        }
    }

    if(curCount == expCount)
        cout<<text.length()-pat.length()<<endl;
}

int main()
{
    string text = "AAABABAA", pat = "AABA";
    getAnagramIndex(text, pat);
    return 0;
}