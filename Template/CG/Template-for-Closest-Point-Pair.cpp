#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

struct Point
{
	int x, y;
	long long Dis(const Point &p)
	{
		return 1LL * (x - p.x) * (x - p.x) + 1LL * (y - p.y) * (y - p.y);
	}
};

int main()
{
	int n; scanf("%d", &n);
	std::vector<Point> p(n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &p[i].x, &p[i].y);
	std::sort(p.begin(), p.end(), [&](Point x, Point y){
		return x.x < y.x;
	});
	std::function<long long(int, int)> DC = [&](int l, int r)
	{
		if (l + 1 == r) return ~(1LL << 63);
		int m = l + r >> 1;
		int X = p[m].x;
		long long d = std::min(DC(l, m), DC(m, r));
		std::inplace_merge(p.begin() + l, p.begin() + m, p.begin() + r, [&](Point x, Point y){
			return x.y < y.y;
		});
		std::vector<Point> t;
		for (int i = l; i < r; i++)
			if (1LL * (p[i].x - X) * (p[i].x - X) < d)
				t.push_back(p[i]);
		for (int i = 0; i < t.size(); i++)
			for (int j = i + 1; j < t.size(); j++)
			{
				if (1LL * (t[j].y - t[i].y) * (t[j].y - t[i].y) >= d)
					break;
				d = std::min(d, t[j].Dis(t[i]));
			}
		return d;
	};
	printf("%lld\n", DC(0, n));
	return 0;
}