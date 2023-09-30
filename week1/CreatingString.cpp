#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int visited[10] = {0};
int len;
int cnt;
string in;
string ans;
vector<string> out;

void dfs(int n){
    if(n == len){
        cnt++;
        out.push_back(ans);
        return;
    }
    char prev = '1';
    // for loop從0開始是因為要掃過visited陣列裡還有誰沒被放過，不可以從i=n開始
    // prev是針對該層(n)可以放哪些字母，而非字串中的前後關係，所以不用開成全局變數
    for (int i = 0; i < len; i++)
    {
        if(visited[i] || prev == in[i]) // prev == in[i]代表該層已經放過該字母
            continue;
        visited[i] = 1;
        ans.push_back(in[i]);
        dfs(n + 1);
        visited[i] = 0;
        ans.pop_back();
        prev = in[i];
    }
}



int main(){
    cin >> in;
    len = in.length();
    sort(in.begin(), in.end());
    cnt = 0;
    dfs(0);
    cout << cnt << endl;
    for(string str : out){
        cout << str << endl;
    }
    return 0;
}