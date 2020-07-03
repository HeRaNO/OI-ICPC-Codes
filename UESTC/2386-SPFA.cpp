#include <bits/stdc++.h>
#define MAXN 500005
using namespace std;

vector <int> e[MAXN],g[MAXN];
int n,m,u,v,a[MAXN],in[MAXN],out[MAXN];
long long ans,ve[MAXN],vl[MAXN];
bool vis[MAXN];
queue <int> q;

inline void read(int &x)
{
	x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return ;
}

int main()
{
	read(n);read(m);memset(vl,0x3f,sizeof vl);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<=m;i++)
	{
		read(u);read(v);++out[u];++in[v];
		e[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i=1;i<=n;i++)
	{
		if (!in[i])
		{
			e[0].push_back(i);
			g[i].push_back(0);
		}
		if (!out[i])
		{
			e[i].push_back(n+1);
			g[n+1].push_back(i);
		}
	}
	q.push(0);
	while (!q.empty())
	{
		int u=q.front();q.pop();vis[u]=false;
		for (auto v:e[u])
			if (ve[v]<=ve[u]+a[u])
			{
				ve[v]=ve[u]+a[u];
				if (!vis[v]){q.push(v);vis[v]=true;}
			}
	}
	printf("%lld\n",ve[n+1]);
	memset(vis,false,sizeof vis);q.push(n+1);vl[n+1]=ve[n+1];
	while (!q.empty())
	{
		int u=q.front();q.pop();vis[u]=false;
		for (auto v:g[u])
			if (vl[v]>=vl[u]-a[v])
			{
				vl[v]=vl[u]-a[v];
				if (!vis[v]){q.push(v);vis[v]=true;}
			}
	}
	for (int i=1;i<=n;i++) ans+=vl[i]-ve[i];
	printf("%lld\n",ans);
	return 0;
}
