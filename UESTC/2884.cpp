#include <cstdio>
#include <numeric>
#include <unordered_map>
#define MAXM 5000005

const int N = 5'000'000;

int prime[MAXM], mu[MAXM], s_mu[MAXM], tot;
bool not_prime[MAXM];

void init(int n)
{
	mu[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (!not_prime[i])
		{
			prime[++tot] = i;
			mu[i] = -1;
		}
		for (int j = 1; i * prime[j] <= n; j++)
		{
			not_prime[i * prime[j]] = true;
			if (!(i % prime[j]))
			{
				mu[i * prime[j]] = 0;
				break;
			}
			mu[i * prime[j]] = -mu[i];
		}
	}
	for (int i = 1; i <= n; i++)
		s_mu[i] = s_mu[i - 1] + mu[i];
	return ;
}

std::unordered_map<int, int> S_large;

int S_mu(int n)
{
	if (n <= N) return s_mu[n];
	if (S_large[n]) return S_large[n];
	int ans = 1;
	for (int i = 2, j; i <= n; i = j + 1)
	{
		j = n / (n / i);
		ans -= S_mu(n / i) * (j - i + 1);
	}
	return S_large[n] = ans;
}

long long sqr(int x){ return (long long)x * x; }

int main()
{
	init(N);
	int T; scanf("%d", &T);
	while (T--)
	{
		int l, r, n;
		scanf("%d %d", &l, &r); n = r - l + 1;
		long long q = (long long)n * (n - 1);
		long long p = -(l == 1);
		for (int i = 1, j; i < l; i = j + 1)
		{
			j = std::min((l - 1) / ((l - 1) / i), r / (r / i));
			p += sqr(r / i - (l - 1) / i) * (S_mu(j) - S_mu(i - 1));
			p -= sqr(r / i) * (S_mu(j) - S_mu(i - 1));
		}
		for (int i = 1, j; i <= r; i = j + 1)
		{
			j = r / (r / i);
			p += sqr(r / i) * (S_mu(j) - S_mu(i - 1));
		}
		long long g = std::gcd(p, q);
		printf("%lld/%lld\n", p / g, q / g);
	}
	return 0;
}