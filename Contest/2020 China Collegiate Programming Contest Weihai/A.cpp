#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, t, x;

int main()
{
    int Test;
    scanf("%d", &Test);
    while (Test--)
    {
        scanf("%lld%lld%lld", &n, &x, &t);
        ll ans = LONG_LONG_MAX;
        ans = min(ans, max(0ll, x - (2 * n - 2) * t) + 4 * n * t);
        ans = min(ans, (4 * n + 1) * t + max(0ll, x - 2 * n * t));
        if (x <= (2 * n - 1) * t)
        {
            ans = min(ans, 4 * n * t + max(0ll, x - (2 * n - 4) * t));
            ans = min(ans, 4 * n * t + t + max(0ll, x - (2 * n - 2) * t));
        }
        cout << ans << '\n';
    }

#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}