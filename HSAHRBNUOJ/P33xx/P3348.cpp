#include <cstdio>
#include <algorithm>
#define MAXN 210
using namespace std;

int n, T;
int a[MAXN];
bool out;

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		if (n & 1) puts("1");
		else
		{
			sort(a + 1, a + n + 1);
			out = false;
			for (int i = 1; i <= (n >> 1); i++)
				if (a[i * 2] != a[i * 2 - 1])
				{
					out = true;
					puts("1");
					break;
				}
			if (!out) puts("0");
		}
	}
	return 0;
}
