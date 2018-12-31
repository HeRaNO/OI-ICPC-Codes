//Code By HeRaNO
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 3100
using namespace std;

int a[MAXN];
char c[MAXN];
int in, cnt;
bool have_num = false;

int main()
{
	gets(c);
	int len = strlen(c);
	for (int i = 0; i < len; i++)
	{
		if (c[i] >= '0' && c[i] <= '9')
		{
			have_num = true;
			in = in * 10 + c[i] - '0';
		}
		else
		{
			if (have_num)
			{
				a[cnt++] = in;
				in = 0;
				have_num = false;
			}
		}
	}
	if (have_num) a[cnt++] = in;
	sort(a, a + cnt);
	printf("%d", a[0]);
	for (int i = 1; i < cnt; i++)
		printf(",%d", a[i]);
	printf("\n");
	return 0;
}
