#include <bits/stdc++.h>
#define int long long
#define MX 9223372036854775807
#define oo 1e18

using namespace std;
struct que
{
    int val, head, tail;
    que *pre, *nxt;
};

que q[1000005];
int head[1000005], tail[1000005];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        tail[i] = head[i] = q[i].val = q[i].head = q[i].tail = i;
        q[i].nxt = q[i].pre = nullptr;
    }
    for (int i = 0; i < m; i++)
    {
        int typ, a, b;
        cin >> typ >> a >> b;
        if (typ == 0)
        {
            if (q[b].nxt == q + a) continue;
            if (q[a].head !=-1)
            {
                if (q[a].nxt != nullptr){
                    head[q[a].head] = q[a].nxt->val;
                    q[a].nxt->head = q[a].head;
                }
                else head[q[a].head] = 0;
                q[a].head =- 1;
            }
            if (q[a].tail !=-1)
            {
                if (q[a].pre != nullptr){
                    tail[q[a].tail] = q[a].pre->val;
                    q[a].pre->tail = q[a].tail;
                }
                else tail[q[a].tail] = 0;
                q[a].tail =-1;
            }
            if (q[b].tail !=-1)
            {
                tail[q[b].tail] = a;
                q[a].tail = q[b].tail;
                q[b].tail =-1;
            }
            if (q[a].pre) q[a].pre->nxt = q[a].nxt;
            if (q[a].nxt) q[a].nxt->pre = q[a].pre;
            q[a].pre = q + b, q[a].nxt = q[b].nxt;
            if (q[b].nxt) q[b].nxt->pre = q + a;
            q[b].nxt = q + a;
        }
        else
        {
            if (head[a] == 0)
                continue;
            int tmp = tail[b], tmp2 = head[a];
            que *start = q + tmp, *start2 = q + tmp2;
            tmp = tail[a];
            que *start3 = q + tmp;
            start3->tail = b;
            if (head[b] == 0)
            {
                head[b] = head[a];
                tail[b] = tail[a];
                start2->head = b;
                head[a] = tail[a] = 0;
                continue;
            }
            start->nxt = start2;
            start2->pre = start;
            head[a] = 0;
            tail[b] = tail[a];
            tail[a] = 0;
            start2->head =-1;
            start->tail =-1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int tmp = head[i];
        que start = q[tmp];
        cout << "#" << i << ":";
        while (start.val != 0)
        {
            cout << " " << start.val;
            if (start.nxt)
                start = *(start.nxt);
            else
                break;
        }
        cout << '\n';
    }
}