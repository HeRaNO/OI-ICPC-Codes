#include <bits/stdc++.h>
#define MAXN 5005
using namespace std;

const long long M=998244353;

long long ans,S[MAXN][MAXN];
long long n,m,p;
int k;

inline long long fpow(long long a,long long b)
{
	if (a==1) return 1;
	if (!a) return 0;
	long long r=1;
	for (;b;a=(a*a)%M,b>>=1) if (b&1) r=(r*a)%M;
	return r;
}

int main()
{
	for (int i=1;i<=5000;i++)
	{
		S[i][0]=0;S[i][i]=1;
		for (int j=1;j<i;j++)
			S[i][j]=(S[i-1][j-1]+j*S[i-1][j]%M)%M;
	}
	scanf("%lld %lld %d",&n,&m,&k);p=fpow(m,M-2);
	for (int i=1;i<=k;i++)
	{
		long long x=S[k][i];
		for (int j=0;j<i;j++) (x*=(n-j))%=M;
		x*=fpow(p,i);x%=M;
		(ans+=x)%=M;
	}
	printf("%lld\n",ans);
	return 0;
}