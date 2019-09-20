#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

struct Trie
{
	int fail,nxt[26],ans,k,id,len,to;
	vector <int> v;
};

Trie tree[MAXN];
int root, top, n, ans[MAXN], k;
char s[MAXN], m[MAXN];
queue <int> q;

inline void add(char S[],int k, int id)
{
	int len = strlen(S);
	int now = root;
	for (int i = 0; i < len; i++)
	{
		if (!tree[now].nxt[S[i] - 'a']) tree[now].nxt[S[i] - 'a'] = ++top;
		tree[tree[now].nxt[S[i] - 'a']].len = tree[now].len + 1;
		now = tree[now].nxt[S[i] - 'a'];
	}
	tree[now].k=k;tree[now].id=id;
	tree[now].ans=~(1<<31);
	return ;
}

inline void Get_Fail()
{
	int u, now;
	for (int i=0;i<26;i++)
		if (tree[root].nxt[i])
			q.push(tree[root].nxt[i]);
	while (!q.empty())
	{
		u = q.front();
		q.pop();
		if (tree[tree[u].fail].id) tree[u].to=tree[u].fail;
		else tree[u].to=tree[tree[u].fail].to;
		for (int i = 0; i < 26; i++)
		{
			int c=tree[u].nxt[i];
			if (!c){tree[u].nxt[i]=tree[tree[u].fail].nxt[i];continue;}
			q.push(c);
			int f=tree[u].fail;
			tree[c].fail=tree[f].nxt[i];
		}
	}
	return ;
}

inline void work()
{
	int len = strlen(s);
	int now = root;
	for (int i = 0; i < len; i++)
	{
		now=tree[now].nxt[s[i]-'a'];
		for (int p=now;p;p=tree[p].to)
			if (tree[p].id)
			{
				tree[p].v.push_back(i);
				if (tree[p].v.size()>=tree[p].k)
				{
					int t=tree[p].v.size(),k=tree[p].k;
					tree[p].ans=min(tree[p].ans,i-(tree[p].v[t-k]-tree[p].len));
				}
			}
	}
	return ;
}

int main()
{
	scanf("%s",s);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d %s",&k,m);
		add(m,k,i);
	}
	Get_Fail();
	work();
	for (int i=1;i<=top;i++)
		if (tree[i].id)
			ans[tree[i].id]=tree[i].ans==~(1<<31)?-1:tree[i].ans;
	for (int i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}