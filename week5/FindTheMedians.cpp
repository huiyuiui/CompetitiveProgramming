#include<bits/stdc++.h>
#define int long long
#define MX 9223372036854775807
#define oo 1e18

using namespace std;

__int32_t main(){
    priority_queue<int> lower; // 比median小的，為Max heap
    priority_queue<int, vector<int>, greater<int>> higher; // 比median大的，為min heap
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int num;
        cin >> num;
        // 此題median因為取floor，所以默認為lower的top
        // 重要！！！lower和higher的size相差最多只能1，若相差2則需要將多的放到另一邊
        // 一開始兩個一定都先放到higher，再將median放到lower
        if(lower.empty() || lower.top() < num){ // 初始狀況或比median大
            higher.push(num);
            if(higher.size() >= lower.size() + 2){
                lower.push(higher.top());
                higher.pop();
            }
        }
        else{ // 比median小於等於的
            lower.push(num);
            if(lower.size() >= higher.size() + 2){
                higher.push(lower.top());
                lower.pop();
            }
        }
        // higher size較大則median在higher，若兩者相同或lower size較大則在lower
        if(lower.size() < higher.size()) cout << higher.top() << ' ';
        else cout << lower.top() << ' ';
    }
    cout << endl;

    return 0;
}

