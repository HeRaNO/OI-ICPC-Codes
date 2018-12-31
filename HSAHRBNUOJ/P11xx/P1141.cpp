#include <cstdio>
using namespace std;

int n, m1, m2, m, mx, x, fc[30010], fm[30010], ans = ~(1 << 31);

inline void max(int &a, int b)
{
	if (a < b) a = b;
	return ;
}
inline void min(int &a, int b)
{
	if (a > b) a = b;
	return ;
}

inline void read(int &x)
{
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
	return ;
}

int main()
{
	read(n);
	read(m1);
	read(m2);
	for (int i = 2; m1 != 1; i++)
		if (!(m1 % i))
		{
			fc[++m] = i;
			while (!(m1 % i)) ++fm[m], m1 /= i;
			fm[m] *= m2;
		}
	while (n--)
	{
		read(x);
		mx = 0;
		for (int i = 1; i <= m; i++)
		{
			int cnt = 0;
			while (!(x % fc[i])) ++cnt, x /= fc[i];
			if (!cnt)
			{
				mx = ~(1 << 31);
				break;
			}
			if (fm[i] % cnt) cnt = fm[i] / cnt + 1;
			else cnt = fm[i] / cnt;
			max(mx, cnt);
		}
		min(ans, mx);
	}
	if (ans == ~(1 << 31)) puts("-1");
	else printf("%d\n", ans);
	return 0;
}