#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

int n,m,a[MAXN];
inline int f(int x){return x*x;}

int main()
{
	while (scanf("%d %d",&n,&m)==2)
	{
		a[0]=0;int s=0;
		for (int i=1;i*i<=n;i++)
			if (!(n%i))
			{
				int t=i;
				for (;t;t/=m) s+=f(t%m);
				t=n/i;if (t==i) continue;
				for (;t;t/=m) s+=f(t%m);
			}
		for (;s;s/=m) a[++a[0]]=s%m;
		for (int i=a[0];i;i--)
		{
			if (a[i]>=10) putchar(a[i]-10+'A');
			else putchar(a[i]+'0');
		}
		putchar('\n');
	}
	return 0;
}