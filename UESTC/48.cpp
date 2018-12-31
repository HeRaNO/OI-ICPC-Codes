#include <cstdio>
using namespace std;

int main()
{
	long long a, b;
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lld %lld", &a, &b);
		printf("%lld\n", a * b - 1); //(a-1)+a*(b-1)
	}
	return 0;
}