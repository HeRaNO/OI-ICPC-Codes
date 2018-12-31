#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int y, m, d, flag, week;
int toy;
int ans[8];
int main()
{
	scanf("%d", &toy);
	y = 1900;
	m = 1;
	d = 1;
	week = 1;
	while (y <= 1900 + toy - 1)
	{
		d++;
		week++;
		if (y % 100 == 0)
		{
			if ((y % 400 == 0) && (m == 2))
				flag = 29;
			else
			{
				switch (m)
				{
				case 1:
					flag = 31;
					break;
				case 2:
					flag = 28;
					break;
				case 3:
					flag = 31;
					break;
				case 4:
					flag = 30;
					break;
				case 5:
					flag = 31;
					break;
				case 6:
					flag = 30;
					break;
				case 7:
					flag = 31;
					break;
				case 8:
					flag = 31;
					break;
				case 9:
					flag = 30;
					break;
				case 10:
					flag = 31;
					break;
				case 11:
					flag = 30;
					break;
				case 12:
					flag = 31;
					break;
				}
			}
			if (d > flag)
			{
				d = 1;
				m++;
				if (m == 13)
				{
					m = 1;
					y++;
				}
			}
		}
		else
		{
			if ((y % 4 == 0) && (m == 2))
				flag = 29;
			else
			{
				switch (m)
				{
				case 1:
					flag = 31;
					break;
				case 2:
					flag = 28;
					break;
				case 3:
					flag = 31;
					break;
				case 4:
					flag = 30;
					break;
				case 5:
					flag = 31;
					break;
				case 6:
					flag = 30;
					break;
				case 7:
					flag = 31;
					break;
				case 8:
					flag = 31;
					break;
				case 9:
					flag = 30;
					break;
				case 10:
					flag = 31;
					break;
				case 11:
					flag = 30;
					break;
				case 12:
					flag = 31;
					break;
				}
			}
			if (d > flag)
			{
				d = 1;
				m++;
				if (m == 13)
				{
					m = 1;
					y++;
				}
			}
		}
		if (week == 8) week = 1;
		if (d == 13) ans[week]++;
	}
	cout << ans[6] << " " << ans[7] << " ";
	for (int i = 1; i <= 4; i++)
		cout << ans[i] << " ";
	cout << ans[5] << endl;
	return 0;
}
