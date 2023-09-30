#include "bits/stdc++.h"
#define MX 9223372036854775807
#define oo 1e18

using namespace std;

long long int N;
long long int minimum;
long long int arr[30];

void dfs(long long int n, long long int val){
    if(n == N){
        if(abs(val) < minimum)
            minimum = abs(val);
        return;
    }
    dfs(n + 1, val + arr[n]);
    dfs(n + 1, val - arr[n]);
}

int main(){
    cin >> N;
    for (long long int i = 0; i < N; i++)
        cin >> arr[i];
    minimum = MX;
    dfs(0, 0);
    cout << minimum << endl;
    
    return 0;
}

