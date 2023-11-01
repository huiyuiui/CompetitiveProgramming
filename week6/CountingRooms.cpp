#include<bits/stdc++.h>
#define int long long
#define MX 9223372036854775807
#define oo 1e18

using namespace std;

int maze[1005][1005];

__int32_t main(){
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char c;
            cin >> c;
            if(c == '#') maze[i][j] = 1;
            else if(c == '.') maze[i][j] = 0;
        }
    }
    queue<pair<int, int>> bfs_queue;
    int count = 0;
    int dRow[4] = {-1, 1, 0, 0};
    int dCol[4] = {0, 0, -1, 1};
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if(maze[i][j] == 0){
                // 找到一個floor代表找到一個房間
                count++;
                bfs_queue.push({i, j});
                // 以該floor往四周延伸，將同為該房間的floor都改成visited，代表該房間的floor都被搜索過了
                // 這樣才可以保證外面的兩層for loop不會找到重複的房間(floor)
                while (bfs_queue.size())
                {
                    int nowRow = bfs_queue.front().first;
                    int nowCol = bfs_queue.front().second;
                    bfs_queue.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int nextRow = nowRow + dRow[k];
                        int nextCol = nowCol + dCol[k];
                        if(nextRow < 0 || nextRow >= N || nextCol < 0 || nextCol >= M || maze[nextRow][nextCol]) continue;
                        maze[nextRow][nextCol] = 1;
                        bfs_queue.push({nextRow, nextCol});
                    }   
                }       
            }
        }
    }
    cout << count << endl;

    return 0;
}

