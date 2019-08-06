#include <bits/stdc++.h>
#define MAXN 5005
#define MAXM 255005
using namespace std;

struct link
{
	int to,nxt;
};

link e[MAXM];
int head[MAXN],cnt;
int n,k,x,p,a[MAXN],pt,ans,in[MAXN];
bitset <5001> s[MAXN];

inline void add(int u,int v)
{
	++in[v];e[cnt]=(link){v,head[u]};head[u]=cnt++;
}

void dfs(int x)
{
	s[x].set(x);
	for (int i=head[x];~i;i=e[i].nxt)
	{
		if (s[e[i].to].none()) dfs(e[i].to);
		s[x]|=s[e[i].to];
	}
	return ;
}

inline bool read(int &x)
{
	x=0;char ch;
	if ((ch=getchar())==EOF) return false;
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return ch==' ';
}

int main()
{
	//freopen("i.in","r",stdin);
	while (true)
	{
		memset(head,-1,sizeof head);cnt=0;ans=0;pt=0;
		memset(in,0,sizeof in);
		if (!read(n)) break;
		read(k);
		for (int i=1;i<=n;i++) s[i].reset();
		for (int i=1;i<=k;i++) read(a[i]);
		for (int i=1;i<=n;i++)
		{
			p=0;
			if (read(x))
			{
				while (true)
				{
					char ch=getchar();
					while (ch>='0'&&ch<='9') p=(p<<3)+(p<<1)+ch-'0',ch=getchar();
					if (p) add(x,p);p=0;
					if (ch!=' ') break;
				}
			}
		}
		for (int i=1;i<=n;i++) if (!in[i]) add(0,i);
		dfs(0);
		for (int i=1;i<=k;i++)
		{
			int t=s[a[i]].count();
			if (t>ans) {ans=t;pt=a[i];}
			else if (t==ans) pt=min(pt,a[i]);
		}
		printf("%d\n",pt);
	}
	return 0;
}
