#include <bits/stdc++.h>
#define MAXN 1000010
using namespace std;

struct PAM
{
	int nxt[10],fail,l;
};

PAM tree[MAXN];
int n,a[MAXN],tot=1,last;
char s[MAXN];
long long ans,_10[MAXN],M;

inline void pre()
{
	tree[0].fail=1;tree[1].l=-1;
	return ;
}

void add(int x,int t)
{
	int now=last;
	while (s[t-tree[now].l-1]!=s[t]) now=tree[now].fail;
	if (!tree[now].nxt[x])
	{
		int nptr=++tot,k=tree[now].fail;
		tree[nptr].l=tree[now].l+2;
		while (s[t-tree[k].l-1]!=s[t]) k=tree[k].fail;
		tree[nptr].fail=tree[k].nxt[x];
		tree[now].nxt[x]=nptr;
	}
	last=tree[now].nxt[x];
	return ;
}

void dfs(int x,long long p)
{
	(ans+=p)%=M;
	for (int i=0;i<=9;i++)
		if (tree[x].nxt[i])
		{
			long long np=i*_10[tree[tree[x].nxt[i]].l-1]%M;
			(np+=p*10%M)%=M;
			(np+=i)%M;
			dfs(tree[x].nxt[i],np);
		}
	return ;
}

int main()
{
	pre();_10[0]=1;
	scanf("%s",s+1);
	scanf("%lld",&M);
	for (int i=1;s[i];i++)
	{
		add(s[i]-'0',i);_10[i]=_10[i-1]*10%M;
	}
	dfs(0,0LL);
	for (int i=0;i<=9;i++)
		if (tree[1].nxt[i])
			dfs(tree[1].nxt[i],i);
	printf("%lld\n",ans);
	return 0;
}