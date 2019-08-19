#include <bits/stdc++.h>
#define MAXN 400005
#define MAXM 500005
using namespace std;

const long long M=1e9+7;

struct link
{
	int to,val,nxt;
};

link e[MAXN<<1];
int head[MAXN],cnt;
int n,m,p,u,v,in[MAXN],f[MAXN];
long long _2[MAXM],ans;

inline int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

inline void add(int u,int v,int w)
{
	e[cnt]=(link){v,w,head[u]};head[u]=cnt++;
	e[cnt]=(link){u,w,head[v]};head[v]=cnt++;
}

inline bool dfs(int x,int f,int p)
{
	bool now=in[x]&1;
	for (int i=head[x];~i;i=e[i].nxt)
		if (e[i].to!=f)
			now^=dfs(e[i].to,x,e[i].val);
	if (now) (ans+=_2[p])%=M;
	return now;
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
	memset(head,-1,sizeof head);
	read(n);read(m);_2[0]=1;
	for (int i=1;i<=n;i++) f[i]=i;
	for (int i=1;i<=m;i++)
	{
		_2[i]=_2[i-1]*2%M;
		read(u);read(v);++in[u];++in[v];
		int fx=getf(u),fy=getf(v);
		if (fx!=fy) f[fy]=fx,add(u,v,i);
	}
	_2[m+1]=_2[m]*2%M;
	dfs(1,-1,0);
	printf("%lld\n",(ans+_2[m+1]-2+M)%M);
	return 0;
}