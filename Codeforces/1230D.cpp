#include <bits/stdc++.h>
#define MAXN 7005
using namespace std;

bitset <7001> a[60],ans;
vector <int> v[MAXN];
long long x,b[MAXN];
int n,num[MAXN];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		for (int j=0;j<60;j++) if (x&(1LL<<j)) a[j][i]=1;
	}
	for (int i=1;i<=n;i++) scanf("%lld",&b[i]);
	for (int i=1;i<=n;i++)
	{
		ans.set();
		for (int j=0;j<60;j++) if (a[j][i]) ans&=a[j];
		for (int j=1;j<=n;j++) if (ans[j]&&i!=j) v[j].push_back(i),++num[i];
	}
	bool flag=1;
	while (flag)
	{
		flag=0;
		for (int i=1;i<=n;i++)
			if (!num[i]&&b[i])
			{
				b[i]=0;
				flag=1;
				for(int j=0;j<v[i].size();j++) num[v[i][j]]--;
			}
	}
	long long p=0;int cnt=0;
	for(int i=1;i<=n;i++)
		if(b[i])
		{
			p+=b[i];
			cnt++;
		}
	if (cnt>=2) printf("%lld\n",p);
	else puts("0");
	return 0;
}