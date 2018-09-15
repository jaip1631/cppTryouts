// https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/

#include <iostream>

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
        return 0;

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

int main(int argc, char const *argv[])
{
    int testCase = 1;
    string str;
    cin >> testCase;
    while (testCase--)
    {
        cin >> str;
        cout << getMaxPalindromeLength(str) << endl;
    }
    return 0;
}
