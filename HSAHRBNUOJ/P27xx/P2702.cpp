#include <cstdio>
#include <cstring>
#define MAXL 3000
using namespace std;

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

struct bign
{
	int c[MAXL], len;
	bign operator + (const bign &a) const
	{
		bign res;
		memset(res.c, 0, sizeof res.c);
		res.len = mymax(len, a.len);
		for (int i = 1; i <= res.len; i++)
		{
			res.c[i] += (c[i] + a.c[i]) % 10;
			res.c[i + 1] += (c[i] + a.c[i]) / 10;
		}
		res.len = a.len + 10;
		while (!res.c[res.len]) res.len--;
		while (res.c[res.len] > 10)
		{
			res.c[res.len + 1] = res.c[res.len] / 10;
			res.c[res.len] %= 10;
			res.len++;
		}
		return res;
	}
	bign operator * (const int &a) const
	{
		bign res;
		memset(res.c, 0, sizeof res.c);
		res.len = len + 4;
		for (int i = 1; i <= res.len; i++)
		{
			res.c[i + 1] = (res.c[i] + c[i] * a) / 10;
			res.c[i] = (res.c[i] + c[i] * a) % 10;
		}
		while (!res.c[res.len]) res.len--;
		while (res.c[res.len] > 10)
		{
			res.c[res.len + 1] = res.c[res.len] / 10;
			res.c[res.len] %= 10;
			res.len++;
		}
		return res;
	}
	void print()
	{
		for (int i = len; i; i--) printf("%d", c[i]);
		puts("");
		return ;
	}
};

bign a[3];
int n;

int main()
{
	//freopen("keke.in","r",stdin);freopen("keke.out","w",stdout);
	scanf("%d", &n); //a[n]=(n-1)*(a[n-1]+a[n-2]);
	if (!n)
	{
		puts("0");
		return 0;
	}
	a[1].len = 1;
	a[2].len = 1;
	a[2].c[1] = 1;
	for (int i = 3; i <= n; i++)
	{
		a[i % 3] = a[(i - 1) % 3] + a[(i - 2) % 3];
		a[i % 3] = a[i % 3] * (i - 1);
	}
	a[n % 3].print();
	return 0;
}
