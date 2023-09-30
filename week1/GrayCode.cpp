#include <iostream>
#include <string>

using namespace std;

int N;
/* This should include vector and algorithm */
// vector<string> out;

// vector<string> generateCode(int n){
//     if(n == 0)
//         return {"0"};
//     if(n == 1)
//         return {"0", "1"};
//     vector<string> rtnAns = generateCode(n - 1);
//     vector<string> nowAns;
//     for(string item : rtnAns){
//         nowAns.push_back("0" + item);
//     }
//     reverse(rtnAns.begin(), rtnAns.end());
//     for(string item : rtnAns){
//         nowAns.push_back("1" + item);
//     }
//     return nowAns;
// }

string out;

string generateCode(int n){
    if(n == 0)  
        return "0";
    if(n == 1) 
        return "0\n1";
    string rtnStr = generateCode(n - 1);
    string nowStr = "0";
    int size = rtnStr.length();
    for (int i = 0; i < size; i++)
    {
        if(rtnStr[i] == '\n')
            nowStr += "\n0";
        else
            nowStr += rtnStr[i];
    }
    // example: 如果是字串為00,01,11,10，則會是從10開始添加1變成110
    // 而非直接講字串全部倒過來（10變成01再添加1變成101，則與上面不符）
    // 所以是倒著掃，可是是以size n-1為單位正著添加prefix 1
    for (int i = size - 1; i >= -1; i--)
    {
        if(rtnStr[i] == '\n' || i == -1){
            nowStr += "\n1";
            for (int j = i + 1; j < i + n; j++)
                nowStr += rtnStr[j];
        }
    }
    
    return nowStr;
}

int main(){

    cin >> N;
    out = generateCode(N);
    // for(string str : out){
    //     cout << str << endl;
    // }
    cout << out << endl;
    return 0;
}