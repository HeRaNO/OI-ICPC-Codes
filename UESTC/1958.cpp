#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int n,m,k,a,b,in[MAXN],d[MAXN];
vector<int> g[MAXN];
queue<int> q;

int main()
{
	memset(d,0x3f,sizeof d);
	scanf("%d %d %d",&n,&k,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d %d",&a,&b);
		g[a].push_back(b);++in[b];
	}
	for (int i=1;i<=n;i++) if (!in[i]) q.push(i),d[i]=1;
	while (!q.empty())
	{
		int u=q.front();q.pop();
		for (int v:g[u])
		{
			d[v]=min(d[v],d[u]+1);
			if (!--in[v]) q.push(v);
		}
	}
	printf("%d\n",d[k]);
	return 0;
}