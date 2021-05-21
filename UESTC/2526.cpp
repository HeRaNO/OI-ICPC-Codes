#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

const int C=50;
const long long msk=(1LL<<(C+1))-1;

int n,m,T=1,rt,in[MAXN],out[MAXN],lazy[1<<19];
long long x[1<<19];
vector <int> g[MAXN],v;
int cache[C+1];
unordered_map <int,int> mp;

inline void add(int x,int y)
{
	if (!x) v.push_back(y);
	else g[x].push_back(y);
	return ;
}

void dfs(int x)
{
	in[x]=T++;
	for (int v:g[x]) dfs(v);
	out[x]=T;
	return ;
}

inline void color(int u,int v)
{
	x[u]=1LL<<v;lazy[u]=v;
	return ;
}

inline void PushDown(int u)
{
	if (!~lazy[u]) return;
	color(u<<1,lazy[u]);color(u<<1|1,lazy[u]);lazy[u]=-1;
	return ;
}

inline void BuildTree(int u,int l,int r)
{
	lazy[u]=-1;x[u]=1;
	if (l+1==r) return;
	int m=l+r>>1;BuildTree(u<<1,l,m);BuildTree(u<<1|1,m,r);
	return ;
}

inline void modify(int u,int l,int r,int v,int pl,int pr)
{
	if (pl==l&&pr==r){color(u,v);return ;}
	int m=pl+pr>>1;PushDown(u);
	if (r<=m) modify(u<<1,l,r,v,pl,m);
	else if (m<=l) modify(u<<1|1,l,r,v,m,pr);
	else
	{
		modify(u<<1,l,m,v,pl,m);
		modify(u<<1|1,m,r,v,m,pr);
	}
	x[u]=x[u<<1]|x[u<<1|1];
	return ;
}

inline long long query(int u,int l,int r,int pl,int pr)
{
	if (pl==l&&pr==r) return x[u];
	int m=pl+pr>>1;PushDown(u);
	if (r<=m) return query(u<<1,l,r,pl,m);
	else if (m<=l) return query(u<<1|1,l,r,m,pr);
	else return query(u<<1,l,m,pl,m)|query(u<<1|1,m,r,m,pr);
}

inline int getLowestZero(long long x)
{
	long long s=x^msk;
	if (!s) return 0;
	return __builtin_ctzll(s);
}

inline int assignColor(int c)
{
	int col=mp[c];
	if (cache[col]!=c)
	{
		col=getLowestZero(x[1]);
		cache[col]=c;mp[c]=col;
	}
	return col;
}

int main()
{
	memset(cache,-1,sizeof cache);
	cache[0]=0;
	scanf("%d %d",&n,&m);
	for (int i=1,f;i<=n;i++) scanf("%d",&f),add(f,i);
	for (int rt:v) dfs(rt);
	BuildTree(1,1,n+1);
	for (int i=1;i<=m;i++)
	{
		int o,p,c;
		scanf("%d",&o);
		if (o==1)
		{
			scanf("%d %d",&p,&c);
			modify(1,in[p],out[p],assignColor(c),1,n+1);
		}
		else
		{
			scanf("%d",&p);
			printf("%d\n",__builtin_popcountll(query(1,in[p],out[p],1,n+1)));
		}
	}
	return 0;
}
