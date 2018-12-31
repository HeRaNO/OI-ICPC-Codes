//Code By HeRaNO
#include <cstring>
#include <cstdio>
using namespace std;

int a[300];
bool c[9] = {false};
int n, cnt;
char b[300];

int main()
{
	gets(b);
	n = strlen(b);
	for (int i = 0; i <= n - 1; i++) a[i + 1] = b[i] - 48;
	for (int i = 2; i <= 9; i++)
	{
		int x = 0, q = 1;
		while (q <= n)
		{
			b[q] = (10 * x + a[q]) / i;
			x = (10 * x + a[q]) % i;
			q++;
		}
		if (x > 0) cnt++;
		else c[i] = true;
	}
	if (cnt == 8) printf("none");
	else
		for (int i = 2; i <= 9; i++) if (c[i]) printf("%d ", i);
	return 0;
}
