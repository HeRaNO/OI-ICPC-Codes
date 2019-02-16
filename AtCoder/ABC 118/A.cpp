#include <bits/stdc++.h>
using namespace std;

int n,a,b;

int main()
{
	scanf("%d %d",&a,&b);
	for (int i=1;i<=20;i++)
		if (a*i==b) return printf("%d\n",a+b),0;
	printf("%d\n",b-a);
	return 0;
}