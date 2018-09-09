// https://www.geeksforgeeks.org/find-a-tour-that-visits-all-stations/

#include <iostream>
#include <vector>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(const vector<petrolPump> &petrolDistance)
{
    vector<int> remainderPetrolFromStation(petrolDistance.size());

    for (int i = 0; i < petrolDistance.size(); i ++)
    {
        remainderPetrolFromStation[i] = petrolDistance[i].petrol - petrolDistance[i].distance;
    }

    int start = -1, cur = -1, carry = 0;
    for(int i = 0; i < remainderPetrolFromStation.size(); i++)
    {
        if(remainderPetrolFromStation[i] + carry >= 0)
        {
            start = i;
            cur = (i+1)%remainderPetrolFromStation.size();
            carry = remainderPetrolFromStation[i];
            while(cur != start && remainderPetrolFromStation[cur] + carry >= 0)
            {
                carry = remainderPetrolFromStation[cur] + carry;
                cur = (cur+1)%remainderPetrolFromStation.size();
            }
            if(cur == start)
                return cur;
            if(cur > start)
                i = cur;
        }
        carry = 0;
    }

    return -1;
}

int tour(petrolPump p[],int n)
{
    vector<petrolPump> arr(p, p+n);
    return tour(arr);
}