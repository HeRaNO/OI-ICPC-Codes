#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=4e4+10,MAXM=1e6+10;
const int MOD=1e8+7,INF=~(1<<31);
const ll llINF=((1ll<<61));

int du[MAXN];
map<pii,int> mp;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		memset(du,0,sizeof(du));
		mp.clear();
		scanf("%d%d",&n,&m);
		for(int i=1;i<n;i++)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			if(u>v)swap(u,v);
			if(w)
			{
				du[u]++;
				du[v]++;
				mp[{u,v}]=1;
			}
			else mp[{u,v}]=2;
		}
		for(int i=1;i<=m;i++)
		{
			int op,u,v;
			scanf("%d",&op);
			if(op==0)
			{
				scanf("%d",&u);
				if(du[u]&1)puts("Girls win!");
				else puts("Boys win!");
			}
			else
			{
				scanf("%d%d",&u,&v);
				int w;
				scanf("%d",&w);
				if(u>v)swap(u,v);
				if(w==0)w=2;
				if(w!=mp[{u,v}])
				{
					mp[{u,v}]=w;
					du[u]++;
					du[v]++;
				}
			}
		}
	}
	return 0;
}