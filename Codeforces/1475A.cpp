#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		long long x;
		scanf("%lld",&x);
		puts(x&(x-1)?"YES":"NO");
	}
	return 0;
}