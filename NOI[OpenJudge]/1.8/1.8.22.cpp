//Code By HeRaNO
#include<iostream>
#include<cstdio>
using namespace std;
int fang[50][50] = {0};
int main()
{
	//freopen("magic.in","r",stdin);
	//freopen("magic.out","w",stdout);
	int hang = 1, lie, x, j, i, tmphang, tmplie;
	cin >> x;
	if (x == 1)
	{
		cout << 1;
		return 0;
	}
	lie = x / 2;
	lie++;
	fang[hang][lie] = 1;
	for (i = 2; i <= x * x; i++)
	{
		if ((hang == 1) && (lie != x))
		{
			hang = x;
			lie++;
			fang[hang][lie] = i;
			continue;
		}
		if ((hang != 1) && (lie == x))
		{
			lie = 1;
			hang--;
			fang[hang][lie] = i;
			continue;
		}
		if ((hang == 1) && (lie == x))
		{
			hang++;
			fang[hang][lie] = i;
			continue;
		}
		if ((hang != 1) && (lie != x))
		{
			hang--;
			lie++;
			if (fang[hang][lie] == 0)
			{
				fang[hang][lie] = i;
				continue;
			}
			else
			{
				hang = hang + 2;
				lie--;
				fang[hang][lie] = i;
				continue;
			}
		}
	}
	for (i = 1; i <= x; i++)
		for (j = 1; j <= x; j++)
		{
			cout << fang[i][j] << " ";
			if (j == x)
				cout << endl;
		}
	return 0;
}
