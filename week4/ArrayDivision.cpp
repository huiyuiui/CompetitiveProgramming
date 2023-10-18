#include<bits/stdc++.h>
#define int long long
#define MX 9223372036854775807
#define oo 1e18

using namespace std;

int N, K;
int arr[200005];

//類似搭電梯的做法
int greedy(int limit){
    int currentSum = 0;
    int times = 0;
    for (int i = 0; i < N; i++)
    {
        if(arr[i] > limit) times = K + 1; // 若是limit無法將某個數字塞下則一定不符合
        if(times > K) break; // 超過K次就不需要繼續分組下去
        if(currentSum + arr[i] > limit){
            times++;
            currentSum = arr[i];
        }
        else currentSum += arr[i];
    }
    if(currentSum) times++; // 記得要加
    return times;
}

int binarySearch(int L, int R){
    int ans = R; // 細節：若是K=1的時候，會找不到答案，所以一開始讓ans=R即為全部的sum，避免邊界情況
    while (L + 1 < R)
    {
        int mid = L + (R - L) / 2;
        int times = greedy(mid); // 計算限制為mid時需要幾次才能分好
        // 重點！！！若times<K代表mid太大所以將R往回調整到mid，重新二分搜
        // 若times=K代表已經符合分堆，但是仍有可能是mid較大恰巧符合，可是分出來的組的sum不一定為最小
        // 所以先讓ans等於mid，然後同樣把R往回調整到mid，繼續二分搜看有沒有更小的答案存在
        if(times <= K){ 
            ans = mid;  
            R = mid;
        }
        else L = mid; // 若times>K代表mid太小，需要分比較多組，所以將L調整到mid
    }
    return ans;
}

__int32_t main(){
    cin >> N >> K;
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    int L = 0;
    int R = sum;
    int ans = binarySearch(L, R);
    cout << ans << endl;

    return 0;
}



