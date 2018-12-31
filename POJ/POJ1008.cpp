#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

string haab[20] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
string holly[21] = {"0", "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

int n;
string a;
int month, year, day;

int main()
{
	scanf("%d", &n);
	printf("%d\n", n);
	while (n--)
	{
		scanf("%d.", &day);
		cin >> a >> year;
		for (int i = 0; i <= 19; i++)
		{
			if (a == haab[i])
			{
				month = i;
				break;
			}
		}
		int date = 365 * year + 20 * month + day + 1;
		int hyear = date / 260;
		if (date % 260 == 0) hyear--;
		date -= hyear * 260;
		int hmonth = date % 20;
		if (!hmonth) hmonth = 20;
		int hday = date % 13;
		if (!hday) hday = 13;
		cout << hday << " " << holly[hmonth] << " " << hyear << endl;
	}
	return 0;
}
