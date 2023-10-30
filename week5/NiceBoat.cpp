#include <bits/stdc++.h>
#define int long long
#define MX 9223372036854775807
#define oo 1e18

using namespace std;

int arr[1000005], prefix[1000005];

__int32_t main()
{

    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        for (int i = 1; i <= N; i++)
            cin >> arr[i];
        
        // 記住到目前每一個點的prefixsum為何。取兩個prefixsum就可以比較區間
        prefix[0] = 0; // 設定初始條件
        for (int i = 1; i <= N; i++)
            prefix[i] = arr[i] + prefix[i - 1];
        
        deque<int> next_smaller_stk;
        // 每個位置下一個比該位置prefixsum來的小的地方
        // 這代表從到next_smaller[i]時，區間prefixsum開始轉為小於0
        // 所以只需計算i到next_smaller[i]這個區間
        vector<int> next_smaller(N + 1); // 因為prefixsum會有N+1個位子。
        for (int i = 0; i < N + 1; i++)
        {
            next_smaller[i] = N + 1; // 一開始初始化全部位置下一個最小的都是最後一個位置
            // 檢查stack內待更新next_smaller的位置，是否目前的(i)的prefix比較小
            while (!next_smaller_stk.empty() && prefix[i] < prefix[next_smaller_stk.back()])
            {
                // 若目前的prefix比較小，那麼就更新該(stack.top)位置的next smaller
                next_smaller[next_smaller_stk.back()] = i;
                // pop為了繼續往下更新前面未更新next smaller的位置
                next_smaller_stk.pop_back();
            }
            // 把目前的放進stack內待更新
            next_smaller_stk.emplace_back(i);
        }
        // 重點！！！透過next smaller去找到區間大小對應關係
        int ans = 0, l = -1, r = 0;
        for (int i = 1; i <= N; i++)
        { // check interval [l,r]
            // l為prefix的起頭，一定要大於等於0
            if (l == -1 && arr[i] >= 0)
                l = i;
            // 若找到起頭，則開始找尾巴
            if (l != -1)
            {
                // 能找到最尾巴的地方會為起頭的下一個prefix較小的地方
                // 因為next smaller是prefix開始轉為負的地方
                int maxr = next_smaller[l];
                // 遍歷i找到各個尾巴的位置，同樣保證尾巴要大於等於0
                // 重點！！！第二個條件，prefix[r] < prefix[i] (r <= i)
                // 若前面的prefix小於等於後面的prefix，代表不論對於prefix還是postfix來說
                // 將這個區間的所有數字加起來，都一定會大於等於0，即為save subarray
                if (i < maxr && arr[i] >= 0 && (prefix[r] <= prefix[i] || r == 0))
                {
                    r = i;
                    ans = max(ans, r - l + 1); // 小細節，本題除arr的size都為N+1，要注意
                }
            }
            else
            {
                if (arr[i] >= 0)
                    l = i; 
                else
                    l = -1;
                r = 0;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
// prefix[r] <- prefix[i] (r < i) 反例：若左prefix大於右prefix
// 代表從r到i這段區間的總和會是負的，那麼postfixsum就會小於0


