#include <bits/stdc++.h>
using namespace std;
int n;
const int N=100050;
struct edge
{
  int u,v,nxt;  
}e[N<<1];
int head[N],ecnt;
inline void ad(int u,int v)
{
	e[++ecnt].v=v;e[ecnt].nxt=head[u];head[u]=ecnt;
}
bool vis[N*105];
int tot;
map <vector <int> ,int> p;
map <int,map<int,int> > Hash;

int dfs(int u,int fa)
{
	if(Hash[u][fa])return Hash[u][fa];
	vector <int> son;
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa)continue;
		son.push_back(dfs(v,u));
	}
	sort(son.begin(),son.end());
	if(!p[son])p[son]=++tot;
	return Hash[u][fa]=p[son];
}
 
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		ad(x,y);ad(y,x);
	}
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		int soncnt=0;
		for(int j=head[i];j;j=e[j].nxt)soncnt++;
		if(soncnt==4)continue;
		int tmp=dfs(i,0);
		if(vis[tmp]==0)ans++,vis[tmp]=true;
	}
	printf("%d\n",ans);
	return 0;
}