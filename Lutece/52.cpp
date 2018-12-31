#include <cstdio>
using namespace std;

int n, cnt[26], ans;
char a[1010];

int main()
{
	scanf("%d", &n);
	scanf("%s", a);
	for (int i = 0; i < n; i++) ++cnt[a[i] - 'a'];
	for (int i = 0; i < 26; i++)
	{
		while (cnt[i])
		{
			++ans;
			for (int j = i; j < 26 && cnt[j]; j++) --cnt[j];
		}
	}
	printf("%d\n", ans);
	return 0;
}
