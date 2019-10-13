#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=300050;

int n;
int du[MAXN],vis[MAXN],cnt;
struct Edge
{
	int u,v;
}e[MAXN];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(b!=n)
			return puts("NO"),0;
		du[a]++;
	}
	int p=1,q=1;
	for(int i=1;i<=n;i++)
		if(du[i]>i)return puts("NO"),0;
	for(int i=1;i<=n;i++)
	{
		if(du[i])
		{
			vis[i]=1;
			if(du[i]==1)
			{
				e[++cnt]={i,n};
				continue;
			}
			else
			{
				while(vis[p])
				p++;
				if(p>=i)return puts("NO"),0;
				du[i]--;
				e[++cnt]={i,p};
				vis[p]=1;
			}
			while(du[i]>1)
			{
				q=p;
				while(vis[p])
				p++;
				if(p>=i)return puts("NO"),0;
				du[i]--;
				e[++cnt]={q,p};
				vis[p]=1;
			}
			e[++cnt]={p,n};
		}
	}
	puts("YES");
	for(int i=1;i<n;i++)
		printf("%d %d\n",e[i].u,e[i].v);
	return 0;
}