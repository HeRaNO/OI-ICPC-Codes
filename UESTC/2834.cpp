#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

struct node
{
	int l,r,ls,rs,x;
	node(){}
	node(int _,int __):l(_),r(__),ls(0),rs(0),x(0){}
}tr[MAXN*20];

int n,m,tot,T,l,r,x;
int a[MAXN],ori[MAXN],rt[MAXN];
vector <pair<int,int*> > v;

inline int Build(int l,int r)
{
	int p=++tot;tr[p]=node(l,r);
	if (l==r) return p;
	int m=l+r>>1;
	tr[p].ls=Build(l,m);tr[p].rs=Build(m+1,r);
	return p;
}

int add(int x,int now)
{
	int p=++tot;tr[p]=tr[now];++tr[p].x;
	if (tr[p].l==tr[p].r) return p;
	int m=tr[p].l+tr[p].r>>1;
	if (x<=m) tr[p].ls=add(x,tr[p].ls);
	else tr[p].rs=add(x,tr[p].rs);
	return p;
}

inline int query(int ls,int rs,int k,int pl,int pr)
{
	if (pl==pr) return pl;
	int x=tr[tr[rs].ls].x-tr[tr[ls].ls].x;
	int m=pl+pr>>1;
	if (k<=x) return query(tr[ls].ls,tr[rs].ls,k,pl,m);
	else return query(tr[ls].rs,tr[rs].rs,k-x,m+1,pr);
}

int main()
{
	scanf("%d",&n);v.push_back({-1,NULL});
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),v.push_back({a[i],&a[i]});
	sort(v.begin(),v.end());
	for (int i=1;i<=n;i++)
	{
		if (v[i].first!=v[i-1].first) ori[++T]=v[i].first;
		*v[i].second=T;
	}
	rt[0]=Build(1,T);
	for (int i=1;i<=n;i++) rt[i]=add(a[i],rt[i-1]);
	scanf("%d",&m);
	while (m--)
	{
		scanf("%d %d",&l,&r);
		int x=r-l+1;
		if (x<3) puts("-1");
		else
		{
			bool f=false;
			unsigned a=ori[query(rt[l-1],rt[r],x,1,T)];--x;
			unsigned b=ori[query(rt[l-1],rt[r],x,1,T)];--x;
			for (;x&&!f;--x)
			{
				unsigned c=ori[query(rt[l-1],rt[r],x,1,T)];
				if (b+c>a)
				{
					printf("%u\n",a+b+c);
					f=true;
				}
				a=b;b=c;
			}
			if (!f) puts("-1");
		}
	}
	return 0;
}
