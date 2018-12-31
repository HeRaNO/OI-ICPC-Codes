#include<cstdio>
#define N 110

bool ch[N][N];
int n, j, i, k, a = 0, b = 0, c = 0;
bool chg = false;
char t;

int main()
{
	scanf("%d", &n);
	getchar();
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n + 1; j++)
		{
			t = getchar();
			ch[i][j] = (t == 'M');
		}
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (i != j)
			{
				if (ch[i][j] && ch[j][i]) a++;
				else if ((!ch[i][j]) && (!ch[j][i])) b++;
				else c++;
			}
	for (i = 0; i <= n; i++)
		for (j = 0; i + j <= n; j++)
		{
			k = n - i - j;
			if (i * (i - 1) + j * (j - 1) + i * k * 2 == a && k * (k - 1) + i * j * 2 == b && j * k * 2 == c)
			{
				printf("M=%d, P=%d, &=%d\n", i, j, k);
				chg = true;
			}
		}
	if (!chg) printf("Impossible");
	return 0;
}
