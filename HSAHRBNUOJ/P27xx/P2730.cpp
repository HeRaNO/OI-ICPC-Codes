#include <cstdio>
#include <cstring>
#define MAXD 20
using namespace std;

int T, ld, rd;
char ll[MAXD], rr[MAXD];
char l[MAXD], r[MAXD];
long long cir[MAXD], cnt[MAXD];

long long mymin(long long a, long long b)
{
	return a < b ? a : b;
}

long long mymax(long long a, long long b)
{
	return a > b ? a : b;
}

inline void make_table()
{
	for (int i = 1; i <= 18; i++)
	{
		long long num = 9;
		for (int j = 1; j < i; j++)
		{
			if (i % j == 0)
			{
				cir[j] = num;
				for (int k = 1; k < j; k++)
					if (j % k == 0) cir[j] -= cir[k];
				cnt[i] += cir[j];
			}
			num *= 10;
		}
	}
	return ;
}

long long turn_to_num(char c[], int l, int r)
{
	long long res = 0;
	for (int i = l; i <= r; i++) res = res * 10 + (c[i] - '0');
	return res;
}

long long work(char x[])
{
	long long ans = 0;
	int d = strlen(x);
	memset(cir, 0, sizeof(cir));
	for (int i = 1; i < d; i++) ans += cnt[i];
	long long num = 1;
	for (int i = 1; i < d; i++)
	{
		if (d % i == 0)
		{
			long long circulate = 0, p = 0, q = 0;
			q = turn_to_num(x, 0, i - 1);
			for (int j = i; j < d; j++)
			{
				p = p * 10 + (x[j] - '0');
				if (j == d - 1 || (j + 1) % i == 0)
				{
					if (p > q) break;
					else if (p < q) circulate = 1;
					p = 0;
				}
			}
			cir[i] = q - num - circulate + 1;
			for (int j = 1; j < i; j++)
				if (i % j == 0) cir[i] -= cir[j];
			ans += cir[i];
		}
		num *= 10;
	}
	return ans;
}

int main()
{
	//freopen("circulate.in","r",stdin);freopen("circulate.out","w",stdout);
	make_table();
	scanf("%d", &T);
	while (T--)
	{
		memset(l, 0, sizeof l);
		memset(r, 0, sizeof r);
		scanf("%s %s", l, r);
		ld = strlen(l);
		rd = strlen(r);
		long long ll = turn_to_num(l, 0, ld - 1) - 1;
		long long tmp = ll;
		ld = 0;
		while (tmp) tmp /= 10, ld++;
		if (!ld) ld++;
		memset(l, 0, sizeof(l));
		while (ll)
		{
			l[--ld] = char(ll % 10 + '0');
			ll /= 10;
		}
		printf("%lld\n", work(r) - work(l));
	}
	return 0;
}
