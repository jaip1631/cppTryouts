#include <iostream>
#include <string>

using namespace std;

bool isInterLeaved(const string &A, const string &B, const string &C, int a, int b, int c)
{
    if(a == A.size() && b == B.size() && c == C.size())
        return true;
    
    if(c == C.size())
        return false;

    if(a < A.size() && A[a] != C[c] && b < B.size() && B[b] != C[c])
        return false;
    
    bool ret = false;
    if(a < A.size() && A[a] == C[c])
        ret = isInterLeaved(A, B, C, a+1, b, c+1);
    
    if(!ret && (b < B.size() && B[b] == C[c]))
        ret = isInterLeaved(A, B, C, a, b+1, c+1);

    return ret;
}

bool isInterLeavedDP(const string &a, const string &b, const string &c)
{
    if(a.size() + b.size() != c.size())
        return false;
    
    int DPMat[a.size() + 1][b.size() + 1];

    for(int j = 0; j < b.size(); j++)
    {
        DPMat[0][j+1] = b[j] == c[j];
    }
    for(int i = 0; i < a.size(); i++)
        DPMat[i+1][0] = a[i] == c[i];
    
    for(int i = 1; i <= a.size(); i++)
    {
        for(int j = 1; j <= b.size(); j++)
        {
            if(c[i+j-1] == a[i-1] && c[i+j-1] == b[j-1])
                DPMat[i][j] = DPMat[i-1][j] || DPMat[i][j-1];
            else if(c[i+j-1] == a[i-1] && c[i+j-1] != b[j-1])
                DPMat[i][j] = DPMat[i-1][j];
            else if(c[i+j-1] != a[i-1] && c[i+j-1] == b[j-1])
                DPMat[i][j] = DPMat[i][j-1];
            else
                DPMat[i][j] = false;
        }
    }

    return DPMat[a.size()][b.size()];
}


int main(int argc, char const *argv[])
{
    string A = "AAAAAA", B = "AAAAAAB", C = "AAAAAAAAAAAAB";
    if(isInterLeavedDP(A, B, C))
        cout<<"yes";
    else
        cout<<"no";
    return 0;
}
