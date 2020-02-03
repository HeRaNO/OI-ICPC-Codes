#include <iostream>
#include <cstring>
using namespace std;

struct student
{
	string name;
	int qmcj;
	int pycj;
	char gb;
	char west;
	int lw;
	int sum = 0;
};

student a[101];
int i, n;
long long sum = 0;
int maxpos, maxl = 0;

int main()
{
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i].name >> a[i].qmcj >> a[i].pycj >> a[i].gb >> a[i].west >> a[i].lw;
		if (a[i].qmcj > 80 && a[i].lw >= 1)
			a[i].sum += 8000;
		if (a[i].qmcj > 85 && a[i].pycj > 80)
			a[i].sum += 4000;
		if (a[i].qmcj > 90)
			a[i].sum += 2000;
		if (a[i].qmcj > 85 && a[i].west == 'Y')
			a[i].sum += 1000;
		if (a[i].pycj > 80 && a[i].gb == 'Y')
			a[i].sum += 850;
		sum += a[i].sum;
		if (a[i].sum > maxl)
		{
			maxpos = i;
			maxl = a[i].sum;
		}
		cin.clear();
	}
	cout << a[maxpos].name << endl;;
	cout << a[maxpos].sum << endl;
	cout << sum;
	return 0;
}
