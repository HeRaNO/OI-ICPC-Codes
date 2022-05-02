#include <cstdio>
#define MAXN 100010
using namespace std;

const long long M = 1e9 + 7;

long long inv[MAXN], ans = 1;
int n;

int main()
{
	scanf("%d", &n);
	inv[1] = 1;
	for (int i = n + 2; i <= (n << 1); i++) ans = ans * i % M;
	for (int i = 2; i <= n; i++) inv[i] = (M - M / i) * inv[M % i] % M;
	for (int i = 1; i <= n; i++) ans = ans * inv[i] % M;
	printf("%lld\n", ans);
	return 0;
}
