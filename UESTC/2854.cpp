#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>

int main()
{
	int n;
	scanf("%d", &n);
	std::vector<int> l(n), r(n);
	std::vector<std::pair<int, int*>> a;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &l[i], &r[i]);
		a.push_back({l[i], &l[i]});
		a.push_back({r[i], &r[i]});
	}
	std::sort(a.begin(), a.end());
	std::vector<int> ori;
	for (int i = 0; i < a.size(); i++)
	{
		if (!i || a[i].first != a[i - 1].first) ori.push_back(a[i].first);
		*a[i].second = ori.size() - 1;
	}
	int N = ori.size();
	std::vector<std::vector<int>> ddl(N);
	for (int i = 0; i < n; i++)
		ddl[l[i]].push_back(ori[r[i]]);
	int ans = 0, now = 0;
	std::priority_queue<int, std::vector<int>, std::greater<int>> q;
	for (int i = 0; i < N; i++)
	{
		while (now < ori[i])
		{
			while (!q.empty() && q.top() < now) q.pop();
			if (q.empty()){ now = ori[i]; break; }
			q.pop(); ++ans; ++now;
		}
		for (int r : ddl[i]) q.push(r);
	}
	printf("%d\n", ans + !q.empty());
	return 0;
}