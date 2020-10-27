#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll c;
const int N = 4000050;
ll vis[N], pri[N];
int tot;
void shaipri(int lim)
{
    for (int i = 2; i <= lim; ++i)
    {
        if (!vis[i])
            vis[i] = i, pri[++tot] = i;
        for (int j = 1; j <= tot && i * pri[j] <= lim; ++j)
        {
            vis[i * pri[j]] = pri[j];
            if (i % pri[j] == 0)
                break;
        }
    }
}
void solve()
{
    scanf("%lld", &c);
    ll now = c;
    for (int i = 1; i <= tot; ++i)
    {
        int cnt = 0;
        while (c % pri[i] == 0)
        {
            c /= pri[i];
            cnt++;
        }
        if (cnt >= 2)
        {
            puts("yes");
            return;
        }
    }
    now = c;
    ll sq = (ll)sqrt(now);
    if (sq * sq == c && c>1)
        return puts("yes"), void();
    puts("no");
}

int main()
{
    shaipri(N - 1);
    int Test;
    scanf("%d", &Test);
    while (Test--)
    {
        solve();
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}
/*
996491788296388609
*/