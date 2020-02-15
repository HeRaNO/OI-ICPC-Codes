#include <bits/stdc++.h>
#define MAXN 500005
#define fi first
#define se second
using namespace std;

int n,T,l,r,a[MAXN],b[MAXN],t[MAXN];
long long s[MAXN],c[MAXN],d[MAXN],ans[MAXN],B[MAXN];
vector <pair<long long,int> > v;
vector <pair<pair<int,int>,int> > q[MAXN];

inline long long f(int x,long long y){return x?y:-y;}
inline int lowbit(int x){return x&-x;}
inline void modify(int x,long long v){for (;x<=n;x+=lowbit(x)) c[x]+=v;return ;}
inline long long query(int x){long long r=0;for (;x;x-=lowbit(x)) r+=c[x];return r;}
inline void add(int x){for (;x<=n;x+=lowbit(x)) ++t[x];return ;}
inline int count(int x){int r=0;for (;x;x-=lowbit(x)) r+=t[x];return r;}

inline void read(int &x)
{
	x=0;char ch=getchar();bool f=false;
	while (ch<'0'||ch>'9'){if (ch=='-') f=true;ch=getchar();}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	if (f) x=-x;return ;
}

int main()
{
	read(n);read(T);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<=n;i++)
	{
		read(b[i]);
		B[i]=B[i-1]+b[i];s[i]=s[i-1]+B[i];
		d[i]=d[i-1]+a[i]-b[i];
		v.push_back({d[i],i});
	}
	v.push_back({0,0});
	for (int i=1;i<=T;i++)
	{
		read(l);read(r);
		ans[i]=s[r]-s[l-1]-(r-l+1)*B[l-1]-(r-l+1)*d[l-1];
		q[l-1].push_back({{r,i},1});
		q[l-1].push_back({{l-1,i},0});
	}
	sort(v.begin(),v.end(),greater<pair<long long,int> >());
	for (auto x:v)
	{
		long long d=x.fi;int i=x.se;
		for (auto y:q[i])
			ans[y.fi.se]+=f(y.se,(y.fi.fi-count(y.fi.fi))*d+query(y.fi.fi));
		if (i) add(i),modify(i,d);
	}
	for (int i=1;i<=T;i++) printf("%lld\n",ans[i]);
	return 0;
}