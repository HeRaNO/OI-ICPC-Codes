#include <bits/stdc++.h>
#define mp make_pair
#define MAXN 100005
using namespace std;

int n, a[MAXN], b[MAXN];
int ans, mx, x;
vector<pair<int, int> > v, r;

inline void max(int &a, int b)
{
	if (a < b) a = b;
	return ;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		if (i & 1) ++a[x];
		else ++b[x];
	}
	for (int i = 1; i <= 100000; i++)
		if (a[i]) v.push_back(mp(a[i], i));
	for (int i = 1; i <= 100000; i++)
		if (b[i]) r.push_back(mp(b[i], i));
	sort(v.begin(), v.end(), greater<pair<int, int> >());
	sort(r.begin(), r.end(), greater<pair<int, int> >());
	if (v.size() < 2) v.push_back(mp(0, 0));
	if (r.size() < 2) r.push_back(mp(0, 0));
	if (v[0].second == r[0].second)
	{
		int k = max(v[0].first + r[1].first, v[1].first + r[0].first);
		printf("%d\n", n - k);
		return 0;
	}
	printf("%d\n", n - v[0].first - r[0].first);
	return 0;
}