#include<bits/stdc++.h>
#define int long long
#define MX 9223372036854775807
#define oo 1e18

using namespace std;

// 依照排序標準
// 0:每個group的sum
// 1:每個group的max
// 2:每個group的人數（K）
// 3:每個group的input order
bool compare(vector<int> a, vector<int> b){
    if(a[0] > b[0]) return true;
    else if(a[0] == b[0]){
        if(a[1] > b[1]) return true;
        else if(a[1] == b[1]){
            if(a[2] > b[2]) return true;
            else if(a[2] == b[2]){ // 即便input order是從小到大，但仍可能交換途中順序亂掉，仍要注意
                if(a[3] < b[3]) return true; 
                else return false;
            }
            else return false;
        }
        else return false;
    }
    else return false;
}

__int32_t main(){
    int T;
    cin >> T;
    while (T--) // test case
    {
        int N;
        cin >> N;
        vector<vector<int>> arr; // 原本的array
        vector<vector<int>> compare_arr; // 用於比較的array，存放的數值如compare上面註解所示
        for (int i = 0; i < N; i++) // group
        {
            int K;
            cin >> K;
            int sum = 0;
            int Max = 0;
            int quantity;
            vector<int> temp;
            vector<int> temp_compare;
            for (int j = 0; j < K; j++)
            {
                cin >> quantity;
                sum += quantity;
                if(Max < quantity) Max = quantity;
                temp.push_back(quantity);
            }
            arr.push_back(temp);
            temp_compare.push_back(sum);
            temp_compare.push_back(Max);
            temp_compare.push_back(K);
            temp_compare.push_back(i);
            compare_arr.push_back(temp_compare);
        }

        sort(compare_arr.begin(), compare_arr.end(), compare);

        for (int i = 0; i < N; i++)
        {
            int people = compare_arr[i][2];
            int index = compare_arr[i][3]; // 按照sort好的index取出，分別print出group資訊
            for (int j = 0; j < people; j++)
            {
                if(j == people - 1) cout << arr[index][j] << endl;
                else cout << arr[index][j] << ' ';
            }
        }
    }
    return 0;
}