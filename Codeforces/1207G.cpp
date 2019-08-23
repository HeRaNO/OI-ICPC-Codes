#include <bits/stdc++.h>
#define MAXN 800005
using namespace std;

struct Trie
{
	int nxt[26],fail,id;
};

struct link
{
	int to,nxt;
};

link e[MAXN<<1];
Trie tree[MAXN];
int head[MAXN],cnt;
int n,m,T,R,opt,p,now,root,top,ed[MAXN>>1],ans[MAXN>>1];
int c[MAXN],in[MAXN],out[MAXN];
char s[MAXN>>1];
queue <int> q;
vector <pair<int,int> > qu[MAXN];

inline void addedge(int u,int v)
{
	e[cnt]=(link){v,head[u]};head[u]=cnt++;
	e[cnt]=(link){u,head[v]};head[v]=cnt++;
}

inline int lowbit(int x){return x&-x;}
inline void modify(int x,int v){for (;x<=R;x+=lowbit(x)) c[x]+=v;return ;}
inline int query(int x){int r=0;for (;x;x-=lowbit(x)) r+=c[x];return r;}

inline int newnode()
{
	memset(tree[top].nxt,-1,sizeof tree[top].nxt);
	tree[top++].fail=-1;
	return top-1;
}

inline int add(char S[])
{
	int len=strlen(S),now=root;
	for (int i=0;i<len;i++)
	{
		if (!~tree[now].nxt[S[i]-'a']) tree[now].nxt[S[i]-'a']=newnode();
		now=tree[now].nxt[S[i]-'a'];
	}
	return now;
}

inline void Get_Fail()
{
	int u,now;q.push(root);
	while (!q.empty())
	{
		u=q.front();q.pop();
		for (int i=0;i<26;i++)
			if (~tree[u].nxt[i])
			{
				if (u==root) tree[tree[u].nxt[i]].fail=root;
				else
				{
					now=tree[u].fail;
					while (~now)
					{
						if (~tree[now].nxt[i])
						{
							tree[tree[u].nxt[i]].fail=tree[now].nxt[i];
							break;
						}
						now=tree[now].fail;
					}
					if (!~now) tree[tree[u].nxt[i]].fail=root;
				}
				q.push(tree[u].nxt[i]);
			}
	}
	for (int i=1;i<top;i++) if (~tree[i].fail) addedge(i,tree[i].fail);
	return ;
}

inline void dfs1(int x,int f)
{
	in[x]=++R;
	for (int i=head[x];~i;i=e[i].nxt) if (e[i].to!=f) dfs1(e[i].to,x);
	out[x]=R;
	return ;
}

inline void dfs2(int x)
{
	modify(in[x],1);
	for (auto i:qu[x]) ans[i.first]=query(out[i.second])-query(in[i.second]-1);
	for (int i=0;i<26;i++)
		if (~tree[x].nxt[i])
			dfs2(tree[x].nxt[i]);
	modify(in[x],-1);
	return ;
}

int main()
{
	memset(head,-1,sizeof head);
	scanf("%d",&n);root=newnode();
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&opt);
		if (opt==1)
		{
			scanf("%s",s);now=root;
			if (!~tree[now].nxt[s[0]-'a']) tree[now].nxt[s[0]-'a']=newnode();
			now=tree[now].nxt[s[0]-'a'];
		}
		else
		{
			scanf("%d %s",&p,s);now=ed[p];
			if (!~tree[now].nxt[s[0]-'a']) tree[now].nxt[s[0]-'a']=newnode();
			now=tree[now].nxt[s[0]-'a'];
		}
		ed[i]=now;
	}
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d %s",&p,s);
		qu[ed[p]].push_back(make_pair(i,add(s)));
	}
	Get_Fail();
	dfs1(0,-1);dfs2(0);
	for (int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}