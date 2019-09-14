#include <bits/stdc++.h>
#define ll long long
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N=100050;
int n,m,k;
vector <int> v[N];
int f[N],val[N];
int a[N];
bool vis[N];
double ans;
int Find(int x){return x==f[x]?x:f[x]=Find(f[x]);}

inline void data_init()
{
	for(int i=1;i<=n;++i)
	{
		f[i]=i;
		val[i]=1;
		v[i].resize(0);
	}
	mem(vis,0);
	ans=0;
}

int main()
{
	int Test;scanf("%d",&Test);
	while(Test--)
	{
		scanf("%d%d%d",&n,&m,&k);
		data_init();
		for(int i=1;i<=m;++i)
		{
			int x,y;scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		for(int i=1;i<=k;++i)
		{
			scanf("%d",&a[i]);
			vis[a[i]]=1;
		}
		for(int i=1;i<=n;++i)
		{
			int sz=v[i].size();
			if(vis[i])continue;
			for(int j=0;j<sz;++j)
			{
				if(!vis[v[i][j]])
				{
					int fx=Find(i),fy=Find(v[i][j]);
					if(fx!=fy)
					{
						f[fx]=fy;
						val[fy]+=val[fx];
					}
				}
			}
		}
		for(int i=1;i<=n;++i)
		{
			bool flag=0;
			if(!vis[i])continue;
			int sz=v[i].size();
			int tmp=0;
			for(auto j:v[i])
			{
				if(vis[j])continue;
				int F=Find(j);
				if(F==Find(1))
				{
					flag=1;
				}
				else
				{
					tmp+=val[F];
				}
			}
			if(flag==1)
			{
				ans=max(ans,(double)(tmp)/(1.0*sz));
			}
		}
		printf("%.12lf\n",ans+val[Find(1)]);
	}
	return 0;
}