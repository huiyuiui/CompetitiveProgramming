#include<bits/stdc++.h>
#define int long long
#define MX 9223372036854775807
#define oo 1e18

using namespace std;

__int32_t main(){
    string str;
    stack<char> stk;
    cin >> str;
    int length = str.size();
    // 若放進stack的是T則檢查目前stack的top是不是為S
    // 若是，則把S給pop掉，也不用把T放進去，等於兩個一起消失
    // 若否，則正常放入stack
    for (int i = 0; i < length; i++)
    {
        if(stk.size() && stk.top() == 'S' && str[i] == 'T') stk.pop();
        else stk.push(str[i]);
    }
    cout << stk.size() << endl; 

    return 0;
}

