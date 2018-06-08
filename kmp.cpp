#include <iostream>
#include <string>
#include <vector>
using namespace std;

void fillPrefixSuffixArray(const string &pattern, vector<unsigned> &prefixSuffixArray)
{
    for(unsigned i = 0, j = 1; j < pattern.length();)
    {
        if(pattern[i] == pattern[j])
        {
            prefixSuffixArray[j] = i+1;
            i++;
            j++;
        }   
        else if(i == 0)
        {
            prefixSuffixArray[j] = 0;
            j++;
        }
        else
        {
            i = prefixSuffixArray[i-1];
        }
    }
}

bool findUsingKmp(const string &str, const string &pattern)
{
    vector<unsigned> prefixSuffixArray(pattern.size());

    fillPrefixSuffixArray(pattern, prefixSuffixArray);

    int i = 0, j = 0;
    while(i < str.size() && j < pattern.size())
    {
        if(str[i] == pattern[j])
        {
            i++;
            j++;
        }
        else if(j != 0)
            j = prefixSuffixArray[j-1];
        else
            i++;
    }

    return (j == pattern.size());
}

// int main(int argc, char const *argv[])
// {
//     string str = "aaabaaabaaabaabaaaab", pattern = "aabaabaaaaba";
//     if(findUsingKmp(str, pattern))
//     {
//         cout<<"String Present";
//     }
//     else
//         cout<<"not present";

//     return 0;
// }