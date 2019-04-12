#include <bits/stdc++.h>
using namespace std;

int n,a[10];

int main()
{
	scanf("%d",&n);bool f=false;
	for (int i=0;i<=9;i++) a[i]=i;
	do{
		int p=0,q=0;
		for (int i=0;i<=4;i++) p=p*10+a[i];
		for (int i=5;i<=9;i++) q=q*10+a[i];
		if (!(p%q)&&p/q==n)
		{
			f=true;
			for (int i=0;i<=4;i++) putchar(a[i]+'0');
			putchar('/');
			for (int i=5;i<=9;i++) putchar(a[i]+'0');
			printf("=%d\n",n);
		}
	}while(next_permutation(a,a+10));
	if (!f) puts("NO");
	return 0;
}
