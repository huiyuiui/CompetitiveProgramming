#include<bits/stdc++.h>
#define int long long
#define MX 9223372036854775807
#define oo 1e18

using namespace std;

__int32_t main(){
    int Q;
    queue<int> original; // 用於存放query 1的element
    priority_queue<int, vector<int>, greater<int>> sorted; // 用於存放query 3(sort)的element
    cin >> Q;
    while (Q--)
    {
        int q;
        cin >> q;
        // query 1就直接push到queue裡
        if(q == 1){
            int val;
            cin >> val;
            original.push(val);
        }
        // 重點！！！若無sort過，則正常print queue內的front
        // 若有sort過，則PQ的elements會優先（若非空），在sort後才append的則是放在queue內等待PQ都pop完才輪到
        // 這樣就能夠保證sort和input的順序
        else if(q == 2){
            if(sorted.empty()){
                cout << original.front() << endl;
                original.pop();
            }
            else{
                cout << sorted.top() << endl;
                sorted.pop();
            }
        }
        // 丟進PQ做sort的同時要把queue給pop掉，保證同一個數字只會出現在其中一邊
        // 若是在途中兩邊都有elements的時候進行sort，則仍能保證PQ順序正確，而queue被清空
        else if(q == 3){
            while (original.size())
            {
                sorted.push(original.front());
                original.pop();
            }
        }
    }

    return 0;
}