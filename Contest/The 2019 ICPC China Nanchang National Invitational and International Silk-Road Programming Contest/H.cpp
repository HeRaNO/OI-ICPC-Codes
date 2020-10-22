#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

const int N=1<<17;

struct ChthollyTree
{
	long long l,r;
	mutable int v;
	ChthollyTree(long long L,long long R=-1,int V=0):l(L),r(R),v(V){}
	bool operator < (const ChthollyTree& o) const {
		return l<o.l;
	}
};

int n,m,a[N],b[N];
long long l,r;
set <ChthollyTree> s;

inline void FWT(int c[],int n,int f)
{
	int x,y;
	for (int i=1;i<n;i<<=1)
		for (int p=i<<1,j=0;j<n;j+=p)
			for (int k=0;k<i;k++)
			{
				x=c[j+k];y=c[j+k+i];
				c[j+k+i]=y+x*f;
			}
	return ;
}

auto split(long long pos)
{
	auto it=s.lower_bound(ChthollyTree(pos));
	if (it!=s.end()&&it->l==pos) return it;
	--it;
	long long L=it->l,R=it->r;int V=it->v;
	s.erase(it);
	s.insert(ChthollyTree(L,pos-1,V));
	return s.insert(ChthollyTree(pos,R,V)).first;
}

int query(long long pos)
{
	auto it=s.lower_bound(ChthollyTree(pos));
	if (it!=s.end()&&it->l==pos) return it->v;
	--it;
	return it->v;
}

void change(int l,int r)
{
	auto itr=split(r+1),itl=split(l);
	int pre=-1;bool same=true;
	for (;itl!=itr;++itl)
	{
		itl->v=(int)sqrt(itl->v);
		if (~pre&&itl->v!=pre) same=false;
		pre=itl->v;
	}
	if (same)
	{
		itl=split(l);
		s.erase(itl,itr);
		s.insert(ChthollyTree(l,r,pre));
	}
	return ;
}

int main()
{
	scanf("%d",&n);
	for (int i=1,x;i<=n;i++) scanf("%d",&x),++a[x];
	for (int i=1,x;i<=n;i++) scanf("%d",&x),++b[x];
	FWT(a,N,1);FWT(b,N,1);
	for (int i=0;i<N;i++) a[i]*=b[i];
	FWT(a,N,-1);
	for (int i=0;i<N;i++)
	{
		if (!a[i]) continue;
		s.insert(ChthollyTree(l+1,l+a[i],i));
		l+=a[i];
	}
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%lld %lld",&l,&r);
		if (!l) printf("%d\n",query(r));
		else change(l,r);
	}
	return 0;
}