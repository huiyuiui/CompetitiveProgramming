#include<bits/stdc++.h>
#define int long long
#define MX 9223372036854775807
#define oo 1e18

using namespace std;

int N, K;
vector<pair<int, int>> arr;
int ans[100005];

bool compare(pair<int, int> a, pair<int, int> b){
    return a.first > b.first;
}

__int32_t main(){
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            int score;
            cin >> score;
            sum += score;
        }
        arr.push_back({sum, i}); // sum用於排序，i用於還原輸入並輸出
    }
    // sort(arr.begin(), arr.end(), compare); // sort後取得第K-1位即可，O(nlogn)
    nth_element(arr.begin(), arr.begin() + (K - 1), arr.end(), compare); // 使用nth_element將第K的值放在K-1的地方，O(n)
    int minTopK = arr[K - 1].first;
    for (auto it = arr.begin(); it != arr.end(); it++)
    {
        if((*it).first + 301 > minTopK) ans[(*it).second] = 1; // 假設第四天能拿滿分300+1並且前TopK的都拿0分就有機會
        else ans[(*it).second] = 0;
    }

    for (int i = 0; i < N; i++)
    {
        if(ans[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}

