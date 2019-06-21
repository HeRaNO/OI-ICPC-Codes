#include <bits/stdc++.h>
#define MAXL 505
using namespace std;

struct Tire
{
	int fail,nxt[26];
	long long val;
};

struct Matrix
{
	long long m[MAXL][MAXL];int n;
	Matrix operator *(const Matrix &a)const{
		Matrix res;res.n=n;
		memset(res.m,-1,sizeof res.m);
		for (int k=0;k<=n;k++)
			for (int i=0;i<=n;i++)
				if (~m[i][k])
				{
					for (int j=0;j<=n;j++)
						if (~a.m[k][j]) res.m[i][j]=max(res.m[i][j],m[i][k]+a.m[k][j]);
				}
		return res;
	}
}r,b;

Tire tree[MAXL];
char s[MAXL];
int n, root, top, x;
long long l,ans,a[MAXL];
queue <int> q;

inline int newnode()
{
	memset(tree[top].nxt, -1, sizeof tree[top].nxt);
	tree[top].fail = -1;
	tree[top++].val = 0;
	return top - 1;
}

inline void add(char S[],int x)
{
	int len = strlen(S);
	int now = root;
	for (int i = 0; i < len; i++)
	{
		if (!~tree[now].nxt[S[i] - 'a']) tree[now].nxt[S[i] - 'a'] = newnode();
		now = tree[now].nxt[S[i] - 'a'];
	}
	tree[now].val += x;
	return ;
}

inline void Get_Fail()
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
		tree[u].val+=tree[tree[u].fail].val;
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
	return ;
}

int main()
{
	memset(b.m,-1,sizeof b.m);memset(r.m,-1,sizeof r.m);
	root=newnode();scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%s %d",s,&x),add(s,x);
	Get_Fail();b.n=top-1;
	for (int i=0;i<top;i++)
		for (int j=0;j<26;j++)
			b.m[i][tree[i].nxt[j]]=tree[tree[i].nxt[j]].val;
	scanf("%lld",&l);
	r=b;--l;
	for (;l;b=b*b,l>>=1) if (l&1) r=r*b;
	for (int i=0;i<=r.n;i++) ans=max(ans,r.m[0][i]);
	printf("%lld\n",ans);
	return 0;
}