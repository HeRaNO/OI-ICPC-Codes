#include <bits/stdc++.h>
#define MAXN 1000010
using namespace std;

struct Trie
{
	int nxt[26];int cnt;
};

Trie p[MAXN],q[MAXN];
int n,r1,r2,t1,t2;
char s[MAXN];

inline int newnode(Trie tree[],int &top)
{
	memset(tree[top].nxt, -1, sizeof tree[top].nxt);
	tree[top++].cnt=0;
	return top-1;
}

inline void add(char S[],int len)
{
	int now=r1;
	for(int i=0;i<len;i++)
	{
		if(!~p[now].nxt[S[i]-'a']) p[now].nxt[S[i]-'a']=newnode(p,t1);
		now=p[now].nxt[S[i]-'a'];
		++p[now].cnt;
	}
	return ;
}

inline void addneg(char S[],int len)
{
	int now=r2;
	for(int i=len-1;~i;i--)
	{
		if(!~q[now].nxt[S[i]-'a']) q[now].nxt[S[i]-'a']=newnode(q,t2);
		now=q[now].nxt[S[i]-'a'];
		++q[now].cnt;
	}
	return ;
}

inline int query(char S[],int l)
{
	int now=r1;
	for (int i=0;i<l;i++)
	{
		if (!~p[now].nxt[S[i]-'a']) return 0;
		now=p[now].nxt[S[i]-'a'];
	}
	return p[now].cnt;
}

inline int queryneg(char S[],int l)
{
	int now=r2;
	for (int i=l-1;~i;i--)
	{
		if (!~q[now].nxt[S[i]-'a']) return 0;
		now=q[now].nxt[S[i]-'a'];
	}
	return q[now].cnt;
}

int main()
{
	scanf("%d",&n);
	r1=newnode(p,t1);r2=newnode(q,t2);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s);int l=strlen(s);
		printf("%d %d\n",query(s,l),queryneg(s,l));
		add(s,l);addneg(s,l);
	}
	return 0;
}