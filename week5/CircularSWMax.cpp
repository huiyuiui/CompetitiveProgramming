#include<bits/stdc++.h>
#define int long long
#define MX 9223372036854775807
#define oo 1e18

using namespace std;

__int32_t main(){
    int N;
    int K;
    cin >> N >> K;

    // first: index, second: val
    vector<int> arr;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    // 本題重點：circular其實就是把會往回用到的數字(K-1個)放到arr最尾巴
    // 然後就做一次普通的Sliding Window Maximum
    for (int i = 0; i < K - 1; i++)
        arr.push_back(arr[i]);

    deque<int> dq; // 存index
    vector<int> ans;
    int arr_size = arr.size();
    for (int i = 0; i < arr_size; i++)
    {
        // 1. 把不在Sliding Window範圍內的刪掉
        while(dq.size() && dq.front() <= (i - K))
            dq.pop_front();
        // 2. 把比目前小的，也就是不可能成為SW內最大的刪掉(包含等於的)
        while(dq.size() && arr[dq.back()] <= arr[i])
            dq.pop_back();
        // 3. 將目前的放入
        dq.push_back(i);
        // 4. 根據1,2，在最前面的一定是符合SW範圍且為最大的(因為後面的數字刪不掉他)
        if(i >= K - 1)
            ans.push_back(arr[dq.front()]);
    }
    
    int ans_size = ans.size();
    for (int i = 0; i < ans_size; i++)
    {
        if(i == ans_size - 1) cout << ans[i] << endl;
        else cout << ans[i] << ' ';
    }

    return 0;
}

