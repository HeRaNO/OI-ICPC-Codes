#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int sta[MAXN],top;
int n,k,las[MAXN],a[MAXN];
bool vis[MAXN];

int main()
{
	scanf("%d %d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),las[a[i]]=max(las[a[i]],i);
	for (int i=1;i<=n;i++)
	{
		if (vis[a[i]]) continue;
		while (top&&las[sta[top]]>i&&a[i]<=sta[top]) vis[sta[top--]]=false;
		if (!vis[a[i]]) vis[sta[++top]=a[i]]=true;
	}
	assert(top==k);
	for (int i=1;i<=k;i++) printf("%d%c",sta[i],i==k?'\n':' ');
	return 0;
}
