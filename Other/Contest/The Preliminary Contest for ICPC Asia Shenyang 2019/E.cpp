#include <bits/stdc++.h>
#define MAXN 1010
#define MAXL 1000005
using namespace std;

int T,n,p;
long long b[MAXL],S[MAXN][MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		memset(S,0,sizeof S);
		scanf("%d %d",&n,&p);
		for (int i=1,l=min(n,p);i<=l;i++)
		{
			S[i][1]=1;b[i]=0;
			for (int j=2;j<=i;j++) S[i][j]=(j*S[i-1][j]%p+S[i-1][j-1])%p;
			for (int j=1;j<=i;j++) (b[i]+=S[i][j])%=p;
		}
		for (int i=1;i<=n-p;i++) b[p+i]=(b[i]+b[i+1])%p;
		printf("%lld\n",b[n]);
	}
	return 0;
}