#include <cstdio>
#include <vector>
#include <cstring>
#include <cassert>

const int dx[] = {0, 1, 1, 2, 3, 3, 4};
const int dy[] = {1, 0, 2, 1, 0, 2, 1};

char s[20][100010];
int patMp[128];

int main()
{
	memset(patMp, -1, sizeof patMp);
	patMp[0b1011101] = 2; patMp[0b1011011] = 3;
	patMp[0b0111010] = 4; patMp[0b1101011] = 5;
	patMp[0b1101111] = 6; patMp[0b1010010] = 7;
	patMp[0b1111111] = 8; patMp[0b1111011] = 9;
	patMp[0b1110111] = 0;
	for (int i = 0; i < 16; i++)
	{
		int a = i >> 2, b = i & 3;
		patMp[1 << 5 | a << 3 | 1 << 2 | b] = 1;
	}
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%s", s[i] + 1);
	for (int j = 1; j <= m; j++)
		for (int i = 1; i <= n; i++)
			if (s[i][j] == 'o')
			{
				int pat = 0;
				for (int k = 0; k < 7; k++)
					pat = pat << 1 | (s[i + dx[k]][j + dy[k]] == 'o');
				int ans = -1;
				ans = patMp[pat];
				assert(ans != -1);
				printf("%d", ans);
				if (ans != 1) j += 2;
				break;
			}
	puts("");
	return 0;
}