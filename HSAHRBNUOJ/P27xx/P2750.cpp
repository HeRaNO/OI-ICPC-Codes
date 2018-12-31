#include <cstdio>
#include <cstring>
#define MAXN 2000010
using namespace std;

char c[MAXN];
long long m[MAXN], n[MAXN], t[MAXN];
int mlen, nlen, tlen;

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

bool check(int d)
{
	memset(t, 0, sizeof t);
	for (int i = 1; i <= nlen; i++) t[i] = n[i] * (long long)d;
	tlen = nlen;
	for (int i = 1; i <= tlen; i++)
	{
		if (t[i] >= 10) tlen = mymax(tlen, i + 1);
		t[i + 1] += t[i] / 10LL;
		t[i] %= 10LL;
	}
	if (tlen > mlen) return false;
	if (tlen < mlen) return true;
	for (int i = tlen; i; i--) if (t[i] != m[i]) return t[i] < m[i];
	return true;
}

inline int Binary()
{
	long long l = 0, r = 2e9, mid;
	int ans;
	while (l <= r)
	{
		mid = l + r >> 1;
		if (check(mid)) l = mid + 1, ans = mid;
		else r = mid - 1;
	}
	return ans;
}

int main()
{
	//freopen("spring.in","r",stdin);freopen("spring.out","w",stdout);
	scanf("%s", c);
	mlen = strlen(c);
	for (int i = 1; i <= mlen; i++) m[i] = c[mlen - i] - '0';
	scanf("%s", c);
	nlen = strlen(c);
	for (int i = 1; i <= nlen; i++) n[i] = c[nlen - i] - '0';
	printf("%d\n", Binary());
	return 0;
}
