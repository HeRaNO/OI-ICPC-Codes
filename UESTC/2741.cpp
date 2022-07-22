#include <cstdio>
#include <algorithm>
#define MAXN 10000005

const int N = 10'000'000;
const int M = 1'000'000'007;

int inv[MAXN];

int fadd(int x, int y){ x += y; if (x >= M) x -= M; return x; }
int fsub(int x, int y){ x -= y; if (x <  0) x += M; return x; }
int fmul(int x, int y){ return 1LL * x * y % M; }

void init(int n)
{
	inv[1] = 1;
	for (int i = 2; i <= n; i++)
		inv[i] = fmul(M - M / i, inv[M % i]);
	return ;
}

int main()
{
	int n, x, ans = 0;
	init(N);
	scanf("%d %d", &n, &x);
	for (int i = 1; i <= n; i++)
	{
		int a, b;
		x ^= x << 13; x ^= x >> 17; x ^= x << 5; x %= 10000000; a = x;
		x ^= x << 13; x ^= x >> 17; x ^= x << 5; x %= 10000000; b = x;
		b = std::max(b, 1); a = std::max(a % b, 1);
		ans = fadd(ans, fmul(b, inv[a]));
	}
	printf("%d\n", ans);
	return 0;
}