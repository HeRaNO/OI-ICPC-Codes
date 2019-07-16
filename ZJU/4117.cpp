#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int n,T,ans;
int a[MAXN],c[MAXN],pre[MAXN],f[MAXN];

inline int lowbit(int x){return x&-x;}
inline void add(int x,int v){for (;x<=n;x+=lowbit(x)) c[x]+=v;return ;}
inline int query(int x){int r=0;for (;x;x-=lowbit(x)) r+=c[x];return r;}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		memset(c,0,sizeof c);memset(pre,0,sizeof pre);memset(f,0,sizeof f);ans=0;
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<=n;i++)
		{
			if (!pre[a[i]]) add(i,1);
			else
			{
				add(i,1);add(pre[a[i]],-1);
				++f[query(i)-query(pre[a[i]]-1)];
			}
			pre[a[i]]=i;
		}
		for (int i=1;i<=n;i++) ans+=f[i],printf("%d%c",n-ans,i==n?'\n':' ');
	}
	return 0;
}
