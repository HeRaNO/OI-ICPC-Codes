#include <cstdio>
#define MAXN 35
using namespace std;

int n, l, m;
int C[MAXN][MAXN];
int pos, sum, ans;

int mymin(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	for (int i = 0; i <= 30; i++)
	{
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++) C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
	}
	scanf("%d %d %d", &n, &l, &m);
	m--;
	while (m > 0)
	{
		pos = 1;
		sum = 1;
		for (int i = 0; i <= n; i++)
		{
			int cas = 0;
			for (int j = 0; j <= mymin(l - 1, i - 1); j++) cas += C[i - 1][j];
			if (sum + cas > m)
			{
				pos = i;
				break;
			}
			if (sum + cas == m)
			{
				sum += cas;
				pos = i + 1;
				break;
			}
			sum += cas;
		}
		ans |= (1 << (pos - 1));
		m -= sum;
		l--;
	}
	printf("%d\n", ans);
	return 0;
}
