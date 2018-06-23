#include <iostream>
#include <vector>
using namespace std;

int cost[7][7] = {
{0, 10, 75, 94, 10, 75, 94},
{-1, 0, 35, 50, 10, 75, 94},
{-1, -1, 0, 80, 10, 75, 94},
{-1, -1, -1, 0, 10, 75, 94},
{-1, 0, 35, 50, 0, 75, 94},
{-1, -1, 0, 80, 10, 0, 94},
{-1, -1, -1, 0, 10, 75, 0}
};

int getMin(int a, int b)
{
    return a<b?a:b;
}

int getMinCostRec(int source, int destination)
{
    if(source == destination || destination == source + 1)
    {
        return cost[source][destination];
    }

    int minCost = cost[source][destination];
    for(int i = source+1; i < destination; i++)
    {
        minCost = getMin(minCost, getMinCostRec(source, i) + getMinCostRec(i, destination));
    }

    return minCost;
}

vector<vector<int>>mem(8, vector<int>(8, -1));

int getMinCostMem(int source, int destination)
{
    if(source == destination || destination == source + 1)
    {
        return cost[source][destination];
    }

    if(mem[source][destination] != -1)
        return mem[source][destination];

    int minCost = cost[source][destination];
    for(int i = source+1; i < destination; i++)
    {
        minCost = getMin(minCost, getMinCostMem(source, i) + getMinCostMem(i, destination));
    }

    mem[source][destination] = minCost;
    return mem[source][destination];
}

int getMinCostDP(int source, int destination)
{
    if(source == destination || destination == source + 1)
    {
        return cost[source][destination];
    }

    vector<int>DP(8);
    DP[0] = 0;

    for(int i = 1; i <= destination; i++)
    {
        int min = cost[0][i];
        for(int j = 0; j < i; j++)
        {
            min = getMin(min, DP[j]+cost[j][i]);
        }
        DP[i] = min;
    }

    return DP[destination];
}

int main(int argc, char const *argv[])
{
    cout<<getMinCostMem(0, 6);
    return 0;
}
