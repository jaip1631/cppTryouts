#include <iostream>
using namespace std;

#define R 3
#define C 14

int dir_x[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dir_y[] = { 0,  1, 1, 1, 0,-1,-1, -1};

bool patterFound(char grid[R][C], const string & pat, int cur_y, int cur_x, int inc_x, int inc_y)
{
    unsigned counter = 0;
    while(cur_x >= 0 && cur_x <C && cur_y >=0 && cur_y < R && counter < pat.size())
    {
        if(grid[cur_y][cur_x] != pat[counter])
            return false;
        cur_x += inc_x;
        cur_y += inc_y;
        counter++;
    }

    if(counter == pat.size())
        return true;
        
    return false;
}

void patternSearch(char grid[R][C], const string &pat)
{
    for(int i = 0 ; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            for(int dir = 0; dir < 8; dir++)
            {
                if(patterFound(grid, pat, i, j, dir_x[dir], dir_y[dir]))
                    cout<<"Pattern "<< pat <<" found at "<< i <<", "<<j<<endl; 
            }
        }
    }
}

// Driver program
int main()
{
    char grid[R][C] = {"GEEKSFORGEEKS",
                       "GEEKSQUIZGEEK",
                       "IDEQAPRACTICE"
                      };
 
    patternSearch(grid, "GEEKS");
    cout << endl; 
    patternSearch(grid, "EEE");
    return 0;
}