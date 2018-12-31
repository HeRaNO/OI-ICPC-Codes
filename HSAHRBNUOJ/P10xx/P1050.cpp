#include <cstdio>
using namespace std;

int a[10];
bool first = true;

inline void out(int a, int b)
{
	for (int i = 1; i <= a; i++)
	{
		if (first)
		{
			first = false;
			printf("%d", b);
		}
		else printf(" %d", b);
	}
	return ;
}

int main()
{
	for (int i = 1; i <= 9; i++) scanf("%d", &a[i]);
	for (int _1 = 0; _1 < 4; _1++)
		for (int _2 = 0; _2 < 4; _2++)
			for (int _3 = 0; _3 < 4; _3++)
				for (int _4 = 0; _4 < 4; _4++)
					for (int _5 = 0; _5 < 4; _5++)
						for (int _6 = 0; _6 < 4; _6++)
							for (int _7 = 0; _7 < 4; _7++)
								for (int _8 = 0; _8 < 4; _8++)
									for (int _9 = 0; _9 < 4; _9++)
									{
										int cnt = 0;
										cnt += (a[1] + _1 + _2 + _4) % 4;
										cnt += (a[2] + _1 + _2 + _3 + _5) % 4;
										cnt += (a[3] + _2 + _3 + _6) % 4;
										cnt += (a[4] + _1 + _4 + _5 + _7) % 4;
										cnt += (a[5] + _1 + _3 + _5 + _7 + _9) % 4;
										cnt += (a[6] + _3 + _5 + _6 + _9) % 4;
										cnt += (a[7] + _4 + _7 + _8) % 4;
										cnt += (a[8] + _5 + _7 + _8 + _9) % 4;
										cnt += (a[9] + _6 + _8 + _9) % 4;
										if (!cnt)
										{
											out(_1, 1);
											out(_2, 2);
											out(_3, 3);
											out(_4, 4);
											out(_5, 5);
											out(_6, 6);
											out(_7, 7);
											out(_8, 8);
											out(_9, 9);
											putchar('\n');
											return 0;
										}
									}
	if (first) puts("No solution!");
	return 0;
}