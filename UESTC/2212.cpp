#include <bits/stdc++.h>
#define MAXL 1000010
#define MAXN 100010
using namespace std;

struct Trie
{
	int fail,nxt[26];
	vector <int> end;
};

Trie tree[MAXL];
int n, T, root, top, cnt[MAXN];
char s[MAXL],t[MAXL];
queue <int> q;

inline int newnode()
{
	memset(tree[top].nxt, -1, sizeof tree[top].nxt);
	tree[top].fail = -1; ++top;
	return top - 1;
}

inline void add(char S[],int id)
{
	int len = strlen(S);
	int now = root;
	for (int i = 0; i < len; i++)
	{
		if (!~tree[now].nxt[S[i] - 'a']) tree[now].nxt[S[i] - 'a'] = newnode();
		now = tree[now].nxt[S[i] - 'a'];
	}
	tree[now].end.push_back(id);
	return ;
}

inline void Get_Fail()
{
	int u, now;
	q.push(root);
	while (!q.empty())
	{
		u = q.front();
		q.pop();
		for (int i = 0; i < 26; i++)
		{
			int c=tree[u].nxt[i];
			if (!~c){tree[u].nxt[i]=tree[tree[u].fail].nxt[i];continue;}
			q.push(c);
			int f=tree[u].fail;
			while (~f&&!~tree[f].nxt[i]) f=tree[f].fail;
			tree[c].fail=tree[f].nxt[i];
		}
	}
	return ;
}

inline void Aho_Corasick_Automation(char S[])
{
	int len = strlen(S), cur, now = root;
	for (int i = 0; i < len; i++)
	{
		now=tree[now].nxt[S[i]-'a'];
		cur=now;
		while (cur!=root)
		{
			if (tree[cur].end.size())
			{
				int ll=tree[cur].end.size();
				for (int j=0;j<ll;j++) ++cnt[tree[cur].end[j]];
			}
			cur=tree[cur].fail;
		}
	}
	for (int i = 1; i <= T; i++) printf("%d\n", cnt[i]);
	return ;
}

int main()
{
	scanf("%s",t);root=newnode();
	scanf("%d",&T);
	for (int i=1;i<=T;i++)
	{
		scanf("%s",s);add(s,i);
	}
	Get_Fail();
	Aho_Corasick_Automation(t);
	return 0;
}