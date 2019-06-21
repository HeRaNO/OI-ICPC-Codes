#include <bits/stdc++.h>
#define MAXN 205
#define MAXL 205
using namespace std;

const long long M=1e9+7;

struct Tire
{
	int fail,nxt[26];
	bool f;
};

struct Matrix
{
	long long m[MAXN][MAXN];int n;
	Matrix operator *(const Matrix &a)const{
		Matrix res;res.n=n;
		for (int i=0;i<=n;i++)
			for (int j=0;j<=n;j++)
			{
				res.m[i][j]=0LL;
				for (int k=0;k<=n;k++) (res.m[i][j]+=m[i][k]*a.m[k][j]%M)%=M;
			}
		return res;
	}
}r,b;

Tire tree[MAXN * MAXL];
char s[MAXL];
int n, root, top;
long long l,p,ans;
queue <int> q;

inline int newnode()
{
	memset(tree[top].nxt, -1, sizeof tree[top].nxt);
	tree[top].fail = -1;
	tree[top++].f = false;
	return top - 1;
}

inline void add(char S[])
{
	int len = strlen(S);
	int now = root;
	for (int i = 0; i < len; i++)
	{
		if (!~tree[now].nxt[S[i] - 'a']) tree[now].nxt[S[i] - 'a'] = newnode();
		now = tree[now].nxt[S[i] - 'a'];
	}
	tree[now].f = true;
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
		tree[u].f|=tree[tree[u].fail].f;
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

inline long long qpow(long long a,long long b)
{
	long long r=1;
	for (;b;a=(a*a)%M,b>>=1LL) if (b&1) r=(r*a)%M;
	return r;
}

int main()
{
	scanf("%d",&n);root=newnode();
	for (int i=1;i<=n;i++) scanf("%s",s),add(s);
	Get_Fail();
	scanf("%lld",&l);p=l;
	r.n=top;b.n=top;
	for (int i=0;i<=top;i++) r.m[i][i]=1LL;
	for (int i=0;i<top;i++)
		for (int j=0;j<26;j++)
			if (!tree[tree[i].nxt[j]].f)
				++b.m[i][tree[i].nxt[j]];
	for (int i=0;i<=top;i++) b.m[i][top]=1;
	++l;
	while (l)
	{
		if (l&1) r=r*b;
		b=b*b;
		l>>=1LL;
	}
	ans=(r.m[0][top]-1+M)%M;
	long long all=qpow(26LL,p+1);
	all=(all-26+M)%M;
	(all*=qpow(25LL,M-2))%=M;
	printf("%lld\n",(all-ans+M)%M);
	return 0;
}