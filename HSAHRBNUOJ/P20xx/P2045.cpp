#include <cstdio>
using namespace std;

int T;
long long a;

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lld", &a);
		if (a == 2)
		{
			puts("1");
			continue;
		}
		if (a & 1) printf("%lld\n", ((a >> 1) + 1) * (a >> 1));
		else
		{
			if (a % 4 == 0) printf("%lld\n", ((a >> 1) - 1) * ((a >> 1) + 1));
			else printf("%lld\n", ((a >> 1) - 2) * ((a >> 1) + 2));
		}
	}
	return 0;
}
