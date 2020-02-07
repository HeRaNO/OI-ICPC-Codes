#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N=200050;
int f[N];
int Find(int x){return x==f[x]?x:f[x]=Find(f[x]);}
int n;
int a[N],b[N];
bool vis[N];
vector <int> change;
int ans;
bool huan[N];
int rt;

int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),b[i]=a[i],f[i]=i;
	int las=0;
	for(int i=1;i<=n;++i)
	{
		if(!rt&&i==a[i]){rt=i;continue;}
		int fx=Find(i),fy=Find(a[i]);
		if(fx!=fy)f[fy]=fx;
		else
		{
			change.push_back(i);
			if(i!=a[i])huan[fx]=true;
		}
	}
	if(rt)
	{
		for(int i=0;i<change.size();++i)
		{
			int u=change[i];
			a[u]=rt;
		}
	}
	else
	{
		for(int i=0;i<change.size()-1;++i)
		{
			int u=change[i];
			int v=change[i+1];
			a[u]=v;
		}
		for(int i=1;i<=n;++i)f[i]=i;
		for(int i=1;i<=n;++i)
		{
			int u=Find(i),v=Find(a[i]);
			if(u!=v)f[v]=u;
			else
			{
				if(i!=a[i])a[i]=i;
				break;
			}
		}	
	}
	
	for(int i=1;i<=n;++i)if(a[i]!=b[i])ans++;
	printf("%d\n",ans);
	for(int i=1;i<=n;++i)
		printf("%d ",a[i]);
	puts("");
	return 0;
}
