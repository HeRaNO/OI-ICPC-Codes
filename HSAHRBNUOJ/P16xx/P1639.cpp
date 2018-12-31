#include <cstdio>
#include <algorithm>
#define MAXN 1010
#define MAXQ 10
using namespace std;

int n, pt[MAXN];
double a[MAXN][MAXQ];
double sum[MAXN], sum1;
double average, posmark[MAXN][MAXQ], sum_posmark[MAXN];
double add;

double myabs(double a)
{
	return a < 0 ? -a : a;
}

bool cmp(int a, int b)
{
	if (sum_posmark[a] == sum_posmark[b])
	{
		if (sum[a] == sum[b]) return a < b;
		else return sum[a] > sum[b];
	}
	return sum_posmark[a] > sum_posmark[b];
}

int main()
{
	//freopen("compe.in","r",stdin);freopen("compe.out","w",stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 8; j++) scanf("%lf", &a[i][j]);
		for (int j = 1; j <= 8; j++) sum[i] += a[i][j];
		pt[i] = i;
	}
	for (int i = 1; i <= 8; i++)
	{
		add = 0.0;
		sum1 = 0;
		for (int j = 1; j <= n; j++) sum1 += a[j][i];
		average = sum1 / (double)n;
		for (int j = 1; j <= n; j++) add += myabs(a[j][i] - average);
		if (add == 0.0) continue;
		add = add / (double)n;
		for (int j = 1; j <= n; j++) posmark[j][i] = (a[j][i] - average) / add;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 3; j++)
			sum_posmark[i] += posmark[i][j];
		for (int j = 4; j <= 8; j++)
			sum_posmark[i] += 0.8 * posmark[i][j];
	}
	sort(pt + 1, pt + n + 1, cmp);
	for (int i = 1; i <= n; i++) printf("%d\n", pt[i]);
	return 0;
}
