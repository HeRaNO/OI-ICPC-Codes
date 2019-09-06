#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

struct E
{
	int mn[10],smn[10];
	E operator + (const E &a)const{
		E res;
		for (int i=0;i<=9;i++)
		{
			res.mn[i]=min(mn[i],a.mn[i]);
			if (mn[i]<a.mn[i]) res.smn[i]=min(smn[i],a.mn[i]);
			else res.smn[i]=min(mn[i],a.smn[i]);
		}
		return res;
	}
	void init()
	{
		for (int i=0;i<=9;i++) mn[i]=smn[i]=0x3f3f3f3f;
		return ;
	}
};

struct SegmentTree
{
	int p,r,m;E x;
};

SegmentTree tree[1<<19];
int n,m,o,l,r,a[MAXN];

inline void BuildTree(int u)
{
	if (tree[u].p+1==tree[u].r)
	{
		int p=a[tree[u].p],l=p,cnt=0;
		tree[u].x.init();
		while (p)
		{
			if (p%10) tree[u].x.mn[cnt]=l;
			p/=10;++cnt;
		}
		return ;
	}
	tree[u].m=tree[u].p+tree[u].r>>1;
	tree[u<<1].p=tree[u].p;tree[u<<1].r=tree[u].m;BuildTree(u<<1);
	tree[u<<1|1].p=tree[u].m;tree[u<<1|1].r=tree[u].r;BuildTree(u<<1|1);
	tree[u].x=tree[u<<1].x+tree[u<<1|1].x;
	return ;
}

inline void modify(int u,int x,int v)
{
	if (tree[u].p+1==tree[u].r)
	{
		int p=v,l=v,cnt=0;
		tree[u].x.init();
		while (p)
		{
			if (p%10) tree[u].x.mn[cnt]=l;
			p/=10;++cnt;
		}
		return ;
	}
	if (x<tree[u].m) modify(u<<1,x,v);
	else modify(u<<1|1,x,v);
	tree[u].x=tree[u<<1].x+tree[u<<1|1].x;
	return ;
}

inline E query(int u,int l,int r)
{
	if (tree[u].p==l&&tree[u].r==r) return tree[u].x;
	if (r<=tree[u].m) return query(u<<1,l,r);
	else if (tree[u].m<=l) return query(u<<1|1,l,r);
	else return query(u<<1,l,tree[u].m)+query(u<<1|1,tree[u].m,r);
}

inline void read(int &x)
{
	x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return ;
}

int main(int argc, char const *argv[])
{
	read(n);read(m);
	for (int i=1;i<=n;i++) read(a[i]);
	tree[1].p=1;tree[1].r=n+1;BuildTree(1);
	while (m--)
	{
		read(o);read(l);read(r);
		if (o==1) modify(1,l,r);
		else
		{
			E res=query(1,l,r+1);
			int ans=~(1<<31);
			for (int i=0;i<=9;i++)
			{
				if (res.mn[i]==0x3f3f3f3f||res.smn[i]==0x3f3f3f3f) continue;
				ans=min(ans,res.mn[i]+res.smn[i]);
			}
			printf("%d\n",ans==~(1<<31)?-1:ans);
		}
	}
	return 0;
}