#include <bits/stdc++.h>
using namespace std;

int T;char a[10];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%s",a);
		int p=a[0];p+=a[1];p+=a[2];
		printf("%.2lf\n",(double)p/3.0);
	}
	return 0;
}
