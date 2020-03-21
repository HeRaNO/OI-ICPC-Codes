#include <bits/stdc++.h>
#define MAXN 105
using namespace std;

int n,m;
char a[MAXN],b[MAXN];

int main()
{
	scanf("%d %d",&n,&m);
	scanf("%s",a);reverse(a,a+n);
	scanf("%s",b);reverse(b,b+m);
	for (int i=0;i<m-n;i++)
	{
		int x=b[i]-a[i];if (x<0) x+=26;
		a[i+n]=x+'a';
	}
	reverse(a,a+m);
	puts(a);
	return 0;
}