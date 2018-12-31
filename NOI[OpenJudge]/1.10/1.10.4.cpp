//Code By HeRaNO
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct student
{
	int num;
	int mark;
	int x;
};

student a[301], tmp;
int i, j, k;
int n, x, y, z;

int main()
{
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i].x >> y >> z;
		a[i].mark = a[i].x + y + z;
		a[i].num = i;
	}
	for (j = 1; j <= n; j++)
		for (i = 1; i <= n - j; i++)
		{
			if (a[i].mark < a[i + 1].mark)
			{
				tmp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = tmp;
			}
			else if (a[i].mark == a[i + 1].mark)
			{
				if (a[i].x < a[i + 1].x)
				{
					tmp = a[i];
					a[i] = a[i + 1];
					a[i + 1] = tmp;
				}
				if (a[i].x == a[i + 1].x && a[i].num > a[i + 1].num)
				{
					tmp = a[i];
					a[i] = a[i + 1];
					a[i + 1] = tmp;
				}
			}
		}
	for (i = 1; i <= 5; i++)
		cout << a[i].num << " " << a[i].mark << endl;
	return 0;
}