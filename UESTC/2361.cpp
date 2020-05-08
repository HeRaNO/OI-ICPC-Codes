#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;

int n,ans,f[MAXN];

inline int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}
inline void add(int u,int v)
{
	int fx=getf(u),fy=getf(v);
	if (fx!=fy) f[fy]=fx;
	return ;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) f[i]=i;
	for (int i=1,x;i<=n;i++) scanf("%d",&x),add(i,x);
	for (int i=1;i<=n;i++) ans+=(getf(i)==i);
	printf("%d\n",ans);
	return 0;
}