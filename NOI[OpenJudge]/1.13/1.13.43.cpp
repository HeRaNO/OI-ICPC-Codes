//Code By HeRaNO
#include <cstdio>
#include <algorithm>
using namespace std;

int day[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int n;
int year, month1, month2;
int sum;

bool is_leap(int n)
{
	if (n % 400 == 0) return true;
	if (n % 4 == 0 && n % 100 != 0) return true;
	return false;
}

int main()
{
	scanf("%d", &n);
	while (n--)
	{
		sum = 0;
		day[2] = 28;
		scanf("%d %d %d", &year, &month1, &month2);
		if (month1 > month2) swap(month1, month2);
		if (is_leap(year)) day[2] = 29;
		for (int i = month1; i < month2; i++)
			sum += day[i];
		if (sum % 7 == 0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
