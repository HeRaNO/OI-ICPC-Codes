#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 1000 + 5;
const int maxm = 10000 + 5;
const int maxk = 1000000 + 5;
int a[maxm], b[maxm], c[maxm], t[maxm];
int r[maxn], get[maxn], off[maxn], in[maxn], leave[maxn], d[maxn], s[maxn];
long long ans;
int n, m, k;
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i < n; ++i) scanf("%d", &d[i]);
	for (int i = 0 ; i < m; ++i)
	{
		scanf("%d%d%d", &t[i], &a[i], &b[i]);
		off[b[i]]++;
		in[a[i]]++;
		leave[a[i]] = max(leave[a[i]], t[i]);
	}
	for (int i = 2; i <= n; ++i)
		get[i] = max(get[i - 1], leave[i - 1]) + d[i - 1];
	int p = 1;
	for (int i = 1; i <= n; ++i)
	{
		while (p < n && leave[p] < get[p] || p <= i) p++;
		r[i] = p;
		s[i] = s[i - 1] + off[i];
	}
	while (k)
	{
		int maxp = 0, station;
		for (int i = 1; i < n; ++i)
			if (s[r[i]] - s[i] > maxp && d[i] > 0)
			{
				maxp = s[r[i]] - s[i];
				station = i;
			}
		if (maxp == 0) break;
		int maxt = 0x7fffffff;
		for (int j = station + 1; j < n && leave[j] < get[j]; ++j)
			maxt = min(maxt, get[j] - leave[j]);
		int maxDecK = min(d[station], min(maxt, k));
		k -= maxDecK;
		d[station] -= maxDecK;
		for (int j = station + 1; j <= r[station]; ++j)
			get[j]  = max(get[j - 1], leave[j - 1]) + d[j - 1];
		for (int j = p = station ; j < r[station]; ++j)
		{
			while (p < n && leave[p] < get[p] || p <= j) p++;
			if (p >= r[j]) break;
			r[j] = p;
		}
	}
	int ans = 0;
	for (int i = 0; i < m ; ++i)
		ans += (long long)(get[b[i]] - t[i]);
	cout << ans << endl;
	return 0;
}