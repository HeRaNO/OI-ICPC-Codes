#include <cstdio>
using namespace std;

int gcd(int m, int n)
{
	return m % n == 0 ? n : gcd(n, m % n);
}

int n, a0, a1, b0, b1, ci, i;
int tmp1, tmp2, ans;

int main()
{
	scanf("%d", &n);
	for (ci = 1; ci <= n; ci++)
	{
		scanf("%d %d %d %d", &a0, &a1, &b0, &b1);
		ans = 0;
		if (a0 % a1 || b1 % b0)
		{
			printf("0\n");
			continue;
		}
		tmp1 = a0 / a1;
		tmp2 = b1 / b0;
		for (i = 1; i * i <= b1; i++)
			if (b1 % i == 0)
			{
				if (i % a1 == 0)
					if (gcd(tmp1, i / a1) == 1 && gcd(tmp2, b1 / i) == 1) ans++;
				if ((b1 / i) != i && (b1 / i) % a1 == 0)
					if (gcd(tmp1, (b1 / i) / a1) == 1 && gcd(tmp2, b1 / (b1 / i)) == 1) ans++;
			}
		printf("%d\n", ans);
	}
	return 0;
}