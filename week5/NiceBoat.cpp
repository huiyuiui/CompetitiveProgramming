#include <bits/stdc++.h>
using namespace std;
#define P pair<long long, long long>
const long long MX = 1000005;
long long t, n, a, ans;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        stack<pair<P, long long>> q;
        ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> a;
            pair<P, long long> pa = pair<P, long long>(P(a, a), (long long)1);
            while (q.size() && (pa.first.first < 0 || q.top().first.second + pa.first.first >= 0)) {
                pair<P, long long> pb = q.top();
                q.pop();
                pa.second += pb.second;
                pa.first.second = min(pa.first.second, pb.first.second + pa.first.first);
                pa.first.first += pb.first.first;
            }
            if (pa.first.first >= 0) {
                q.push(pa);
                if (pa.first.second >= 0) ans = max(ans, pa.second);
            }
        }
        cout << ans << endl;
    }
}