#include <bits/stdc++.h>
#define ll long long
#define ls id << 1
#define rs id << 1 | 1
#define mem(array, value, size, type) memset(array, value, ((size) + 5) * sizeof(type))
#define memarray(array, value) memset(array, value, sizeof(array))
#define pb(x) push_back(x)
#define st(x) (1LL << (x))
#define pii pair<int, int>
#define mp(a, b) make_pair((a), (b))
using namespace std;
const int N = 105;
const int inf = 0x3f3f3f3f;
const ll mod = 998244353LL;
clock_t TIME_START, TIME_END;
void program_end()
{
#ifdef ONLINE
    printf("\nTime used: %.6lf(s)\n", ((double)TIME_END - TIME_START) / CLOCKS_PER_SEC);
    system("pause");
#endif
}

int n, m;
bool vis[N][N];
int dis[N][N];
int dis2[N][N];
bool used[N*10];

void solve()
{
    scanf("%d%d", &n, &m);
    memarray(vis, 0);
    memarray(used, 0);
    memarray(dis, inf);
    memarray(dis2, inf);
    for (int i = 1; i < n; ++i)
    {
        dis[i][i + 1] = i;
        used[i] = 1;
    }
    if (n % 3 == 1)
        dis[n][1] = n + 2, used[n + 2] = 1;
    else
        dis[n][1] = n, used[n] = 1;
    memcpy(dis2, dis, sizeof(dis2));
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (dis[i][k] != inf && dis[k][j] != inf && dis[i][k] + dis[k][j] < dis[i][j])
                    dis[i][j] = dis[i][k] + dis[k][j];
    for (int k = n; k <= m; ++k)
    {
        if (used[k])
            continue;
        int MOD = k % 3;
        bool flag = false;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (i == j)
                    continue;
                if (dis[i][j] % 3 == MOD && dis2[i][j] == inf && dis2[j][i] == inf)
                {
                    dis2[i][j] = k;
                    flag = true;
                }
                if (flag)
                    break;
            }
            if (flag)
                break;
        }
        if (!flag)
        {
            puts("-1");
            return;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i != j && dis2[i][j] != inf)
                printf("%d %d %d\n", i, j, dis2[i][j]);
        }
    }
}

int main()
{
    TIME_START = clock();
    int Test = 1, kase = 0;
    cin >> Test;
    while (Test--)
    {
        printf("Case #%d:\n", ++kase);
        solve();
    }

    TIME_END = clock();
    program_end();
    return 0;
}