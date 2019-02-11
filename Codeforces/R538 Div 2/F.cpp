#include <cstdio>
#include <algorithm>
using namespace std;

const long long P=1e9+7;

struct SegmentTree
{
	int p,r,m;
	long long mul,x,lazy,xl;
};

SegmentTree tree[1<<20];
int n,T,l,r,x,a[400010];
char o[100];
const long long c[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293};
const long long cc[]={500000004,666666672,600000005,857142864,181818184,846153853,647058829,842105270,260869568,241379313,870967749,378378382,341463418,604651168,595744686,943396234,949152550,311475413,313432839,901408458,589041101,797468361,915662658,584269668,731958769,59405942,427184470,775700941,990825696,106194692,519685044,809160312,941605847,395683457,469798662,516556296,656050961,883435590,994011984,208092488,564245815,66298344,560209429,305699485,30456854,492462316,909952614,874439469,964757717,288209610,909871252,719665278,593361001,87649404,929961097,163498101,256505579,549815503,747292425,281138793,349823325,477815704};

void BuildTree(int u)
{
	tree[u].lazy=1;
	if (tree[u].p+1==tree[u].r)
	{
		long long x=a[tree[u].p];long long p=x;
		for (int i=0;i<62;i++)
		{
			if (p==1) break;
			if (!(p%c[i]))
			{
				tree[u].x|=(1LL<<i);
				while (!(p%c[i])) p/=c[i];
			}
		}
		tree[u].mul=a[tree[u].p];
		return ;
	}
	tree[u].m=tree[u].p+tree[u].r>>1;
	tree[u<<1].p=tree[u].p;tree[u<<1].r=tree[u].m;BuildTree(u<<1);
	tree[u<<1|1].p=tree[u].m;tree[u<<1|1].r=tree[u].r;BuildTree(u<<1|1);
	tree[u].mul=(tree[u<<1].mul*tree[u<<1|1].mul)%P;
	tree[u].x=tree[u<<1].x|tree[u<<1|1].x;
	return ;
}

inline long long qpow(long long a,int b)
{
	long long r=1;
	for (;b;a=(a*a)%P,b>>=1) if (b&1) r=(r*a)%P;
	return r;
}

inline void PushDown(int u)
{
	if (tree[u].lazy==1&&tree[u].xl==0) return ;
	(tree[u<<1].mul*=qpow(tree[u].lazy,tree[u<<1].r-tree[u<<1].p))%=P;
	(tree[u<<1].lazy*=tree[u].lazy)%=P;
	tree[u<<1].x|=tree[u].xl;tree[u<<1].xl|=tree[u].xl;
	(tree[u<<1|1].mul*=qpow(tree[u].lazy,tree[u<<1|1].r-tree[u<<1|1].p))%=P;
	(tree[u<<1|1].lazy*=tree[u].lazy)%=P;
	tree[u<<1|1].x|=tree[u].xl;tree[u<<1|1].xl|=tree[u].xl;
	tree[u].lazy=1;tree[u].xl=0;
	return ;
}

void modify(int u,int l,int r,long long x)
{
	if (tree[u].p==l&&tree[u].r==r)
	{
		int cnt=0,p=x;
		for (int i=0;i<62;i++)
		{
			if (p==1) break;
			if (!(p%c[i]))
			{
				tree[u].x|=(1LL<<i);tree[u].xl|=(1LL<<i);
				while (!(p%c[i])) p/=c[i];
			}
		}
		(tree[u].mul*=qpow(x,r-l))%=P;
		(tree[u].lazy*=x)%=P;
		return ;
	}
	PushDown(u);
	if (r<=tree[u].m) modify(u<<1,l,r,x);
	else if (tree[u].m<=l) modify(u<<1|1,l,r,x);
	else
	{
		modify(u<<1,l,tree[u].m,x);
		modify(u<<1|1,tree[u].m,r,x);
	}
	tree[u].mul=(tree[u<<1].mul*tree[u<<1|1].mul)%P;
	tree[u].x=tree[u<<1].x|tree[u<<1|1].x;
	return ;
}

pair <long long,long long> query(int u,int l,int r)
{
	if (tree[u].p==l&&tree[u].r==r) return make_pair(tree[u].x,tree[u].mul);
	PushDown(u);
	if (r<=tree[u].m) return query(u<<1,l,r);
	else if (tree[u].m<=l) return query(u<<1|1,l,r);
	else
	{
		pair <long long,long long> a=query(u<<1,l,tree[u].m),b=query(u<<1|1,tree[u].m,r);
		return make_pair(a.first|b.first,a.second*b.second%P);
	}
}

int main()
{
	scanf("%d %d",&n,&T);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	tree[1].p=1;tree[1].r=n+1;BuildTree(1);
	while (T--)
	{
		scanf("%s",o);
		if (o[0]=='T')
		{
			scanf("%d %d",&l,&r);
			pair<long long,long long> x=query(1,l,r+1);
			for (int i=0;i<62;i++)
				if (x.first&(1LL<<i)) (x.second*=cc[i])%=P;
			printf("%I64d\n",x.second);
		}
		else
		{
			scanf("%d %d %d",&l,&r,&x);
			modify(1,l,r+1,x);
		}
	}
	return 0;
}