#include <bits/stdc++.h>
#define MAXN 20005
using namespace std;

int m,pos[MAXN];

struct query
{
	int l,r,t;
	bool operator < (const query &b)const{
		return pos[l]==pos[b.l]?r<b.r:l<b.l;
	}
};

query p[MAXN];
int T,n,q,phi[MAXN],cnt[MAXN],a[MAXN];
long long ans[MAXN],now;
vector <int> F[MAXN];

inline void init()
{
	int n=20000;
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j+=i)
			F[j].push_back(i);
	phi[1]=1;
	for (int i=2;i<=n;i++)
	{
		if (!phi[i]) phi[i]=i;
		else continue;
		for (int j=i;j<=n;j+=i)
		{
			if (!phi[j]) phi[j]=j;
			phi[j]=phi[j]/i*(i-1);
		}
	}
	return ;
}

inline void update(int x,int v)
{
	x=a[x];
	for (int i=0;i<F[x].size();i++)
	{
		if (!~v) --cnt[F[x][i]];
		now+=1LL*v*cnt[F[x][i]]*phi[F[x][i]];
		if (v==1) ++cnt[F[x][i]];
	}
	return ;
}

inline void Modui()
{
	int l=1,r=0;now=0;
	for (int i=1;i<=q;i++)
	{
		while (r<p[i].r) update(++r, 1);
		while (r>p[i].r) update(r--,-1);
		while (l<p[i].l) update(l++,-1);
		while (l>p[i].l) update(--l, 1);
		ans[p[i].t]=now;
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
	init();read(T);
	for (int TT=1;TT<=T;TT++)
	{
		printf("Case #%d:\n",TT);
		read(n);m=(int)sqrt(n);memset(cnt,0,sizeof cnt);
		for (int i=1;i<=n;i++) pos[i]=(i-1)/m+1,read(a[i]);
		read(q);
		for (int i=1;i<=q;i++) read(p[i].l),read(p[i].r),p[i].t=i;
		sort(p+1,p+q+1);
		Modui();
		for (int i=1;i<=q;i++) printf("%lld\n",ans[i]);
	}
	return 0;
}