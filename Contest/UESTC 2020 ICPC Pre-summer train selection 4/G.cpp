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
#define Flush fflush(stdout)
using namespace std;
const int N = 20002;
const int inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
clock_t TIME_START, TIME_END;
void program_end()
{
#ifdef ONLINE
    printf("\nTime used: %.6lf(s)\n", ((double)TIME_END - TIME_START) / CLOCKS_PER_SEC);
    system("pause");
#endif
}
int n, m;
vector<int> e[N][102];
vector<int> g[N];
ll BigPointCost[N];
int ine[N][102], ing[N];
int siz[N];
struct SmallPoint
{
    int type;
    int callid;
    ll cost;
} p[N][102];
void Input()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        int k;
        scanf("%d", &k);
        siz[i] = k;
        assert(k <= 100);
        for (int j = 1; j <= k; ++j)
        {
            int l;
            scanf("%d", &l);
            while (l--)
            {
                int x;
                scanf("%d", &x);
                e[i][x].push_back(j);
                ine[i][j]++;
            }
            int o;
            scanf("%d", &o);
            if (o == 0)
            {
                p[i][j].type = 1;
                scanf("%lld", &p[i][j].cost);
                if(p[i][j].cost==0)return printf("!"),void();
                // p[i][j].cost = read();
            }
            else
            {
                p[i][j].type = 2;
                scanf("%d", &p[i][j].callid);
                ing[i]++;
                g[p[i][j].callid].push_back(i);
            }
        }
    }
}
bool vis[N];
ll dp[150];
void work(int BigID)
{
    for (int i = 1; i <= siz[BigID]; ++i)
    {
        if (p[BigID][i].type == 2)
        {
            p[BigID][i].cost = BigPointCost[p[BigID][i].callid]+1;
            //assert(BigPointCost[p[BigID][i].callid]);
        }
    }
    for (int i = 0; i <= siz[BigID]; ++i)
        dp[i] = 0;
    queue<int> q;
    for (int i = 1; i <= siz[BigID]; ++i)
    {
        if (!ine[BigID][i])
            q.push(i);
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        (dp[u]+=p[BigID][u].cost)%=mod;
        for (auto v : e[BigID][u])
        {
            dp[v] = max(dp[v],dp[u]);
            ine[BigID][v]--;
            if (ine[BigID][v] == 0)
                q.push(v);
        }
    }
    for (int i = 1; i <= siz[BigID]; ++i)
        BigPointCost[BigID] = max(BigPointCost[BigID], dp[i]);
}
void Topsort()
{
    queue<int> q;
    for (int i = 1; i <= n; ++i)
        if (ing[i] == 0)
            q.push(i), vis[i] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        work(u);
        for (auto v : g[u])
        {
            ing[v]--;
            if (ing[v] == 0 && !vis[v])
                q.push(v), vis[v] = 1;
        }
    }
    while (m--)
    {
        int x;
        scanf("%d", &x);
        printf("%lld\n", BigPointCost[x] % mod);
        // print(BigPointCost[x] % mod);
        // puts("");
    }
}

void solve()
{
    Input();
    Topsort();
}

int main()
{
    //freopen("07.in","r",stdin);
    TIME_START = clock();
    int Test = 1;
    // cin >> Test;
    while (Test--)
        solve();
    TIME_END = clock();
    program_end();
    return 0;
}