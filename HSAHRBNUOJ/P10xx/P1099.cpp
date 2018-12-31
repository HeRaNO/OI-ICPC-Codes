#include <cstdio>
#define MAXN 110
using namespace std;

int n;
bool deng[MAXN];

int main()
{
	scanf("%d", &n);
	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (j % i == 0)
				deng[j] = !deng[j];
	for (int i = 1; i <= n; i++) printf("%d", deng[i]);
	puts("");
	return 0;
}
