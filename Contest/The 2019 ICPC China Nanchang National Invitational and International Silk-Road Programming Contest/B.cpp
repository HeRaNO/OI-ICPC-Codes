#include <bits/stdc++.h>
#define MAXN 1005
using namespace std;

const int M=9999991;

int inv[M],invfac[MAXN];
int T,l,r,n,m,y[MAXN],pre[MAXN],suf[MAXN];

inline void fadd(int &x,int y){x+=y;if (x>=M) x-=M;return ;}
inline int fsub(int x,int y){fadd(x,M-y);return x;}

inline void init(int n)
{
	inv[1]=invfac[0]=1;
	for (int i=2;i<=n;i++) inv[i]=1LL*(M-M/i)*inv[M%i]%M;
	for (int i=1;i<=n;i++) invfac[i]=1LL*invfac[i-1]*inv[i]%M;
	return ;
}

inline int F(int x)
{
	if (x<=n) return y[x];
	int ans=0;
	pre[0]=x;suf[n+1]=1;
	for (int i=1;i<=n;i++) pre[i]=1LL*pre[i-1]*(x-i)%M;
	for (int i=n;~i;i--) suf[i]=1LL*suf[i+1]*(x-i)%M;
	for (int i=0;i<=n;i++)
	{
		int t=y[i];
		if (i!=0) t=1LL*t*pre[i-1]%M;
		t=1LL*suf[i+1]*t%M;
		t=1LL*t*invfac[i]%M;
		if ((n-i)&1) t=1LL*t*(M-invfac[n-i])%M;
		else t=1LL*t*invfac[n-i]%M;
		fadd(ans,t);
	}
	return ans;
}

inline void Solve()
{
	scanf("%d %d",&n,&m);
	for (int i=0;i<=n;i++) scanf("%d",&y[i]);
	y[n+1]=F(n+1);++n;
	for (int i=1;i<=n;i++) fadd(y[i],y[i-1]);
	while (m--)
	{
		scanf("%d %d",&l,&r);
		printf("%d\n",fsub(F(r),F(l-1)));
	}
	return ;
}

int main()
{
	init(1000);
	scanf("%d",&T);
	while (T--) Solve();
	return 0;
}