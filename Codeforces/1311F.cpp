#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int c[MAXN];
long long d[MAXN],ans;
int n,m,x[MAXN],y[MAXN];
pair <int,int*> p[MAXN];
pair <int,int> a[MAXN];

inline int lowbit(int x){return x&-x;}
inline void add(int x){for (;x<=m;x+=lowbit(x)) ++c[x];return ;}
inline int count(int x){int r=0;for (;x;x-=lowbit(x)) r+=c[x];return r;}
inline void modify(int x,int v){for (;x<=m;x+=lowbit(x)) d[x]+=v;return ;}
inline long long query(int x){long long r=0;for (;x;x-=lowbit(x)) r+=d[x];return r;}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&x[i]);
	for (int i=1;i<=n;i++) scanf("%d",&y[i]);
	for (int i=1;i<=n;i++) a[i]={x[i],y[i]};
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++) p[i]={a[i].second,&a[i].second};
	sort(p+1,p+n+1);p[0].first=1<<31;
	for (int i=1;i<=n;i++)
	{
		if (p[i].first!=p[i-1].first) ++m;
		*p[i].second=m;
	}
	for (int i=1;i<=n;i++)
	{
		ans+=query(a[i].second)+1LL*count(a[i].second)*a[i].first;
		add(a[i].second);modify(a[i].second,-a[i].first);
	}
	printf("%lld\n",ans);
	return 0;
}