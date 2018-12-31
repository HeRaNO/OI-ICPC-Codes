#include <cstdio>
using namespace std;

char a[3];

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
	scanf("%s", a);
	for (int i = 0; i < 3; i++)
	{
		if (a[i] == '9') a[i] = '1';
		else if (a[i] == '1') a[i] = '9';
	}
	puts(a);
	return 0;
}