#include <cstdio>
using namespace std;

int s, t, w, cnt = 5;
char num[26], l, r;

int main()
{
	scanf("%d %d %d", &s, &t, &w);
	scanf("%s", num);
	l = s + 'a' - 1;
	r = t + 'a' - 1;
	while (cnt--)
	{
		int i = w - 1;
		while (i != -1 && num[i] == r + i + 1 - w) i--;
		if (i == -1) break;
		num[i]++;
		for (int j = i + 1; j < w; j++) num[j] = num[j - 1] + 1;
		puts(num);
	}
	return 0;
}
