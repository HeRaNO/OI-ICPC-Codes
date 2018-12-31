#include <cstdio>
#define MAXR 101
using namespace std;

int n, x;
bool a[MAXR];

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(n);
	for (int i = 1; i <= n; i++)
	{
		read(x);
		if (a[x]) continue;
		else
		{
			printf("%d ", x);
			a[x] = true;
		}
	}
	printf("\n");
	return 0;
}