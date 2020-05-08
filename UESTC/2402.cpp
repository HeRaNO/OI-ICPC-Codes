#include <bits/stdc++.h>
#define MAXN 100005
#define IT set<ChthollyTree>::iterator
using namespace std;

struct ChthollyTree
{
	int l,r;
	mutable int v;
	ChthollyTree(int L,int R=-1,int V=0):l(L),r(R),v(V){}
	bool operator < (const ChthollyTree& o) const {
		return l<o.l;
	}
};

set <ChthollyTree> s;
int n,m,a[MAXN];

IT split(int pos)
{
	IT it=s.lower_bound(ChthollyTree(pos));
	if (it!=s.end()&&it->l==pos) return it;
	--it;
	int L=it->l,R=it->r,V=it->v;
	s.erase(it);
	s.insert(ChthollyTree(L,pos-1,V));
	return s.insert(ChthollyTree(pos,R,V)).first;
}

int cnt(int l,int r,int v)
{
	int res=0;
	IT itr=split(r+1),itl=split(l);
	for (;itl!=itr;++itl) if (itl->v==v) res+=itl->r-itl->l+1;
	return res;
}

void assign_val(int l,int r,int val)
{
	IT itr=split(r+1),itl=split(l);
	s.erase(itl,itr);
	s.insert(ChthollyTree(l,r,val));
	return ;
}

inline void read(int &x)
{
	x=0;char ch=getchar();bool f=false;
	while (ch<'0'||ch>'9'){if (ch=='-') f=true;ch=getchar();}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	if (f) x=-x;return ;
}

int main()
{
	read(n);
	for (int i=1; i<=n; ++i)
	{
		read(a[i]);
		s.insert(ChthollyTree(i,i,a[i]));
	}
	read(m);
	s.insert(ChthollyTree(n+1,n+1,0));
	while (m--)
	{
		int l,r,v;
		read(l);read(r);read(v);
		printf("%d\n",r-l+1-cnt(l,r,v));
		assign_val(l,r,v);
	}
	return 0;
}