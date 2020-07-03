#include <bits/stdc++.h>
using namespace std;

int n,x;

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if (x&1) return puts("Alice"),0;
	}
	puts("Bob");
	return 0;
}