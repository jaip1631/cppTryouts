#include <iostream>
#include <vector>
using namespace std;

int getMax(int a, int b)
{
    return a>b?a:b;
}
int getMin(int a, int b)
{
    return a<b?a:b;
}

int eggDropRec(int floors, int eggs)
{
    if(floors <=0)
        return 0;

    if(eggs == 1)
        return floors;


    int minTrial = __INT_MAX__;
    for(int i = 1; i <= floors; i++)
    {
        minTrial = getMin(minTrial, 1 + getMax(
                                                eggDropRec(floors-i, eggs), 
                                                eggDropRec(i-1, eggs-1)
                                            )
                        );
    }

    return minTrial;
}


int eggDropDP(int floors, int eggs)
{
    vector<vector<int>> DPMat(eggs+1, vector<int>(floors+1, 0));
    
    for(int i = 0; i <= floors; i++)
        DPMat[1][i] = i;
    
    for(int i = 2; i <= eggs; i++)
    {
        for(int j = 1; j <= floors; j++)
        {
            if(i > j)
                DPMat[i][j] = DPMat[i-1][j];
            else
            {
                DPMat[i][j] = __INT_MAX__;
                for(int k = 1; k < j; k++)
                    DPMat[i][j] = getMin(DPMat[i][j], 1 + getMax(DPMat[i-1][k-1], DPMat[i][j-k]));
            }
        }
    }

    return DPMat[eggs][floors];
}

int main(int argc, char const *argv[])
{
    int floors = 10, eggs = 2;
    cout<<eggDropDP(floors, eggs);
    return 0;
}