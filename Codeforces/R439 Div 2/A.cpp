#include <cstdio>
#define MAXN 2010
using namespace std;

int n, x[MAXN], y[MAXN], ans;
bool appear[20000010];

inline void read(int &x)
{
	x = 0;
	bool f = false;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = true;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	x = f ? -x : x;
	return ;
}

int main()
{
	read(n);
	for (int i = 1; i <= n; i++)
	{
		read(x[i]);
		appear[x[i]] = true;
	}
	for (int i = 1; i <= n; i++)
	{
		read(y[i]);
		appear[y[i]] = true;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (appear[x[i]^y[j]]) ans++;
	if (!(ans & 1)) puts("Karen");
	else puts("Koyomi");
	return 0;
}