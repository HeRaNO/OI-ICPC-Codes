#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int n,x;
long long ans=1;
vector <int> v[MAXN];

inline long long fpow(long long a,long long b)
{
	long long r=1;
	for (;b;b>>=1,a*=a) if (b&1) r*=a;
	return r;
}

int main()
{
	scanf("%d",&n);
	for (int j=1;j<=n;j++)
	{
		scanf("%d",&x);
		for (int i=2,p=x;i*i<=p;i++)
			if (!(x%i))
			{
				int c=0;
				while (!(x%i)) x/=i,++c;
				v[i].push_back(c);
			}
		if (x) v[x].push_back(1);
	}
	for (int i=2;i<=200000;i++)
	{
		sort(v[i].begin(),v[i].end());
		if (v[i].size()>=n-1)
		{
			if (v[i].size()==n) ans*=fpow(i,v[i][1]);
			else ans*=fpow(i,v[i][0]);
		}
	}
	printf("%lld\n",ans);
	return 0;
}