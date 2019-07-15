#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;

int n, pt;
int r[MAXN][2];
bool vis[MAXN];
stack <int> ans;
stack <int> fans;

bool f(int fa, int id)
{
	int son = r[fa][id];
	int gson = r[fa][id ^ 1];
	if (r[son][0] == gson || r[son][1] == gson) return true;
	return false;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &r[i][0], &r[i][1]);
	ans.push(1);
	pt = 1;
	vis[pt] = true;
	while (!vis[r[pt][0]] || !vis[r[pt][1]])
	{
		int a = r[pt][0], b = r[pt][1];
		if (f(pt, 0))
		{
			ans.push(a);
			vis[a] = true;
			if (!vis[b])
			{
				vis[b] = true;
				ans.push(b);
			}
		}
		else
		{
			swap(a, b);
			ans.push(a);
			vis[a] = true;
			if (!vis[b])
			{
				vis[b] = true;
				ans.push(b);
			}
		}
		pt = ans.top();
	}
	while (!ans.empty())
	{
		fans.push(ans.top());
		ans.pop();
	}
	while (!fans.empty())
	{
		printf("%d ", fans.top());
		fans.pop();
	}
	puts("");
	return 0;
}