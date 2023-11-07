#include <bits/stdc++.h>
#define int long long
#define MX 9223372036854775807
#define oo 1e18

using namespace std;

int32_t main()
{
    int T, N, K;
    cin >> T;
    while (T--)
    {
        cin >> N >> K;
        int init, rate;
        vector<pair<int, int>> my_horses;
        vector<int> op_horses;
        for (int i = 0; i < N; i++)
        {
            cin >> init >> rate;
            my_horses.push_back({init, rate});
        }
        for (int i = 0; i < N; i++)
        {
            cin >> init;
            op_horses.push_back(init);
        }
        // opponent sored from smaller to greater
        sort(op_horses.begin(), op_horses.end());
        int l = 0, r = 100000005, mid, ans = -1;
        while (l < r)
        {
            vector<int> trained;
            mid = l + (r - l) / 2;
            for (int i = 0; i < N; i++)
                trained.emplace_back(my_horses[i].first + my_horses[i].second * mid);
            // after trained, sorted from smaller to greater too
            sort(trained.begin(), trained.end());
            int canWin = 1;
            // Important!!! Since we only need to win K rounds
            // So we can use the fatest K horses to win slowest K horses
            // If can not, train the hourses for longer time
            for (int i = K - 1; i >= 0; i--)
            {
                // trained: fatest K hourses from greater to smaller
                // op_horses: slowest K hourses from greater to smaller
                if (trained[N - 1 - (K - 1 - i)] <= op_horses[i])
                {
                    canWin = 0;
                    break;
                }
            }
            if (canWin)
                r = mid, ans = mid;
            else
                l = mid + 1;
        }
        cout << ans << endl;
    }

    return 0;
}
