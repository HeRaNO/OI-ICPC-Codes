#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;

struct SegmentTree
{
	int p,r,m;int lazy,mx,mn;
};

SegmentTree tree[1<<21];
int n,pt=1;
string s;
char p[MAXN];

inline void BuildTree(int u)
{
	if (tree[u].p+1==tree[u].r) return ;
	tree[u].m=tree[u].p+tree[u].r>>1;
	tree[u<<1].p=tree[u].p;tree[u<<1].r=tree[u].m;BuildTree(u<<1);
	tree[u<<1|1].p=tree[u].m;tree[u<<1|1].r=tree[u].r;BuildTree(u<<1|1);
	return ;
}

inline void PushDown(int u)
{
	if (!tree[u].lazy) return ;
	tree[u<<1].lazy+=tree[u].lazy;
	tree[u<<1].mx+=tree[u].lazy;
	tree[u<<1].mn+=tree[u].lazy;
	tree[u<<1|1].lazy+=tree[u].lazy;
	tree[u<<1|1].mx+=tree[u].lazy;
	tree[u<<1|1].mn+=tree[u].lazy;
	tree[u].lazy=0;
	return ;
}

inline void modify(int u,int l,int r,int v)
{
	if (tree[u].p==l&&tree[u].r==r)
	{
		tree[u].lazy+=v;
		tree[u].mx+=v;tree[u].mn+=v;
		return ;
	}
	PushDown(u);
	if (r<=tree[u].m) modify(u<<1,l,r,v);
	else if (tree[u].m<=l) modify(u<<1|1,l,r,v);
	else
	{
		modify(u<<1,l,tree[u].m,v);
		modify(u<<1|1,tree[u].m,r,v);
	}
	tree[u].mx=max(tree[u<<1].mx,tree[u<<1|1].mx);
	tree[u].mn=min(tree[u<<1].mn,tree[u<<1|1].mn);
	return ;
}

inline int qmax(int u,int l,int r)
{
	if (tree[u].p==l&&tree[u].r==r) return tree[u].mx;
	PushDown(u);
	if (r<=tree[u].m) return qmax(u<<1,l,r);
	else if (tree[u].m<=l) return qmax(u<<1|1,l,r);
	else return max(qmax(u<<1,l,tree[u].m),qmax(u<<1|1,tree[u].m,r));
}

inline int qmin(int u,int l,int r)
{
	if (tree[u].p==l&&tree[u].r==r) return tree[u].mn;
	PushDown(u);
	if (r<=tree[u].m) return qmin(u<<1,l,r);
	else if (tree[u].m<=l) return qmin(u<<1|1,l,r);
	else return min(qmin(u<<1,l,tree[u].m),qmin(u<<1|1,tree[u].m,r));
}

int main()
{
	scanf("%d",&n);tree[1].p=1;tree[1].r=n+1;BuildTree(1);
	getline(cin,s);getline(cin,s);
	for (int i=0;i<n;i++)
	{
		if (s[i]=='R') ++pt;
		else if (s[i]=='L') pt=max(pt-1,1);
		else if (s[i]=='(')
		{
			if (p[pt]!='(')
			{
				if (p[pt]==')') modify(1,pt,n+1,2);
				else modify(1,pt,n+1,1);
				p[pt]='(';
			}
		}
		else if (s[i]==')')
		{
			if (p[pt]!=')')
			{
				if (p[pt]=='(') modify(1,pt,n+1,-2);
				else modify(1,pt,n+1,-1);
				p[pt]=')';
			}
		}
		else
		{
			if (p[pt]=='(') modify(1,pt,n+1,-1);
			if (p[pt]==')') modify(1,pt,n+1,1);
			p[pt]=s[i];
		}
		if (qmin(1,1,n+1)>=0&&qmin(1,n,n+1)==0)
			printf("%d ",qmax(1,1,n+1));
		else printf("-1 ");
	}
	puts("");
	return 0;
}