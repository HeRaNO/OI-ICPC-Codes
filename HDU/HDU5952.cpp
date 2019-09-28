#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=2e6+10,MAXM=1e6+10;
const int MOD=1e9+7,INF=~(1<<31);
const ll llINF=((1ll<<61));

int n,m,s,ans;
int du[105];

int v[105],cnt;
bool flag,mp[105][105];

vector <int> e[105];

void dfs(int dep,int u)
{
	if(dep==s)
	{
		ans++;
		return;
	}
	for (auto i:e[u])
	{
		if(!du[i])continue;
		flag=0;
		for(int j=1;j<=cnt;j++)
			if(!mp[v[j]][i]){flag=1;break;}
		if(flag)continue;
		v[++cnt]=i;
		dfs(dep+1,i);
		cnt--;
	}
}

int main()
{
	int t;
	//freopen("in.txt","r",stdin);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&s);
		memset(mp,0,sizeof mp);
		memset(du,0,sizeof du);
		for (int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<=m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			mp[u][v]=mp[v][u]=1;
			e[u].push_back(v);
			du[u]++;
			du[v]++;
		}
		for(int i=1;i<=n;i++)if(du[i]<s-1)du[i]=0;
		ans=0;
		for (int i=1;i<=n;i++)
		{
			v[cnt=1]=i;
			dfs(1,i);
		}
		printf("%d\n",ans);
	}
	return 0;
}
