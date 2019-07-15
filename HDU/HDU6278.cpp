#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

namespace SegmentTree
{
	struct node
	{
		int l,r,ls,rs,x;
	}tr[MAXN*40];

	int rt[MAXN],tot;

	int build(int ll,int rr)
	{
		int p=++tot;tr[p].l=ll;tr[p].r=rr;tr[p].x=0;
		if (ll==rr) return p;
		int m=ll+rr>>1;
		tr[p].ls=build(ll,m);tr[p].rs=build(m+1,rr);
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

	int query(int ls,int rs,int ll,int rr,int k)
	{
		if (ll==rr) return ll;
		int cnt=tr[tr[rs].rs].x-tr[tr[ls].rs].x+k;
		int m=ll+rr>>1;
		if (cnt<=m) return query(tr[ls].ls,tr[rs].ls,ll,m,cnt);
		else return query(tr[ls].rs,tr[rs].rs,m+1,rr,k);
	}
}

int n,q,l,r,x;

int main()
{
	using namespace SegmentTree;
	while (~scanf("%d %d",&n,&q))
	{
		tot=0;rt[0]=build(1,n);
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			rt[i]=add(x,rt[i-1]);
		}
		while (q--)
		{
			scanf("%d %d",&l,&r);
			printf("%d\n",query(rt[l-1],rt[r],1,n,0));
		}
	}
	return 0;
}
