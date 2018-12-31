#include <cstdio>
#include <algorithm>
#define MAXN 5010
using namespace std;

int password[MAXN];
int len, n;

int main()
{
	scanf("%d", &n);
	scanf("%d", &len);
	for (int i = 1; i <= n; i++)
		scanf("%d", &password[i]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j != i && j <= n; j++)
			if (password[i] + password[j] == len)
			{
				if (i > j) swap(i, j);
				printf("%d\n%d\n", i, j);
				return 0;
			}
	printf("0\n");
	return 0;
}
