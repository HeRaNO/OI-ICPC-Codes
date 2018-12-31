//Code By HeRaNO
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;

struct longnum
{
	int f[55], len;
	longnum()
	{
		memset(f, 0, sizeof(f));
		len = 1;
	}
	bool empty()
	{
		if (len == 1 && f[0] == 0) return true;
		return false;
	}
	longnum operator *(const int x)
	{
		longnum c;
		c.len = len;
		for (int i = 0; i < c.len; i++)
			c.f[i] = f[i] * x;
		for (int i = 0; i < c.len; i++)
		{
			c.f[i + 1] += c.f[i] / 10;
			c.f[i] %= 10;
		}
		while (c.f[c.len])
		{
			c.f[c.len + 1] += c.f[c.len] / 10;
			c.f[c.len] %= 10;
			c.len++;
		}
		return c;
	}
	longnum operator +(const int x)
	{
		f[0] += x;
		for (int i = 0; i < len; i++)
		{
			f[i + 1] += f[i] / 10;
			f[i] %= 10;
		}
		while (f[len])
		{
			f[len + 1] = f[len] / 10;
			f[len] %= 10;
			len++;
		}
		return *this;
	}
	longnum operator /(const int x)
	{
		longnum c;
		c = *this;
		for (int i = len - 1, k = 0; ~i; i--)
		{
			c.f[i] = (k * 10 + f[i]) / x;
			k = (k * 10 + f[i]) % x;
		}
		while (!c.f[c.len - 1] && c.len > 1) c.len--;
		return c;
	}
	int mod(int x)
	{
		int k = 0;
		for (int i = len - 1; ~i; i--)
			k = (k * 10 + f[i]) % x;
		return k % x;
	}
	void clear()
	{
		memset(f, 0, sizeof(f));
		len = 1;
	}
	void out()
	{
		for (int i = len - 1; ~i; i--)
			printf("%d", f[i]);
		printf("\n");
	}
} AB;

char st[300], ch[300];
int T, t, a, b, op, len, w[300], g[300];

int main()
{
	scanf("%d", &T);
	for (int i = 'A'; i <= 'Z'; i++)
	{
		g[i] = i - 'A' + 10;
		ch[i - 'A' + 10] = i;
	}
	for (int i = 0; i <= 9; i++)
	{
		ch[i] = i + '0';
		g[i + '0'] = i;
	}
	while (T--)
	{
		scanf("%s\n", st);
		AB.clear();
		op = t = a = b = 0;
		for (int i = 0; i < strlen(st); i++)
		{
			if (st[i] == ',')
			{
				t++;
				continue;
			}
			switch (t)
			{
			case 0:
			{
				a = a * 10 + st[i] - '0';
				break;
			}
			case 1:
			{
				AB = AB * a + g[st[i]];
				break;
			}
			case 2:
			{
				b = b * 10 + st[i] - '0';
				break;
			}
			}
		}
		if (AB.empty()) printf("0");
		while (!AB.empty())
		{
			w[++op] = AB.mod(b);
			AB = AB / b;
		}
		for (int i = op; i; i--)
			printf("%c", ch[w[i]]);
		printf("\n");
	}
	return 0;
}
