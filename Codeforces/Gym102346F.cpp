#include <bits/stdc++.h>
#define MAXN 10005
using namespace std;

struct SegmentTree
{
	int p,r,m,cnt;long long l;
};

struct Seg
{
	long long l,r,y,d;
	Seg(){}
	Seg(int _l,int _r,int _y,int _d):l(_l),r(_r),y(_y),d(_d){}
	bool operator < (const Seg &a)const{
		return y<a.y;
	}
}a[MAXN<<1];

SegmentTree tree[1<<18];
int x[MAXN<<1],ori[MAXN<<1];
int n,m,P,_x1[MAXN],_x2[MAXN],_1y1[MAXN],_y2[MAXN];
int _a,b,c,d;
long long S;
map <int,int> h;

void Build(int u)
{
	tree[u].cnt=0;tree[u].l=0LL;
	if (tree[u].p+1==tree[u].r) return ;
	tree[u].m=tree[u].p+tree[u].r>>1;
	tree[u<<1].p=tree[u].p;tree[u<<1].r=tree[u].m;Build(u<<1);
	tree[u<<1|1].p=tree[u].m;tree[u<<1|1].r=tree[u].r;Build(u<<1|1);
	return ;
}

inline void PushUp(int u)
{
	if (tree[u].cnt) tree[u].l=ori[tree[u].r]-ori[tree[u].p];
	else if (tree[u].p+1==tree[u].r) tree[u].l=0;
	else tree[u].l=tree[u<<1].l+tree[u<<1|1].l;
	return ;
}

void modify(int u,int l,int r,int v)
{
	if (tree[u].p==l&&tree[u].r==r)
	{
		tree[u].cnt+=v;
		PushUp(u);
		return ;
	}
	if (r<=tree[u].m) modify(u<<1,l,r,v);
	else if (tree[u].m<=l) modify(u<<1|1,l,r,v);
	else
	{
		modify(u<<1,l,tree[u].m,v);
		modify(u<<1|1,tree[u].m,r,v);
	}
	PushUp(u);
	return ;
}

inline bool check(int R)
{
	long long ans=0LL;x[0]=0;m=0;h.clear();
	for (int i=1;i<=n;i++)
	{
		int p,q,r,s;
		int lx=min(_x1[i],_x2[i])-R;
		int ly=min(_1y1[i],_y2[i])-R;
		int hx=max(_x1[i],_x2[i])+R;
		int hy=max(_1y1[i],_y2[i])+R;
		p=max(_a,lx);q=max(b,ly);
		r=min(c,hx);s=min(d,hy);
		a[(i<<1)-1]=Seg(min(p,r),max(p,r),min(q,s),1);
		a[i<<1]=Seg(min(p,r),max(p,r),max(q,s),-1);
		x[++x[0]]=p;x[++x[0]]=r;
	}
	sort(x+1,x+x[0]+1);
	sort(a+1,a+(n<<1)+1);
	h[x[1]]=++m;ori[m]=x[1];
	for (int i=2;i<=x[0];i++)
	{
		if (x[i]!=x[i-1]) ++m;
		h[x[i]]=m;ori[m]=x[i];
	}
	tree[1].p=1;tree[1].r=m;Build(1);
	for (int i=1;i<(n<<1);i++)
	{
		if (h[a[i].l]<h[a[i].r]) modify(1,h[a[i].l],h[a[i].r],a[i].d);
		ans+=tree[1].l*(a[i+1].y-a[i].y);
	}
	return ans*100>=S*P;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d %d %d %d",&_x1[i],&_1y1[i],&_x2[i],&_y2[i]);
	scanf("%d",&P);
	scanf("%d %d %d %d",&_a,&b,&c,&d);
	S=1LL*abs(c-_a)*abs(d-b);
	int l=1,r=100000,ans;
	while (l<=r)
	{
		int m=l+r>>1;
		if (check(m)){ans=m;r=m-1;}
		else l=m+1;
	}
	printf("%d\n",ans);
	return 0;
}
