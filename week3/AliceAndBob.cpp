#include<bits/stdc++.h>
#define int long long
#define MX 9223372036854775807
#define oo 1e18
#define P pair<int, int>
#define PP pair<P, P>
#define F first
#define S second
using namespace std;

int K, N, M;
queue<pair<int, int>> alice;
queue<pair<int, int>> bob;

__int32_t main(){
    cin >> K >> N >> M;
    int time;
    int flag = 0; // 0:right, 1:down
    int nowRow = 0;
    int nowCol = -1;
    int prevTime = 0;
    for (int i = 0; i <= N; i++)
    {
        if(i == N) time = K + 1;
        else cin >> time;
        if(flag == 0) nowCol += time - prevTime;
        else if(flag == 1) nowRow += time - prevTime;
        alice.push({nowRow, nowCol});
        prevTime = time;
        flag = !flag;
    }
    flag = 1;
    nowRow = -1;
    nowCol = 0;
    prevTime = 0;
    for (int i = 0; i <= M; i++)
    {
        if(i == M) time = K + 1;
        else cin >> time;
        if(flag == 0) nowCol += time - prevTime;
        else if(flag == 1) nowRow += time - prevTime;
        bob.push({nowRow, nowCol});
        flag = !flag;
        prevTime = time; 
    }

    flag = 0;
    int purpleCount = 0;
    int prevAliceRow, prevAliceCol, prevBobRow, prevBobCol;
    int nowAliceRow = 0, nowAliceCol = 0, nowBobRow = 0, nowBobCol = 0;
    prevAliceRow = prevAliceCol = prevBobRow = prevBobCol = 0;
    // nowAliceRow = alice.front().first;
    // nowAliceCol = alice.front().second;
    // nowBobRow = bob.front().first;
    // nowBobCol = bob.front().second;
    // alice.pop();
    // bob.pop();
    while (bob.size() || alice.size())
    {       
        if((alice.size() && (nowAliceRow < nowBobRow || nowAliceCol < nowBobCol)) || !bob.size()){
            prevAliceRow = nowAliceRow;
            prevAliceCol = nowAliceCol;
            nowAliceRow = alice.front().first;
            nowAliceCol = alice.front().second;
            alice.pop();
        }
        else{
            prevBobRow = nowBobRow;
            prevBobCol = nowBobCol;
            nowBobRow = bob.front().first;
            nowBobCol = bob.front().second;
            bob.pop();
            flag = !flag;
        }    
        // right cross
        if(flag == 0){
            if(prevAliceRow == nowBobRow && nowBobRow == nowAliceRow){
                int start = max(prevAliceCol, prevBobCol) + 1;
                int end = min(nowAliceCol, nowBobCol);
                if(end - start >= 0){
                    // for (int i = start; i <= end; i++)
                    // {
                    //     cout << nowBobRow << ' ' << i << endl;
                    // }
                    purpleCount += (end - start) + 1;
                }
            }
            else if(prevAliceRow < nowBobRow && nowBobRow <= nowAliceRow && prevBobCol < nowAliceCol && nowAliceCol <= nowBobCol){
                // cout << nowBobRow << ' ' << nowAliceCol << endl;
                purpleCount++;
            }
        }
        // down cross
        else if(flag == 1){
            if(prevAliceCol == nowBobCol && nowBobCol == nowAliceCol){
                int start = max(prevAliceRow, prevBobRow) + 1;
                int end = min(nowAliceRow, nowBobRow);
                if(end - start >= 0){
                    // for (int i = start; i <= end; i++)
                    // {
                    //     cout << i << ' ' << nowBobCol << endl;
                    // }
                    purpleCount += (end - start) + 1;
                }
            }
            else if(prevAliceCol < nowBobCol && nowBobCol <= nowAliceCol && prevBobRow < nowAliceRow && nowAliceRow <= nowBobRow){
                // cout << nowAliceRow << ' ' << nowBobCol << endl;
                purpleCount++;
            }
        }
    }
    // if(alice.size()){
    //     if(flag == 0){ // prev is down
    //         if(nowAliceCol == nowBobCol){
    //             int start = prevBobRow + 1;
    //             int end = min(nowAliceRow, nowBobRow);
    //             for (int i = start; i <= end; i++)
    //             {
    //                 cout << i << ' ' << nowBobCol << endl;
    //             }
    //             purpleCount += (end - start) + 1;
    //         }
    //     }
    //     else if(flag == 1){ // prev is right
    //         if(nowAliceRow == nowBobRow){
    //             int start = prevAliceCol + 1;
    //             int end = min(nowAliceCol, nowBobCol);
    //             for (int i = start; i <= end; i++)
    //             {
    //                 cout << nowBobRow << ' ' << i << endl;
    //             }
    //             purpleCount += (end - start) + 1;
    //         }
    //     } 
    // }
    cout << K - purpleCount << ' ' << K - purpleCount << ' ' << purpleCount << endl;
    
    return 0;
}
