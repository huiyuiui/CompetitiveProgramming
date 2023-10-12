#include<bits/stdc++.h>
// 此題的age是32bits postive integer，保險起見用unsigned long long
#define int unsigned long long
#define MX 9223372036854775807
#define oo 1e18

using namespace std;

struct Cat{
    string name;
    int position;
    int age;
};

// 比較順序
// 0: position
// 1: age
// 2: name
bool compare(Cat a, Cat b){
    if(a.position < b.position) return true;
    else if(a.position == b.position){
        if(a.position == 5 && a.age < b.age) return true; // 只有appentice需要從小到大
        else if(a.position != 5 && a.age > b.age) return true;
        else if(a.age == b.age){
            int minLength; // 取兩者name的最小長度，防止比較時out of range
            int flag;
            if(a.name.length() < b.name.length()){
                minLength = a.name.length();
                flag = 0;
            }
            else{
                minLength = b.name.length();
                flag = 1;
            }
            for (int i = 0; i < minLength; i++){
                if(a.name[i] < b.name[i]) return true;
                else if(a.name[i] > b.name[i]) return false;
            }
            // 若以上迴圈結束代表minLength內的字母都相同，那麼比較長的字典序就會比較後面
            if(flag == 0) return true;
            else if(flag == 1) return false;
        }
        else return false;
    }
    else return false;
}

// 將position從字串轉成idx容易比較
int positionTable(string position){ 
    if(position == "elder")     return 1;
    if(position == "nursy")     return 2;
    if(position == "kit")       return 3;
    if(position == "warrior")   return 4;
    if(position == "appentice") return 5;
    if(position == "medicent")  return 6;
    if(position == "deputy")    return 7;
    if(position == "leader")    return 8;
}

__int32_t main(){
    int N, M;
    while (cin >> N >> M)
    {
        vector<Cat> catList;
        for (int i = 0; i < N; i++)
        {
            string name;
            string position;
            int age;
            cin >> name >> position >> age;
            Cat cat;
            cat.name = name;
            cat.position = positionTable(position);
            cat.age = age;
            catList.push_back(cat);
        }
        sort(catList.begin(), catList.end(), compare);
        if(M > N) M = N; // 有可能M>N，那麼下面的迴圈會out of range造成RE
        for (int i = 0; i < M; i++)
            cout << catList[i].name << endl;
    }
    
    return 0;
}

