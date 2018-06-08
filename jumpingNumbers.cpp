#include<iostream>
#include<queue>

using namespace std;

void printJumpingUtil(int n, int max)
{
    queue<int> q;
    q.push(n);

    while(!q.empty())
    {
        int num = q.front();
        q.pop();
        if(num < max)
        {
            cout<<num<<" ";

            int lastDigit = num%10;
            if(lastDigit == 0)
                q.push(num*10+lastDigit+1);
            else if(lastDigit == 9)
                q.push(num*10+lastDigit-1);
            else
            {
                q.push(num*10+lastDigit+1);
                q.push(num*10+lastDigit-1);
            }
        }
    }
}

void printJumping(int n)
{
    for(int i= 1; i < 10 && i < n; i++)
        printJumpingUtil(i, n);
}

int main(int argc, char const *argv[])
{
    int n = 999;
    printJumping(n);
    return 0;
}
