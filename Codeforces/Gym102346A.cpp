#include <cstdio>
#define MAXN 1005
using namespace std;

int n,m,k,f[MAXN],fx,fy,x[MAXN],y[MAXN],r[MAXN];
bool vis[MAXN][4];

inline int sqr(int a){return a*a;}

inline int dis(int i,int j)
{
	return sqr(x[i]-x[j])+sqr(y[i]-y[j]);
}

inline int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

inline void read(int &x)
{
	x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return ;
}

int main()
{
	read(m);read(n);read(k);
	for (int i=1;i<=k;i++) f[i]=i;
	for (int i=1;i<=k;i++) read(x[i]),read(y[i]),read(r[i]);
	for (int i=1;i<=k;i++)
		for (int j=i+1;j<=k;j++)
			if (dis(i,j)<=sqr(r[i]+r[j]))
			{
				fx=getf(i);fy=getf(j);
				if (fx!=fy) f[fy]=fx;
			}
	for (int i=1;i<=k;i++)
	{
		if (x[i]<=r[i]) vis[getf(i)][0]=true;
		if (y[i]<=r[i]) vis[getf(i)][1]=true;
		if (m-x[i]<=r[i]) vis[getf(i)][2]=true;
		if (n-y[i]<=r[i]) vis[getf(i)][3]=true;
	}
	for (int i=1;i<=k;i++)
	{
		if (vis[i][0]&&vis[i][1]) return puts("N"),0;
		if (vis[i][2]&&vis[i][3]) return puts("N"),0;
		if (vis[i][0]&&vis[i][2]) return puts("N"),0;
		if (vis[i][1]&&vis[i][3]) return puts("N"),0;
	}
	puts("S");
	return 0;
}
