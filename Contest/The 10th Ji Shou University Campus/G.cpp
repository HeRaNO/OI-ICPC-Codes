#include <bits/stdc++.h>
#define MAXN 100005
#define MAXM 305
using namespace std;

const int M=1000000007;

struct Trie
{
	int fail,nxt[26];
};

Trie tree[MAXN];
int n,Q,T=1,rt,k,m,a,b,top,cnt[MAXN],c[MAXN];
int dp[MAXN][MAXM],in[MAXN],out[MAXN];
char s[MAXN];
queue <int> q;
vector <int> v[MAXN],g[MAXN],tmp;

inline int fadd(int a,int b){a+=b;return a>=M?a-M:a;}
inline int lowbit(int x){return x&-x;}
inline void modify(int x,int v){for (;x<=top;x+=lowbit(x)) c[x]+=v;return ;}
inline int query(int x){int r=0;for (;x;x-=lowbit(x)) r+=c[x];return r;}

inline int newnode()
{
	memset(tree[top].nxt,-1,sizeof tree[top].nxt);
	tree[top++].fail=0;
	return top-1;
}

inline void add(char S[],int id)
{
	int n=strlen(S),u=rt;
	v[id].push_back(0);
	for (int i=0;i<n;i++)
	{
		if (!~tree[u].nxt[S[i]-'a']) tree[u].nxt[S[i]-'a']=newnode();
		u=tree[u].nxt[S[i]-'a'];
		v[id].push_back(u);
	}
	return ;
}

inline void Get_Fail()
{
	tree[rt].fail=rt;
	for (int i=0;i<26;i++)
	{
		if (!~tree[rt].nxt[i]) tree[rt].nxt[i]=rt;
		else {tree[tree[rt].nxt[i]].fail=rt;q.push(tree[rt].nxt[i]);}
	}
	while (!q.empty())
	{
		int u=q.front();q.pop();
		for (int i=0;i<26;i++)
			if (~tree[u].nxt[i])
			{
				tree[tree[u].nxt[i]].fail=tree[tree[u].fail].nxt[i];
				q.push(tree[u].nxt[i]);
			}
			else tree[u].nxt[i]=tree[tree[u].fail].nxt[i];
	}
	return ;
}

inline void dfs(int x)
{
	in[x]=T++;
	for (int v:g[x]) dfs(v);
	out[x]=T;
	return ;
}

int main()
{
	rt=newnode();
	scanf("%d %d",&n,&Q);
	for (int i=1;i<=n;i++) scanf("%s",s),add(s,i);
	Get_Fail();
	for (int i=1;i<top;i++) g[tree[i].fail].push_back(i);
	dfs(rt);
	while (Q--)
	{
		scanf("%d %d",&k,&m);tmp.clear();
		for (int i=1;i<=k;i++)
		{
			scanf("%d %d",&a,&b);
			int p=v[a][b];tmp.push_back(p);++cnt[p];
			modify(in[p],1);modify(out[p],-1);
		}
		sort(tmp.begin(),tmp.end(),[&](int &a,int &b){return in[a]<in[b];});
		dp[0][0]=1;
		for (int i=1;i<=k;i++)
		{
			int t=cnt[tmp[i-1]]-query(in[tmp[i-1]]);
			for (int j=1;j<=m;j++)
			{
				++t;
				if (t<=0) dp[i][j]=dp[i-1][j-1];
				else dp[i][j]=fadd(dp[i-1][j-1],1LL*t*dp[i-1][j]%M);
			}
			--cnt[tmp[i-1]];
		}
		printf("%d\n",dp[k][m]);
		for (int i:tmp) modify(in[i],-1),modify(out[i],1);
	}
	return 0;
}