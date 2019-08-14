#include <bits/stdc++.h>
using namespace std;
const int MAXN=105;

int mp[105][105],du[MAXN],vis[MAXN],f[MAXN];
int ans1[MAXN*MAXN],ans2[MAXN*MAXN],cnt,c,tt,tot;
int cirnum=-1;

bool cmp(int a,int b)
{
	return du[a]>du[b];
}

vector<int> v[2][MAXN];

void init()
{
	memset(mp,0,sizeof(mp));
	memset(du,0,sizeof(du));
	cirnum=-1;
}

bool dfs(int cur,int t)
{
	int sz=v[t][cur].size();
	for(int i=0;i<sz;i++)
		if(!vis[v[t][cur][i]])
		{
			vis[v[t][cur][i]]=1;
			if(dfs(v[t][cur][i],t^1))
				return true;
			if(v[t][cur][i]==c&&t==0)
				return true;
		}
	return false;
}

bool tag=false;

void dfs2(int cur,int t,int p)
{
	int sz=v[t][cur].size();
	for(int i=0;i<sz;i++)
		if(!vis[v[t][cur][i]])
		{
			vis[v[t][cur][i]]=1;
			if(v[t][cur][i]==cirnum&&t==0)
			{
				tag=true;
				mp[v[t][cur][i]][cur]=1;
				mp[cur][v[t][cur][i]]=1;
				return;
			}
			dfs2(v[t][cur][i],t^1,cur);
			if(tag)
			{
				mp[v[t][cur][i]][cur]=t^1;
				mp[cur][v[t][cur][i]]=t^1;
				return;
			}
		}
}

int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{
		init();
		bool flag=false;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&du[i]);
			f[i]=i;
		}
		for(int i=1;i<=n;i++)
		{
			sort(f+1,f+n+1,cmp);
			for(int j=2;j<=n;j++)
			{
				if(du[f[1]]&&du[f[j]]&&!mp[f[1]][f[j]])
				{
					du[f[1]]--;
					du[f[j]]--;
					mp[f[1]][f[j]]=1;
					mp[f[j]][f[1]]=1;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(du[i])
			{
				flag=true;
			}
		}
		if(flag)
		{
			cout<<"IMPOSSIBLE"<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			v[1][i].clear();
			v[0][i].clear();
		}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(mp[i][j])
				{
					v[1][i].push_back(j);
					v[1][j].push_back(i);
				}
				else
				{
					v[0][i].push_back(j);
					v[0][j].push_back(i);
				}
		flag=false;
		for(int i=1;i<=n;i++)
		{
			memset(vis,0,sizeof(vis));
			tot=0;
			tt=1;
			c=i;
				if(dfs(i,1))
				{
					cirnum=i;
					flag=true;
					break;
				}
		}
		if(flag) printf("MULTIPLE\n");
		else printf("UNIQUE\n");
		cnt=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(mp[i][j])
				{
					ans1[++cnt]=i;
					ans2[cnt]=j;
				}
		printf("%d %d\n",n,cnt);
		for(int i=1;i<=cnt;i++)
			printf("%d ",ans1[i]);
		printf("\n");
		for(int i=1;i<=cnt;i++)
			printf("%d ",ans2[i]);
		printf("\n");
		if(flag)
		{
			printf("%d %d\n",n,cnt);
			cnt=0;
			tag=false;
			memset(vis,0,sizeof(vis));
			dfs2(cirnum,1,-1);
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					if(mp[i][j])
					{
						ans1[++cnt]=i;
						ans2[cnt]=j;
					}
			for(int i=1;i<=cnt;i++)
				printf("%d ",ans1[i]);
			printf("\n");
			for(int i=1;i<=cnt;i++)
				printf("%d ",ans2[i]);
			printf("\n");
		}
	}
	return 0;
}
/*
5
3 2 2 1 2
*/