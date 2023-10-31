#include<bits/stdc++.h>
#define int long long
#define MX 9223372036854775807
#define oo 1e18

using namespace std;

int maze[1005][1005];

__int32_t main(){
    int N, M;
    cin >> N >> M;
    // maze init
    pair<int, int> start;
    pair<int, int> end;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char c;
            cin >> c;
            if(c == '#') maze[i][j] = 1;
            else if(c == '.') maze[i][j] = 0;
            else if(c == 'A'){
                start.first = i;
                start.second = j;
                maze[i][j] = 2;
            }
            else if(c == 'B'){
                end.first = i;
                end.second = j;
                maze[i][j] = 3;
            }
        }
    }
    // Reconstruct maze
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < M; j++)
    //     {
    //         if(maze[i][j] == 1) cout << '#';
    //         else if(maze[i][j] == 2) cout << 'A';
    //         else if(maze[i][j] == 3) cout << 'B';
    //         else cout << '.';
    //     }
    //     cout << endl;
    // }

    // U, D, L, R
    int dRow[4] = {-1, 1, 0, 0};
    int dCol[4] = {0, 0, -1, 1};
    char action[4] = {'U', 'D', 'L', 'R'};
    vector<char> ans;
    vector<char> empty;
    // first:position, second:action list
    queue<pair<pair<int, int>, vector<char>>> bfs_queue;
    bfs_queue.push({start, empty});
    while (bfs_queue.size())
    {
        pair<pair<int, int>, vector<char>> nowState = bfs_queue.front();
        bfs_queue.pop();
        int nowRow = nowState.first.first;
        int nowCol = nowState.first.second;
        vector<char> nowActionList = nowState.second;
        if(nowRow == end.first && nowCol == end.second){
            cout << "YES" << endl;
            int size = nowActionList.size();
            cout << size << endl;
            for (int i = 0; i < size; i++)
                cout << nowActionList[i];
            cout << endl;
            return 0;
        }
        for (int i = 0; i < 4; i++)
        {
            int nextRow = nowRow + dRow[i];
            int nextCol = nowCol + dCol[i];
            if(nextRow < 0 || nextRow >= N || nextCol < 0 || nextCol >= M || maze[nextRow][nextCol] == 1) continue;
            vector<char> nextActionList = nowActionList;
            nextActionList.push_back(action[i]);
            maze[nextRow][nextCol] = 1;
            bfs_queue.push({{nextRow, nextCol}, nextActionList});
        }
    }
    
    cout << "NO" << endl;
    

    return 0;
}

