#include <bits/stdc++.h>
using namespace std;

int n;

bool prime(int x)
{
	if (x==2) return true;
	for (long long i=2;i*i<=x;i++)
		if (!(x%i)) return false;
	return true;
}

int main()
{
	scanf("%d",&n);
	if (prime(n)) return puts("1"),0;
	if (!(n&1)) return puts("2"),0;
	if (prime(n-2)) return puts("2"),0;
	puts("3");
	return 0;
}