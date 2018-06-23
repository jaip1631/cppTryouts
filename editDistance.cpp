#include <iostream>
#include <string>
using namespace std;

int getMin(int a, int b)
{
    return a<b?a:b;
}

int editDistance(string &str1, string &str2, int n1, int n2)
{
    if(n1 == str1.size() && n2 == str2.size())
        return 0;
    
    if(n1 == str1.size())
        return n1-n2;
    
    if(n2 == str2.size())
        return n2-n1;
    
    if(str1[n1] != str2[n2])
        return 1 + getMin(
                        editDistance(str1, str2, n1+1, n2+1), // replace in first
                        getMin(
                            editDistance(str1, str2, n1, n2+1), // insert in first
                            editDistance(str1, str2, n1, n2+1) // remove from first
                        )
                    );
    return editDistance(str1, str2, n1+1, n2+1);
}

int editDistanceDP(string str1, string str2)
{
    int DPMat[str1.size()+1][str2.size()+1];
    DPMat[0][0] = 0;

    for(int j = 0; j < str2.size(); j++)
        DPMat[0][j+1] = j+1;

    for(int i = 0; i < str1.size(); i++)
        DPMat[i+1][0] = i+1;
    
    for(int i = 1; i <= str1.size(); i++)
    {
        for(int j = 1; j <= str2.size(); j++)
        {
            if(str1[i-1] == str2[j-1])
                DPMat[i][j] = DPMat[i-1][j-1];
            else
                DPMat[i][j] = 1 + getMin(DPMat[i-1][j-1], getMin(DPMat[i-1][j], DPMat[i][j-1]));
        }
    }

    return DPMat[str1.size()][str2.size()];
}

int main(int argc, char const *argv[])
{
    string str1 = "CAR", str2 = "CAT";
    cout<<editDistanceDP(str1, str2);
    return 0;
}
