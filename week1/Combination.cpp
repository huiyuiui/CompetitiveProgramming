#include "bits/stdc++.h"
#define INT long long
#define MX 100005
#define oo 1e18

using namespace std;

int N, C;
int arr[25];
int ans[25] = {0};
int visited[25];

void print(){
    for (int i = 0; i < C; i++)
    {
        if(i == C - 1) cout << ans[i] << endl;
        else cout << ans[i] << ' ';
    }
    
}


// idx用於記錄目前放入ans裡的index為何
void dfs(int n, int idx){
    if(n == C){ //只需取到C即可print
        print();
        return;
    }
    int prev = 0;
    // i=idx，因為要求要升序排列，所以不用從i=0開始掃，小於idx的都不會符合升序
    // 所以直接從上一個放入ans裡的index開始往後（後面的數字>=剛放進ans的數字）
    for (int i = idx; i < N; i++)
    {
        if(visited[i] || prev == arr[i]) continue;
        visited[i] = 1;
        ans[n] = arr[i];
        dfs(n + 1, i + 1);
        visited[i] = 0;
        ans[n] = 0;
        prev = arr[i];
    }
}

int main(){

    cin >> N >> C;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort(arr, arr + N); // sort確保字典序
    dfs(0, 0);
    return 0;
}

