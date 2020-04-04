#include <bits/stdc++.h>
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	for (int i=2;i*i<=n;i++)
		if (!(n%i))
		{
			while (!(n%i)) printf("%d",i),n/=i;
		}
	if (n!=1) printf("%d\n",n);
	else puts("");
	return 0;
}