#include <bits/stdc++.h>
#define MAXN 300010
using namespace std;

int T,n,m,u,v,ans[MAXN];
bool a[MAXN];

inline void read(int &x)
{
	x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return ;
}

int main()
{
	read(T);
	while (T--)
	{
		memset(a,0,sizeof a);
		read(n);read(m);ans[0]=0;
		for (int i=1;i<=m;i++)
		{
			read(u);read(v);
			if (a[u]||a[v]) continue;
			a[u]=true;a[v]=true;
			ans[++ans[0]]=i;
		}
		if (ans[0]>=n) puts("Matching");
		else
		{
			puts("IndSet");ans[0]=0;
			for (int i=1;i<=3*n;i++)
			{
				if (a[i]) continue;
				ans[++ans[0]]=i;
				if (ans[0]==n) break;
			}
		}
		for (int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');
	}
	return 0;
}