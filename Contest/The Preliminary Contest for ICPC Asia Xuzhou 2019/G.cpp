#include <bits/stdc++.h>
#define MAXN 300010
using namespace std;

struct PAM
{
	int nxt[26],fail,l;
};

PAM tree[MAXN];
int n,tot=1,last;
char s[MAXN];
long long ans,cnt[MAXN];

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
	++cnt[last=tree[now].nxt[x]];
	return ;
}

void dfs(int x,int f)
{
	for (int i=0;i<=25;i++)
		if (tree[x].nxt[i])
		{
			int t=f|(1<<i);
			long long c=__builtin_popcount(t);
			ans+=c*cnt[tree[x].nxt[i]];
			dfs(tree[x].nxt[i],f|(1<<i));
		}
	return ;
}

int main()
{
	pre();
	scanf("%s",s+1);
	for (int i=1;s[i];i++) add(s[i]-'a',i);
	for (int i=tot;i>=2;i--) cnt[tree[i].fail]+=cnt[i];
	dfs(0,0);dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}