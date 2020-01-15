#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;

const int _2019=2019;
const int _3[]={3,3,0,1,0};
const int _4[]={5,3,3,0,1};
const long long mod=2009731336725594113LL;
const long long _34[]={1,2006101093849356424,941391648911191089,1022292690726729920,1810419142002041716,1184285083219342236,1267651882537955420,1816515142381353759,1698479428772363217,1582534033367424005,1302320796828332778,1694849185896125529,510564102676783292,1256273799740659674,508098345173708939,1495536991172573131,742079454187638693,193216194344240354,2009731336725594112,3630242876237689,1068339687814403024,987438645998864193,199312194723552397,825446253506251877,1501632991551885174,514194345553020982,311251907953230896,427197303358170108,707410539897261335,314882150829468584,1499167234048810821,753457536984934439};

int n,T,l,r,las,t[32],p[2019][32];
int lazy[1<<21][2],x[1<<21][32];
long long _t34[MAXN][32];

inline void fadd(long long &a,long long b){a+=b;if (a>=mod) a-=mod;return ;}

void BuildTree(int u,int l,int r)
{
	if (l+1==r)
	{
		for (int i=0;i<32;i++) x[u][i]=_t34[l][i]%2019;
		return ;
	}
	int m=l+r>>1;BuildTree(u<<1,l,m);BuildTree(u<<1|1,m,r);
	for (int i=0;i<32;i++) x[u][i]=x[u<<1][i]+x[u<<1|1][i];
	return ;
}

inline void add(int u,int v,int w)
{
	for (int i=0,pt=0;i<4;i++)
		for (int j=0;j<8;j++)
			t[pt++]=x[u][(((i+v)&3)<<3)|((j+w+((i+v)&4))&7)];
	for (int i=0;i<32;i++) x[u][i]=t[i];
	lazy[u][0]+=v;(lazy[u][1]+=w)&=7;
	if (lazy[u][0]&4) (lazy[u][1]+=4)&=7,lazy[u][0]&=3;
	return ;
}

inline void PushDown(int u)
{
	if (!lazy[u][0]&&!lazy[u][1]) return ;
	add(u<<1,lazy[u][0],lazy[u][1]);
	add(u<<1|1,lazy[u][0],lazy[u][1]);
	lazy[u][0]=lazy[u][1]=0;
	return ;
}

void modify(int u,int l,int r,int v,int w,int pl,int pr)
{
	if (pl==l&&pr==r){add(u,v,w);return ;}
	PushDown(u);int m=pl+pr>>1;
	if (r<=m) modify(u<<1,l,r,v,w,pl,m);
	else if (m<=l) modify(u<<1|1,l,r,v,w,m,pr);
	else
	{
		modify(u<<1,l,m,v,w,pl,m);
		modify(u<<1|1,m,r,v,w,m,pr);
	}
	for (int i=0;i<32;i++) x[u][i]=x[u<<1][i]+x[u<<1|1][i];
	return ;
}

inline int query(int u,int l,int r,int pl,int pr)
{
	if (pl==l&&pr==r) return x[u][0];
	PushDown(u);int m=pl+pr>>1;
	if (r<=m) return query(u<<1,l,r,pl,m);
	else if (m<=l) return query(u<<1|1,l,r,m,pr);
	else return query(u<<1,l,m,pl,m)+query(u<<1|1,m,r,m,pr);
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
	read(n);read(T);
	for (int i=1;i<=n;i++)
		for (int j=0;j<32;j++)
		{
			_t34[i][j]=_t34[i-1][j]+_34[j];
			if (_t34[i][j]>=mod) _t34[i][j]-=mod;
		}
	BuildTree(1,1,n+1);
	while (T--)
	{
		read(l);read(r);printf("%d\n",las=query(1,l,r+1,1,n+1));las%=5;
		modify(1,l,r+1,_3[las],_4[las],1,n+1);
	}
	return 0;
}
