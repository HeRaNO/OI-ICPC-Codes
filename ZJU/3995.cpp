#include <bits/stdc++.h>
#define MAXL 500010
#define MAXN 100010
using namespace std;

struct Trie
{
	int nxt[26],fail,cnt;
};

struct link
{
	int to,nxt;
};

link e[MAXL<<1];
Trie tree[MAXL];
int head[MAXL],cnt;
int n,m,x,y,top,root,ed[MAXN];
int dep[MAXL],LCAFather[MAXL][20],_2pow[20],k;
char s[MAXL];
queue <int> q;

inline int newnode()
{
	memset(tree[top].nxt,-1,sizeof tree[top].nxt);
	tree[top].fail=-1;
	tree[top++].cnt=0;
	return top-1;
}

inline void add(char S[],int id)
{
	int len=strlen(S),now=root;
	for (int i=0;i<len;i++)
	{
		if (!~tree[now].nxt[S[i]-'a']) tree[now].nxt[S[i]-'a']=newnode();
		now=tree[now].nxt[S[i]-'a'];
		++tree[now].cnt;
	}
	ed[id]=now;
	return ;
}

inline void addedge(int u,int v)
{
	e[cnt]=(link){v,head[u]};head[u]=cnt++;
	e[cnt]=(link){u,head[v]};head[v]=cnt++;
}

inline void GetFail()
{
	int u, now;
	tree[root].fail=root;
	for (int i=0;i<26;i++)
	{
		if (!~tree[root].nxt[i]) tree[root].nxt[i]=root;
		else {tree[tree[root].nxt[i]].fail=root;q.push(tree[root].nxt[i]);}
	}
	while (!q.empty())
	{
		u = q.front();
		q.pop();
		for (int i = 0; i < 26; i++)
		{
			if (!~tree[u].nxt[i]) tree[u].nxt[i]=tree[tree[u].fail].nxt[i];
			else
			{
				tree[tree[u].nxt[i]].fail=tree[tree[u].fail].nxt[i];
				q.push(tree[u].nxt[i]);
			}
		}
	}
	for (int i=1;i<top;i++) addedge(i+1,tree[i].fail+1);
	return ;
}

void dfs(int x,int f,int deep)
{
	LCAFather[x][0]=f;dep[x]=deep;
	for (int i=head[x];~i;i=e[i].nxt) if (e[i].to!=f) dfs(e[i].to,x,deep+1);
	return ;
}

inline void LCA()
{
	for (int j=1;j<=k;j++)
		for (int i=1;i<=top;i++)
			LCAFather[i][j]=LCAFather[LCAFather[i][j-1]][j-1];
	return ;
}

inline int GetLCA(int x,int y)
{
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=k;~i;i--)
		if (_2pow[i]<=dep[x]-dep[y])
			x=LCAFather[x][i];
	if (x==y) return x;
	for (int i=k;~i;i--)
		if (LCAFather[x][i]!=LCAFather[y][i])
			x=LCAFather[x][i],y=LCAFather[y][i];
	return LCAFather[x][0];
}

inline int query(int x,int y)
{
	return tree[GetLCA(ed[x]+1,ed[y]+1)-1].cnt;
}

int main()
{
	while (~scanf("%d",&n))
	{
		top=0;root=newnode();cnt=0;memset(head,-1,sizeof head);
		for (int i=1;i<=n;i++) scanf("%s",s),add(s,i);
		for (_2pow[k=0]=1;_2pow[k]<=top;k++) _2pow[k+1]=_2pow[k]<<1;
		GetFail();dfs(1,0,1);LCA();
		scanf("%d",&m);
		while (m--)
		{
			scanf("%d %d",&x,&y);
			int res=query(x,y);
			if (!res) puts("N");
			else printf("%d\n",res);
		}
	}
	return 0;
}