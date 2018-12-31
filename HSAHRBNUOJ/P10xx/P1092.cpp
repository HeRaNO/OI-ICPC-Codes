#include <cstdio>
using namespace std;
int main()
{
	int i, j, time = 0, t, n;
	int s[10000] = {0};
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &s[i]);
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n - i; j++)
		{
			if (s[j] > s[j + 1])
			{
				t = s[j];
				s[j] = s[j + 1];
				s[j + 1] = t;
				time++;
			}
		}
	printf("%d\n", time);
	return 0;
}
