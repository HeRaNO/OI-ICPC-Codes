#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;

float a[MAXN];
int n,T;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);float ans=1e9;bool f;
		for (int i=1;i<=n;i++) scanf("%f",&a[i]);
		for (int i=1;i<n;i++)
			if (ans>fabs(a[i+1]-a[i]))
			{
				ans=fabs(a[i+1]-a[i]);
				f=(a[i+1]-a[i])<0;
			}
		printf("%.2f\n",f?-ans:ans);
	}
	return 0;
}