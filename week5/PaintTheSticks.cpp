#include<bits/stdc++.h>
#define int long long
#define MX 9223372036854775807
#define oo 1e18

using namespace std;

__int32_t main(){
    int N; 

    while (cin >> N)
    {
        int MaxLen = 0;
        stack<pair<int, int>> sticks; 
        // first為idx，second為value 
        vector<int> arr;  
        for (int i = 0; i < N; i++)
        {
            int length;
            cin >> length;
            arr.push_back(length);
        }
        arr.push_back(0); // 重點！！！最後要有一個0才可以把stack裡全部清空
        for (int i = 0; i < N + 1; i++) // 此處因為多一個0在最尾巴，所以要執行N+1次
        {
            int corner = i;
            // 切掉：因為若是可以往前切掉，意思即為前面最大的長方形一定不會往後延伸
            // 那麼就計算前面最大的長方形然後順便把比此時大的都pop掉
            // 所以維護好的形狀是為一個階梯形
            while(sticks.size() && sticks.top().second >= arr[i]){
                corner = sticks.top().first;
                MaxLen = max(MaxLen, sticks.top().second * (i - corner));
                sticks.pop();
            }
            sticks.push({corner, arr[i]}); 
        }
        cout << MaxLen << endl;
    }
    
    return 0;
}

