#include <bits/stdc++.h>
#define MAXN 300010
using namespace std;

long long num[MAXN];
int T,n,ans[MAXN];

int main()
{
	for(long long i=1;i<=200005;i++) num[i]=(i-1)*i/2;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int t=lower_bound(num+1,num+100001,n)-num;
		int cnt=0;
		for(int i=t;i;i--)
		{
			while (n>=num[i]&&num[i])
			{
				n-=num[i];
				ans[++cnt]=1;
			}
			ans[++cnt]=3;
		}
		ans[++cnt]=7;
		for(int i=1;i<=cnt;i++) printf("%d",ans[i]);putchar('\n');
	}
	return 0;
}