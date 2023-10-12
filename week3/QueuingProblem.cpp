#include<bits/stdc++.h>
#define int long long
#define MX 9223372036854775807
#define oo 1e18

using namespace std;

struct Node{
    int id;
    Node* next;
};

struct Head{
    Node* next;
};

int inQueue[1000005];

__int32_t main(){
    int N, M;
    vector<Head*> queueList;
    Head* empty = new Head;
    queueList.push_back(empty);
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        Head* head = new Head;
        Node* node = new Node;
        node->id = i;
        node->next = NULL;
        head->next = node;
        queueList.push_back(head);
        inQueue[i] = i;
    }
    for (int i = 0; i < M; i++)
    {
        int query, a, b;
        cin >> query  >> a >> b;
        if(query == 0){
            int fromQueue = inQueue[a];
            int toQueue = inQueue[b];
            Node* fromNow = queueList[fromQueue]->next;
            Node* toNow = queueList[toQueue]->next;
            Node* from;
            int flag = 1;
            if(fromNow->id == a){ // 如果第一個即為要移動的
                from = fromNow;
                queueList[fromQueue]->next = from->next;
                flag = 0;
            }
            if(flag){ // 如果不在第一個則遍歷
                while (fromNow != NULL) // 遍歷找到
                {
                    if(fromNow->next->id == a){ // 用next判斷，因為要更改next
                        from = fromNow->next;
                        fromNow->next = from->next; // 目前的next接到下下個
                        break;
                    }
                    else fromNow = fromNow->next;
                }
            }
            while (toNow != NULL)
            {
                if(toNow->id == b){
                    from->next = toNow->next;
                    toNow->next = from;
                    break;
                }
                else toNow = toNow->next;
            }
            inQueue[a] = inQueue[b]; // 記得更新a在哪個queue
        }
        else if(query == 1){
            Node* from = queueList[a]->next;
            Node* to = queueList[b]->next;
            Node* now = from;
            queueList[a]->next = NULL;
            while (now != NULL)
            {
                inQueue[now->id] = b;
                now = now->next;
            }
            if(to == NULL) queueList[b]->next = from;
            else{
                while (to->next != NULL)
                    to = to->next;
                to->next = from;
            }
        }
    }
    
    for (int i = 1; i <= N; i++)
    {
        cout << '#' << i << ':';
        Node* now = queueList[i]->next;
        while (now != NULL){
            cout << ' ' << now->id;
            now = now->next;
        }
        cout << endl;
    }
    

    return 0;
}

