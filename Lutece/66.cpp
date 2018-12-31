#include <cstdio>
using namespace std;

int srt, wit, rr;
int n, a, b, c, d, e, f;
bool p[1000000];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d:%d:%d %d:%d:%d", &a, &b, &c, &d, &e, &f);
		int l = a * 3600 + b * 60 + c, r = d * 3600 + e * 60 + f;
		for (int j = l; j < r; j++) p[j] = true;
	}
	scanf("%d:%d:%d", &a, &b, &c);
	srt = a * 3600 + b * 60 + c;
	scanf("%d:%d:%d", &a, &b, &c);
	rr = a * 3600 + b * 60 + c;
	scanf("%d:%d:%d", &a, &b, &c);
	wit = a * 3600 + b * 60 + c;
	while (srt < 86400)
	{
		for (int j = srt; j <= srt + wit; j++) if (!p[j])
			{
				printf("%02d:%02d:%02d\n", j / 3600, (j % 3600) / 60, j % 60);
				return 0;
			}
		srt += rr;
	}
	puts("-1");
	return 0;
}