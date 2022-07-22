#include <deque>
#include <cstdio>
#include <vector>
#include <algorithm>

long long solve(std::vector<int> &a)
{
	int n = a.size(); long long ans = 0;
	if (n >= 3)
	{
		if (n & 1) std::swap(*a.begin(), *(a.begin() + n - 3));
		else std::swap(*a.begin(), *(a.begin() + n - 2));
	}
	for (int i = 1; i < n; i++)
		ans += std::abs(a[i - 1] - a[i]);
	return ans;
}

long long solve1(std::vector<int> &a)
{
	std::deque<int> _a;
	for (int i : a) _a.push_back(i);
	std::vector<int> b;
	while (!_a.empty())
	{
		if (!_a.empty())
		{
			b.push_back(_a.front());
			_a.pop_front();
		}
		if (!_a.empty())
		{
			b.push_back(_a.back());
			_a.pop_back();
		}
	}
	return solve(b);
}

long long solve2(std::vector<int> &a)
{
	std::deque<int> _a;
	for (int i : a) _a.push_back(i);
	std::vector<int> b;
	while (!_a.empty())
	{
		if (!_a.empty())
		{
			b.push_back(_a.back());
			_a.pop_back();
		}
		if (!_a.empty())
		{
			b.push_back(_a.front());
			_a.pop_front();
		}
	}
	return solve(b);
}

int main()
{
	int n;
	scanf("%d", &n);
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a.begin(), a.end());
	printf("%lld\n", std::max(solve1(a), solve2(a)));
	return 0;
}