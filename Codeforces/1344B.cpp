#include <bits/stdc++.h>
#define MAXN 1000005
#define MAXL 1005
using namespace std;

int n,m,f[MAXN],ans;
char s[MAXL][MAXL];
bool f1=true,f2=true,vis[MAXN];

inline int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
inline int getid(int x,int y){return (x-1)*m+y;}

inline void Merge(int x,int y)
{
	x=getf(x);y=getf(y);
	if (x!=y) f[y]=x;
	return ;
}

int main()
{
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n*m;i++) f[i]=i;
	for (int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for (int i=1;i<=n&&f1;i++)
	{
		bool f=false;
		for (int j=1;j<=m&&!f;j++) if (s[i][j]=='#') f=true;
		if (!f) f1=false;
	}
	for (int i=1;i<=m&&f2;i++)
	{
		bool f=false;
		for (int j=1;j<=n&&!f;j++) if (s[j][i]=='#') f=true;
		if (!f) f2=false;
	}
	if (f1^f2) return puts("-1"),0;
	for (int i=1;i<=n;i++)
	{
		int j=1;
		for (;j<=m;j++) if (s[i][j]=='#') break;
		for (++j;j<=m;j++) if (s[i][j]=='.') break;
		for (++j;j<=m;j++) if (s[i][j]=='#') break;
		if (j<=m) return puts("-1"),0;
	}
	for (int i=1;i<=m;i++)
	{
		int j=1;
		for (;j<=n;j++)
			if (s[j][i]=='#') break;
		for (++j;j<=n;j++)
			if (s[j][i]=='.') break;
		for (++j;j<=n;j++)
			if (s[j][i]=='#') break;
		if (j<=n) return puts("-1"),0;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
		{
			if (s[i][j]=='#'&&s[i-1][j]=='#')
				Merge(getid(i,j),getid(i-1,j));
			if (s[i][j]=='#'&&s[i][j-1]=='#')
				Merge(getid(i,j),getid(i,j-1));
		}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (s[i][j]=='#') vis[getf(getid(i,j))]=true;
	for (int i=1;i<=n*m;i++) ans+=vis[i];
	printf("%d\n",ans);
	return 0;
}