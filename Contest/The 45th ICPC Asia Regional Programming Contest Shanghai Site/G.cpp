#include <bits/stdc++.h>
using namespace std;

inline long long C(long long x)
{
	return x*(x-1)/2;
}

int main()
{
	int n;
	scanf("%d",&n);
	printf("%lld\n",C(n)-C(n-n/3));
	return 0;
}