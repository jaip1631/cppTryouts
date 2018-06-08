#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

char getCharForN(int N)
{
    if(N%26)
        return 'A'+(N%26)-1;
    else
        return 'Z';
}

string getEncoded(int N)
{
    string colName = "";
    while(N != 0)
    {
        colName.push_back(getCharForN(N));
        N -= N%26?N%26:26;
        N = N/26;
        //cout<<N<<endl;
    }
    reverse(colName.begin(), colName.end());
    return colName;
}

int getDecoded(const string &str)
{
    int ans = 0;
    int base = 1;
    for(int i = str.length()-1; i >= 0; i--)
    {
        ans += (str[i]-'A'+1)*base;
        base*=26;
    }
    return ans;
}

int main() {
	int testCase, N;
	cin>>testCase;
	
	while(testCase--)
	{
	    cin>>N;
	    cout<<getEncoded(N)<<endl;
        cout<<getDecoded(getEncoded(N))<<endl;
	}
	return 0;
}