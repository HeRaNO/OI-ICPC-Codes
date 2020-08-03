#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		long long n;
		scanf("%lld",&n);
		puts(n==1||n==24?"Fake news!":"Nobody knows it better than me!");
	}
	return 0;
}