#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int T,n,rt,son[MAXN][10],top;
char s[MAXN][10];
bool fin[MAXN];

inline int newnode()
{
	memset(son[top],-1,sizeof son[top]);
	fin[top++]=false;
	return top-1;
}

inline bool add(int p)
{
	int l=strlen(s[p]),now=rt;
	for (int i=0;i<l;i++)
	{
		if (!~son[now][s[p][i]-'0']) son[now][s[p][i]-'0']=newnode();
		now=son[now][s[p][i]-'0'];
		if (fin[now]) return true;
	}
	fin[now]=true;
	for (int i=0;i<=9;i++) if (~son[now][i]) return true;
	return false;
}

int main()
{
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++)
	{
		top=0;rt=newnode();
		scanf("%d",&n);bool f=true;
		for (int i=1;i<=n;i++)
		{
			scanf("%s",s[i]);
			if (add(i)) f=false;
		}
		printf("Case #%d: %s\n",cas,f?"Yes":"No");
	}
	return 0;
}