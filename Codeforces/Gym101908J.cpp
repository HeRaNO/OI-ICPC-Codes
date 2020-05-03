#include <bits/stdc++.h>
#define MAXN 105
using namespace std;

int n,k,x[MAXN],y[MAXN];
double f[MAXN][1<<10];
bool vis[MAXN];
queue <int> q;

inline double getDis(int u,int v)
{
	return sqrt((x[u]-x[v])*(x[u]-x[v])+(y[u]-y[v])*(y[u]-y[v]));
}

inline void SPFA(int u)
{
	while (!q.empty())
	{
		int x=q.front();q.pop();vis[x]=false;
		for (int i=k;i<n;i++)
		{
			if (i==x) continue;
			double d=getDis(i,x);
			if (f[i][u]>f[x][u]+d)
			{
				f[i][u]=f[x][u]+d;
				q.push(i);
			}
		}
	}
	return ;
}

int main()
{
	scanf("%d %d",&n,&k);
	for (int i=0;i<n;i++)
		for (int j=0;j<(1<<k);j++)
			f[i][j]=2147483647;
	for (int i=0;i<n;i++)
	{
		scanf("%d %d",&x[i],&y[i]);
		if (i<k) f[i][1<<i]=0;
	}
	for (int i=0;i<(1<<k);i++)
	{
		for (int x=0;x<n;x++)
		{
			for (int j=i;j;j=(j-1)&i)
				if (f[x][i]>f[x][j]+f[x][i-j])
					f[x][i]=f[x][j]+f[x][i-j];
			if (f[x][i]<2147483647) q.push(x),vis[x]=true;
		}
		SPFA(i);
	}
	double ans=2147483647;
	for (int i=k;i<n;i++) ans=min(ans,f[i][(1<<k)-1]);
	printf("%.5lf\n",ans);
	return 0;
}