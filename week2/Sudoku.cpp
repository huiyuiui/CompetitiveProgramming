#include<bits/stdc++.h>
#define int long long
#define MX 9223372036854775807
#define oo 1e18

using namespace std;

int grid[9][9];

// row, col各9，分別代表各row和各col目前有的數字，使用bit做儲存，ex：0010001000即為目前放了3和7，有十個bit因為第0bit用不到
int row[9];
int col[9];
// sub_grid共3*3=9塊，各自代表小區塊內有的數字
int sub_grid[3][3];

// for checking input
bool illegal(int r, int c, int num){
    return (row[r] | col[c] | sub_grid[r / 3][c / 3]) & num;
}

void update(int r, int c, int num){
    // 使用xor是因為當該數字找不到答案，需要將row, col sub_grid設回原本的時候，再將該num傳入便會是對應bit皆為1，xor完變回0
    row[r] ^= num;
    col[c] ^= num;
    sub_grid[r / 3][c / 3] ^= num;  // row和col各切成3塊，所以將r和c(目前的位置)各除以3就可以找到對應的sub grid
}

// bit對應數字
int lg(int num){
    if(num == 2) return 1;
    if(num == 4) return 2;
    if(num == 8) return 3;
    if(num == 16) return 4;
    if(num == 32) return 5;
    if(num == 64) return 6;
    if(num == 128) return 7;
    if(num == 256) return 8;
    if(num == 512) return 9;
    return 0;
}

// 最重要！！！將num取反之後0變1，1變0，此時對反的再加1並取and，則會找到第一個1的位置，
int lowbit(int num){
    return num & (~num + 1);
}

bool dfs(int idx){
    if(idx == 81) return true;
    else if(idx > 81) return false;
    int r = idx / 9;
    int c = idx % 9;
    if(grid[r][c]) return dfs(idx + 1);
    int MASK = (1 << 10) - 2; // 移位10個bit會比9來的大才可以減掉，而減2是為了讓第0bit也為0.所以就會變成第1～9bit都為1
    int S = MASK & ~(row[r] | col[c] | sub_grid[r / 3][c / 3]); // S為目前可以用的數字，對不可用數字的取not後，用MASK將大於第9bit多餘的1給轉成0
    // num會是每次要填的數字，而S在下次和num做xor的時候，都是1的地方會變成0，意思是說上次填過的數字的bit就會被抵銷成0，最後會全部用完，S=0即跳出迴圈
    for (int num = 0; S; S ^= num)  
    {
        num = lowbit(S); //每次都取得最小的bit，當成填入數字
        grid[r][c] = num;
        update(r, c, num);
        if(dfs(idx + 1)) return true;
        grid[r][c] = 0;
        update(r, c, num);  // 第二次做update，會將原本update完變成1的對應bit，兩個1做xor完變成0
    }
    
    return false;
}

void init(){
    for (int i = 0; i < 9; i++)
    {
        row[i] = 0;
        col[i] = 0;
        sub_grid[i / 3][i % 3] = 0;
        for (int j = 0; j < 9; j++)
        {
            grid[i][j] = 0;
        }
    }   
}

void out(){
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << lg(grid[i][j]);
        }
    }
    cout << endl;
}

__int32_t main(){
    int wrong_input;
    char c;
    string input;
    while (1)
    {
        wrong_input = 0;
        cin >> input;
        init();
        if(input == "end") break;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                c = input[i * 9 + j];
                if(isdigit(c)){
                    grid[i][j] = 1 << (c - '0');
                    if(!illegal(i, j, grid[i][j])) // input有可能是錯的，所以輸入的時候就先判斷
                        update(i, j, grid[i][j]);
                    else wrong_input = 1;
                }
                else grid[i][j] = 0;
            }
        }
        if(wrong_input){
            cout << "No solution." << endl;
            continue;
        }

        if(dfs(0)) out();
        else cout << "No solution." << endl;
    }

    return 0;
}

