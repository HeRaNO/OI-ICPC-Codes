#include <bits/stdc++.h>
#define MAXN 26
using namespace std;

int n,k,m;
long long s,a[MAXN],ans;
map <long long,long long> mp[MAXN];

long long f(long long x){return (x*(x+1))>>1;}

void dfs1(int x,int r,long long p)
{
	if (r>k) return ;
	if (p>s) return ;
	if (x==m+1)
	{
		if (mp[r].find(p)==mp[r].end()) mp[r].insert(make_pair(p,1));
		else ++mp[r][p];
		return ;
	}
	dfs1(x+1,r,p);
	dfs1(x+1,r,p+a[x]);
	dfs1(x+1,r+1,p+f(a[x]));
	return ;
}

void dfs2(int x,int r,long long p)
{
	if (p>s) return ;
	if (r>k) return ;
	if (x==n+1)
	{
		for (int i=0;i<=k-r;i++) if(mp[i].count(s-p)) ans+=mp[i][s-p];
		return ;
	}
	dfs2(x+1,r,p);
	dfs2(x+1,r,p+a[x]);
	dfs2(x+1,r+1,p+f(a[x]));
	return ;
}

int main()
{
	scanf("%d %d %lld",&n,&k,&s);m=(n>>1)+(n&1);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	dfs1(1,0,0LL);dfs2(m+1,0,0LL);
	printf("%lld\n",ans);
	return 0;
}