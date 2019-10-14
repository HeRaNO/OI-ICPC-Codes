#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

struct H
{
	int rt,sz;
	H(){}
	H(int _,int __):rt(_),sz(__){}
	bool operator < (const H &a)const{
		return sz>a.sz;
	}
};

struct link
{
	int to,nxt;
};

link e[MAXN];
H a[MAXN];
int head[MAXN],c;
int n,top,cnt,ans,f[MAXN],sta[MAXN],match[MAXN];
vector <int> um[MAXN];

inline void add(int u,int v)
{
	e[c]=(link){v,head[u]};head[u]=c++;
}

inline void dfs(int x,int p)
{
	match[x]=0;
	for (int i=head[x];~i;i=e[i].nxt)
	{
		dfs(e[i].to,p);
		if (!match[x]&&!match[e[i].to])
		{
			match[x]=e[i].to;
			match[e[i].to]=x;
			++ans;
		}
		if (!match[e[i].to]) um[p].push_back(e[i].to);
	}
	return ;
}

int main()
{
	freopen("hidden.in","r",stdin);freopen("hidden.out","w",stdout);
	memset(head,-1,sizeof head);
	scanf("%d",&n);
	for (int i=2;i<=n;i++)
	{
		scanf("%d",&f[i]);
		if (f[i]) add(f[i],i);
	}
	for (int i=1;i<=n;i++)
		if (!f[i])
		{
			dfs(i,i);
			if (i==1||match[i])
			{
				f[i]=1;
				for (auto j:um[i]) sta[++top]=j;
				if (i==1&&!match[i]) sta[++top]=1;
			}
			else a[++cnt]=H(i,um[i].size());
		}
	sort(a+1,a+cnt+1);
	for (int i=1;i<=cnt;i++)
	{
		int x=a[i].rt;
		if (top){++ans;f[x]=sta[top--];}
		else{f[x]=1;sta[++top]=x;}
		for (auto j:um[x]) sta[++top]=j;
	}
	printf("%d\n",ans);
	for (int i=2;i<=n;i++) printf("%d%c",f[i],i==n?'\n':' ');
	return 0;
}