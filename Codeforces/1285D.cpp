#include <bits/stdc++.h>
#define MAXN 3000005
using namespace std;

int n,x,son[MAXN][2],cnt;

inline void add(int x)
{
	for (int i=29,u=0;~i;i--)
	{
		int p=(x>>i)&1;
		if (!son[u][p]) son[u][p]=++cnt;
		u=son[u][p];
	}
	return ;
}

int dfs(int x,int p)
{
	if (!~p) return 0;
	if (son[x][0]&&son[x][1])
	{
		int pp=dfs(son[x][0],p-1);
		int qq=dfs(son[x][1],p-1);
		return min(pp,qq)|(1<<p);
	}
	return dfs(son[x][0]?son[x][0]:son[x][1],p-1);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&x),add(x);
	printf("%d\n",dfs(0,29));
	return 0;
}