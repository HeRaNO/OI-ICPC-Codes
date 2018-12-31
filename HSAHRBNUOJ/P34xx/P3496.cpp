#include <cstdio>
#define MAXN 5010
using namespace std;

int a[MAXN], b[MAXN];
int ranka[MAXN], rankb[MAXN];
int ansrank[MAXN], n;
bool out[MAXN], first = true;

inline void read(int &x)
{
	x = 0;
	int f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	x *= f;
	return ;
}

int main()
{
	read(n);
	for (int i = n; i; i--) read(a[i]);
	for (int i = n; i; i--) read(b[i]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < i; j++)
			if (a[j] < a[i]) ranka[i]++;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < i; j++)
			if (b[j] < b[i]) rankb[i]++;
	for (int i = 2; i <= n; i++)
	{
		ansrank[i] += ranka[i] + rankb[i];
		ansrank[i + 1] += ansrank[i] / i;
		ansrank[i] %= i;
	}
	for (int i = n; i; i--)
	{
		int t = -1;
		while (ansrank[i] >= 0)
		{
			t++;
			if (!out[t]) ansrank[i]--;
		}
		if (first)
		{
			printf("%d", t);
			first = false;
		}
		else printf(" %d", t);
		out[t] = true;
	}
	puts("");
	return 0;
}
