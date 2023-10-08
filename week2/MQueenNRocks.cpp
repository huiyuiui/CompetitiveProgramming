#include<bits/stdc++.h>
#define int long long
#define MX 9223372036854775807
#define oo 1e18

using namespace std;

int T;
int M, N;
int MASK;
int ans;

int lowbit(int num){
    return num & (~num + 1);
}

// 默認從每個row的cols選取可以放的點，每一次遞迴即為一個row，往下搜尋
// left_queen和right_queen是左右對角線上有queen，所以對於queen和rock都不能放
// left_rock和right_rock是左右對角線上有rock，對於queen不能放，但rock可以放
// middle為col，皆不能放
void dfs(int left_queen, int left_rock, int middle, int right_queen, int right_rock, int m, int n){
    if(m == 0 && n == 0){
        ans++;
        return;
    }
    // MASK做and可以保證取到有1的bit數皆位於M+N裡面
    // 對於queen來說，所有不能放的位置都要判斷，否則可能攻擊到左右斜上方的rock
    int S_queen = MASK & ~(left_queen | left_rock | middle | right_queen | right_rock);
    for (int num = 0; S_queen; S_queen ^= num)
    {
        if(!m) break;
        num = lowbit(S_queen);
        // 因為目前放的是queen，下一層遞迴left_rock和right_rock只需shift不需做or
        dfs((left_queen | num) << 1, left_rock << 1, middle | num, (right_queen | num) >> 1, right_rock >> 1, m - 1, n);
    }
    // 對於rock來說，只要左右對角線上沒有queen就可以放
    int S_rock = MASK & ~(left_queen | middle | right_queen);
    for (int num = 0; S_rock; S_rock ^= num)
    {
        if(!n) break;
        num = lowbit(S_rock);
        // 因為目前放的是rock，下一層遞迴left_queen和right_queen只需shift不需做or
        dfs(left_queen << 1, (left_rock | num) << 1, middle | num, right_queen >> 1, (right_rock | num) >> 1, m, n - 1);
    }
    
}

__int32_t main(){
    cin >> T;
    while (T--)
    {
        cin >> M >> N;
        if(M + N == 0){
            cout << 0 << endl;
            continue;
        }
        MASK = (1 << (M + N)) - 1; // MASK在大於M+N的bit都會是0，保證不會越界
        ans = 0;
        dfs(0, 0, 0, 0, 0, M, N);
        cout << ans << endl;
    }

    return 0;
}

