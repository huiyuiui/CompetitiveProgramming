#include<bits/stdc++.h>
#define int long long
#define MX 9223372036854775807
#define oo 1e18

using namespace std;

int prefixSum[200005];

__int32_t main(){
    int n, x;
    cin >> n >> x;
    int ans = 0;
    map<int, int> recordPrefixTimes; // 記錄該prefixsum在整個array裡出現幾次，ex: 1, -1, 1，則prefixsum=1, 0, 1，而1出現兩次
    recordPrefixTimes[0] = 1; // 邊界情況：如果剛好prefixsum=x，那麼prefixsum - x = 0，此時也要有對應的值可以加
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        // prefixsum
        if(i == 0)
            prefixSum[0] = num;
        else
            prefixSum[i] = prefixSum[i - 1] + num;
        // 重點！！！原本的思想方式是，如果有兩個prefixsum相減=x，那麼就找到一個subarray
        // ex: 1 2 3 4 5，prefixsum= 1 3 6 10 15, x=9, 那麼10-1=9，即為[1 2 3 4] - [1]，找到[2 3 4]這個subarray
        // 那麼相反過來，用prefixsum[j]-x去找有沒有對應的prefixsum[i], i<j，同樣成立，以上面為例就是10-9=1，而1這個prefixsum是存在的，則代表找到一個subarray
        // 所以recordPrefixTimes就是記錄prefixsum有沒有出現，出現過幾次，從而用prefixsum-x，如果相減得到的數字在map裡找得到
        // 就代表找到兩個prefixsum相減會等於x，從而找到subarray。用ans+=代表prefixsum可能出現不只一次
        ans += recordPrefixTimes[prefixSum[i] - x];
        recordPrefixTimes[prefixSum[i]]++;
    }

    cout << ans << endl;
    

    return 0;
}

