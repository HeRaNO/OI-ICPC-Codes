#include <bits/stdc++.h>
using namespace std;

inline int A(long long n)
{
	if (n==1) return 0;
	if (n&1) return A(n+1)+1;
	else return A(n>>1)+1;
}

int main(int argc, char const *argv[])
{
	long long n;
	scanf("%lld",&n);
	printf("%d\n",A(n));
	return 0;
}