#include <bits/stdc++.h>
using namespace std;

int a[100001];

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int pt=0,n;bool f=false;
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<=n;i++) if (a[pt]<a[i]) pt=i;
		if (pt==1||pt==n){puts("No");f=true;}
		for (int i=2;i<=pt&&!f;i++) if (a[i]<=a[i-1]) {puts("No");f=true;}
		for (int i=n;i>pt&&!f;i--) if (a[i-1]<=a[i]) {puts("No");f=true;}
		if (!f) puts("Yes");
	}
	return 0;
}