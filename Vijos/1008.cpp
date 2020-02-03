#include <cstdio>
#define N 50001
using namespace std;

int n, ans;
int a[N], b[N], c[N], t1[N], t2[N];
bool used[N];

int mymax(int a, int b)
{
	return a > b ? a : b;
}

void read()
{
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d%d", &a[i], &b[i]);
	return;
}

void work()
{
	int i, t;
	c[1] = 1;
	c[2] = a[1];
	used[c[1]] = 1;
	used[c[2]] = 1;
	for (i = 2; i < n; i++)
	{
		if (c[i - 1] == a[c[i]])
			c[i + 1] = b[c[i]];
		else if (c[i - 1] == b[c[i]])
			c[i + 1] = a[c[i]];
		else
		{
			printf("-1\n");
			return;
		}
		used[c[i + 1]] = 1;
	}
	for (i = 1; i <= n; i++)
		if (!used[i])
		{
			printf("-1\n");
			return;
		}
	for (i = 1; i <= n; i++)
	{
		t = (c[i] - i + n) % n;
		t1[t]++;
		ans = mymax(ans, t1[t]);
		t = (c[n - i + 1] - i + n) % n;
		t2[t]++;
		ans = mymax(ans, t2[t]);
	}
	printf("%d", n - ans);
	return;
}

int main()
{
	read();
	work();
	return 0;
}