#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char zhongxu[9], houxu[9], xian[9];
int i, j, k;
int len;

void work(int zx, int zxcd, int hx, int hxcd)
{
	if (zx > zxcd)
		return;
	cout << houxu[hxcd];
	for (i = zx; i <= zxcd; i++)
	{
		if (zhongxu[i] == houxu[hxcd])
		{
			work(zx, i - 1, hx, hx + i - 1 - zx);
			work(i + 1, zxcd, hx + i - zx, hxcd - 1);
		}
	}
}

int main()
{
	cin >> zhongxu;
	cin.clear();
	cin >> houxu;
	cin.clear();
	len = strlen(zhongxu);
	work(0, len - 1, 0, len - 1);
	cout << endl;
	return 0;
}
