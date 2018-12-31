#include <cstdio>
#include <cstring>
using namespace std;
int n, i, j, k;
int main()
{
	scanf("%d", &n);
	char *s = new char[72 * (n / 72 + 1) + 1];
	char *temp = new char[73];
	for (i = 0; i <= n / 72; i++)
	{
		scanf("%s", temp);
		memcpy(s + i * 72, temp, 72);
	}
	i = 0;
	j = 1;
	while ((i < n) && (j < n))
	{
		for (k = 0; k < n; k++) if (s[i + k] != s[j + k]) break;
		if (k == n) break;
		if (s[i + k] > s[j + k]) i = i + k + 1;
		else j = j + k + 1;
		if (i == j) j++;
	}
	if (i == n) i = 0;
	printf("%d\n", i);
	return 0;
}
