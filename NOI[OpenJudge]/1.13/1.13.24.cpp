//Code By HeRaNO
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;

int yue[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int year, month, week = 1;

bool is_leap(int x)
{
	if (x % 4 == 0 && x % 100 != 0 || x % 400 == 0) return true;
	return false;
}

int main()
{
	scanf("%d %d", &year, &month);
	printf("Sun Mon Tue Wed Thu Fri Sat\n");
	for (int i = 1900; i < year; i++)
	{
		if (is_leap(i)) yue[2] = 29;
		for (int j = 1; j <= 12; j++) week = (week + yue[j]) % 7;
		if (yue[2] == 29) yue[2] = 28;
	}
	if (is_leap(year)) yue[2] = 29;
	else yue[2] = 28;
	for (int i = 1; i < month; i++) week = (week + yue[i]) % 7;
	for (int i = 1; i <= week; i++) printf("    ");
	for (int i = 1; i <= yue[month]; i++)
	{
		cout << setw(3) << setiosflags(ios::right) << i << " ";
		if (i == yue[month] || (i + week) % 7 == 0) printf("\n");
	}
	return 0;
}
