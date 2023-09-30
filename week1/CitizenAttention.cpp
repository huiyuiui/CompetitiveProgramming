#include<bits/stdc++.h>
#define int long long
#define MX 9223372036854775807
#define oo 1e18

using namespace std;

int T;
int N;
int arr[5][5] = {{0}};
int temp[5] = {0, 1, 2, 3, 4};
int ans[5] = {0, 1, 2, 3 ,4};
int minimum[5][5];
int visited[25] = {0};
int minSum = MX;

void init(){
    for (int i = 0; i < 5; i++){
        temp[i] = i;
        ans[i] = i;
        for (int j = 0; j < 5; j++){
            visited[i * 5 + j] = 0;
            arr[i][j] = 0;
        }
    }
    minSum = MX;
}

void print(){
    for (int i = 0; i < 5; i++){
        if(i == 4) cout << ans[i] << endl;
        else cout << ans[i] << ' ';
    }
}

void updateMin(){
    // update minimum array
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            minimum[i][j] = MX;

    for (int k = 0; k < 5; k++)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                int x_dist = abs(temp[k] / 5 - i);
                int y_dist = abs(temp[k] % 5 - j);
                int val = (x_dist + y_dist) * arr[i][j];
                if(val < minimum[i][j])
                    minimum[i][j] = val;
            }
        }
    }   
    // update ans
    int sum = 0;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            sum += minimum[i][j];
    if(sum < minSum){
        minSum = sum;
        for (int i = 0; i < 5; i++)
            ans[i] = temp[i];
    } 
}

void dfs(int n){
    if(n == 5){
        updateMin();
        return;
    }
    int idx = (n == 0) ? 0 : temp[n - 1] + 1;
    for (int i = idx; i < 25; i++)
    {
        if(visited[i]) continue;
        visited[i] = 1;
        temp[n] = i;
        dfs(n + 1);
        visited[i] = 0;
    }
}

__int32_t main(){

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        init();
        cin >> N;
        for (int j = 0; j < N; j++)
        {
            int x, y;
            cin >> x >> y;
            cin >> arr[x][y];
        }
        dfs(0);
        print();
    }
}

