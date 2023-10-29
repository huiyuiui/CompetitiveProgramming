#include<bits/stdc++.h>
#define int long long
#define MX 9223372036854775807
#define oo 1e18

using namespace std;

__int32_t main(){
    stack<pair<int, int>> stk;
    // first為idx，second為value
    int N;
    cin >> N;
    stk.push({0, 0});
    for (int i = 1; i <= N; i++)
    {
        int num;
        cin >> num;
        // 若是stack內的num比目前的num大，代表後面在找smaller的時候也不會找到stack內的
        // 所以就把這些比目前的num大的，不可能的答案都刪掉
        while(stk.size() && stk.top().second >= num)
            stk.pop();
        // 直到找到一個數字比目前的num小即為答案，隨後將目前的num推進去
        if(i == N) cout << stk.top().first << endl;
        else cout << stk.top().first << ' ';
        stk.push({i, num});
    }

    return 0;
}

