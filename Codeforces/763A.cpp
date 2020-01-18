#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int n,cnt,u[MAXN],v[MAXN],c[MAXN],in[MAXN];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++) scanf("%d %d",&u[i],&v[i]);
	for (int i=1;i<=n;i++) scanf("%d",&c[i]);
	for (int i=1;i<n;i++)
		if (c[u[i]]!=c[v[i]])
		{
			++cnt;
			++in[u[i]];++in[v[i]];
		}
	for (int i=1;i<=n;i++) if (cnt==in[i]) return printf("YES\n%d\n",i),0;
	puts("NO");
	return 0;
}