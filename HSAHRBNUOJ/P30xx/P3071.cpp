#include <cstdio>
using namespace std;
long long a, b;
long long gcd(long long a, long long b)
{
	return b == 0 ? a : gcd(b, a % b);
}
long long lcm(long long a, long long b)
{
	return a * b / gcd(a, b);
}
int main()
{
	scanf("%lld %lld", &a, &b);
	printf("%lld %lld\n", gcd(a, b), lcm(a, b));
	return 0;
}
