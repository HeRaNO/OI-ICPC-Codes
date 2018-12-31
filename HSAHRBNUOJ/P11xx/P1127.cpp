#include <cstdio>
using namespace std;
const int a[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int need(int k)
{
	int num = 0;
	if (k == 0) return 6;
	while (k)
	{
		int tmp = k % 10;
		num += a[tmp];
		k /= 10;
	}
	return num;
}

int main()
{
	int n, num, ans = 0;
	int i, j;
	scanf("%d", &n);
	n -= 4;
	for (i = 0; i <= 1111; i++)
		for (j = 0; j <= 1111; j++)
		{
			num = need(i) + need(j) + need(i + j);
			if (num != n)
				continue;
			else
				ans++;
		}
	printf("%d\n", ans);
	return 0;
}
