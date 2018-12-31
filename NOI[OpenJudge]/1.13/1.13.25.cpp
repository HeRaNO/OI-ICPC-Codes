//Code By HeRaNO
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int y, m, d, flag, i, toy, tom, tod;
	int cnt = 0;
	cin >> y >> m >> d;
	cin >> toy >> tom >> tod;
	while ((y != toy) || (m != tom) || (d != tod))
	{
		d++;
		cnt++;
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
	}
	cout << cnt;
	return 0;
}
