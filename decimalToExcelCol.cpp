// https://www.geeksforgeeks.org/find-excel-column-name-given-number/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string decimalToExcelCol(int num)
{
    int remainder = 0;
    string excel = "";

    while (num != 0)
    {
        num--;
        remainder = num % 26;
        excel.push_back('A'+remainder);
        num /= 26;
    }

    reverse(excel.begin(), excel.end());
    return excel;
}

int main(int argc, char const *argv[])
{
    int testCase, num;
    cin>>testCase;
    while(testCase--)
    {
        cin>>num;
        cout<<decimalToExcelCol(num)<<endl;
    }
    return 0;
}
