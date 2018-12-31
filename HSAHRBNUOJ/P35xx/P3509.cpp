#include <cstdio>
#include <cstring>
using namespace std;

char s[25];
long long n, len;
long long fac[25];
long long ranka[25];
bool appear[26];

long long getrank()
{
	long long res = 0, t;
	for (int i = 0; i < len; i++) appear[s[i] - 'A'] = true;
	for (int i = 0; i < len; i++)
	{
		t = 0;
		appear[s[i] - 'A'] = false;
		for (int j = 0; j < s[i] - 'A'; j++) t += appear[j];
		res = res * (len - i) + t;
	}
	return res + n;
}

inline void getsequence(long long x)
{
	if (x >= fac[len] || x < 0)
	{
		puts("Are you kidding me.");
		return ;
	}
	for (int i = 0; i < len; i++) appear[s[i] - 'A'] = true;
	for (int i = 0; i < len; i++)
	{
		ranka[len - i - 1] = x % (i + 1);
		x /= (i + 1);
	}
	for (int i = 0; i < len; i++)
	{
		int t = -1, j;
		for (j = 0; t < ranka[i]; j++) t += appear[j];
		appear[--j] = false;
		putchar('A' + j);
	}
	puts("");
	return ;
}

int main()
{
	scanf("%s", s);
	len = strlen(s);
	scanf("%lld", &n);
	fac[0] = 1;
	for (int i = 1; i <= len; i++) fac[i] = fac[i - 1] * (long long)i;
	getsequence(getrank());
	return 0;
}
