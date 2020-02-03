#include <cstdio>
#include <climits>
using namespace std;

bool f[101][10101];
int ji[101][101];
int n, i, tmp, j, k, s, s_min = INT_MAX;

int mymin(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		s = 0;
		ji[i][0] = 0;
		while (true)
		{
			scanf("%d", &tmp);
			if (tmp == -1) break;
			else
			{
				ji[i][++ji[i][0]] = tmp;
				s += tmp;
			}
		}
		s_min = mymin(s, s_min);
	}
	for (i = 1; i <= n; i++)
	{
		f[i][0] = true;
		for (j = 1; j <= ji[i][0]; j++)
			for (k = s_min; k >= ji[i][j]; k--)
			{
				if (f[i][k - ji[i][j]])
					f[i][k] = f[i][k - ji[i][j]];
			}
	}
	for (i = s_min; i >= 0; i--)
	{
		bool ok = true;
		for (j = 1; j <= n; j++)
		{
			ok = ok && f[j][i];
			if (!ok) break;
		}
		if (ok)
		{
			printf("%d", i);
			return 0;
		}
	}
}