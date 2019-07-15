#include <bits/stdc++.h>
#define MAXK 100010
using namespace std;

const long long M=1e9+7;

int n,m,cnt;
long long _2[MAXK],ans;
char k[MAXK];

int main()
{
	_2[0]=1LL;
	for (int i=1;i<=100000;i++) _2[i]=_2[i-1]*2%M;
	while (~scanf("%d %s",&n,k))
	{
		m=strlen(k);ans=1LL;cnt=n-m;
		for (int i=0;i<m;i++)
		{
			if (k[i]=='0') ++cnt;
			else
			{
				long long p=(_2[cnt]-1+M)%M*_2[m-i-1]%M;
				(ans*=p)%=M;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}