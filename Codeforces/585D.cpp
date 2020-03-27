#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
#define lowbit(x) x&-x
#define pb push_back
#define ls (id<<1)
#define rs (id<<1|1)
#define Rint register int
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=5e5+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;
const int inv2=5e8+4;

struct Node
{
	int a[3];
	ll st,val;
	bool operator < (const Node &rhs)const
	{
		for(int i=0;i<2;i++)if(a[i]!=rhs.a[i])return a[i]<rhs.a[i];
		return a[2]<rhs.a[2];
	}
};

map<Node,Node>mp;
int n;
ll _3[50];

inline ll ksm(ll x,ll v)
{
	return _3[v];
}

ll a[MAXN][3];

void dfs(Node cur,int u,int dep)
{
	if(dep+1==u)
	{
		if(mp.find(cur)==mp.end())mp[cur]=cur;
		else if(mp[cur].val<cur.val)mp[cur]=cur;
		return;
	}
	for(int i=0;i<3;i++)
	for(int j=i+1;j<3;j++)
	{
		int p;
		if(i==1&&j==2)p=0;
		else if(i==0&&j==2)p=1;
		else p=2;
		Node tmp=cur;
		tmp.st+=ksm(3,u)*p;
		for(int k=0;k<3;k++)
		if(k==i||k==j)tmp.a[k]+=a[u][k];
		int minn=INF;
		for(int k=0;k<3;k++)minn=min(minn,tmp.a[k]);
		for(int k=0;k<3;k++)tmp.a[k]-=minn;
		tmp.val+=minn;
		dfs(tmp,u+1,dep);
	}
}

ll mx=-INF,id;

void dfs1(Node cur,int u,int dep)
{
	if(dep+1==u)
	{
		Node c;int maxn=0;
		for(int i=0;i<3;i++)maxn=max(maxn,cur.a[i]);
		for(int i=0;i<3;i++)c.a[i]=maxn-cur.a[i];
		if(mp.find(c)==mp.end())return;
		c=mp[c];
		if(cur.a[0]+c.a[0]+cur.val+c.val>mx)
		{
			mx=cur.a[0]+c.a[0]+cur.val+c.val;
			id=c.st+cur.st;
		}
		return;
	}
	for(int i=0;i<3;i++)
	for(int j=i+1;j<3;j++)
	{
		int p;
		if(i==1&&j==2)p=0;
		else if(i==0&&j==2)p=1;
		else p=2;
		Node tmp=cur;
		tmp.st+=ksm(3,u)*p;
		for(int k=0;k<3;k++)
		if(k==i||k==j)tmp.a[k]+=a[u][k];
		int minn=INF;
		for(int k=0;k<3;k++)minn=min(minn,tmp.a[k]);
		for(int k=0;k<3;k++)tmp.a[k]-=minn;
		tmp.val+=minn;
		dfs1(tmp,u+1,dep);
	}
}

Node tmp1,tmp2;

int main()
{
	_3[0]=1;
	for (int i=1;i<=25;i++) _3[i]=_3[i-1]*3LL;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)scanf("%lld",&a[i][j]);
	}
	if (n==1)
	{
		if (a[0][0]==a[0][1]) return puts("LM"),0;
		if (a[0][0]==a[0][2]) return puts("LW"),0;
		if (a[0][1]==a[0][2]) return puts("MW"),0;
		return puts("Impossible"),0;
	}
	dfs(tmp1,0,n/2-1);
	dfs1(tmp2,n/2,n-1);
	if(mx==-INF)return puts("Impossible"),0;
	for(int i=0;i<n;i++)
	{
		int now=id%3;id/=3;
		if(now==0)puts("MW");
		else if(now==1)puts("LW");
		else puts("LM");
	}
	return 0;
}