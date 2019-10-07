#include <bits/stdc++.h>
#define MAXN 500005
using namespace std;

struct link
{
	int to,val,nxt;
};

link e[MAXN<<1];
int head[MAXN],cnt;
int T,n,k,u,v,w;
long long dp[MAXN][2];
vector <long long> a[MAXN];

inline void add(int u,int v,int w)
{
	e[cnt]=(link){v,w,head[u]};head[u]=cnt++;
	e[cnt]=(link){u,w,head[v]};head[v]=cnt++;
}

inline void TreeDP(int x,int f)
{
	long long ans=0;a[x].clear();
	for (int i=head[x];~i;i=e[i].nxt)
		if (e[i].to!=f)
		{
			TreeDP(e[i].to,x);
			ans+=dp[e[i].to][0];
			if (dp[e[i].to][1]+e[i].val>dp[e[i].to][0])
				a[x].push_back(dp[e[i].to][1]+e[i].val-dp[e[i].to][0]);
		}
	sort(a[x].begin(),a[x].end(),greater<long long>());
	for (int i=0,p=min((int)a[x].size(),k);i<p;i++) ans+=a[x][i];
	dp[x][0]=dp[x][1]=ans;
	if (k<=a[x].size()) dp[x][1]-=a[x][k-1];
	return ;
}

inline void read(int &x)
{
	x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return ;
}

int main()
{
	read(T);
	while (T--)
	{
		read(n);read(k);cnt=0;
		for (int i=1;i<=n;i++) head[i]=-1;
		for (int i=1;i<n;i++) read(u),read(v),read(w),add(u,v,w);
		TreeDP(1,-1);
		printf("%lld\n",dp[1][0]);
	}
	return 0;
}