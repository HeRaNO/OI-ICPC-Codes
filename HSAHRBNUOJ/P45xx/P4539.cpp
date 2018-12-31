#include <cstdio>
#include <cstring>
#define MAXN 100010
using namespace std;

char a[MAXN], sta[MAXN];
int n, top, ans;

int main()
{
	scanf("%s", a + 1);
	n = strlen(a + 1);
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == '(') sta[++top] = a[i];
		else
		{
			if (top && a[i] == ')') top--;
			else
			{
				sta[++top] = '(';
				ans++;
			}
		}
	}
	printf("%d\n", ans + (top >> 1));
	return 0;
}