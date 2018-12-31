#include <cstdio>
#define MAXN 1000010
using namespace std;
int lis[MAXN], n;
int main()
{
	for (int i = 0; i <= 1000; i++)
		for (int j = i; j <= 1000; j++)
			if (i * i + j * j <= 1000000)
				lis[i * i + j * j]++;
	while (scanf("%d", &n) != EOF)
	{
		if (lis[n]) printf("%d\n", lis[n]);
		else printf("No Solution!\n");
	}
	return 0;
}
