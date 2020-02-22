#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define ALL(x) (x.begin(),x.end())
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
const int MAXN=1e3+10,MAXM=4e6+10;
const int INF=INT_MAX,SINF=0x3f3f3f3f;
const ll llINF=LLONG_MAX;
const int MOD=1e9+7,mod=998244353;

int du[6],vis[6];
int g[30][30];
char s[5];
vector<int> ans;

void check(int u)
{
	if(vis[u])
	{
		puts("impossible");
		exit(0);
	}
	vis[u]=1;
	for(int i=0;i<5;i++)if(g[u][i])check(i);
	vis[u]=0;
}

void dfs(int u)
{
	ans.push_back(u);
	vis[u]=1;
	for(int i=0;i<5;i++)
	if(g[u][i])
	{
		du[i]--;
		if(!du[i])dfs(i);
	}
}

int main()
{
	for(int i=1;i<=5;i++)
	{
		scanf("%s",s);
		int u=s[0]-'A';
		int v=s[2]-'A';
		if(s[1]=='<')g[u][v]=1,du[v]++;
		else g[v][u]=1,du[u]++;
	}
	for(int i=0;i<5;i++)check(i);
	for(int i=0;i<5;i++)if(!du[i]&&!vis[i])dfs(i);
	for(int i=0;i<5;i++)if(!vis[i])ans.push_back(i);
	for(auto j:ans)printf("%c",j+'A');
	return 0;
}