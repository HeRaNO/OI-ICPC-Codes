#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;

int n,a[MAXN];

int main()
{
	scanf("%d",&n);int pt=0;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) if (a[pt]<a[i]) pt=i;
	for (int i=2;i<=pt;i++) if (a[i]<a[i-1]) return puts("no"),0;
	for (int i=n;i>pt;i--) if (a[i-1]<a[i]) return puts("no"),0;
	puts("yes");
	return 0;
}