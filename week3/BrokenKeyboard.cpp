#include<bits/stdc++.h>
#define int long long
#define MX 9223372036854775807
#define oo 1e18

using namespace std;

__int32_t main(){
    string input;
    while (cin >> input)
    {
        deque<string> output;
        output.push_front("");
        int length = input.length();
        int flag = 0; // 0: front, 1: end
        for (int i = 0; i < length; i++)
        {
            if(input[i] == '['){
                flag = 0;
                output.push_front(""); // 創建一個新的string放在頭
                continue;
            }
            else if(input[i] == ']') flag = 1;
            else{ // 正常輸入則根據目前游標的位置
                if(flag == 0){
                    auto it = output.begin(); // 以頭的string往後接，注意不能用deque<char>然後簡單的push_front
                    *it += input[i];
                }
                else if(flag == 1){
                    auto it = output.end() - 1; // 注意end() return的時最後空的位置，所以要減1
                    *it += input[i];
                }
            }
        }
        for (auto it = output.begin(); it != output.end(); it++)
            cout << *it;
        cout << endl;
    }
    

    return 0;
}

