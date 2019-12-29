#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;

struct link
{
	int to, nxt;
};

link e[MAXN];
int n, T, x, scc_cnt, top, cas;
int head[MAXN], cnt;
int dfn[MAXN], low[MAXN], sta[MAXN];
bool vis[MAXN];
vector <int> ans[MAXN];

inline void add(int u, int v)
{
	e[cnt] = (link)
	{
		v, head[u]
	};
	head[u] = cnt++;
}

inline void Tarjan(int x)
{
	dfn[x] = low[x] = ++T; sta[++top] = x;
	for (int i = head[x]; ~i; i = e[i].nxt)
	{
		if (vis[e[i].to]) continue;
		if (dfn[e[i].to]) low[x] = min(low[x], dfn[e[i].to]);
		else
		{
			Tarjan(e[i].to);
			low[x] = min(low[x], low[e[i].to]);
		}
	}
	if (dfn[x] == low[x])
	{
		int t;
		scc_cnt++;
		do {
			t = sta[top--];
			vis[t] = true;
			ans[scc_cnt].push_back(t);
		} while (t != x);
	}
	return ;
}

int main()
{
	scanf("%d",&cas);
	while (cas--)
	{
		scanf("%d",&n);bool f=false;
		memset(head, -1, (n+5)<<2);cnt=0;
		scc_cnt=0;T=0;top=0;
		for (int i=1;i<=n;i++)
		{
			dfn[i]=0;low[i]=0;vis[i]=false;
			scanf("%d",&x);
			if (!x&&!f)
			{
				printf("1\n%d\n",i);
				f=true;
			}
			add(i,i-x);
		}
		if (!f)
		{
			for (int i=1;i<=n;i++) if (!dfn[i]) Tarjan(i);
			for (int i=1;i<=scc_cnt;i++)
				if (ans[i].size()>1)
				{
					printf("%d\n",ans[i].size());
					for (int j=0;j<ans[i].size();j++)
						printf("%d%c",ans[i][j],j+1==ans[i].size()?'\n':' ');
					break;
				}
		}
		for (int i=1;i<=scc_cnt;i++) ans[i].clear();
	}
	return 0;
}