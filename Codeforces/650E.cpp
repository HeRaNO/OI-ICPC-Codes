#include <bits/stdc++.h>
#define ll long long
#define ls id<<1
#define rs id<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define mp(a,b) make_pair((a),(b))
using namespace std;
const int inf=0x3f3f3f3f;
const int N=500050;
const ll mod=1e9+7;
int n;
struct Answer
{
	int X1,Y1,X2,Y2;
}ans[N<<1];int cnt;
vector <int> e1[N],e2[N];
int f[N],father1[N],father2[N];
int Find(int x){return x==f[x]?x:Find(f[x]);}
void dfs1(int u,int fa)
{
	father1[u]=fa;
	for(auto v:e1[u])
	{
		if(v==fa)continue;
		dfs1(v,u);
	}
}
void dfs2(int u,int fa)
{
	father2[u]=fa;
	for(auto v:e2[u])
	{
		if(v==fa)continue;
		dfs2(v,u);
	}
}
void dfs3(int u,int fa)
{
	for(auto v:e1[u])
	{
		if(v==fa)continue;
		dfs3(v,u);
		if(u!=father2[v]&&v!=father2[u])
			ans[++cnt]=(Answer){u,v,Find(v),father2[Find(v)]};
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)f[i]=i;
	for(int i=1;i<n;++i)
	{
		int x,y;scanf("%d%d",&x,&y);
		e1[x].push_back(y);
		e1[y].push_back(x);
	}
	for(int i=1;i<n;++i)
	{
		int x,y;scanf("%d%d",&x,&y);
		e2[x].push_back(y);
		e2[y].push_back(x);
	}
	dfs1(1,0);dfs2(1,0);
	for(int i=2;i<=n;++i)
	{
		if(father1[i]==father2[i]||father1[father2[i]]==i)
			f[i]=father2[i];
	}
	dfs3(1,0);
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;++i)
	{
		printf("%d %d %d %d\n",ans[i].X1,ans[i].Y1,ans[i].X2,ans[i].Y2);
	}
	return 0;
}
