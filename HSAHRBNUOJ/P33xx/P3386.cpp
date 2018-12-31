#include <queue>
#include <cstdio>
#include <algorithm>
#define MAXC 100010
using namespace std;

struct finance
{
	int v, c;
};

finance a[MAXC];
int n, c, f, half, sum, ans = -1;
int low[MAXC], up[MAXC];
priority_queue <int> q;

bool cmp(finance a, finance b)
{
	if (a.v == b.v) return a.c < b.c;
	return a.v < b.v;
}

int main()
{
	//freopen("finance.in","r",stdin);freopen("finance.out","w",stdout);
	scanf("%d %d %d", &n, &c, &f);
	for (int i = 1; i <= c; i++)
		scanf("%d %d", &a[i].v, &a[i].c);
	half = n >> 1;
	sort(a + 1, a + c + 1, cmp);
	while (!q.empty()) q.pop();
	for (int i = 1; i <= c; i++)
	{
		if (q.size() == half) low[i] = sum;
		else low[i] = 1e9;
		q.push(a[i].c);
		sum += a[i].c;
		if (q.size() > half)
		{
			sum -= q.top();
			q.pop();
		}
	}
	while (!q.empty()) q.pop();
	sum = 0;
	for (int i = c; i; i--)
	{
		if (q.size() == half) up[i] = sum;
		else up[i] = 1e9;
		q.push(a[i].c);
		sum += a[i].c;
		if (q.size() > half)
		{
			sum -= q.top();
			q.pop();
		}
	}
	for (int i = c; i; i--)
		if (up[i] + low[i] + a[i].c <= f)
		{
			ans = a[i].v;
			break;
		}
	printf("%d\n", ans);
	return 0;
}
