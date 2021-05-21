// std.cpp: Model solution of 'expected-range'
// Method: Cartesian tree, DFS
// Time complexity: O(n)
// Author: HeRaNO
#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;

const int M=1000000007;

int n,ans,a[MAXN],sta[MAXN],ls[MAXN],rs[MAXN],in[MAXN],sz[MAXN];

inline void fadd(int &x,int y){x+=y;if (x>=M) x-=M;return ;}

inline int fpow(int a,int b)
{
	int r=1;
	for (;b;b>>=1,a=1LL*a*a%M) if (b&1) r=1LL*r*a%M;
	return r;
}

inline void dfs(int x)
{
	sz[x]=1;
	if (ls[x]) dfs(ls[x]);
	if (rs[x]) dfs(rs[x]);
	sz[x]+=sz[ls[x]]+sz[rs[x]];
	return ;
}

bool lt(int a,int b){return a<b;}
bool gt(int a,int b){return a>b;}

inline int BuildTree(bool comp(int,int))
{
	int top=0;
	for (int i=1;i<=n;i++)
	{
		int k=top;in[i]=0;
		for (;k&&comp(a[sta[k]],a[i]);--k);
		if (k) rs[sta[k]]=i;
		if (k<top) ls[i]=sta[k+1];
		sta[++k]=i;top=k;
	}
	int rt=0,ans=0,rtcnt=0;
	for (int i=1;i<=n;i++) ++in[ls[i]],++in[rs[i]];
	for (int i=1;i<=n;i++) assert(in[i]<=1),rtcnt+=(in[i]==0);
	assert(rtcnt==1);
	for (int i=1;i<=n&&!rt;i++) if (!in[i]) rt=i;
	assert(rt!=0);
	dfs(rt);
	for (int i=1;i<=n;i++)
		fadd(ans,1LL*a[i]*(sz[ls[i]]+1)%M*(sz[rs[i]]+1)%M);
	return ans;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	fadd(ans,BuildTree(lt));
	memset(ls,0,sizeof ls);memset(rs,0,sizeof rs);
	fadd(ans,BuildTree(gt));
	printf("%d\n",1LL*ans*fpow(1LL*n*(n+1)%M,M-2)%M);
	return 0;
}