//Code By HeRaNO
#include <cstdio>
#define MAXN 50010
using namespace std;

int len[MAXN];
int l, m, n;
int left, right, middle;

bool check(int length)
{
	int b = 0, k = 0;
	for (int i = 1; i <= n; i++)
	{
		if (len[i] - k < length)
		{
			b++;
			if (b > m) return true;
			continue;
		}
		k = len[i];
	}
	return false;
}

int main()
{
	scanf("%d %d %d", &l, &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &len[i]);
	len[++n] = l;
	left = -1;
	right = l + 1;
	while (left + 1 != right)
	{
		middle = (left + right) >> 1;
		if (check(middle)) right = middle;
		else left = middle;
	}
	printf("%d\n", left);
	return 0;
}
