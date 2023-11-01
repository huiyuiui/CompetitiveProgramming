#include<bits/stdc++.h>
#define int long long
#define MX 9223372036854775807
#define oo 1e18

using namespace std;

int maze[1005][1005];
// path的每個點記的都是到達該點時所執行的動作，例如0就代表到該點的時候執行了U，所以是從D來的
int path[1005][1005];

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
            }
            else if(c == 'B'){
                end.first = i;
                end.second = j;
            }
        }
    }

    // U, D, L, R
    int dRow[4] = {-1, 1, 0, 0};
    int dCol[4] = {0, 0, -1, 1};
    queue<pair<int, int>> bfs_queue;
    // vector<string> actionList; // 原本的做法，但每次都開一個nowActionList會導致RE
    bfs_queue.push(start);
    while (bfs_queue.size())
    {
        pair<int, int> nowPos = bfs_queue.front();
        bfs_queue.pop();
        int nowRow = nowPos.first;
        int nowCol = nowPos.second;
        // Goal state
        if(nowRow == end.first && nowCol == end.second){
            cout << "YES" << endl;
            stack<char> action;
            while(1){
                // 回到起點時就可以將action stack的全部動作print出來了
                if(nowRow == start.first && nowCol == start.second){
                    cout << action.size() << endl;
                    while(action.size()){
                        cout << action.top();
                        action.pop();
                    }
                    cout << endl;
                    return 0;
                }
                // 回溯：根據path記載執行的動作反向往回到起點，並將動作放入stack(FILO)
                // action: U, D, L, R => back path: D, U, R, L
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
            }
        }
        for (int i = 0; i < 4; i++)
        {
            int nextRow = nowRow + dRow[i];
            int nextCol = nowCol + dCol[i];
            if(nextRow < 0 || nextRow >= N || nextCol < 0 || nextCol >= M || maze[nextRow][nextCol]) continue;
            maze[nextRow][nextCol] = 1;
            path[nextRow][nextCol] = i; // 紀錄到達下一點時要執行的動作
            bfs_queue.push({nextRow, nextCol});
        }
    }
    
    cout << "NO" << endl;
    

    return 0;
}

