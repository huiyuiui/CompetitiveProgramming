#include<bits/stdc++.h>
#define int long long
#define MX 9223372036854775807
#define oo 1e18

using namespace std;

int N, R, C, ans = 2e9;
int pipe[15][15], rec[15][15];
const int dr[2][6] = {{-1, -1, 0, 1, 1, 0}, {-1, -1, 0, 1, 1, 0}};
const int dc[2][6] = {{0, 1, 1, 1, 0, -1}, {-1, 0, 1, 0, -1, -1}};
pair<int, int> r1, r2, r3, r4;

void dfs(int r, int c, int pred, int ishon, int sum)
{

    sum += pipe[r][c];
    if (sum >= ans)
        return;
    if (ishon)
    {
        if (pred == -1)
        {
            for (int i = 0; i < 6; i++)
            {
                int newr = r + dr[r % 2][i], newc = c + dc[r % 2][i];
                if (newr == r4.first && newc == r4.second)
                    ans = min(ans, sum + pipe[newr][newc]);
                else if (!rec[newr][newc])
                {
                    rec[newr][newc] = 1;
                    dfs(newr, newc, i, ishon, sum);
                    rec[newr][newc] = 0;
                }
            }
        }
        else
        {
            int start = (pred + 5) % 6;
            int end = (pred + 8) % 6;
            for (int i = start; i != end; i = (i + 1) % 6)
            {
                int newr = r + dr[r % 2][i], newc = c + dc[r % 2][i];
                if (newr == r4.first && newc == r4.second)
                    ans = min(ans, sum + pipe[newr][newc]);
                else if (!rec[newr][newc])
                {
                    rec[newr][newc] = 1;
                    dfs(newr, newc, i, ishon, sum);
                    rec[newr][newc] = 0;
                }
            }
        }
    }
    else
    {
        if (pred == -1)
        {
            for (int i = 0; i < 6; i++)
            {
                int newr = r + dr[r % 2][i], newc = c + dc[r % 2][i];
                if (newr == r2.first && newc == r2.second)
                    dfs(r3.first, r3.second, -1, 1, sum + pipe[newr][newc]);
                else if (!rec[newr][newc])
                {
                    rec[newr][newc] = 1;
                    dfs(newr, newc, i, ishon, sum);
                    rec[newr][newc] = 0;
                }
            }
        }
        else
        {
            int start = (pred + 5) % 6;
            int end = (pred + 8) % 6;
            for (int i = start; i != end; i = (i + 1) % 6)
            {
                int newr = r + dr[r % 2][i], newc = c + dc[r % 2][i];
                if (newr == r2.first && newc == r2.second)
                    dfs(r3.first, r3.second, -1, 1, sum + pipe[newr][newc]);
                else if (!rec[newr][newc])
                {
                    rec[newr][newc] = 1;
                    dfs(newr, newc, i, ishon, sum);
                    rec[newr][newc] = 0;
                }
            }
        }
    }
}


__int32_t main()
{
    cin >> N;
    while (N--)
    {
        cin >> R >> C;
        cin >> r1.first >> r1.second >> r2.first >> r2.second >>
            r3.first >> r3.second >> r4.first >> r4.second;
        for (int r = 0; r <= R + 1; r++)
        {
            fill(rec[r], rec[r] + 7, 1);
        }
        for (int i = 1; i <= R; i++)
            for (int j = 1; j <= C; j++)
                cin >> pipe[i][j], rec[i][j] = 0;
        ans = 2e9;
        rec[r1.first][r1.second] = 1;
        rec[r2.first][r2.second] = 1;
        rec[r3.first][r3.second] = 1;
        rec[r4.first][r4.second] = 1;
        dfs(r1.first, r1.second, -1, 0, 0);
        if (ans != 2e9)
            cout << ans << '\n';
        else
            cout << "-1\n";
    }

    return 0;
}