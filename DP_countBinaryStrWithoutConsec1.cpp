// https://www.geeksforgeeks.org/count-number-binary-strings-without-consecutive-1s/

#include <iostream>
#include <vector>

using namespace std;

#define _MOD 1000000007

unsigned long countBinaryStrWithoutConsecutiveOne(int sizeOfString)
{
    vector<unsigned long> DPArr(sizeOfString + 1);

    DPArr[0] = 1;
    DPArr[1] = 2;

    for (int i = 2; i <= sizeOfString; i++)
    {
        DPArr[i] = DPArr[i - 2] + DPArr[i - 1];
        DPArr[i] = DPArr[i] % _MOD;
    }

    return DPArr[sizeOfString];
}

int main(int argc, char const *argv[])
{
    int testCase = 1, size = 92;
    cin >> testCase;
    while (testCase--)
    {
        cin >> size;
        cout << (countBinaryStrWithoutConsecutiveOne(size)) % _MOD << endl;
    }
    return 0;
}