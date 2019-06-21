#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

struct link
{
	int to,nxt;
};

link e[MAXN];
int head[MAXN],cnt;
int n,m,x,y,p,dep[MAXN],in[MAXN];

inline void add(int x,int y)
{
	++in[y];e[cnt]=(link){y,head[x]};head[x]=cnt++;
}

void dfs(int x,int deep)
{
	dep[x]=deep;
	for (int i=head[x];~i;i=e[i].nxt) dfs(e[i].to,deep+1);
	return ;
}

inline void read(int &x)
{
	x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return ;
}

int main()
{
	while (true)
	{
		read(n);read(m);
		if (!n&&!m) break;
		memset(head,-1,sizeof head);memset(in,0,sizeof in);cnt=p=0;
		for (int i=1;i<n;i++)
		{
			read(x);read(y);
			add(x,y);
		}
		for (int i=1;i<=n&&!p;i++) if (!in[i]) p=i;
		dfs(p,1);
		while (m--)
		{
			read(x);read(y);
			puts(dep[x]<=dep[y]?"lxh":"pfz");
		}
	}
	return 0;
}