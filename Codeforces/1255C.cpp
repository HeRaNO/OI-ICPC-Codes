#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

vector <int> g[MAXN],ans;
int n,a,b,c,s,cnt[MAXN],in[MAXN];
queue <int> q;

inline void add(int a,int b)
{
	for (auto p:g[a]) if (p==b) return ;
	g[a].push_back(b);g[b].push_back(a);
	return ;
}

inline void BFS(int x)
{
	ans.push_back(x);
	for (auto v:g[x])
	{
		--in[v];
		if (cnt[v]==2) ans.push_back(v),q.push(v);
	}
	while (!q.empty())
	{
		int u=q.front();q.pop();
		for (auto v:g[u])
		{
			--in[v];
			if (in[v]==1&&cnt[v]>=3) ans.push_back(v),q.push(v);
		}
	}
	return ;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n-2;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		++cnt[a];++cnt[b];++cnt[c];
		++in[a];++in[b];++in[c];
		add(a,b);add(a,c);add(b,c);
	}
	for (int i=1;i<=n;i++)
		if (cnt[i]==1)
		{
			if (!s) s=i;
			else BFS(i);
		}
	for (auto i:g[s]) if (cnt[i]==2) ans.push_back(i);
	ans.push_back(s);
	for (auto i:ans) printf("%d ",i);puts("");
	return 0;
}