#include <iostream>
#include <vector>
using namespace std;

//first try not returning throught function. Returning through parameter
void Knapsack_rec(const vector<int> &val, const vector<int> &wgt, int W, int solVal, int &maxSolVal, int i)
{
    if(W < 0)
        return;
    if(solVal > maxSolVal)
        maxSolVal = solVal;
    if(i == val.size())
        return;
    
    Knapsack_rec(val, wgt, W-wgt[i], solVal + val[i], maxSolVal, i+1);
    Knapsack_rec(val, wgt, W, solVal, maxSolVal, i+1);
}

int getMax(int a, int b)
{
    return a>b?a:b;
}

//second try. Returning through function
int Knapsack_ret_rec(const vector<int> &val, const vector<int> &wgt, int W, int i)
{
    if(i == val.size())
        return 0;

    if(W == 0)
        return 0;

    if(wgt[i] > W)
        return Knapsack_ret_rec(val, wgt, W, i+1);

    return getMax(val[i] + Knapsack_ret_rec(val, wgt, W-wgt[i], i+1),
                            Knapsack_ret_rec(val, wgt, W, i+1));
}

//memoitazion approach
int DP_mem[51][4];

int Knapsack_ret_mem(const vector<int> &val, const vector<int> &wgt, int W, int i)
{
    if(DP_mem[W][i] != -1)
        return DP_mem[W][i];

    if(i == val.size() || W == 0)
    {
        DP_mem[W][i] = 0;
        return DP_mem[W][i];
    }

    if(wgt[i] > W)
        DP_mem[W][i] = Knapsack_ret_mem(val, wgt, W, i+1);
    else
        DP_mem[W][i] = getMax(val[i] + Knapsack_ret_mem(val, wgt, W-wgt[i], i+1),
                            Knapsack_ret_mem(val, wgt, W, i+1));
    
    return DP_mem[W][i];
}

void SetDPMat(int row, int col, int n)
{
    for(int i = 0 ; i <= row; i++)
        for(int j = 0; j <= col; j++)
            DP_mem[i][j] = n;
}

//DP iterative
int Knapsack_ret_itr(const vector<int> &val, const vector<int> &wgt, int W)
{
    SetDPMat(W, val.size(), 0);

    for(int i = 1; i <= W; i++)
    {
        for(int j = 1; j <= val.size(); j++)
        {
            if(i < wgt[j-1])
                DP_mem[i][j] = DP_mem[i][j-1];
            else
            {
                DP_mem[i][j] = getMax(val[j-1] + DP_mem[i-wgt[j-1]][j-1],
                                        DP_mem[i][j-1]);
            }
        }
    }

    return DP_mem[W][val.size()];
}

int main()
{
    vector<int> val({60, 100, 120});
    vector<int> wgt({10, 20, 30});
    int W = 50, sol=0;

    SetDPMat(val.size(), W, -1);
    
    //Knapsack_rec(val, wgt, W, 0, sol, 0);
    sol = Knapsack_ret_itr(val, wgt, W);
    cout<<sol<<endl;
    return 0;
}