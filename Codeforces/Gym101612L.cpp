#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void Init()
{
	freopen("little.in","r",stdin);
	freopen("little.out","w",stdout);
}

ll n;
vector <ll> v[100];
int cnt;

int main()
{
	Init();
	scanf("%lld",&n);
	for(ll i=0;i<=62;++i)
		if((1LL<<i)==n)return printf("-1\n"),0;
	v[++cnt].push_back(n);
	for (long long i=2;i*i*i<=n;i++)
	{
		long long p=n;
		int acnt=0,bcnt=0;
		if (n%i==0)
		{
			while (p%i==0)
			{
				p/=i;++acnt;
			}
			while (p%(i+1)==0)
			{
				p/=(i+1);++bcnt;
			}
			if (p==1)
			{
				++cnt;
				for (int j=1;j<=acnt;j++) v[cnt].push_back(i);
				for (int j=1;j<=bcnt;j++) v[cnt].push_back(i+1);
			}
		}
	}
	long long p=sqrt(n);
	if (p*p==n)
	{
		++cnt;
		v[cnt].push_back(p);v[cnt].push_back(p);
	}
	else if (p*(p+1)==n)
	{
		++cnt;
		v[cnt].push_back(p);v[cnt].push_back(p+1);
	}
	else if ((p+1)*(p+1)==n)
	{
		++cnt;
		v[cnt].push_back(p+1);v[cnt].push_back(p+1);
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;++i)
	{
		printf("%d",v[i].size());
		for(int j=0;j<v[i].size();++j)
		{
			printf(" %lld",v[i][j]);
		}
		puts("");
	}
	return 0;
}