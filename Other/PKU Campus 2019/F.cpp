#include <bits/stdc++.h>
using namespace std;

int now[60],tar[60],er[60],cntt[60];
int T,n,id[110],ty[110],cr[110];
vector <pair<pair<int,int>,int> > g[1000];
bool occ[7][20];
vector <int> ans;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		ans.clear();
		for (int i=1;i<=5;i++) scanf("%d",&now[i]);
		for (int i=1;i<=5;i++) scanf("%d",&tar[i]);
		scanf("%d",&n);
		for (int i=1;i<=n;i++) g[i].clear();
		for (int i=1;i<=n;i++)
		{
			int k,x,a,b;
			scanf("%d",&id[i]);
			scanf("%d",&ty[i]);
			scanf("%d",&cr[i]);
			scanf("%d",&k);
			for (int j=1;j<=k;j++)
			{
				scanf("%d %d %d",&x,&a,&b);
				g[i].push_back(make_pair(make_pair(x,a),b));
			}
		}
		bool f=false;int be=-1;
		for (int i=0;i<(1<<n);i++)
		{
			memset(er,0,sizeof er);f=true;
			memset(occ,false,sizeof occ);memset(cntt,0,sizeof cntt);
			for (int j=1;j<=n&&f;j++)
				if (i&(1<<(j-1)))
				{
					er[ty[j]]+=cr[j];cntt[ty[j]]++;
					for (int k=0;k<g[j].size()&&f;k++)
					{
						int x=g[j][k].first.first;
						int a=g[j][k].first.second;
						int b=g[j][k].second;
						for (int p=a;p<=b&&f;p++)
						{
							if (occ[x][p]) f=false;
							occ[x][p]=true;
						}
					}
				}
			if (f)
			{
				int cnt=0;
				for (int ii=1;ii<=5&&f;ii++) if (now[ii]+er[ii]<tar[ii]) f=false;
				for (int ii=1;ii<=5&&f;ii++) cnt+=er[ii];
				if (cntt[3]>1||cntt[4]>1||cntt[5]>1) f=false;
				if (cnt>25) f=false;
			}
			if (f)
			{
				if (!~be) be=i;
				else if (__builtin_popcount(be)>__builtin_popcount(i))
					be=i;
			}
		}
		if (~be)
		{
			for (int i=1;i<=n;i++)
				if (be&(1<<(i-1))) ans.push_back(id[i]);
			sort(ans.begin(),ans.end());
			puts("able to graduate");
			if (ans.size())
				for (int i=0;i<ans.size();i++) printf("%d%c",ans[i],i==ans.size()-1?'\n':' ');
		}
		else puts("unable to graduate");
	}
	return 0;
}