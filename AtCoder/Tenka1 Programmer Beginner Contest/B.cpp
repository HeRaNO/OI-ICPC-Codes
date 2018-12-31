#include <cstdio>

int main()
{
	int t, a, k;
	scanf("%d %d %d", &t, &a, &k);
	for (int i = 1; i <= k; i++)
	{
		if (i & 1)
		{
			a += (t >> 1);
			t >>= 1;
		}
		else
		{
			t += (a >> 1);
			a >>= 1;
		}
	}
	printf("%d %d\n", t, a);
	return 0;
}