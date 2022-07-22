#include <cstdio>
#include <vector>
#include <algorithm>

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	std::vector<int> x(n);
	for (int i = 0; i < n; i++) scanf("%d", &x[i]);
	std::sort(x.begin(), x.end());
	int l = k / 2, r = k - k / 2;
	std::vector<int> L(x.begin(), x.begin() + l);
	std::vector<int> R(x.rbegin(), x.rbegin() + r);
	for (; R.size(); R.pop_back()) L.push_back(R.back());
	long long ans = 0;
	for (int i = 1; i < k; i++)
		ans += 1LL * i * (k - i) * (L[i] - L[i - 1]);
	printf("%lld\n", ans);
	return 0;
}