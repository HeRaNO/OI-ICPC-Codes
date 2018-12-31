#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n, k, p[200010], ii;
int tot, cnt[32], pos, ans;

int main()
{
	scanf("%d %d", &n, &k);
	while (n)
	{
		if (n & 1)
		{
			p[++tot] = ii;
			cnt[pos]++;
			++ans;
		}
		n >>= 1;
		ii <<= 1;
		pos++;
	}
	if (ans > k)
	{
		puts("NO");
		return 0;
	}
	while (1)
	{
		pos = 0;
		if (ans == k)
		{
			puts("YES");
			for (int i = 0; i < 32; i++)
				for (int j = 1; j <= cnt[i]; j++)
					printf("%d ", 1 << i);
			puts("");
			return 0;
		}
		for (int i = 31; ~i && !pos; i--)
			if (cnt[i]) pos = i;
		if (!pos)
		{
			puts("NO");
			return 0;
		}
		cnt[pos]--;
		cnt[pos - 1] += 2;
		ans++;
	}
	return 0;
}