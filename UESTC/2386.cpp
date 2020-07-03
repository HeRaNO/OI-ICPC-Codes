#include <bits/stdc++.h>
#define MAXN 500005
using namespace std;

vector <int> e[MAXN],g[MAXN];
int n,m,u,v,a[MAXN],in[MAXN],out[MAXN],sta[MAXN],top;
long long ans,ve[MAXN],vl[MAXN];

inline void chkmax(long long &a,long long b){if (a<b) a=b;return ;}
inline void chkmin(long long &a,long long b){if (a>b) a=b;return ;}

inline void TopoPos()
{
	for (int i=1;i<=n;i++) if (!in[i]) sta[++top]=i;
	for (int x;top;)
		for (auto v:e[x=sta[top--]])
		{
			if (!--in[v]) sta[++top]=v;
			chkmax(ve[v],ve[x]+a[x]);
		}
	for (int i=1;i<=n;i++) chkmax(ans,ve[i]+a[i]);
	return ;
}

inline void TopoNeg()
{
	for (int i=1;i<=n;i++) if (!out[i]) sta[++top]=i,vl[i]=ans-a[i];
	for (int x;top;)
		for (auto v:g[x=sta[top--]])
		{
			if (!--out[v]) sta[++top]=v;
			chkmin(vl[v],vl[x]-a[v]);
		}
	ans=0;for (int i=1;i<=n;i++) ans+=vl[i]-ve[i];
	return ;
}

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
		read(u);read(v);++in[v];++out[u];
		e[u].push_back(v);g[v].push_back(u);
	}
	TopoPos();printf("%lld\n",ans);
	TopoNeg();printf("%lld\n",ans);
	return 0;
}