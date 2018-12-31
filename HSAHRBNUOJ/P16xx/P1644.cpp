#include <cstdio>
using namespace std;

int a[27] = {0, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};
char c;
int ans;

int main()
{
	while (true)
	{
		c = getchar();
		if (c == '\n') break;
		if (c >= 'a' && c <= 'z') ans += a[c - 'a' + 1];
		else ans++;
	}
	printf("%d\n", ans);
	return 0;
}
