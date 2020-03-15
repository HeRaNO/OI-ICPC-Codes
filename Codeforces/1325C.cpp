#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int n,u,v,tot,a[MAXN],in[MAXN],ans[MAXN];
vector <int> g[MAXN];

int main()
{
	memset(ans,-1,sizeof ans);
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		++in[u];++in[v];
		g[u].push_back(i);g[v].push_back(i);
	}
	for(int i=1;i<=n;i++) a[i]=i;
	sort(a+1,a+n+1,[&](int a,int b){return in[a]<in[b];});
	for (int i=1;i<=n;i++)
		for (auto j:g[a[i]])
			if (!~ans[j])
				ans[j]=tot++;
	for (int i=1;i<n;i++) printf("%d\n",ans[i]);
	return 0;
}