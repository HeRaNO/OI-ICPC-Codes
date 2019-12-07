#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

const long long M=998244353;

struct SegmentTree
{
	int p,r,m;
	long long x,lazy;
};

SegmentTree tree[1<<19];
int n,T,x,l,r;
long long inv[105],a[MAXN],ia[MAXN];
set <int> s;
set <int> :: iterator it;

inline long long fpow(long long a)
{
	long long r=1,b=M-2;
	for (;b;b>>=1,(a*=a)%=M) if (b&1) (r*=a)%=M;
	return r;
}

void BuildTree(int u)
{
	tree[u].lazy=1;
	if (tree[u].p+1==tree[u].r){tree[u].x=a[tree[u].p];return ;}
	tree[u].m=tree[u].p+tree[u].r>>1;
	tree[u<<1].p=tree[u].p;tree[u<<1].r=tree[u].m;BuildTree(u<<1);
	tree[u<<1|1].p=tree[u].m;tree[u<<1|1].r=tree[u].r;BuildTree(u<<1|1);
	tree[u].x=(tree[u<<1].x+tree[u<<1|1].x)%M;
	return ;
}

inline void PushDown(int u)
{
	if (tree[u].lazy==1) return ;
	(tree[u<<1].x*=tree[u].lazy)%=M;
	(tree[u<<1].lazy*=tree[u].lazy)%=M;
	(tree[u<<1|1].x*=tree[u].lazy)%=M;
	(tree[u<<1|1].lazy*=tree[u].lazy)%=M;
	tree[u].lazy=1;return ;
}

inline void modify(int u,int l,int r,long long v)
{
	if (tree[u].p==l&&tree[u].r==r)
	{
		(tree[u].x*=v)%=M;(tree[u].lazy*=v)%=M;
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
	tree[u].x=(tree[u<<1].x+tree[u<<1|1].x)%M;
	return ;
}

int main()
{
	inv[1]=1;for (int i=2;i<=100;i++) inv[i]=(M-M/i)*inv[M%i]%M;
	scanf("%d %d",&n,&T);s.insert(1);a[n+1]=1;ia[n+1]=1;
	for (int i=1;i<=n;i++) scanf("%d",&x),a[i]=100LL*inv[x]%M;
	for (int i=n;i;i--) (a[i]*=a[i+1])%=M,ia[i]=fpow(a[i]);
	tree[1].p=1;tree[1].r=n+1;BuildTree(1);
	while (T--)
	{
		scanf("%d",&x);it=s.find(x);
		if (it==s.end())
		{
			s.insert(x);it=s.find(x);--it;
			l=*it;++it;++it;
			if (it==s.end()) r=n+1;
			else r=*it;
			modify(1,l,x,fpow(a[x]*ia[r]%M));
		}
		else
		{
			--it;l=*it;++it;++it;
			if (it==s.end()) r=n+1;
			else r=*it;
			modify(1,l,x,a[x]*ia[r]%M);
			s.erase(x);
		}
		printf("%lld\n",tree[1].x);
	}
	return 0;
}