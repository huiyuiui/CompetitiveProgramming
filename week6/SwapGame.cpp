#include<bits/stdc++.h>
#define int long long
#define MX 9223372036854775807
#define oo 1e18

using namespace std;

__int32_t main(){
    string startState = "";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            char c;
            cin >> c;
            startState += c;
        }
    }
    
    queue<pair<string, int>> bfs_queue;
    unordered_set<string> visited; // 重點！！！一定要用unordered_set，判斷visited才可以過TLE
    bfs_queue.push({startState, 0});
    visited.insert(startState);
    while (bfs_queue.size())
    {
        string nowState = bfs_queue.front().first;
        int nowCost = bfs_queue.front().second;
        bfs_queue.pop();
        if(nowState == "123456789"){
            cout << nowCost << endl;
            return 0;
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int nowIdx = i * 3 + j;
                int nextIdx;
                string nextState = nowState;
                // 重點！！！因為向下交換和下一排向上交換呈現的state是一樣的
                // 所以所有的點都只做向下和向右交換（要做邊界判定）
                if(i < 2){ // down swap
                    nextIdx = nowIdx + 3;
                    nextState[nowIdx] = nowState[nextIdx];
                    nextState[nextIdx] = nowState[nowIdx];
                    if(!visited.count(nextState)){
                        bfs_queue.push({nextState, nowCost + 1});
                        visited.insert(nextState);
                    }
                }
                nextState = nowState; // reset state
                if(j < 2){ // right swap
                    nextIdx = nowIdx + 1;
                    nextState[nowIdx] = nowState[nextIdx];
                    nextState[nextIdx] = nowState[nowIdx];
                    if(!visited.count(nextState)){
                        bfs_queue.push({nextState, nowCost + 1});
                        visited.insert(nextState);
                    }
                }
            }
        }
    }

    return 0;
}

