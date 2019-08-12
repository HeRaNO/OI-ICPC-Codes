#include <bits/stdc++.h>
#define MAXN 100005
#define fi first
#define se second
using namespace std;

int n,M,e,u,v,w,f[MAXN<<1];
vector <pair<int,int> > g[31],t[2];
long long ans[MAXN],s[MAXN];

inline int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

int main()
{
	scanf("%d %d %d",&n,&M,&e);
	for (int i=1;i<=e;i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		for (int j=w+1;j<=30;j++) g[j].push_back(make_pair(u,v+n));
	}
	for (w=1;w<=30;w++)
	{
		for (int i=1;i<=(n<<1);i++) f[i]=i;
		t[0].clear();t[1].clear();memset(s,0,sizeof s);
		for (int i=0;i<g[w].size();i++)
		{
			int fx=getf(g[w][i].fi),fy=getf(g[w][i].se);
			if (fx>fy) swap(fx,fy);
			if (fx!=fy)
			{
				if (fx>n&&fy>n) t[0].push_back(make_pair(fx-n,fy-n));
				++s[1];
				f[fx]=fy;
			}
		}
		for (int i=2,now=1;i<=M;i++,now=1-now)
		{
			t[now].clear();
			for (int j=0;j<t[1-now].size();j++)
			{
				int fx=getf(t[1-now][j].fi),fy=getf(t[1-now][j].se);
				if (fx>fy) swap(fx,fy);
				if (fx!=fy)
				{
					if (fx>n&&fy>n) t[now].push_back(make_pair(fx-n,fy-n));
					f[fx]=fy;
				}
				else --s[i];
			}
		}
		for (int i=1;i<=M;i++) s[i]+=s[i-1];
		for (int i=1;i<=M;i++) s[i]+=s[i-1];
		for (int i=1;i<=M;i++) ans[i]+=1LL*(i+1)*n-s[i]-1;
	}
	for (int i=1;i<=M;i++) printf("%lld\n",ans[i]);
	return 0;
}
