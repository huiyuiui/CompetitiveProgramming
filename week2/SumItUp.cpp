#include <bits/stdc++.h>
#define int long long
#define MX 9223372036854775807
#define oo 1e18

using namespace std;

int T, N;
int flag;
int arr[15];
int ans[15];

void print(int n){
    for (int i = 0; i < n; i++)
    {
        if(i == n - 1)
            cout << ans[i] << endl;
        else 
            cout << ans[i] << "+";
    }
    
}

// n是ans第幾格，idx是arr第幾格，sum為目前總和
void dfs(int n, int idx, int sum){
    if(sum == T){
        print(n);
        flag = 1;
        return; // 已經找到答案就可以return，因為再往後掃一定不符合
    } // sum > T同樣不符合可以直接return
    else if(sum > T || n == N || idx == N) return;
    int prev = -1; 
    for (int i = idx; i < N; i++) // 從idx開始，因為先前的一定都已經填過或是不符合
    {
        if(arr[i] == prev) continue; // 避免重複答案
        ans[n] = arr[i]; // ans的第n格要填的答案
        dfs(n + 1, i + 1, sum + arr[i]);
        prev = arr[i];
    }
}

__int32_t main()
{
    while (1)
    {
        cin >> T >> N;
        if(N == 0) return 0;
        for (int i = 0; i < N; i++)
            cin >> arr[i]; 
        cout << "Sums of " << T << ":" << endl;
        flag = 0;
        dfs(0, 0, 0);
        if(flag == 0)
            cout << "NONE" << endl;
    }
}
