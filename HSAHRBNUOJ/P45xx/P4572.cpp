#include <cstdio>
#define MAXR 1000010
using namespace std;

int n, ans, l, r, mxr, a[MAXR], s[MAXR];

inline void max(int &a, int b)
{
	if (a < b) a = b;
	return ;
}

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
		read(l);
		read(r);
		max(mxr, r + 1);
		a[l]++;
		a[r + 1]--;
	}
	for (int i = 1; i <= mxr; i++) s[i] = s[i - 1] + a[i], max(ans, s[i]);
	printf("%d\n", ans);
	return 0;
}