#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

const long long M=1e9+7;

int T,n,now,o,x;
char s[MAXN];
long long ans[MAXN],inv[MAXN],fac[MAXN],invfac[MAXN],f[MAXN],_25[MAXN];
vector <pair<int,int> > q[MAXN];

inline void Init()
{
	int n=1e5;inv[1]=fac[0]=invfac[0]=_25[0]=1LL;
	for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%M;
	for (int i=2;i<=n;i++) inv[i]=(M-M/i)*inv[M%i]%M;
	for (int i=1;i<=n;i++) invfac[i]=invfac[i-1]*inv[i]%M;
	for (int i=1;i<=n;i++) _25[i]=_25[i-1]*25%M;
	return ;
}

inline long long C(int n,int m)
{
	return fac[n]*invfac[m]%M*invfac[n-m]%M;
}

inline void Calc(int s,int n)
{
	for (int i=0;i<s;i++) f[i]=0;f[s]=1;
	for (int i=s+1;i<=n;i++)
		f[i]=(26*f[i-1]%M+C(i-1,s-1)*_25[i-s]%M)%M;
	return ;
}

int main()
{
	Init();
	scanf("%d",&T);scanf("%s",s);now=strlen(s);
	for (int i=1;i<=T;i++)
	{
		scanf("%d",&o);
		if (o==1)
		{
			scanf("%s",s);now=strlen(s);
		}
		else
		{
			scanf("%d",&x);q[now].push_back({x,++n});
		}
	}
	for (int i=1;i<=100000;i++)
	{
		if (!q[i].size()) continue;
		sort(q[i].begin(),q[i].end());
		Calc(i,q[i].back().first);
		for (auto j:q[i]) ans[j.second]=f[j.first];
	}
	for (int i=1;i<=n;i++) printf("%lld\n",ans[i]);
	return 0;
}