#include <bits/stdc++.h>
#define MAXN 200005
#define MAXM 1000005
#define fi first
#define se second
using namespace std;

const int M=1e9+7;

int n,m,l,r,a[MAXN],ans[MAXN],c[MAXN],mul[MAXN],imul[MAXN];
int tot,prime[MAXM],inv[MAXM],las[MAXM];
bool not_prime[MAXM];
vector <pair<int,int> > q[MAXN];
vector <int> f[MAXM];

inline int fpow(int a,int b)
{
	int r=1;
	for (;b;b>>=1,a=1LL*a*a%M) if (b&1) r=1LL*r*a%M;
	return r;
}

inline int lowbit(int x){return x&-x;}
inline void modify(int x,int v){for (;x<=n;x+=lowbit(x)) c[x]=1LL*c[x]*v%M;return ;}
inline int query(int x){int r=1;for (;x;x-=lowbit(x)) r=1LL*r*c[x]%M;return r;}
inline int query(int l,int r){return 1LL*query(r)*fpow(query(l-1),M-2)%M;}
inline int prod(int l,int r){return 1LL*mul[r]*imul[l-1]%M;}

inline void LinearShaker(int n=1000000)
{
	for (int i=2;i<=n;i++)
	{
		if (!not_prime[i]) prime[++tot]=i;
		for (int j=1;i*prime[j]<=n;j++)
		{
			not_prime[i*prime[j]]=true;
			if (!(i%prime[j])) break;
		}
	}
	inv[1]=1;
	for (int i=2;i<=n;i++) inv[i]=1LL*(M-M/i)*inv[M%i]%M;
	return ;
}

inline void fac(int x)
{
	int p=x;if (f[x].size()) return ;
	for (int i=1;prime[i]*prime[i]<=x;i++)
		if (!(x%prime[i]))
		{
			f[p].push_back(prime[i]);
			while (!(x%prime[i])) x/=prime[i];
		}
	if (x>1) f[p].push_back(x);
	return ;
}

inline void add(int x)
{
	for (auto v:f[a[x]])
	{
		if (las[v]) modify(las[v],1LL*v*inv[v-1]%M);
		modify(x,1LL*(v-1)*inv[v]%M);
		las[v]=x;
	}
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
	LinearShaker();read(n);mul[0]=imul[0]=1;
	for (int i=1;i<=n;i++)
	{
		read(a[i]),fac(a[i]),c[i]=1;
		mul[i]=1LL*mul[i-1]*a[i]%M;
		imul[i]=1LL*imul[i-1]*inv[a[i]]%M;
	}
	read(m);
	for (int i=1;i<=m;i++)
	{
		read(l);read(r);
		q[r].push_back({l,i});
	}
	for (int i=1;i<=n;i++)
	{
		add(i);
		for (auto v:q[i])
			ans[v.se]=1LL*prod(v.fi,i)*query(v.fi,i)%M;
	}
	for (int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}
