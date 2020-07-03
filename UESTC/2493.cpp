#include <cstdio>
#include <vector>
#define MAXN 100005
using namespace std;

const int M=1e9+7;

int n,k;
vector <int> g[MAXN];

int dfs(int x,int f)
{
	if (k<g[x].size()) return 0;
	int ans=1,t=!f?k-1:k-2;
	for (auto v:g[x])
		if (v!=f)
		{
			ans=1LL*ans*t%M;
			--t;
		}
	for (auto v:g[x])
		if (v!=f) ans=1LL*ans*dfs(v,x)%M;
	return ans;
}

int main()
{
	scanf("%d %d",&n,&k);
	for (int i=1,u,v;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		g[u].push_back(v);g[v].push_back(u);
	}
	printf("%d\n",1LL*k*dfs(1,0)%M);
	return 0;
}