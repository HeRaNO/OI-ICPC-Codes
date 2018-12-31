//Code By HeRaNO
#include <cstdio>
using namespace std;

int gcd(int m, int n)
{
	return m % n == 0 ? n : gcd(n, m % n);
}

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d\n", gcd(a, b));
	return 0;
}
