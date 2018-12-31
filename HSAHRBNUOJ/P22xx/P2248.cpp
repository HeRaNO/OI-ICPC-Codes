#include <cstdio>
#define MAXN 210
using namespace std;

int na, nb, n;
int a[MAXN], b[MAXN];
int wina, winb;

int judge(int a, int b) //A win 1 B win -1 draw 0
{
	if (a == b) return 0;
	if (a == 0)
	{
		if (b == 1 || b == 4) return -1;
		else return 1;
	}
	if (a == 1)
	{
		if (b == 2 || b == 4) return -1;
		else return 1;
	}
	if (a == 2)
	{
		if (b == 0 || b == 3) return -1;
		else return 1;
	}
	if (a == 3)
	{
		if (b == 0 || b == 1) return -1;
		else return 1;
	}
	if (a == 4)
	{
		if (b == 2 || b == 3) return -1;
		else return 1;
	}
}

int main()
{
	scanf("%d %d %d", &n, &na, &nb);
	for (int i = 0; i < na; i++) scanf("%d", &a[i]);
	for (int i = 0; i < nb; i++) scanf("%d", &b[i]);
	for (int i = 0; i < n; i++) // A win 1 B win -1 draw 0
	{
		int res = judge(a[i % na], b[i % nb]);
		if (res == 1) wina++;
		else if (res == -1) winb++;
	}
	printf("%d %d\n", wina, winb);
	return 0;
}
