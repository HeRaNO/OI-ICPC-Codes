#include <bits/stdc++.h>
#define MAXN 500005
using namespace std;

const int INF=1e9;

struct SegmenTree
{
	int p,r,m,x;
};

SegmenTree tree[1<<20];
int T,n,m,a[MAXN],num[MAXN],op,x,y,las;

inline void BuildTree(int u)
{
	if (tree[u].p+1==tree[u].r){tree[u].x=num[tree[u].p];return ;}
	tree[u].m=tree[u].p+tree[u].r>>1;
	tree[u<<1].p=tree[u].p;tree[u<<1].r=tree[u].m;BuildTree(u<<1);
	tree[u<<1|1].p=tree[u].m;tree[u<<1|1].r=tree[u].r;BuildTree(u<<1|1);
	tree[u].x=max(tree[u<<1].x,tree[u<<1|1].x);
	return ;
}

inline void modify(int u,int x,int v)
{
	if (tree[u].p+1==tree[u].r)
	{
		tree[u].x=v;
		return ;
	}
	if (x<tree[u].m) modify(u<<1,x,v);
	else modify(u<<1|1,x,v);
	tree[u].x=max(tree[u<<1].x,tree[u<<1|1].x);
	return ;
}

inline int query(int u,int l,int r,int v)
{
	if (tree[u].x<=v) return -1;
	if (tree[u].p+1==tree[u].r) return tree[u].p;
	if (r<=tree[u].m) return query(u<<1,l,r,v);
	else if (tree[u].m<=l) return query(u<<1|1,l,r,v);
	else
	{
		int res=query(u<<1,l,tree[u].m,v);
		if (~res) return res;
		return query(u<<1|1,tree[u].m,r,v);
	}
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
	read(T);
	while (T--)
	{
		read(n);read(m);las=0;
		for (int i=1;i<=n;i++) read(a[i]),num[a[i]]=i;
		tree[1].p=1;tree[1].r=n+1;BuildTree(1);
		while (m--)
		{
			read(op);
			if(op==1)
			{
				read(x);x^=las;
				num[a[x]]=INF;
				modify(1,a[x],INF);
			}
			else
			{
				read(x);read(y);x^=las;y^=las;
				las=query(1,y,n+1,x);
				if (!~las) las=n+1;
				printf("%d\n",las);
			}
		}
	}
	return 0;
}
