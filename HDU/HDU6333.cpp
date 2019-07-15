#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;

const long long MOD=1e9+7;

struct Modui
{
	int l,r,id;
};

Modui a[MAXN];
int T,n,m,mx,pos[MAXN];
long long fac[MAXN], inv[MAXN], invfac[MAXN], ans[MAXN], now = 1;

inline void Get_Factor_and_Inv(int n)
{
	fac[0] = inv[1] = fac[1] = invfac[0] = invfac[1] = 1LL;
	for (int i = 2; i <= n; i++) inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
	for (int i = 2; i <= n; i++) fac[i] = (fac[i - 1] * i) % MOD, invfac[i] = (invfac[i - 1] * inv[i]) % MOD;
	return ;
}

inline long long C(int n, int m)
{
	return fac[n] * invfac[m] % MOD * invfac[n - m] % MOD;
}

bool cmp(Modui a, Modui b)
{
	return pos[a.l] == pos[b.l] ? a.r < b.r : a.l < b.l;
}

inline void ModuiAlgorithm()
{
	int l = 1, r = 0;
	for (int i = 1; i <= T; i++)
	{
		while (r < a[i].r) now=(2*now%MOD-C(r++,l)+MOD)%MOD;
		while (r > a[i].r) now=(now+C(--r,l))%MOD*inv[2]%MOD;
		while (l < a[i].l) now=(now+C(r,++l))%MOD;
		while (l > a[i].l) now=(now-C(r,l--)+MOD)%MOD;
		ans[a[i].id] = now;
	}
	return ;
}

int main()
{
	Get_Factor_and_Inv(100000);
	scanf("%d",&T);
	for (int i=1;i<=T;i++)
	{
		scanf("%d %d",&n,&m);
		mx=max(mx,n);
		a[i].l=m;a[i].r=n;a[i].id=i;
	}
	m=(int)sqrt(mx);
	for (int i=1;i<=mx;i++) pos[i]=(i-1)/m+1;
	sort(a+1,a+T+1,cmp);
	ModuiAlgorithm();
	for (int i=1;i<=T;i++) printf("%lld\n",ans[i]);
	return 0;
}