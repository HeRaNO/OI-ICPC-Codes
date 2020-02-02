#include <bits/stdc++.h>
#define MAXN 300005
using namespace std;

int n,T,a[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=0;i<n;i++) scanf("%d",&a[i]);
		int l=n-1,r=0;
		for (int i=0;i<n;i++) if (a[i]<i){l=i-1;break;}
		for (int i=n-1;~i;i--) if (a[i]<n-i-1){r=i+1;break;}
		puts(l>=r?"Yes":"No");
	}
	return 0;
}
