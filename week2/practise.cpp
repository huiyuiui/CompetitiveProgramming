#include <iostream>
#include <string>
using namespace std;
int grid[9][9];
void input()
{
    for (int r = 0; r < 9; ++r)
    {
        string buffer;
        cin >> buffer;
        for (int c = 0; c < 9; ++c)
        {
            grid[r][c] = buffer[c] - '0';
        }
    }
}
