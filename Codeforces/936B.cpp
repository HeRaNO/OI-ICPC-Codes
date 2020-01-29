#include <bits/stdc++.h>
#define ll long long
#define mem(a,b) memset(a,b,sizeof(a))
#define ls id<<1
#define rs id<<1|1
using namespace std;
const int N=300050;
int n,m,s;
vector <int> e[N],ans;
int out[N];
bool vis2[N];
bool vis[N][3];
bool existCircle;
inline void ad(int u,int v)
{
	e[u].push_back(v);
	out[u]++;
}
void dfs(int u,int player)
{
	if(vis[u][player])return;
	vis[u][player]=1;
	if(out[u]==0&&player==2)
	{
		puts("Win");
		for(auto i:ans)printf("%d ",i);
		exit(0);
	}
	for(auto v:e[u])
	{
		if(vis2[v])existCircle=true;
		vis2[v]=true;
		ans.push_back(v);
		dfs(v,player==1?2:1);
		ans.pop_back();
		vis2[v]=false;
	}
}


int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		int kk;cin>>kk;
		while(kk--){int x;scanf("%d",&x);ad(i,x);}
	}
	scanf("%d",&s);vis2[s]=true;
	ans.push_back(s);
	dfs(s,1);
	if(existCircle)return puts("Draw"),0;
	puts("Lose");
	return 0;
}