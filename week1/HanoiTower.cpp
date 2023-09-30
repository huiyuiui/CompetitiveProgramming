#include <iostream>

using namespace std;

int N;
int out[1000005][2] = {0};
int idx = 0;

// from temp to
void hanoi(int n, int A, int B, int C)
{
    if (n == 1)
    {
        out[idx][0] = A;
        out[idx][1] = C;
        idx++;
        return;
    }
    hanoi(n - 1, A, C, B);
    out[idx][0] = A;
    out[idx][1] = C;
    idx++;
    hanoi(n - 1, B, A, C);
}

int main()
{

    cin >> N;
    hanoi(N, 1, 2, 3);
    cout << idx << endl;
    for (int i = 0; i < idx; i++)
    {
        cout << out[i][0] << " " << out[i][1] << endl;
    }

    return 0;
}