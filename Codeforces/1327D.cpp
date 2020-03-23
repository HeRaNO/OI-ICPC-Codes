#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int T,n,p[MAXN],c[MAXN];
bool vis[MAXN];
vector <int> v[MAXN],cyc;

int main()
{
	for (int i=1;i<=200000;i++)
		for (int j=i;j<=200000;j+=i)
			v[j].push_back(i);
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);int ans=n+1;
		for (int i=1;i<=n;i++) vis[i]=false;
		for (int i=1;i<=n;i++) scanf("%d",&p[i]);
		for (int i=1;i<=n;i++) scanf("%d",&c[i]);
		for (int i=1;i<=n;i++)
			if (!vis[i])
			{
				int x=i;cyc.clear();
				while (!vis[x])
				{
					cyc.push_back(c[x]);
					vis[x]=true;x=p[x];
				}
				int m=cyc.size();
				for (auto k:v[m])
					for (int j=0;j<k;j++)
					{
						bool f=true;
						for (int r=j;r<m&&f;r+=k)
							if (cyc[r]!=cyc[j]) f=false;
						if (f) ans=min(ans,k);
					}
			}
		printf("%d\n",ans);
	}
	return 0;
}
