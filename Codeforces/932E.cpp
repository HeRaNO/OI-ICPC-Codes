#include <bits/stdc++.h>
#define MAXK 5005
using namespace std;

const long long M=1e9+7;
const long long inv2=(M+1)>>1;

int n,k;
long long S[MAXK][MAXK],ans,fac,_2;

long long fpow(long long a,long long b)
{
	long long r=1;
	for (;b;b>>=1,(a*=a)%=M) if (b&1) (r*=a)%=M;
	return r;
}

int main()
{
	scanf("%d %d",&n,&k);
	for (int i=1;i<=k;i++)
	{
		S[i][0]=0;S[i][i]=1;
		for (int j=1;j<i;j++)
			S[i][j]=(S[i-1][j-1]+j*S[i-1][j]%M)%M;
	}
	fac=n;_2=fpow(2,n-1);
	for (int i=1;i<=k;i++)
	{
		long long r=S[k][i];
		(r*=fac)%=M;(r*=_2)%=M;(ans+=r)%=M;
		(fac*=(n-i))%=M;(_2*=inv2)%=M;
	}
	printf("%lld\n",ans);
	return 0;
}