// https://www.geeksforgeeks.org/longest-common-substring-dp-29/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int getLongestCommonSuffix(const string &str1, const string &str2)
{
    vector<vector<int>> maxSuffixMatrixLen(str1.size() + 1, vector<int>(str2.size() + 1, 0));
    int longestCommonSuffix = 0;

    for (int str1Len = 1; str1Len < str1.size() + 1; str1Len++)
    {
        for (int str2Index = 1; str2Index < str2.size() + 1; str2Index++)
        {
            if (str1[str1Len - 1] == str2[str2Index - 1])
            {
                maxSuffixMatrixLen[str1Len][str2Index] = 1 + maxSuffixMatrixLen[str1Len - 1][str2Index - 1];
                if (longestCommonSuffix < maxSuffixMatrixLen[str1Len][str2Index])
                    longestCommonSuffix = maxSuffixMatrixLen[str1Len][str2Index];
            }
        }
    }

    return longestCommonSuffix;
}

int main(int argc, char const *argv[])
{
    int testCase = 1, size;
    string str1, str2;
    cin >> testCase;
    while (testCase--)
    {
        cin >> size >> size;
        cin >> str1 >> str2;
        cout << getLongestCommonSuffix(str1, str2) << endl;
    }
    return 0;
}
