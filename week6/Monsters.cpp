#include<bits/stdc++.h>
#define int long long
#define MX 9223372036854775807
#define oo 1e18

using namespace std;

int N, M;
int maze[1005][1005];
int path[1005][1005];
int visited[1005][1005];
pair<int, int> start;
vector<pair<int, int>> monsters;

__int32_t main(){
    cin >> N >> M;
    char c;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> c;
            if(c == '.'){
                if(i == 0 || i == N - 1 || j == 0 || j == M - 1)
                    maze[i][j] = 4; // Boundary Goal
                else maze[i][j] = 0;
                visited[i][j] = 0;
            }
            else if(c == '#'){
                maze[i][j] = 1;
                visited[i][j] = 1;
            }
            else if(c == 'A'){
                maze[i][j] = 2;
                visited[i][j] = 2; // 2代表player
                start.first = i;
                start.second = j;
                // 細節！！！若player直接在bondary上直接輸出
                if(i == 0 || i == N - 1 || j == 0 || j == M - 1){
                    cout << "YES" << endl;
                    cout << 0 << endl;
                    return 0;
                }
            }
            else if(c == 'M'){
                maze[i][j] = 3;
                visited[i][j] = 3; // 3代表monster
                monsters.push_back({i, j});
            }
        }
    }

    int dRow[4] = {-1, 1, 0, 0};
    int dCol[4] = {0, 0, -1, 1};
    // first: postion, second: role
    queue<pair<pair<int, int>, int>> bfs_queue;
    // 重點！！！初始將monster和player同時放進queue，代表他們在同一時間一起往外延伸
    // 即為講義所教的類似淹水的概念。此時大家都是以最短路徑往外搜尋
    // 一定要先把monsters先放進queue內，這樣才可以保證monsters會先做搜尋
    // 而若是同level有某點monster和player都會走到，則monster會先佔領該格(visited)
    // 代表player若繼續走下去就會被抓到（所以無法繼續往該格作延伸）
    // player勝利的條件是中途都沒有碰到monster而且走到bondary
    // 若將monster視為動態增長的牆壁，那麼此題就變成動態的Grid maze
    for (int i = 0; i < (int)monsters.size(); i++)
        bfs_queue.push({{monsters[i].first, monsters[i].second}, 3});
    bfs_queue.push({start, 2});
    while (bfs_queue.size())
    {
        int nowRow = bfs_queue.front().first.first;
        int nowCol = bfs_queue.front().first.second;
        int nowRole = bfs_queue.front().second;
        bfs_queue.pop();
        
        // Bondary Goal and Role be the player
        if(maze[nowRow][nowCol] == 4 && nowRole == 2){
            cout << "YES" << endl;
                int count = 0;
                stack<char> action;
                while(1){
                    if(maze[nowRow][nowCol] == 2){
                        cout << count << endl;
                        while (action.size())
                        {
                            cout << action.top();
                            action.pop();
                        }
                        cout << endl;
                        return 0;
                    }
                    // action: U, D, L, R, back track: D, U, R, L
                    if(path[nowRow][nowCol] == 0){
                        action.push('U');
                        nowRow += 1;
                    }
                    else if(path[nowRow][nowCol] == 1){
                        action.push('D');
                        nowRow -= 1;
                    }
                    else if(path[nowRow][nowCol] == 2){
                        action.push('L');
                        nowCol += 1;
                    }
                    else if(path[nowRow][nowCol] == 3){
                        action.push('R');
                        nowCol -= 1;
                    }
                    count++;
                }
        }

        // Search
        for (int i = 0; i < 4; i++)
        {
            int nextRow = nowRow + dRow[i];
            int nextCol = nowCol + dCol[i];
            if(nextRow < 0 || nextRow >= N || nextCol < 0 || nextCol >= M || visited[nextRow][nextCol]) continue;
            bfs_queue.push({{nextRow, nextCol}, nowRole});
            visited[nextRow][nextCol] = nowRole;
            path[nextRow][nextCol] = i;
        }
    }

    cout << "NO" << endl;

    return 0;
}

