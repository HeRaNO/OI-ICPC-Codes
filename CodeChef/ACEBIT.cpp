#include <bits/stdc++.h>
using namespace std;

inline void Solve()
{
	long long x;
	scanf("%lld",&x);
	printf("%d\n",__builtin_popcountll(x));
	return ;
}

int main()
{
	int T;scanf("%d",&T);
	while (T--) Solve();
	return 0;
}