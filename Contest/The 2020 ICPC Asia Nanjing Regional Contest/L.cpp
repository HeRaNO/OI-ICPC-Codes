#include <bits/stdc++.h>
using namespace std;
const int N = 500050;
int n,m;
int a[N],b[N];

void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=2;i<=m+1;++i)scanf("%d",&b[i]);
	b[1] = -1e9;
	b[m+2] = 2e9;
	m=m+2;
	sort(a+1,a+n+1);sort(b+1,b+m+1);
	int ans = 0;
	for(int i=1;i<=m;++i)
	{
		int l = upper_bound(a+1,a+n+1,b[i-1])-a;
		int r = lower_bound(a+1,a+n+1,b[i])-a-1;
		ans=max(ans,r-l+1);
	}
	if(ans==0)return puts("Impossible"),void();
	printf("%d\n",ans);
}


int main()
{
	int Test;
	scanf("%d",&Test);
	while(Test--)solve();

	return 0;
}
