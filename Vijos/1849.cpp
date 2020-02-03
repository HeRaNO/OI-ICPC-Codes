#include <cstdio>
using namespace std;

long long a[1000001] = {0};
char c[1000001] = {0};
int ans = 0;

int main()
{
	int i = 2;
	scanf("%d", &a[1]);
	while (scanf("%c", &c[i++]) != EOF)
		scanf("%lld", &a[i++]);
	i -= 2;
	for (int j = i; j > 0; j--)
		if (c[j] == '*')
		{
			a[j - 1] *= a[j + 1];
			a[j - 1] %= 10000;
		}
	for (int j = 1; j <= i; j++)
		if (c[j] == '+')
		{
			ans += a[j + 1];
			ans %= 10000;
		}
	printf("%d", (ans + a[1]) % 10000);
	return 0;
}