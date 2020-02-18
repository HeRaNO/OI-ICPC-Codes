#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int n,f[MAXN],ans=~(1<<31);
vector <int> g[MAXN];

inline void dfs(int x)
{
	for (auto v:g[x]) dfs(v),f[x]+=f[v];
	return ;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&f[i]);
	for (int i=2,x;i<=n;i++) scanf("%d",&x),g[x+1].push_back(i);
	dfs(1);
	for (int i=1;i<=n;i++)
		for (auto v:g[i])
			ans=min(ans,abs(f[1]-f[v]*2));
	printf("%d\n",ans);
	return 0;
}