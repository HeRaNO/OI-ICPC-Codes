#include <map>
#include <cstdio>
#include <algorithm>
#define MAXN 15010
using namespace std;

int n, T, cnt;
long long x, y;
int a[MAXN << 1];
char s[3];
map <long long, int> m;
map <long long, int> :: iterator it, itt;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	freopen("battle.in", "r", stdin);
	freopen("battle.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s);
		if (s[0] == 'C')
		{
			scanf("%lld", &x);
			it = m.find(x);
			if (it == m.end()) m.insert(make_pair(x, 1));
			else it->second++;
		}
		else if (s[0] == 'D')
		{
			scanf("%lld", &x);
			it = m.find(x);
			if (it == m.end()) continue;
			it->second--;
			if (!it->second) m.erase(it);
		}
		else
		{
			scanf("%lld<%lld", &x, &y);
			it = m.find(x);
			itt = m.find(y);
			if (it == m.end() || itt == m.end()) continue;
			it->second += itt->second;
			m.erase(itt);
		}
	}
	for (it = m.begin(); it != m.end(); it++) a[++cnt] = it->second;
	sort(a + 1, a + cnt + 1, cmp);
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		scanf("%lld", &x);
		if (x > cnt) puts("NO");
		else printf("%d\n", a[x]);
	}
	return 0;
}
