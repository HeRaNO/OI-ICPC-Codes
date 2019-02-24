#include <bits/stdc++.h>
using namespace std;

int n,a[410],pt=1;
int m[21][21],cnt[1001];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n*n;i++)
	{
		scanf("%d",&a[i]);++cnt[a[i]];
	}
	sort(a+1,a+n*n+1);
	for (int i=1;i<=n/2;i++)
		for (int j=1;j<=n/2;j++)
		{
			while (pt<=n*n)
			{
				if (cnt[a[pt]]>=4)
				{
					m[i][j]=a[pt];
					m[n-i+1][j]=a[pt];
					m[i][n-j+1]=a[pt];
					m[n-i+1][n-j+1]=a[pt];
					cnt[a[pt]]-=4;pt+=4;
					break;
				}
				else ++pt;
			}
		}
	pt=1;
	if (n&1)
	{
		for (int i=1;i<=n;i++)
		{
			while (pt<=n*n)
			{
				if (cnt[a[pt]]>=2)
				{
					m[i][n/2+1]=a[pt];
					m[n-i+1][n/2+1]=a[pt];
					cnt[a[pt]]-=2;pt+=2;
					break;
				}
				else ++pt;
			}
			while (pt<=n*n)
			{
				if (cnt[a[pt]]>=2)
				{
					m[n/2+1][i]=a[pt];
					m[n/2+1][n-i+1]=a[pt];
					cnt[a[pt]]-=2;pt+=2;
					break;
				}
				else ++pt;
			}
		}
		for (int i=1;i<=n*n;i++) if (cnt[a[i]]){m[n/2+1][n/2+1]=a[i];break;}
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (!m[i][j])
			{
				puts("NO");
				return 0;
			}
	puts("YES");
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			printf("%d%c",m[i][j],j==n?'\n':' ');
	return 0;
}
