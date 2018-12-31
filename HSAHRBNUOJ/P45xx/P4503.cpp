#include <cstdio>
#define MAXN 10000010
using namespace std;

int n;
int a[4], b[MAXN];
long long ans, p, q;

long long mymax(long long a, long long b)
{
	return a > b ? a : b;
}

int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch > '9' || ch < '0')
	{
		if (ch == '-')f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

int main()
{
	//freopen("nijia.in","r",stdin);freopen("nijia.out","w",stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		b[i] = read();
		a[b[i]]++;
	}
	for (int i = 1; i <= a[1]; i++) if (b[i] != 1) ans++;
	for (int i = a[1] + 1; i <= a[1] + a[2]; i++) if (b[i] == 3) p++;
	for (int i = a[1] + a[2] + 1; i <= n; i++) if (b[i] == 2) q++;
	printf("%lld\n", ans + mymax(p, q));
	return 0;
}
