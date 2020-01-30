#include <bits/stdc++.h>
#define MAXN 505
#define MAXM 510
using namespace std;

int n,m,l,u,v,s,t,c[MAXN],f[MAXN];
bitset <1024> vis[MAXN];
pair <int,int> a[MAXM];
vector <pair<int,int> > g[MAXN];
queue <pair<int,int> > q;

inline int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

inline bool find()
{
	q.push({s,0});
	while (!q.empty())
	{
		pair <int,int> u=q.front();q.pop();
		if (u.first==t&&__builtin_popcount(u.second)==l) return true;
		if (vis[u.first].test(u.second)) continue;
		vis[u.first].set(u.second);
		for (auto v:g[u.first])
			if (!(u.second&(1<<c[v.second])))
				q.push({v.first,u.second|(1<<c[v.second])});
	}
	return false;
}

int main()
{
	scanf("%d %d %d",&n,&m,&l);
	for (int i=1;i<=n;i++) f[i]=i;
	for (int i=1;i<=m;i++)
	{
		scanf("%d %d",&u,&v);
		g[u].push_back({v,i});
		g[v].push_back({u,i});
		int fx=getf(u),fy=getf(v);
		if (fx!=fy) f[fy]=fx;
	}
	scanf("%d %d",&s,&t);
	if (!l) return puts(s==t?"YES":"NO"),0;
	if (getf(s)!=getf(v)) return puts("NO"),0;
	mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
	uniform_int_distribution <int> uni(0,l-1);
	for (int T=1;T<=10000;T++)
	{
		for (int i=1;i<=n;i++) vis[i].reset();
		for (int i=1;i<=m;i++) c[i]=uni(rng);
		if (find()) return puts("YES"),0;
	}
	puts("NO");
	return 0;
}