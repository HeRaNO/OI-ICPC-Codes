//Code By HeRaNO
#include <cstdio>
#include <cstring>
#define MAXN 300
using namespace std;

char eight[MAXN];
int ten[3 * MAXN];
int len, tenl;
long long jin = 8;

int mymax(int a, int b)
{
	return a > b ? a : b;
}

void division(int a, long long b)
{
	ten[0] += a / b;
	long long jie = a * 10;
	long long div[MAXN * 3], cnt = 1;
	memset(div, 0, sizeof(div));
	while (jie)
	{
		div[cnt++] = jie / b;
		jie = (jie - b * div[cnt - 1]) * 10;
	}
	cnt--;
	tenl = mymax(cnt, tenl);
	for (int i = cnt; i >= 1; i--)
	{
		ten[i] = div[i] + ten[i] + jie;
		jie = ten[i] / 10;
		ten[i] %= 10;
	}
	return ;
}

int main()
{
	gets(eight);
	len = strlen(eight);
	for (int i = 2; i < len; i++)
	{
		division(eight[i] - '0', jin);
		jin *= 8;
	}
	while (!ten[tenl]) tenl--;
	for (int i = 0; i < len; i++) printf("%c", eight[i]);
	printf(" [8] = ");
	printf("%d.", ten[0]);
	for (int i = 1; i <= tenl; i++) printf("%d", ten[i]);
	printf(" [10]\n");
	return 0;
}
