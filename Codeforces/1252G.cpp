#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=2e5+10,MAXM=2e7+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
#define lowbit(x) x&-x
const int inv2=5e8+4;

int sum[MAXN],r[MAXN],a[MAXN];
vector<int> v[MAXN];
int n,m,q;

int x[1<<18],lazy[1<<18];

inline void BuildTree(int u,int l,int R)
{
	if (l+1==R)
	{
		x[u]=n-r[l]-sum[l]-1;
		return ;
	}
	int m=l+R>>1;BuildTree(u<<1,l,m);BuildTree(u<<1|1,m,R);
	x[u]=min(x[u<<1],x[u<<1|1]);
	return ;
}

inline void add(int u,int v)
{
	x[u]+=v;lazy[u]+=v;
	return ;
}

inline void PushDown(int u)
{
	if (!lazy[u]) return ;
	add(u<<1,lazy[u]);add(u<<1|1,lazy[u]);
	lazy[u]=0;return ;
}

inline void modify(int u,int l,int r,int v,int pl,int pr)
{
	if (l==pl&&r==pr)
	{
		add(u,v);return ;
	}
	PushDown(u);int m=pl+pr>>1;
	if (r<=m) modify(u<<1,l,r,v,pl,m);
	else if (m<=l) modify(u<<1|1,l,r,v,m,pr);
	else
	{
		modify(u<<1,l,m,v,pl,m);
		modify(u<<1|1,m,r,v,m,pr);
	}
	x[u]=min(x[u<<1],x[u<<1|1]);
	return ;
}

int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum[1]+=a[i]>a[1];
	}
	for(int i=1;i<=m;i++)
	{
		sum[i]+=sum[i-1];
		scanf("%d",&r[i]);
		v[i].push_back(0);
		for(int j=1;j<=r[i];j++)
		{
			int p;
			scanf("%d",&p);
			v[i].push_back(p);
			sum[i+1]+=(p>a[1]);
		}
	}
	BuildTree(1,1,m+1);
	for(int i=1;i<=q;i++)
	{
		int X,y,z;
		scanf("%d%d%d",&X,&y,&z);
		if((v[X][y]>a[1])==(z>a[1])||X==m)
		{
			printf("%d\n",(int)(x[1]>=0));
			continue;
		}
		if(z<a[1])
		{
			v[X][y]=z;
			modify(1,X+1,m+1,1,1,m+1);
		}
		else
		{
			v[X][y]=z;
			modify(1,X+1,m+1,-1,1,m+1);
		}
		if(x[1]<0)puts("0");
		else puts("1");
	}
	return 0;
}
