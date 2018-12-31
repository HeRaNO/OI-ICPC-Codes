#include <bits/stdc++.h>
#define mp make_pair
using namespace std;

int a, b, c, d, x, y, z;
pair <int, int> dc[3];

inline int read()
{
	int x = 0;
	char ch = getchar();
	bool f = false;
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = true;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return f ? -x : x;
}

int main()
{
	scanf("%d", &a);
	for (int i = 1; i <= 9; i++)
	{
		if (i * 111 >= a)
		{
			printf("%d\n", i * 111);
			return 0;
		}
	}
	return 0;
}