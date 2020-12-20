#include <bits/stdc++.h>
using namespace std;
#define Flush fflush(stdout)
const int N = 350;
int n, T, C, ans;
int score[N];
set<int> vecbelong[N];
set<int> veccase[N];
vector<int> e[N];
bool fail[N];
bool vis[N];

void dfsdel(int u)
{
	vis[u] = 1;
	fail[u] = 1;
	for (auto i : veccase[u])
		vecbelong[i].erase(u);
	for (auto v : e[u])
	{
		if (vis[v] || fail[v])
			continue;
		dfsdel(v);
		vis[v] = 1;
	}
}

void work()
{
	while (true)
	{
		int nowtest = C + 1;
		while (vecbelong[nowtest].empty() && nowtest <= T)
			nowtest++;
		if (nowtest > T)
			break;
		printf("%d\n", C - nowtest), Flush;
		int x;
		scanf("%d", &x);
		if (x == 0)
		{
			memset(vis, 0, sizeof vis);
			set<int> snow = vecbelong[nowtest];
			for (auto i : snow)
				dfsdel(i);
		}
		C = nowtest;
	}
	for (int i = 1; i <= n; ++i)
		if (!fail[i])
			ans += score[i];
	printf("%d\n", ans);
}

int main()
{
	scanf("%d%d", &n, &T);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &score[i]);
		int tot;
		scanf("%d", &tot);
		while (tot--)
		{
			int x;
			scanf("%d", &x);
			vecbelong[x].insert(i);
			veccase[i].insert(x);
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		int s;
		scanf("%d", &s);
		while (s--)
		{
			int v;
			scanf("%d", &v);
			e[v].push_back(i);
		}
	}
	work();
	system("pause");
	return 0;
}
/*
2 7
40 5 1 2 3 4 5
60 3 5 6 7
0
1 1
*/