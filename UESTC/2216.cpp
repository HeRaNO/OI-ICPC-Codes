#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;

int n,m,u,v,srt=~(1<<31),in[MAXN],out[MAXN],a,b,cnt;
int ans[MAXN<<1],sta[MAXN<<1],top;
pair<int,int> l[MAXN<<1];
queue <int> q[MAXN];

inline void add(int u,int v)
{
	++in[v];++out[u];q[u].push(v);
	return ;
}

void dfs(int x)
{
	sta[++top]=x;
	while (top)
	{
A:		int x=sta[top];
		while (!q[x].empty())
		{
			int i=q[x].front();q[x].pop();
			sta[++top]=i;goto A;
		}
		ans[++cnt]=x;--top;
	}
	return ;
}

inline void read(int &x)
{
	x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return ;
}

int main()
{
	read(n);read(m);
	for (int i=1;i<=m;i++)
	{
		read(l[i].first);read(l[i].second);
		srt=min(srt,min(l[i].first,l[i].second));
	}
	sort(l+1,l+m+1);
	for (int i=1;i<=m;i++) add(l[i].first,l[i].second);
	for (int i=1;i<=n;i++)
	{
		if (out[i]-in[i]==1){++a;srt=i;}
		else if (out[i]-in[i]==-1) ++b;
		else if (out[i]-in[i]!=0) a=3;
	}
	if(!((!a&&!b)||(a==1&&b==1))) return puts("What a shame!"),0;
	dfs(srt);
	if (cnt!=m+1) return puts("What a shame!"),0;
	for (int i=cnt;i;i--) printf("%d%c",ans[i],i==1?'\n':' ');
	return 0;
}