#include <queue>
#include <cstdio>
#define MAXN 1000010
using namespace std;

struct SegmentTree{int p,r,m;long long x;};

SegmentTree tree[1<<21];

int T,_P,h=1,t=0,opt,x;long long P;

void BuildTree(int x)
{
	if (tree[x].p+1==tree[x].r) return ;
	tree[x].m=tree[x].p+tree[x].r>>1;
	tree[x<<1].p=tree[x].p;tree[x<<1].r=tree[x].m;BuildTree(x<<1);
	tree[x<<1|1].p=tree[x].m;tree[x<<1|1].r=tree[x].r;BuildTree(x<<1|1);
	return ;
}

void modify(int u,int x,long long v)
{
	if (tree[u].p+1==tree[u].r){tree[u].x=v;return ;}
	if (x<tree[u].m) modify(u<<1,x,v);
	else modify(u<<1|1,x,v);
	tree[u].x=(tree[u<<1].x*tree[u<<1|1].x)%P;
	return ;
}

long long query(int u,int l,int r)
{
	if (tree[u].p==l&&tree[u].r==r) return tree[u].x;
	if (r<=tree[u].m) return query(u<<1,l,r);
	else if (tree[u].m<=l) return query(u<<1|1,l,r);
	else return (query(u<<1,l,tree[u].m)*query(u<<1|1,tree[u].m,r))%P;
}

inline void read(int &x)
{
	x=0;char ch=getchar();
	while (ch<'0'||ch>'9')
	{
		if (ch=='+'){x=1;return ;}
		if (ch=='-'){x=0;return ;}
		if (ch=='?'){x=2;return ;}
		ch=getchar(); 
	}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return ;
}

int main()
{
	read(T);read(_P);P=_P;
	tree[1].p=1;tree[1].r=T+1;BuildTree(1);
	while (T--)
	{
		read(opt);
		if (!opt) ++h;
		else if (opt==1)
		{
			read(x);modify(1,++t,x);
		}
		else
		{
			if (h<=t) printf("%lld\n",query(1,h,t+1));
			else puts("0");
		}
	}
	return 0;
}