#include <bits/stdc++.h>
#define MAXN 1000005
using namespace std;

const long long M=998244353;

int n,k,x,cnt[MAXN];
long long inv[MAXN],ans;
vector <int> v[MAXN];

int main()
{
	inv[1]=1;
	for (int i=2;i<=1000000;i++) inv[i]=(M-M/i)*inv[M%i]%M;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		for (int j=1;j<=k;j++)
		{
			scanf("%d",&x);
			v[i].push_back(x);++cnt[x];
		}
	}
	for (int i=1;i<=n;i++)
		for (auto j:v[i])
			(ans+=inv[n]*cnt[j]%M*inv[v[i].size()])%=M;
	(ans*=inv[n])%=M;
	printf("%lld\n",ans);
	return 0;
}