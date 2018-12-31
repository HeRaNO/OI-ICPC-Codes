//Code By HeRaNO
#include <cstdio>
#include <iostream>
using namespace std;

char a[11][11], b[11][11];
int n;
int One, Two, Three, Four;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> b[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (a[i][j] == b[j][n + 1 - i]) One++;
			if (a[i][j] == b[n + 1 - j][i]) Two++;
			if (a[i][j] == b[n + 1 - i][n + 1 - j]) Three++;
			if (a[i][j] == b[i][j]) Four++;
		}
	n *= n;
	if (One == n) printf("1\n");
	else if (Two == n) printf("2\n");
	else if (Three == n) printf("3\n");
	else if (Four == n) printf("4\n");
	else printf("5\n");
	return 0;
}
