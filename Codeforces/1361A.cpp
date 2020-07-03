#include <bits/stdc++.h>
#define MAXN 500005
using namespace std;

int n,m,a[MAXN],b[MAXN];
vector <int> g[MAXN],ans;
priority_queue <pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > > q;

int main()
{
	scanf("%d %d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		g[u].push_back(v);g[v].push_back(u);
	}
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),q.push({a[i],i});
	for (int i=1;i<=n;i++)
	{
		for (auto v:g[i]) b[a[v]]=i;
		for (int j=1;j<a[i];j++) if (b[j]!=i) return puts("-1"),0;
		if (b[a[i]]==i) return puts("-1"),0;
	}
	for (;!q.empty();q.pop()) ans.push_back(q.top().second);
	for (auto i:ans) printf("%d ",i);putchar('\n');
	return 0;
}