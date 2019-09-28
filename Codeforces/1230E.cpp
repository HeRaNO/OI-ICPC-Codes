#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

const long long M=1e9+7;

struct link
{
	int to,nxt;
};

link e[MAXN<<1];
int head[MAXN],cnt;
int n,u,v;
long long ans,a[MAXN];
vector <pair<long long,int> > p[MAXN];

inline void add(int u,int v)
{
	e[cnt]=(link){v,head[u]};head[u]=cnt++;
	e[cnt]=(link){u,head[v]};head[v]=cnt++;
}

void dfs(int x,int f)
{
	p[x].push_back(make_pair(a[x],1));
	(ans+=a[x])%=M;
	for (auto i:p[f])
	{
		long long g=__gcd(a[x],i.first);
		(ans+=g*i.second%M)%=M;
		if (g==p[x].back().first) p[x].back().second+=i.second;
		else p[x].push_back(make_pair(g,i.second));
	}
	for (int i=head[x];~i;i=e[i].nxt)
		if (e[i].to!=f) dfs(e[i].to,x);
	return ;
}

int main()
{
	memset(head,-1,sizeof head);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (int i=1;i<n;i++) scanf("%d %d",&u,&v),add(u,v);
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}