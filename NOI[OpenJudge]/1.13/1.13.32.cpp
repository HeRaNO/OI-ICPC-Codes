//Code By HeRaNO
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int y = 2000, m = 1, d = 1, xq = 6, flag, i, q;
	scanf("%d", &q);
	for (i = 1; i <= q; i++)
	{
		d++;
		xq++;
		if (xq > 7) xq = 1;
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
	printf("%d-%02d-%02d", y, m, d);
	switch (xq)
	{
	case 1:
		printf(" Monday");
		break;
	case 2:
		printf(" Tuesday");
		break;
	case 3:
		printf(" Wednesday");
		break;
	case 4:
		printf(" Thursday");
		break;
	case 5:
		printf(" Friday");
		break;
	case 6:
		printf(" Saturday");
		break;
	case 7:
		printf(" Sunday");
		break;
	}
}
