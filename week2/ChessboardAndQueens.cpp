#include<bits/stdc++.h>
#define int long long
#define MX 9223372036854775807
#define oo 1e18

using namespace std;

const int N = 8;
int ans;
int row[N] = {0};
int col[N] = {0};
int LD_RU[2 * N - 1] = {0}; // 右上左下
int LU_RD[2 * N - 1] = {0}; // 左上右下
int chessboard[N][N];

// diagonal是重點，建議可以先畫可以矩陣並標上每條對角線的序號，再用序號去推導
int illegal(int x, int y){
    return row[x] || col[y] || LD_RU[x + y] || LU_RD[N - 1 + (x - y)];
}

// 更新目前可以or不可放的位置，val可為0or1
void update(int x, int y, int val){
    row[x] = val;
    col[y] = val;
    LD_RU[x + y] = val;
    LU_RD[N - 1 + (x - y)] = val;
}

void dfs(int x){ // 參數僅需x即可，因為row一旦放過則不會有重複的x，而y會在迴圈內窮舉
    if(x == N){
        ans++;
        return;
    }
    for (int y = 0; y < N; y++)
    {
        if(illegal(x, y) || chessboard[x][y]) continue; // 目前無法放的位置
        update(x, y, 1);
        dfs(x + 1);
        update(x, y, 0);
    }
}

__int32_t main(){
    ans = 0;
    string str;
    for (int i = 0; i < N; i++)
    {
        cin >> str;
        for (int j = 0; j < N; j++)
        {
            if(str[j] == '.') chessboard[i][j] = 0;
            else if(str[j] == '*') chessboard[i][j] = 1;
        }
    }
    dfs(0);
    cout << ans;
}

