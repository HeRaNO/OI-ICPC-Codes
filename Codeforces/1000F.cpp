#include <bits/stdc++.h>
#define MAXN 500010
using namespace std;

struct seg
{
	int l,r,id;
	bool operator < (const seg &a)const{
		return r<a.r;
	}
};

struct SegmentTree
{
	int p,r,m;
	pair<int,int> x;
};

SegmentTree tree[1<<20];
int n,q,l,r,a[MAXN],pre[MAXN],las[MAXN],p[MAXN];
vector <pair<int,int> > ans[MAXN];

void BuildTree(int u)
{
	if (tree[u].p+1==tree[u].r){tree[u].x=make_pair(~(1<<31),~(1<<31));return ;}
	tree[u].m=tree[u].p+tree[u].r>>1;
	tree[u<<1].p=tree[u].p;tree[u<<1].r=tree[u].m;BuildTree(u<<1);
	tree[u<<1|1].p=tree[u].m;tree[u<<1|1].r=tree[u].r;BuildTree(u<<1|1);
	tree[u].x=min(tree[u<<1].x,tree[u<<1|1].x);
	return ;
}

void modify(int u,int x,pair<int,int> v)
{
	if (tree[u].p+1==tree[u].r){tree[u].x=v;return ;}
	if (x<tree[u].m) modify(u<<1,x,v);
	else modify(u<<1|1,x,v);
	tree[u].x=min(tree[u<<1].x,tree[u<<1|1].x);
	return ;
}

pair <int,int> query(int u,int l,int r)
{
	if (tree[u].p==l&&tree[u].r==r) return tree[u].x;
	if (r<=tree[u].m) return query(u<<1,l,r);
	else if (tree[u].m<=l) return query(u<<1|1,l,r);
	else return min(query(u<<1,l,tree[u].m),query(u<<1|1,tree[u].m,r));
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
	read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<=n;i++)
	{
		pre[i]=las[a[i]];
		las[a[i]]=i;
	}
	tree[1].p=1;tree[1].r=n+1;BuildTree(1);
	read(q);
	for (int i=1;i<=q;i++)
	{
		read(l);read(r);
		ans[r].push_back(make_pair(l,i));
	}
	for (int i=1;i<=n;i++)
	{
		if (pre[i]) modify(1,pre[i],make_pair(~(1<<31),~(1<<31)));
		modify(1,i,make_pair(pre[i],a[i]));
		for (int pt=0;pt<ans[i].size();pt++)
		{
			pair<int,int> res=query(1,ans[i][pt].first,i+1);
			if (res.first<ans[i][pt].first) p[ans[i][pt].second]=res.second;
			else p[ans[i][pt].second]=0;
		}
	}
	for (int i=1;i<=q;i++) printf("%d\n",p[i]);
	return 0;
}