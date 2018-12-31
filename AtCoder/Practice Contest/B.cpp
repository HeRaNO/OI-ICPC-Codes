#include <bits/stdc++.h>
using namespace std;

int n, q;
char a[26], b[26], ans[3];

namespace Subtask1
{
	inline bool Ask(char a, char b)
	{
		printf("? %c %c\n", a, b);
		fflush(stdout);
		scanf("%s", ans);
		if (ans[0] == '<') return true;
		return false;
	}

	void DC(int l, int r)
	{
		if (l >= r) return ;
		int m = l + r >> 1;
		int i = l, j = m + 1, k = l;
		DC(l, m);
		DC(m + 1, r);
		while (i <= m && j <= r)
		{
			if (Ask(a[i], a[j])) b[k++] = a[i++];
			else b[k++] = a[j++];
		}
		while (i <= m) b[k++] = a[i++];
		while (j <= r) b[k++] = a[j++];
		for (int i = l; i <= r; i++) a[i] = b[i];
		return ;
	}
}

namespace Subtask2
{
	int cmp[5][5];
	char c;

	inline bool Ask(char a, char b)
	{
		if (~cmp[a - 'A'][b - 'A']) return cmp[a - 'A'][b - 'A'];
		printf("? %c %c\n", a, b);
		fflush(stdout);
		scanf("%s", ans);
		if (ans[0] == '<')
		{
			cmp[a - 'A'][b - 'A'] = 1;
			cmp[b - 'A'][a - 'A'] = 0;
			return true;
		}
		cmp[a - 'A'][b - 'A'] = 0;
		cmp[b - 'A'][a - 'A'] = 1;
		return false;
	}

	void Magic()
	{
		memset(cmp, -1, sizeof cmp);
		if (!As k(a[0], a[1])) swap(a[0], a[1]);
		if (!Ask(a[2], a[3])) swap(a[2], a[3]);
		if (!Ask(a[1], a[3]))
		{
			swap(a[0], a[2]);
			swap(a[1], a[3]);
		}
		c = a[2];
		if (Ask(a[1], a[4]))
		{
			if (Ask(a[3], a[4])) a[2] = a[3];
			else
			{
				a[2] = a[4];
				a[4] = a[3];
			}
		}
		else
		{
			if (Ask(a[0], a[4]))
			{
				a[2] = a[1];
				a[1] = a[4];
				a[4] = a[3];
			}
			else
			{
				a[2] = a[1];
				a[1] = a[0];
				a[0] = a[4];
				a[4] = a[3];
			}
		}
		if (Ask(a[1], c))
		{
			if (Ask(a[2], c)) a[3] = c;
			else
			{
				a[3] = a[2];
				a[2] = c;
			}
		}
		else
		{
			if (Ask(a[0], c))
			{
				a[3] = a[2];
				a[2] = a[1];
				a[1] = c;
			}
			else
			{
				a[3] = a[2];
				a[2] = a[1];
				a[1] = a[0];
				a[0] = c;
			}
		}
		return ;
	}
}

int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++) a[i] = (char)(i + 'A');
	if (n == 26) Subtask1::DC(0, n - 1);
	else Subtask2::Magic();
	putchar('!');
	putchar(' ');
	puts(a);
	fflush(stdout);
	return 0;
}
