#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

int n, k;
int a[MAXN], cnt[MAXN], ans[MAXN], mx;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		++cnt[a[i]];
		mx = max(mx, a[i]);
	}
	for (int i = mx; i; i--)
	{
		int ct = 0;
		for (int j = i; j <= mx; j += i) ct += cnt[j];
		if (ans[ct] < i) ans[ct] = i;
	}
	for (int i = n; i; i--) ans[i] = max(ans[i + 1], ans[i]);
	for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
	return 0;
}
