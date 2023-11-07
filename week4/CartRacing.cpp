#include <bits/stdc++.h>
#define int long long
#define MX 9223372036854775807
#define oo 1e18

using namespace std;

int A, B, C, D, M, S, T;

__int32_t main()
{
    cin >> A >> B >> C >> D >> M >> S >> T;
    int l = 1, r = T + 1, ans = 0, sec = 2e9, found = 0;
    while (l < r)
    {
        // do binary search with time
        // since it request the minimum time if it can reach final
        // instead using for loop search time from 1 to T
        // the binary search time complexity can reduce to O(lgT)
        // So, this problem is not about how to solve it, is about the time
        int t = (l + r) / 2;
        int remdis = 0, remt = t, remfuel = M, search = 1;
        remdis += B * min(M / C, t);
        remt -= min(t, M / C), remfuel -= C * (M / C);
        // search refill times to find a best operation
        for (int i = 0; i <= remt; i++) 
        {
            // do i times refill
            int tmp_dis = remdis, tmp_t = remt - i, tmp_fuel = remfuel + D * i;
            tmp_dis += B * min(tmp_fuel / C, tmp_t);
            tmp_t -= min(tmp_t, tmp_fuel / C);
            tmp_dis += tmp_t * A;
            if (tmp_dis >= S)
            {
                search = 0;
                found = 1;
                if (t < sec) sec = t;
            }
            else
            {
                if (ans < tmp_dis) ans = tmp_dis;
            }
        }
        if (search)
            l = t + 1;
        else
            r = t;
    }
    if (found)
        cout << "Yes\n" << sec << '\n';
    else
        cout << "No\n" << ans << '\n';
}