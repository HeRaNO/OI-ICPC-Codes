#include <bits/stdc++.h>
#define MAXN 100005
#define MAXL 105
using namespace std;

int n,T,R=1,u,v,a,b;
char s[MAXN];
int in[MAXN],pos[MAXN],top[MAXN],fa[MAXN],dep[MAXN],siz[MAXN],mx[MAXN];
vector <int> g[MAXN];

inline void dfs1(int x)
{
	siz[x]=1;mx[x]=-1;
	for (auto v:g[x])
		if (fa[x]!=v)
		{
			fa[v]=x;dep[v]=dep[x]+1;
			dfs1(v);
			siz[x]+=siz[v];
			if (!~mx[x]||siz[mx[x]]<siz[v]) mx[x]=v;
		}
	return ;
}

inline void dfs2(int x,int t)
{
	pos[R]=x;in[x]=R++;top[x]=t;
	if (~mx[x]) dfs2(mx[x],t);
	for (auto v:g[x]) if (v!=fa[x]&&v!=mx[x]) dfs2(v,v);
	return ;
}

int nxt[MAXL];
void getnxt(string &tmp)
{
	tmp=' '+tmp;
	for(int i=1;i<tmp.size();i++)
	{
		int u=nxt[i-1];
		while(u>0&&tmp[u]!=tmp[i])u=nxt[u-1];
		if(tmp[u]==tmp[i])u++;
		nxt[i]=u;
	}
}
string p;
struct Tr
{
	int trans[105],ans[105];
	Tr(){memset(trans,0,sizeof trans);memset(ans,0,sizeof ans);}
}ch[30];

Tr x[1<<18];

void calc()
{
	cin>>p;
	getnxt(p);
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<p.size();j++)
		{
			int u=j;
			while(u>0&&p[u+1]!=i+'a')u=nxt[u];
			if(p[u+1]==i+'a')u++;
			ch[i].trans[j]=u;if(u==n)ch[i].ans[j]++;
		}
	}
}

Tr merget(Tr &lch,Tr &rch)
{
	Tr res;
	for(int i=0;i<p.size();i++)
	{
		res.trans[i]=rch.trans[lch.trans[i]];
		res.ans[i]=lch.ans[i]+rch.ans[lch.trans[i]];
	}
	return res;
}

inline void BuildTree(int u,int l,int r)
{
	if (l+1==r)
	{
		x[u]=ch[s[pos[l]]-'a'];
		return ;
	}
	int m=l+r>>1;BuildTree(u<<1,l,m);BuildTree(u<<1|1,m,r);
	return ;
}

inline void modify(int u,int p,int v,int pl,int pr)
{
	if (pl+1==pr)
	{
		x[u]=ch[v];return ;
	}
	int m=pl+pr>>1;
	if (p<m) modify(u<<1,p,v,pl,m);
	else modify(u<<1|1,p,v,m,pr);
	x[u]=merget(x[u<<1],x[u<<1|1]);
	return ;
}

inline Tr query(int u,int l,int r,int pl,int pr)
{
	if (l==pl&&r==pr) return x[u];
	int m=pl+pr>>1;
	if (r<=m) return query(u<<1,l,r,pl,m);
	else if (m<=l) return query(u<<1|1,l,r,m,pr);
	Tr lc=query(u<<1,l,m,pl,m),rc=query(u<<1|1,m,r,m,pr);
	return merget(lc,rc);
}

inline int Q(int l,int r)
{
	Tr res,t;
	while (top[l]!=top[r])
	{
		if (dep[top[l]]<dep[top[r]]) swap(l,r);
		t=query(1,in[top[l]],in[l]+1,1,n+1);
		res=merget(res,t);
		l=fa[top[l]];
	}
	if (in[l]>in[r]) swap(l,r);
	t=query(1,in[l],in[r]+1,1,n+1);
	res=merget(res,t);
	for (int i=0;i<p.size();i++) printf("%d ",res.ans[i]);
	puts("");
	return res.ans[0];
}

int main()
{
	scanf("%d %d",&n,&T);
	calc();
	scanf("%s",s+1);
	for (int i=1;i<n;i++)
	{
		scanf("%d %d",&u,&v);
		g[u].push_back(v);g[v].push_back(u);
	}
	dfs1(1);dfs2(1,1);BuildTree(1,1,n+1);
	while (T--)
	{
		int o;
		scanf("%d",&o);
		if (o==1)
		{
			scanf("%d %d",&u,&v);
			printf("%d\n",Q(u,v));
		}
		else
		{
			scanf("%d %s",&u,s);
			modify(1,pos[u],s[0]-'a',1,n+1);
		}
	}
	return 0;
}