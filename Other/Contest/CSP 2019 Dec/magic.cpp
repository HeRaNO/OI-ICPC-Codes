#include <bits/stdc++.h>
using namespace std;

const int _2019=2019;
const int _3[]={3,3,0,1,0};
const int _4[]={5,3,3,0,1};
const long long mod=2009731336725594113LL;
const long long x[]={1,2006101093849356424,941391648911191089,1022292690726729920,1810419142002041716,1184285083219342236,1267651882537955420,1816515142381353759,1698479428772363217,1582534033367424005,1302320796828332778,1694849185896125529,510564102676783292,1256273799740659674,508098345173708939,1495536991172573131,742079454187638693,193216194344240354,2009731336725594112,3630242876237689,1068339687814403024,987438645998864193,199312194723552397,825446253506251877,1501632991551885174,514194345553020982,311251907953230896,427197303358170108,707410539897261335,314882150829468584,1499167234048810821,753457536984934439};

struct SegmentTree
{
	int p,r,m,lazy[2],x[32];
};

SegmentTree tree[1<<21];
int n,T,l,r,las,t[32],p[2019][32];

inline void fadd(long long &a,long long b){a+=b;if (a>mod) a-=mod;return ;}

void BuildTree(int u)
{
	if (tree[u].p+1==tree[u].r)
	{
		for (int i=0,a=tree[u].p%_2019;i<32;i++) tree[u].x[i]=p[a][i];
		return ;
	}
	tree[u].m=tree[u].p+tree[u].r>>1;
	tree[u<<1].p=tree[u].p;tree[u<<1].r=tree[u].m;BuildTree(u<<1);
	tree[u<<1|1].p=tree[u].m;tree[u<<1|1].r=tree[u].r;BuildTree(u<<1|1);
	for (int i=0;i<32;i++) tree[u].x[i]=tree[u<<1].x[i]+tree[u<<1|1].x[i];
	return ;
}

inline void add(int u,int v,int w)
{
	for (int i=0,pt=0;i<4;i++)
		for (int j=0;j<8;j++)
			t[pt++]=tree[u].x[(((i+v)&3)<<3)|((j+w+((i+v)&4))&7)];
	for (int i=0;i<32;i++) tree[u].x[i]=t[i];
	tree[u].lazy[0]+=v;(tree[u].lazy[1]+=w)&=7;
	if (tree[u].lazy[0]&4) (tree[u].lazy[1]+=4)&=7,tree[u].lazy[0]&=3;
	return ;
}

inline void PushDown(int u)
{
	if (!tree[u].lazy[0]&&!tree[u].lazy[1]) return ;
	add(u<<1,tree[u].lazy[0],tree[u].lazy[1]);
	add(u<<1|1,tree[u].lazy[0],tree[u].lazy[1]);
	tree[u].lazy[0]=tree[u].lazy[1]=0;
	return ;
}

void modify(int u,int l,int r,int v,int w)
{
	if (tree[u].p==l&&tree[u].r==r){add(u,v,w);return ;}
	PushDown(u);
	if (r<=tree[u].m) modify(u<<1,l,r,v,w);
	else if (tree[u].m<=l) modify(u<<1|1,l,r,v,w);
	else
	{
		modify(u<<1,l,tree[u].m,v,w);
		modify(u<<1|1,tree[u].m,r,v,w);
	}
	for (int i=0;i<32;i++) tree[u].x[i]=tree[u<<1].x[i]+tree[u<<1|1].x[i];
	return ;
}

inline int query(int u,int l,int r)
{
	if (tree[u].p==l&&tree[u].r==r) return tree[u].x[0];
	PushDown(u);
	if (r<=tree[u].m) return query(u<<1,l,r);
	else if (tree[u].m<=l) return query(u<<1|1,l,r);
	else return query(u<<1,l,tree[u].m)+query(u<<1|1,tree[u].m,r);
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
	for (int i=0;i<32;i++)
	{
		long long now=x[i];
		for (int j=1;j<2019;j++,fadd(now,x[i])) p[j][i]=now%_2019;
	}
	read(n);read(T);tree[1].p=1;tree[1].r=n+1;BuildTree(1);
	while (T--)
	{
		read(l);read(r);printf("%d\n",las=query(1,l,r+1));las%=5;
		modify(1,l,r+1,_3[las],_4[las]);
	}
	return 0;
}
