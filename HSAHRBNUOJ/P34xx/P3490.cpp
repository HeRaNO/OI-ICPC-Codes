#include <queue>
#include <vector>
#include <cstdio>
#include <algorithm>
#define MAXN 5010
using namespace std;

int n, a[MAXN], ans;
priority_queue <int, vector<int>, greater<int> > q;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	q.push(1);
	for (int i = 2; i <= n; i++)
	{
		int u = q.top();
		if (u > a[i]) q.push(1);
		else
		{
			q.pop();
			q.push(u + 1);
		}
	}
	ans = q.size();
	printf("%d\n", ans);
	return 0;
}
