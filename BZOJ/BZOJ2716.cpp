#include <cstdio>
#include <algorithm>
#define MAXN 300005
#define MAXT 1000005
#define DM 2
#define INF ~(1<<31)
using namespace std;

int ND;

struct point
{
	int x[DM];
	bool operator < (const point &a)const {
		return x[ND]<a.x[ND];
	}
	inline int Dis(const point &a)const {
		int r=0;
		for (int i=0;i<DM;i++) r+=abs(x[i]-a.x[i]);
		return r;
	}
};

struct KDTree
{
	int lch, rch, siz;
	point P;int mx[DM],mn[DM];
	inline int MinDis(const point &p)const {
		int ans = 0;
		for (int i=0;i<DM;i++)
			ans+=max(0,p.x[i]-mx[i])+max(0,mn[i]-p.x[i]);
		return ans;
	}
};

point p[MAXN],t;
KDTree tree[MAXT];
int n,T,x,res,opt,pool[MAXT],top,tot,rt;

inline void PushUp(int x)
{
	int l=tree[x].lch,r=tree[x].rch;
	for (int i=0;i<DM;i++)
	{
		tree[x].mx[i]=tree[x].mn[i]=tree[x].P.x[i];
		if (l)
		{
			tree[x].mn[i]=min(tree[x].mn[i],tree[l].mn[i]);
			tree[x].mx[i]=max(tree[x].mx[i],tree[l].mx[i]);
		}
		if (r)
		{
			tree[x].mn[i]=min(tree[x].mn[i],tree[r].mn[i]);
			tree[x].mx[i]=max(tree[x].mx[i],tree[r].mx[i]);
		}
	}
	tree[x].siz=tree[l].siz+tree[r].siz+1;
	return ;
}

inline int newnode()
{
	if (top) return pool[top--];
	return ++tot;
}

inline int Build(int l,int r,int d)
{
	if (l>r) return 0;
	int k=newnode(),mid=l+r>>1;
	ND=d;nth_element(p+l,p+mid,p+r+1);tree[k].P=p[mid];
	tree[k].lch=Build(l,mid-1,(d+1)%DM);tree[k].rch=Build(mid+1,r,(d+1)%DM);
	PushUp(k);return k;
}

void flat(int x,int cnt)
{
	int l=tree[x].lch,r=tree[x].rch;
	if (l) flat(l,cnt);
	p[cnt+tree[l].siz+1]=tree[x].P;pool[++top]=x;
	if (r) flat(r,cnt+tree[l].siz+1);
}

const int alpha_a=2;
const int alpha_b=3;

void Rebuild(int &x,int d)
{
	int l=tree[x].lch,r=tree[x].rch;
	if (alpha_a*tree[x].siz<alpha_b*tree[l].siz||alpha_a*tree[x].siz<alpha_b*tree[r].siz)
		flat(x,0),x=Build(1,tree[x].siz,d);
	return ;
}

void add(int &x,int d)
{
	if (!x)
	{
		x=newnode();
		tree[x].P=t;tree[x].lch=tree[x].rch=0;PushUp(x);
		return ;
	}
	if (tree[x].P.x[d]<t.x[d]) add(tree[x].rch,(d+1)%DM);
	else add(tree[x].lch,(d+1)%DM);
	PushUp(x);Rebuild(x,d);
	return ;
}

inline void query(int u)
{
	res=min(res,tree[u].P.Dis(t));
	int ldis=tree[u].lch?tree[tree[u].lch].MinDis(t):INF;
	int rdis=tree[u].rch?tree[tree[u].rch].MinDis(t):INF;
	if (ldis<rdis)
	{
		if (tree[u].lch&&res>ldis) query(tree[u].lch);
		if (tree[u].rch&&res>rdis) query(tree[u].rch);
	}
	else
	{
		if (tree[u].rch&&res>rdis) query(tree[u].rch);
		if (tree[u].lch&&res>ldis) query(tree[u].lch);
	}
	return ;
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
	//freopen("angel.in","r",stdin);freopen("angel.out","w",stdout);
	read(n);read(T);
	for (int i=1;i<=n;i++) read(p[i].x[0]),read(p[i].x[1]);
	rt=Build(1,n,0);
	while (T--)
	{
		read(opt);read(t.x[0]);read(t.x[1]);
		if (opt==1) add(rt,0);
		else res=INF,query(rt),printf("%d\n",res);
	}
	return 0;
}