#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

char a[110], m;
int cnt[6], lx, n, k, r;

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= min(k, n) && !r; i++)
	{
		cnt['F' - 'A']++;
		if (cnt['F' - 'A'] == 50)
		{
			r = i;
			m = 'F';
			break;
		}
		scanf("%s", &a);
		lx = strlen(a);
		for (int j = 0; j < lx; j++)
		{
			++cnt[a[j] - 'A'];
			if (cnt[a[j] - 'A'] == 50)
			{
				r = i;
				m = a[j];
				break;
			}
		}
	}
	if (r)
		printf("%d %c\n", r, m);
	else
	{
		if (k <= n) puts("Feizhou Yin");
		else puts("AMNZ");
	}
	return 0;
}
