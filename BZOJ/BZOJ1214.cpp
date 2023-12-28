#include <stack>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

const int N = 755;

char s[N];

int main()
{
	int n, m; scanf("%d %d", &n, &m);
	std::vector<std::vector<int>> a(n, std::vector<int>(m));
	for (int i = 0; i < n; i++)
	{
		scanf("%s", s);
		for (int j = 0; j < m; j++)
			a[i][j] = s[j] - '0';
	}
	std::vector<int> col(m, 0);
	std::vector<std::vector<long long>> dl, dr, ul, ur;
	std::function<std::vector<long long>(const std::vector<int>&)> calc = [&](const std::vector<int> &c)
	{
		std::vector<long long> res(m);
		std::stack<int> sta;
		int ans = 0;
		for (int i = 0; i < m; i++)
		{
			while (!sta.empty() && c[i] <= c[sta.top()])
			{
				int r = sta.top(); sta.pop();
				int l = sta.empty() ? -1 : sta.top();
				ans -= (r - l) * (c[r] - c[i]);
			}
			sta.push(i);
			ans += c[i];
			res[i] = ans;
		}
		return res;
	};
	std::function<std::vector<long long>(const std::vector<int>&)> calc_reverse = [=](std::vector<int> c)
	{
		std::reverse(c.begin(), c.end());
		std::vector<long long> res = calc(c);
		std::reverse(res.begin(), res.end());
		return res;
	};
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j]) ++col[j];
			else col[j] = 0;
		}
		dl.push_back(calc(col));
		dr.push_back(calc_reverse(col));
	}
	std::fill(col.begin(), col.end(), 0);
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j]) ++col[j];
			else col[j] = 0;
		}
		ul.push_back(calc(col));
		ur.push_back(calc_reverse(col));
	}
	std::reverse(ul.begin(), ul.end());
	std::reverse(ur.begin(), ur.end());
	std::function<void(std::vector<std::vector<long long>>&)> sum_up = [&](std::vector<std::vector<long long>> &a)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				if (i) a[i][j] += a[i - 1][j];
				if (j) a[i][j] += a[i][j - 1];
				if (i && j) a[i][j] -= a[i - 1][j - 1];
			}
	};
	sum_up(dl); sum_up(dr); sum_up(ul); sum_up(ur);
	long long ans = ~(1LL << 63);
	std::function<long long(const std::vector<std::vector<long long>>&, int, int, int, int)> get_sum =
	[&](const std::vector<std::vector<long long>> &a, int p, int q, int x, int y)
	{
		if (p > x || q > y) return 0LL;
		std::function<long long(int, int)> safe_get = [&](int x, int y)
		{
			if (x >= 0 && y >= 0) return a[x][y];
			return 0LL;
		};
		return a[x][y] - safe_get(p - 1, y) - safe_get(x, q - 1) + safe_get(p - 1, q - 1);
	};
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j])
			{
				long long res = get_sum(dl, 0, 0, i - 1, m - 1) + get_sum(ul, i + 1, 0, n - 1, m - 1) +
								get_sum(dl, 0, 0, n - 1, j - 1) + get_sum(dr, 0, j + 1, n - 1, m - 1) -
								get_sum(dl, 0, 0, i - 1, j - 1) - get_sum(dr, 0, j + 1, i - 1, m - 1) -
								get_sum(ul, i + 1, 0, n - 1, j - 1) - get_sum(ur, i + 1, j + 1, n - 1, m - 1);
				ans = std::min(ans, res);
			}
	printf("%lld\n", ans);
	return 0;
}
