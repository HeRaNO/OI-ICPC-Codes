#include <cstdio>
#include <cstring>
#define MAXN 40
using namespace std;

const int table[10][10] =
{
	{0},
	{0},
	{0, 0, 1},
	{0, 0, 0, 1},
	{0, 0, 2, 1},
	{0, 0, 0, 0, 0, 1},
	{0, 0, 0, 1, 0, 1},
	{0, 0, 0, 0, 0, 0, 0, 1},
	{0, 0, 3, 0, 0, 0, 0, 1},
	{0, 0, 1, 2, 0, 0, 0, 1}
};

char n[MAXN];
int len;
int a[10];

int main()
{
	scanf("%d", &len);
	scanf("%s", n + 1);
	len = strlen(n + 1);
	for (int i = 1; i <= len; i++)
		for (int j = 1; j <= 9; j++)
			a[j] += table[n[i] - '0'][j];
	for (int i = 9; i; i--)
		while (a[i]) printf("%d", i), a[i]--;
	puts("");
	return 0;
}
