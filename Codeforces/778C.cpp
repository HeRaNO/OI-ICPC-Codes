#include <bits/stdc++.h>
#define MAXN 300005
using namespace std;

int tot,c;
int n,D,u,v,ans[MAXN],k,son[MAXN<<1][26];
char s[3];

inline int merge(int x,int y)
{
	if (!x||!y) return x+y;
	int rt=++tot;++c;
	for (int i=0;i<26;i++) son[rt][i]=merge(son[x][i],son[y][i]);
	return rt;
}

inline void dfs(int x,int dep)
{
	D=max(D,dep);tot=n;c=0;int rt=++tot;
	for (int i=0;i<26;i++) if (son[x][i]) rt=merge(rt,son[x][i]);
	ans[dep]+=c;
	for (int i=0;i<26;i++) if (son[x][i]) dfs(son[x][i],dep+1);
	return ;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		scanf("%d %d %s",&u,&v,s);
		son[u][s[0]-'a']=v;
	}
	dfs(1,1);
	for (int i=1;i<=D;i++) if (ans[k]<ans[i]) k=i;
	printf("%d\n",n-ans[k]);
	printf("%d\n",k);
	return 0;
}