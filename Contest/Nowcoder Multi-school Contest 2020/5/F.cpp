#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

int a[MAXN],mx;
int n;

inline int ceil(long long x,int y)
{
	if (!y) return 0;
	if (x%y) return x/y+1;
	else return x/y;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		mx=max(mx,a[i]);
	}
	for (int i=1;i<=n;i++)
	{
		if (!a[i])
		{
			puts("++");
			puts("||0");
			puts("++");
			continue;
		}
		int l=ceil(50LL*a[i],mx);
		putchar('+');
		for (int j=1;j<=l;j++) putchar('-');
		puts("+");
		putchar('|');
		for (int j=1;j<l;j++) putchar(' ');
		if (a[i]==mx) putchar('*');
		else putchar(' ');
		putchar('|');
		printf("%d\n",a[i]);
		putchar('+');
		for (int j=1;j<=l;j++) putchar('-');
		puts("+");
	}
	return 0;
}