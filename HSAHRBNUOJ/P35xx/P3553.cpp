#include <set>
#include <cstdio>
#define MAXN 100010
using namespace std;

int n, a[MAXN], pos, ans, g;
set <int> s;

int gcd(int a, int b)
{
	return !b ? a : gcd(b, a % b);
}
int myabs(int a)
{
	return a > 0 ? a : -a;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	pos = 1;
	while (pos <= n)
	{
		s.clear();
		g = 0;
		ans++;
		s.insert(a[pos++]);
		while (pos <= n && g != 1)
		{
			if (s.find(a[pos]) != s.end())
			{
				g = 1;
				pos++;
				break;
			}
			if (!g) g = myabs(a[pos] - a[pos - 1]);
			else g = gcd(g, myabs(a[pos] - a[pos - 1]));
			s.insert(a[pos++]);
		}
		if (g == 1) pos--;
	}
	printf("%d\n", ans);
	return 0;
}
