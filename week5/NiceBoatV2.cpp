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
        int N;
        cin >> N;
        int val;
        int minPostfixSum = oo;
        int maxLength = 0;
        stack<int> prefixStack;
        int prefixSum = 0;
        for (int i = 0; i < N; i++)
        {
            cin >> val;
            if(val < 0 && prefixStack.empty()) continue; // 仍未找到可以做起頭的點
            if(val >= 0 && prefixStack.empty()){ // 找到可以起頭的點(同時也為結尾)
                prefixSum += val;
                minPostfixSum = val;
                maxLength = max(maxLength, (int)1);
                prefixStack.push(val);
                continue;
            }
            if(prefixSum + val < 0){ // prefixSum轉為負的時候代表已經不符合了，結束此次搜尋
                while (prefixStack.size()) // 清空stack並初始化全部資訊
                    prefixStack.pop();
                prefixSum = 0; 
                minPostfixSum = oo;
                continue;
            }
            else{ // prefixSum仍為>=0, 所以可以繼續往後搜尋
                prefixSum += val;
                prefixStack.push(val);
                // 重點！！！minPostFixSum永遠只看最小的，若這個都>=0,代表前面的值加起來也會>=0
                // 不符合的情況: minPostfixSum加上正的val仍為負的，代表val沒法成為尾巴(壓不過前面)
                // 也有可能minPostfixSum本為正的，但val為負的，一樣無法成為尾巴
                // 一直取min下去就會使得save array可以最小的滿足postfixSum
                minPostfixSum = min(minPostfixSum + val, val);
                cout << minPostfixSum << ' ';
                if(minPostfixSum >= 0)
                    maxLength = max(maxLength, (int)prefixStack.size());
            }
        }
        cout << endl;
        cout << maxLength << endl;
    }
    


    return 0;
}

