#include<bits/stdc++.h>
#define int long long
#define MX 9223372036854775807
#define oo 1e18

using namespace std;

int ans;
// 分別對應(-1, 0), (1, 0), (0, -1), (0, 1) => 上下左右
int dir_row[4] = {-1, 1, 0, 0};
int dir_col[4] = {0, 0, -1, 1};
char prev_dir[4] = {'D', 'U', 'R', 'L'}; // 記錄來的方向
char next_dir[4] = {'U', 'D', 'L', 'R'}; // 要去的方向
int visited[7][7] = {{0}};
string path;

void dfs(int row, int col, int step, char prev){
    if(row == 6 && col == 0){ 
        if(step == 48) ans++;
        return; // 經過終點若不為最後一步則不符合，所以也return
    }
    if(row < 0 || row >= 7 || col < 0 || col >= 7 || step >= 48) return; // 超出邊界情況
    if(visited[row][col]) return; // 已經走過
    // 重點！！！：以下判斷條件皆為將grid切成兩半的情況
    // ex: 1 1 1  1   1 1 1
    //     1 1 0  now 0 1 1
    //     . . . from
    // 則以上兩個零沒有辦法在這種情況下走到，所以把grid切成兩半的情況下直接return剪枝
    // 只有做了這個才可以通過TLE
    if((row - 1 < 0 || visited[row - 1][col]) && prev == 'D' && col - 1 >= 0 && col + 1 < 7 && !visited[row][col - 1] && !visited[row][col + 1]) return;
    else if((row + 1 >= 7 || visited[row + 1][col]) && prev == 'U' && col - 1 >= 0 && col + 1 < 7 && !visited[row][col - 1] && !visited[row][col + 1]) return;
    else if((col - 1 < 0 || visited[row][col - 1]) && prev == 'R' && row - 1 >= 0 && row + 1 < 7 && !visited[row - 1][col] && !visited[row + 1][col]) return;
    else if((col + 1 >= 7 || visited[row][col + 1]) && prev == 'L' && row - 1 >= 0 && row + 1 < 7 && !visited[row - 1][col] && !visited[row + 1][col]) return;

    visited[row][col] = 1;  // 此處改成進到這個點才設置visited，與前面進入前就設置不太一樣
    if(path[step] == 'U') dfs(row - 1, col, step + 1, 'D');
    else if(path[step] == 'D') dfs(row + 1, col, step + 1, 'U');
    else if(path[step] == 'L') dfs(row, col - 1 , step + 1, 'R');
    else if(path[step] == 'R') dfs(row, col + 1, step + 1, 'L');
    else{
        for (int i = 0; i < 4; i++)
        {  
            if(prev == next_dir[i]) continue;
            // 透過加法決定下一點在哪
            int next_row = row + dir_row[i];
            int next_col = col + dir_col[i];
            dfs(next_row, next_col, step + 1, prev_dir[i]);
        }
    }
    visited[row][col] = 0; // 離開這次遞迴時記得設置回來
}

__int32_t main(){
    ans = 0;
    cin >> path;
    dfs(0, 0, 0, 'U');
    cout << ans << endl;
}

