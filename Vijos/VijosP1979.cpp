#include<cstdio>
using namespace std;

int n;
int minn = 10000000;
int t[200005] = {0};
int s[200005] = {0};
int can[200005] = {0};
int c[200005] = {0};
int tt = -1;

inline int min(int a, int b)
{
	if (a < b)return a;
	return b;
}

void dfs(int now, int step)
{
	if (can[now] == tt)
	{
		minn = min(minn, step - s[now]);
		return ;
	}
	can[now] = tt;
	s[now] = step;
	dfs(t[now], step + 1);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &t[i]);
		c[t[i]]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (can[i] == 0)
		{
			if (c[i] != 0)
			{
				s[i] = 1;
				dfs(i, 1);
				tt--;
			}
			else c[t[i]]--;
		}
	}
	printf("%d", minn);
	return 0;
}
