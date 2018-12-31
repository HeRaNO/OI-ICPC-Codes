#include <queue>
#include <cstdio>
#include <algorithm>
#define MAXN 200010
using namespace std;

struct game
{
	int time;
	int val;
};

bool cmp(game a, game b)
{
	return a.time > b.time;
}

game a[MAXN];
priority_queue <int> q;
int n, pos;
long long ans;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &a[i].time, &a[i].val);
	sort(a + 1, a + n + 1, cmp);
	pos = 1;
	for (int i = 200000; i; i--)
	{
		while (a[pos].time == i) q.push(a[pos++].val);
		if (!q.empty())
		{
			ans += q.top();
			q.pop();
		}
	}
	printf("%lld\n", ans);
	return 0;
}
