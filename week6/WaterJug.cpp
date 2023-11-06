#include<bits/stdc++.h>
#define int long long
#define MX 9223372036854775807
#define oo 1e18

using namespace std;

int N, Q;
int limit[5];
queue<pair<vector<int>, int>> bfs_queue;
queue<string> str_queue;
unordered_set<string> visited;

bool isGoal(vector<int> state){
    for (int i = 0; i < N; i++)
        if(state[i] == Q) return true;
    return false;
}

__int32_t main(){
    vector<int> startState;
    string startString = "";
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> limit[i];
        startState.push_back(0);
        startString += "0";
    }        
    cin >> Q;

    bfs_queue.push({startState, 0});
    str_queue.push(startString);
    visited.insert(startString);
    while (bfs_queue.size())
    {
        vector<int> nowState = bfs_queue.front().first;
        int nowCost = bfs_queue.front().second;
        string nowString = str_queue.front();
        bfs_queue.pop();
        str_queue.pop();
        if(isGoal(nowState)){
            cout << nowCost << endl;
            return 0;
        }

        vector<int> nextState = nowState;
        string nextString = nowString;
        for (int i = 0; i < N; i++)
        {
            // fill ith jug to full
            nextState[i] = limit[i];
            // 重點！！！將數字轉為ASCII，透過unorder_set去做判斷visited
            // 不能單純將數字轉為字串，ex:45 -> "45"，則字串長度會不為N
            // 使用ASCII(+"0")可以讓數值範圍1~50 -> 48->98，每一位都是一個ASCII字元（固定字串長度）
            nextString[i] = nextState[i] + '0';
            if(visited.count(nextString) == 0){
                bfs_queue.push({nextState, nowCost + 1});
                str_queue.push(nextString);
                visited.insert(nextString);
            }
            nextState[i] = nowState[i];
            nextString[i] = nowString[i];

            // empty ith jug
            nextState[i] = 0;
            nextString[i] = nextState[i] + '0';
            if(visited.count(nextString) == 0){
                bfs_queue.push({nextState, nowCost + 1});
                str_queue.push(nextString);
                visited.insert(nextString);
            }
            nextState[i] = nowState[i];
            nextString[i] = nowString[i];

            // transfer water from ith jug to jth jug
            for (int j = 0; j < N; j++)
            {
                if(i == j) continue;
                nextState[j] = min(limit[j], nowState[i] + nowState[j]);
                nextState[i] = nowState[i] + nowState[j] - nextState[j];
                nextString[i] = nextState[i] + '0';
                nextString[j] = nextState[j] + '0';
                if(visited.count(nextString) == 0){
                    bfs_queue.push({nextState, nowCost + 1});
                    str_queue.push(nextString);
                    visited.insert(nextString);
                }
                nextState[i] = nowState[i];
                nextState[j] = nowState[j];
                nextString[i] = nowString[i];
                nextString[j] = nowString[j];
            }
        }
    }
    cout << -1 << endl;

    return 0;
}
