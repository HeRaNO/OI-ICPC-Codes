#include <cstdio>
#include <cstring>
#define MAXN 5000010
using namespace std;

char s[MAXN];
int n, code, ans;
int DNA[MAXN], cnt[1 << 10], _4pow[6];

inline int mymax(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	_4pow[0] = 1;
	for (int i = 1; i <= 5; i++) _4pow[i] = _4pow[i - 1] << 2;
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'A') DNA[i + 1] = 0;
		else if (s[i] == 'G') DNA[i + 1] = 1;
		else if (s[i] == 'C') DNA[i + 1] = 2;
		else DNA[i + 1] = 3;
	}
	for (int i = 1; i <= n - 4; i++)
	{
		code = 0;
		for (int j = 0; j <= 4; j++) code += _4pow[j] * DNA[j + i];
		cnt[code]++;
	}
	for (int i = 0; i < (1 << 10); i++) ans = mymax(ans, cnt[i]);
	printf("%d\n", ans);
	return 0;
}