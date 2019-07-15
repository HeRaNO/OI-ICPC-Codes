#include <cstdio>
using namespace std;

long long a, b, ans = 1;

int main()
{
	scanf("%I64d %I64d", &a, &b);
	if (b - a >= 10)
	{
		puts("0");
		return 0;
	}
	for (long long i = a + 1; i <= b; i++) ans = (ans * i) % 10;
	printf("%I64d\n", ans);
	return 0;
}