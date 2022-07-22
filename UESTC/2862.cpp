#include <cstdio>
#include <vector>
#include <functional>
#define MAXN 200005

const int Z = 200000;

char s[MAXN];

int main()
{
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	long long ans = 0;
	for (char c = 'a'; c <= 'z'; c++)
	{
		std::vector<int> t(Z * 2 + 1, 0);
		std::vector<int> f(n + 1, 0);
		for (int i = 0; i < n; i++)
			f[i + 1] = f[i] + (s[i] == c);
		std::function<void(int)> add = [&](int x) {
			for (; x <= Z * 2; x += x & -x) ++t[x];
			return ;
		};
		std::function<int(int)> query = [&](int x) {
			int r = 0;
			for (; x; x -= x & -x) r += t[x];
			return r;
		};
		add(Z);
		for (int i = 1; i <= n; i++)
		{
			f[i] = f[i] * 2 - i;
			ans += query(f[i] - 1 + Z);
			add(f[i] + Z);
		}
	}
	printf("%lld\n", ans);
	return 0;
}