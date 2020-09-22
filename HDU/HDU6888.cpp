#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

struct SegmentTreeBeats
{
	int mn,smn,mncnt,lh,rh,lazy;
	long long X,_2Y,len;
	void init(int x)
	{
		mn=0;smn=~(1<<31);mncnt=0;
		lh=rh=0;len=x;X=0;_2Y=0;
		return ;
	}
	long long getAns()
	{
		return _2Y+(X<<1);
	}
};

SegmentTreeBeats tree[1<<20];
int T,n,m,l[MAXN],r[MAXN],h[MAXN],ori[MAXN<<1];
pair <int,int*> b[MAXN<<1];

inline void color(int u)
{
	tree[u].X=tree[u].len;tree[u].lazy=1;
	return ;
}

inline void raiseUp(int u,int v)
{
	if (v<=tree[u].mn) return ;
	tree[u].lh=max(tree[u].lh,v);tree[u].rh=max(tree[u].rh,v);
	tree[u]._2Y-=1LL*tree[u].mncnt*(v-tree[u].mn);
	tree[u].mn=v;
	return ;
}

inline void PushDownX(int u)
{
	if (!tree[u].lazy) return ;
	color(u<<1);color(u<<1|1);tree[u].lazy=0;
	return ;
}

inline void PushDownY(int u)
{
	raiseUp(u<<1,tree[u].mn);raiseUp(u<<1|1,tree[u].mn);
	return ;
}

inline void PushUp(int u)
{
	tree[u].mncnt=0;
	tree[u].lh=tree[u<<1].lh;tree[u].rh=tree[u<<1|1].rh;
	tree[u]._2Y=tree[u<<1]._2Y+tree[u<<1|1]._2Y+abs(tree[u<<1].rh-tree[u<<1|1].lh);
	tree[u].mn=min(tree[u<<1].mn,tree[u<<1|1].mn);
	tree[u].smn=min(tree[u<<1].smn,tree[u<<1|1].smn);
	if (tree[u<<1].mn!=tree[u<<1|1].mn)
		tree[u].smn=min(tree[u].smn,max(tree[u<<1].mn,tree[u<<1|1].mn));
	if (tree[u].mn==tree[u<<1].mn) tree[u].mncnt+=tree[u<<1].mncnt;
	if (tree[u].mn==tree[u<<1|1].mn) tree[u].mncnt+=tree[u<<1|1].mncnt;
	if (tree[u<<1].rh+tree[u<<1|1].lh!=tree[u].mn<<1)
		tree[u].mncnt+=(tree[u<<1].rh==tree[u].mn||tree[u<<1|1].lh==tree[u].mn);
	return ;
}

void BuildTree(int u,int l,int r)
{
	tree[u].lazy=tree[u].X=0;
	if (l+1==r)
	{
		tree[u].init(ori[r]-ori[l]);
		return ;
	}
	int m=l+r>>1;BuildTree(u<<1,l,m);BuildTree(u<<1|1,m,r);
	PushUp(u);
	tree[u].len=tree[u<<1].len+tree[u<<1|1].len;
	return ;
}

inline void modifyX(int u,int l,int r,int pl,int pr)
{
	if (pl==l&&pr==r){color(u);return ;}
	PushDownX(u);int m=pl+pr>>1;
	if (r<=m) modifyX(u<<1,l,r,pl,m);
	else if (m<=l) modifyX(u<<1|1,l,r,m,pr);
	else
	{
		modifyX(u<<1,l,m,pl,m);
		modifyX(u<<1|1,m,r,m,pr);
	}
	tree[u].X=tree[u<<1].X+tree[u<<1|1].X;
	return ;
}

inline void modifyY(int u,int l,int r,int v,int pl,int pr)
{
	if (v<=tree[u].mn) return ;
	if (pl==l&&pr==r&&v<tree[u].smn){raiseUp(u,v);return ;}
	if (pl+1==pr) return ;
	PushDownY(u);int m=pl+pr>>1;
	if (r<=m) modifyY(u<<1,l,r,v,pl,m);
	else if (m<=l) modifyY(u<<1|1,l,r,v,m,pr);
	else
	{
		modifyY(u<<1,l,m,v,pl,m);
		modifyY(u<<1|1,m,r,v,m,pr);
	}
	PushUp(u);
	return ;
}

inline void read(int &x)
{
	x=0;bool f=false;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=true;ch=getchar();}
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	if (f) x=-x;return ;
}

inline void Solve()
{
	read(n);m=0;
	for (int i=0;i<n;i++)
	{
		read(l[i]);read(r[i]);read(h[i]);
		b[i<<1]={l[i],&l[i]};b[i<<1|1]={r[i],&r[i]};
	}
	sort(b,b+(n<<1));
	for (int i=0,p=n<<1;i<p;i++)
	{
		if (!i||b[i].first!=b[i-1].first) ori[++m]=b[i].first;
		*b[i].second=m;
	}
	BuildTree(1,0,m+1);
	for (int i=0;i<n;i++)
	{
		modifyX(1,l[i],r[i],0,m+1);
		modifyY(1,l[i],r[i],h[i],0,m+1);
		printf("%lld\n",tree[1].getAns());
	}
	return ;
}

int main()
{
	scanf("%d",&T);
	while (T--) Solve();
	return 0;
}