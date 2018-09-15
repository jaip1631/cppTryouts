// https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/

#include <iostream>
#include <vector>

using namespace std;

int getMax(int a, int b)
{
    return a > b ? a : b;
}

int getMaxCommon(const string &str, int leftIndex, int rightIndex)
{
    int count = 0;
    while (leftIndex >= 0 && rightIndex < str.size() && str[leftIndex] == str[rightIndex])
    {
        count++;
        leftIndex--;
        rightIndex++;
    }

    return count;
}

void updateMaxPalindromeString(int &start, int len, int &maxPalindromeStart, int &maxPalindromeLen)
{
    if (len > maxPalindromeLen)
    {
        maxPalindromeLen = len;
        maxPalindromeStart = start;
    }
}

// get max palindrome length around center of a potential palindrome.
string getMaxPalindromeLength(const string &str)
{
    if (str.empty())
        return "";

    int strLen = str.size(), maxPalindromeLen = 1, maxPalindromeStart = 0;
    string maxPalindromeString = "";
    int left = -1, palLen = -1, count = 0;
    for (int middle = 0; middle < strLen; middle++)
    {
        int evenLenPal = getMaxCommon(str, middle, middle + 1);
        int oddLenPal = getMaxCommon(str, middle - 1, middle + 1);
        if (evenLenPal > oddLenPal)
        {
            left = middle - evenLenPal + 1;
            palLen = 2 * evenLenPal;

            updateMaxPalindromeString(left, palLen, maxPalindromeStart, maxPalindromeLen);
        }
        else
        {
            left = middle - oddLenPal;
            palLen = 2 * oddLenPal + 1;

            updateMaxPalindromeString(left, palLen, maxPalindromeStart, maxPalindromeLen);
        }
    }

    return str.substr(maxPalindromeStart, maxPalindromeLen);
}

void printMatrix(const vector<vector<bool>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

string getMaxPalindromeLength_DP(const string &str)
{
    if (str.empty())
        return "";
    vector<vector<bool>> palindromeLengthVsEndingAt(str.size() + 1, vector<bool>(str.size() + 1, false));
    int maxPalStartingAt = 0, maxPalLen = 1;

    for (int len = 0; len < str.size() + 1; len++)
    {
        for (int endingAt = len; endingAt < str.size() + 1; endingAt++)
        {
            if (len == 0 || len == 1)
            {
                palindromeLengthVsEndingAt[len][endingAt] = true;
                continue;
            }

            if (palindromeLengthVsEndingAt[len - 2][endingAt - 1] && (str[endingAt - 1] == str[endingAt - len]))
            {
                palindromeLengthVsEndingAt[len][endingAt] = true;
                if (len > maxPalLen)
                {
                    maxPalStartingAt = endingAt - len;
                    maxPalLen = len;
                }
            }
        }
    }

    //printMatrix(palindromeLengthVsEndingAt);
    return str.substr(maxPalStartingAt, maxPalLen);
}

int main(int argc, char const *argv[])
{
    int testCase = 1;
    string str;
    cin >> testCase;
    while (testCase--)
    {
        cin >> str;
        cout << getMaxPalindromeLength_DP(str) << endl;
    }
    return 0;
}
