#include<bits/stdc++.h>
#define int long long
#define MX 9223372036854775807
#define oo 1e18

using namespace std;

int N;
// deadline first compare, not in this problem
vector<pair<int, int>> tasks;
bool compare(pair<int, int> a, pair<int, int> b){
    if(a.second < b.second) return true;
    else if((a.second == b.second) && (a.first < b.first)) return true;
    else return false;
}

// 因為每個任務都要執行，所以不必考慮deadline前能否做完
// 而是要考慮reward最大化(max d-f)，那麼排序的依據就是
// d要大，f要小，所以duration小的要先被執行
// 而dealine較大的要放在後面，若是兩者皆較小代表時間緊迫且優先度高就會放在前面
__int32_t main(){
    cin >> N;
    int duration, deadline;
    for (int i = 0; i < N; i++)
    {
        cin >> duration >> deadline;
        tasks.push_back({duration, deadline});
    }
    int ans = 0;  
    int nowTime = 0;
    sort(tasks.begin(), tasks.end()); // 默認升序排列
    for (int i = 0; i < N; i++)
    {
        nowTime += tasks[i].first;
        ans += tasks[i].second - nowTime;
    }
    cout << ans << endl;
    
    return 0;
}

