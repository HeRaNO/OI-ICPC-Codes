#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
	scanf("%d",&n);
	for (int i=2;i<n;i+=2)
		if ((n-i)%2==0) return puts("YES"),0;
	puts("NO");
	return 0;
}