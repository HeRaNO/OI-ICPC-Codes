#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x.begin(),x.end())
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=6e5+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;

int n,m,a[MAXM],dis[MAXM];
int getdix(int x,int y)
{
	return x*m+y;
}

vector<int> v;
int bx[MAXM],by[MAXM],fa[MAXM];
vector<int> p[MAXM],q[MAXM];
vector<int> f[MAXM];

int _find(int x)
{
	return fa[x]^x?fa[x]=_find(fa[x]):fa[x];
}

bool cmp(int p,int q)
{
	return a[p]<a[q];
}

void unite(int u,int v)
{
	u=_find(u),v=_find(v);
	fa[u]=v;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n*m;i++)fa[i]=i;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			scanf("%d",&a[getdix(i,j)]);
			p[i].push_back(getdix(i,j));
			q[j].push_back(getdix(i,j));
		}
	for(int i=0;i<n;i++)sort(p[i].begin(),p[i].end(),cmp);
	for(int i=0;i<m;i++)sort(q[i].begin(),q[i].end(),cmp);
	for(int i=0;i<n;i++)
		for(int j=1;j<SZ(p[i]);j++)
			if(a[p[i][j]]==a[p[i][j-1]])unite(p[i][j],p[i][j-1]);
	for(int i=0;i<m;i++)
		for(int j=1;j<SZ(q[i]);j++)
			if(a[q[i][j]]==a[q[i][j-1]])unite(q[i][j],q[i][j-1]);
	for(int i=0;i<n*m;i++)v.push_back(_find(i));
	sort(v.begin(),v.end());
	v.resize(unique(v.begin(),v.end())-v.begin());
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<n*m;i++)
	{
		f[_find(i)].push_back(i);
	}
	for(auto i:v)
	{
		int maxn=1;
		for(auto j:f[i])
		{
			maxn=max(maxn,bx[j/m]+1);
			maxn=max(maxn,by[j%m]+1);
		}
		for(auto j:f[i])
		{
			dis[j]=maxn;
			bx[j/m]=maxn;
			by[j%m]=maxn;
		}
	}
	for(int i=0;i<n;i++,puts(""))
		for(int j=0;j<m;j++)
			printf("%d ",dis[_find(getdix(i,j))]);
	return 0;
}
