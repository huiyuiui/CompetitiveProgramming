#include<bits/stdc++.h>
#define int long long
#define MX 9223372036854775807
#define oo 1e18

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}

__int32_t main(){
    int N, X;
    cin >> N >> X;
    vector<pair<int, int>> arr;
    int min = oo;
    int sum = 0;
    for (int i = 1; i <= N; i++)
    {
        int value;
        cin >> value;
        sum += value;
        if(value < min) min = value;
        arr.push_back({value, i});
    }
    if(min >= X || sum < X){ // 若最小的數字大於等於所求則找不到更小的sum在一起，而若全部sum起來小於所求也不可能找到
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    sort(arr.begin(), arr.end(), compare); // 對值去做sort，要符合二分搜的遞增或遞減特性
    for (int i = 0; i < N; i++)
    {
        int L = 0;
        int R = N - 1;
        int twoSumTarget = X - arr[i].first; // 從1到n，先固定一個值，隨後另外兩個值用二分搜
        int ans[3];
        ans[0] = arr[i].second;
        while(L != R){
            int twoSum = arr[L].first + arr[R].first; 
            if(L != i && R != i && twoSum == twoSumTarget){
                ans[1] = arr[L].second;
                ans[2] = arr[R].second;
                sort(ans, ans + 3); // 讓答案呈現遞增輸出
                for (int i = 0; i < 3; i++)
                {
                    if(i == 2) cout << ans[i] << endl;
                    else cout << ans[i] << " ";
                }
                return 0;
            }
            if(twoSum < twoSumTarget) L++;
            else R--; // 重點！！！因為有可能twoSum = twoSumTarget但是L, R, i有重疊
                      // 需要R--才可以繼續迴圈搜尋，否則會卡住
            // 為什麼twoSum < twoSumTarget不是R++，而且大於時不是L--
            // 也就是說為什麼組合是小於L++大於R--，而非小於R++大於L--
            // 邊界情況:若L和R剛好位於0和N-1，若大於或小於都會超出邊界
            // General case：若存在一組答案是大於L--後才找得到，那在小於時，使用L++往中間靠攏的過程中就會找到
            // 或是有一組答案是小於R++後才找得到，那在大於時，使用R--往中間靠攏的過程中也會找到
            // 所以使用小於L++大於R--是可以符合正確答案的
        }
    }
    cout << "IMPOSSIBLE" << endl;

    return 0;
}

