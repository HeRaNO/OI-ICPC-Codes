#include <cstdio>
#include <cstring>
#define MAXL 1010
using namespace std;

char m[MAXL];
int n, mlen, ans;

int main()
{
	scanf("%d", &n);
	scanf("%s", m);
	mlen = strlen(m);
	for (int i = 0; i < mlen; i++) ans = (ans * 10 + m[i] - '0') % n;
	if (!ans) printf("%d\n", n);
	else printf("%d\n", ans);
	return 0;
}
