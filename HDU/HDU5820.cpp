#include <bits/stdc++.h>
#define MAXW 50010
#define MAXN 500010
using namespace std;

struct point
{
	int x,y;
	bool operator < (const point &a)const{
		if (x!=a.x) return x<a.x;
		return y<a.y;
	}
};

struct SegmentTree
{
	int p,r,m,x;
};

SegmentTree tree[1<<18];
point p[MAXN];
int n;

inline void BuildTree(int u)
{
	tree[u].x=0;
	if (tree[u].p+1==tree[u].r) return ;
	tree[u].m=tree[u].p+tree[u].r>>1;
	tree[u<<1].p=tree[u].p;tree[u<<1].r=tree[u].m;BuildTree(u<<1);
	tree[u<<1|1].p=tree[u].m;tree[u<<1|1].r=tree[u].r;BuildTree(u<<1|1);
	return ;
}

inline void modify(int u,int x,int v)
{
	if (tree[u].p+1==tree[u].r){tree[u].x=v;return ;}
	if (x<tree[u].m) modify(u<<1,x,v);
	else modify(u<<1|1,x,v);
	tree[u].x=max(tree[u<<1].x,tree[u<<1|1].x);
	return ;
}

inline int query(int u,int l,int r)
{
	if (l>=r) return 0;
	if (tree[u].p==l&&tree[u].r==r) return tree[u].x;
	if (r<=tree[u].m) return query(u<<1,l,r);
	else if (tree[u].m<=l) return query(u<<1|1,l,r);
	else return max(query(u<<1,l,tree[u].m),query(u<<1|1,tree[u].m,r));
}

int main()
{
	while (~scanf("%d",&n)&&n)
	{
		bool f=true;tree[1].p=1;tree[1].r=50001;BuildTree(1);
		for (int i=1;i<=n;i++) scanf("%d %d",&p[i].x,&p[i].y);
		sort(p+1,p+n+1);
		for (int l=1,r=0;l<=n&&f;l=r+1)
		{
			while (r<n&&p[l].x==p[r+1].x) ++r;
			for (int i=l;i<=r&&f;i++)
			{
				if (i>l&&p[i].y==p[i-1].y) continue;
				int x=i==l?1:p[i-1].y+1;
				int y=i==r?50000:p[i+1].y-1;
				int res=query(1,x,y+1);
				if (res>query(1,p[i].y,p[i].y+1)) f=false;
			}
			for (int i=l;i<=r&&f;i++) modify(1,p[i].y,p[i].x);
		}
		puts(f?"YES":"NO");
	}
	return 0;
}