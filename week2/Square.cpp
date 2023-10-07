#include<bits/stdc++.h>
#define int long long
#define MX 9223372036854775807
#define oo 1e18

using namespace std;

int N;
int M;
int sum;
int mean;
int sticks[25] = {0};
int visited[25] = {0};

// idx為目前sticks的index，nowSum為目前該邊的和，cnt為第幾邊
bool dfs(int idx, int nowSum, int cnt){
    if(cnt == 4) return true; // 到達第四邊的時候代表四邊都已經找完了（解釋在下），也可以理解為index為0～3，所以4代表就找完了
    if(nowSum > mean) return false;
    if(nowSum == mean){ // 第一遍找到mean的時候並不會馬上更新cnt，會隨著遞迴下一層時才會更新，所以感覺上cnt少一
        for (int i = 0; i < M; i++)
        {
            if(visited[i]) continue;
            visited[i] = 1;
            if(dfs(i + 1, sticks[i], cnt + 1)) // 在該邊找到時，要進入下一邊才會將cnt+1，並且將nowSum設為該sticks的值
                return true;
            visited[i] = 0;
        }
        return false; // 如果for迴圈結束沒有return true代表找不到答案，那麼就return false
    }
    if(idx >= M) return false;
    
    for (int i = idx; i < M; i++)
    {
        if(visited[i]) continue;
        visited[i] = 1;
        if(dfs(i + 1, nowSum + sticks[i], cnt)) // 此處為主要搜尋加法，主要架構解釋如上，但遞迴是針對該邊，所以cnt不變
            return true;
        visited[i] = 0;
    }
    return false;
}

__int32_t main(){
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        sum = 0;
        mean = 0;
        cin >> M;
        for (int j = 0; j < M; j++)
        {
            cin >> sticks[j];
            sum += sticks[j];
            visited[j] = 0;
        }
        if(sum % 4 != 0){ // 如果全部sticks加起來求4邊平均不為整數，代表找不到四邊相等的情形
            cout << "no" << endl;
            continue;
        }
        mean = sum / 4;
        sort(sticks, sticks + M, greater<int>());
        if(dfs(0, 0, 1)) cout << "yes" << endl;
        else cout << "no" << endl;        
    }
    return 0;
}