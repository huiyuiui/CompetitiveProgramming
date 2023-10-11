#include<bits/stdc++.h>
#define int long long
#define MX 9223372036854775807
#define oo 1e18

using namespace std;

__int32_t main(){
    int T;
    cin >> T;
    while (T--)
    {
        int N, Q;
        cin >> N >> Q;
        vector<pair<char, int>> input;
        deque<pair<char, int>> query;
        int visited[200005] = {0};
        for (int i = 0; i < Q; i++)
        {
            char q;
            int val;
            cin >> q >> val;
            input.push_back({q, val});
        }
        // 從尾巴掃回頭，只記錄最新(較後面)的更新，保證每個val只會被更新一次
        for (auto it = input.rbegin(); it != input.rend(); it++)
        {
            if(visited[(*it).second]) continue;
            query.push_front({(*it).first, (*it).second}); // 用push front保持順序
            visited[(*it).second] = 1;
        }
        deque<int> head;
        deque<int> tail;
        // 根據刪減過後的query再進行移動
        for (auto it = query.begin(); it != query.end(); it++)
        {
           if((*it).first == 'H') head.push_front((*it).second); // head push front
           else if((*it).first == 'T') tail.push_back((*it).second); // tail push back
        } 
        
        // print 移動到head的
        for (auto it = head.begin(); it != head.end(); it++) cout << *it << ' ';
        // print 原本的
        for (int i = 1; i <= N; i++)
        {
            if(!visited[i]) cout << i << ' '; // !visited代表沒有被移動過，按照原本順序print
        }
        // print 移動到tail的
        for (auto it = tail.begin(); it != tail.end(); it++)
        {
            if(it == tail.end() - 1) cout << *it << endl;
            else cout << *it << ' ';
        }
    }
    

    return 0;
}

